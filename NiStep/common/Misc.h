//
// Misc.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#define SMARTPOINTER

#include <vector>
#include "atlrx.h"
#include "atlcomtime.h"
#include "atlfile.h"
#include "Comutil.h"
#include <atlstr.h>
#include <comdef.h>


typedef std::vector<CString>::iterator CStringVectorIterator;
/**
* Clones a WSTR using CoTaskMemAlloc for marshalling in COM. Not used for BSTR. 
* @param  oldstr  string to clone.
*/
inline WCHAR * WSTRClone(const WCHAR *oldstr)
{
	WCHAR *newstr;
	if(oldstr==NULL)
		oldstr=L"";

	newstr = (WCHAR*)CoTaskMemAlloc(sizeof(WCHAR) * (wcslen(oldstr) + 1));

	if(newstr) 
		wcscpy(newstr, oldstr);
	return newstr;
}

#ifdef SMARTPOINTER
#include <boost/intrusive_ptr.hpp>

/**
* Generic Template for using boost smart pointer.
*/
template<typename T>
class ISmartPointer
{
public:
	ISmartPointer() : _refs(0) {}
	//! destructor
	virtual ~ISmartPointer(){};
//private:
	int _refs; //! reference count
	friend inline void intrusive_ptr_release(T* pThis)
	{
		if(--pThis->_refs == 0 ) { 
			delete pThis;
		}
	}
	friend inline void intrusive_ptr_add_ref(T* pThis)
	{
		pThis->_refs++;
	}
	friend inline void intrusive_ptr_release(const T* pThis)
	{
		if(--const_cast<T*>(pThis)->_refs == 0 ) { 
			delete const_cast<T*>(pThis);
		}
	}
	friend inline void intrusive_ptr_add_ref(const T* pThis)
	{
		const_cast<T*>(pThis)->_refs++;

	}
};
#endif

/** Load a string given a resource id @param id is the resorce id. */
inline CString LoadResString(UINT id) { CString txt; txt.LoadString((UINT) id); return txt; }

/** Converts a string vector into one string. @param string is the string vector @param is the separator between vector items. Default is blank.*/

inline CString ToString(std::vector<CString> &strings, CString separator=_T(" "))
{
	CString tmp; 
	for(UINT i=0; i< strings.size(); i++) 
		tmp.AppendFormat(_T("%s%s"), ((i>0)? separator : _T("")), strings.at(i));  
	return tmp; 
}
inline int StrCount(CString s, char c) { int n=0; for(int i=0; i<s.GetLength(); i++) if(s.GetAt(i)==c) n++; return n; }


template<class T>
class TResizingTable  
{
public:
	typedef std::vector<T>  StepTableRow; 


	TResizingTable<T>() //: table (10, std::vector<T>(10)) 
	{
		
	}
	T & operator ()( int i, int j=0) 
	{
		return this->at(i,j);
		//if(i>=table.size() ) 
		//	table.resize(i+1);
		//if(j>=table[i].size())
		//	table[i].resize(j+1);
		//return table[i][j];

	}
	std::vector<T> & operator[](int i) 
	{ 
		if(i>=table.size() ) 
			table.resize(i+1);
		return table[i]; 
	}
	void clear() {table.clear();   }
	int rows() {  table.size();}
	int cols(int i) { if(i<table.size())  return table[i].size(); return 0;}
	int size() { return table.size(); }
	 bool isDuplicate(std::vector<T> & row)
	 {
		for(int i=0; i< table.size(); i++)
			if(table[i]==row)
				return true;
		return false;		
	 }
	 T & at( int i, int j) 
	 {
		 if(i>=table.size() ) 
			 table.resize(i+1);
		 if(j>=table[i].size())
			 table[i].resize(j+1);
		 return table[i][j];

	 }
	 void push_back(int i, T val) { int n=cols(i); this->at(i,n+1) = val; }
	 void push_back(T val) { int n=size(); this->at(n,0) = val; }

	 std::vector< std::vector<T> > table;

};
typedef TResizingTable<_variant_t>  VarTable;
typedef std::vector<_variant_t> VarList;
typedef TResizingTable<CString>  StringTable;


inline bool CompareVariants(_variant_t a, _variant_t b, VARTYPE vt)
{
	try {
		if(a.vt == b.vt)
			return a==b;
		a.ChangeType(vt);
		b.ChangeType(vt);
		if(a==b)
			return true;

	}
	catch(...)
	{
	}
	return false;

}


class CStringVector : public std::vector<CString> 
{
public:
	typedef std::vector<CString>  Baseclass;
	CStringVector(){}

	operator const std::vector<CString> () {std::vector<CString>  to_vector;  copy( this->begin(), this->end(), to_vector.begin() ); return to_vector;} 
	CStringVector & operator = (const  std::vector<CString> & from)
	{
		this->resize(from.size());
		copy( from.begin(), from.end(), this->begin() );
		return *this;
	}
 	CStringVector( std::vector<CString> & from)
	{
		this->resize(from.size());
		copy( from.begin(), from.end(), this->begin() );
	}
	explicit CStringVector(int n, ...) 
	{ 
		va_list ap;	
		va_start(ap,n); 
		for(int i=0; i< n; i++)
		{
			CString s =va_arg ( ap, CString );
			push_back(s);
		}
		va_end(ap);
	}
	CString Merge() { CString tmp; for(UINT i=0; i< size(); i++) tmp+=at(i);  return tmp; }
	CString ToString(CString separator=_T(" ")) { 
		CString tmp; 
		for(UINT i=0; i< size(); i++) 
		{
			if(i>0)
				tmp.AppendFormat(_T("%s"), separator);  
			tmp.AppendFormat(_T("%s"), at(i));  
		}
		return tmp; 
	}
	void RemoveBlankStrings()
	{
		for(int i=0; i<size(); i++)
		{
			CString tmp = this->at(i);
			tmp.Replace(_T(" "), _T(""));
			tmp.Replace(_T("\t"), _T(""));
			if(tmp.GetLength() < 1)
			{
				erase(begin() + i);
				i--;
			}

		}
	}
	static CStringVector Tokenize(CString str, CString tokens, int bSave=0)
	{
		CString resToken;
		int curPos= 0;
		CStringVector strs;

		resToken= str.Tokenize(tokens,curPos);
		while (resToken != "")
		{
			strs.push_back((!bSave) ? resToken: resToken+str[curPos-1]);  
			resToken= str.Tokenize(tokens,curPos);
		};
		return strs;
	}
	static CStringVector Extract(CString str, CString tokenA, CString tokenB, int bSave=0)
	{
		CStringVector strs;
		int curPos= str.Find(tokenA);

		str=str.Mid(curPos+1);

		while((curPos=str.Find(tokenB))>=0)
		{
			strs.push_back(str.Mid(0,curPos));
			str=str.Mid(curPos+1);
			if((curPos= str.Find(tokenA)) < 0)
				break;
			str=str.Mid(curPos+1); 
			
		}
		return strs;
	}


};

inline _bstr_t bstrFormat(const TCHAR* format, ...)
{
		CString str;
		va_list ptr; va_start(ptr, format);
		str.FormatV(format, ptr);
		// Trace model: ATL::CTrace::s_trace.TraceV(m_pszFileName, m_nLineNo, dwCategory, nLevel, pszFmt, ptr);
		va_end(ptr);
		return _bstr_t((LPCTSTR) str);

}

inline CString StrFormat(const TCHAR* format, ...)
{
		CString str;
		va_list ptr; va_start(ptr, format);
		str.FormatV(format, ptr);
		// Trace model: ATL::CTrace::s_trace.TraceV(m_pszFileName, m_nLineNo, dwCategory, nLevel, pszFmt, ptr);
		va_end(ptr);
		return str;

}
inline std::vector<CString> DoubleZeroString(const TCHAR* str, int size)
{
	CString tmp;
	int curPos= 0;
	char last = '1';
	std::vector<CString> strs;
	
	for(int i=0; i<size; i++) 
	{
		if(last==0 && str[i]==0)
			break;
		if(str[i]==0)
		{
			strs.push_back(tmp);  
			tmp.Empty();
		}
		else
		{
			tmp+=str[i];
		}
		last=str[i];

	};
	if(!tmp.IsEmpty())
		strs.push_back(tmp);  
	return strs;

}
inline CString StrReplace(CString inStr, int pos, int n, CString newStr)
{
		return inStr.Mid(0,pos)+ newStr + inStr.Mid(pos+n);

}

inline boolean ReplacePattern(CString & inStr, CString oldBeginningStr, CString oldEndingStr, CString newStr){
	int i,j,k;

	// Sanity checks
	if(inStr.IsEmpty()) 
		return false;
	if(oldBeginningStr.IsEmpty()) 
		return false;
	if(oldEndingStr.IsEmpty()) 
		return false;

	// Setup up StringEx sizes
	int newCnt = newStr.GetLength();  

	i=0; // Let find determine where to start.

	int cnt=0;
	for(;i<inStr.GetLength();)
	{
		if((j=inStr.Find(oldBeginningStr,  i))<0)
			break;
		if((k=inStr.Find(oldEndingStr, j))<0) 
			break;
		inStr = inStr.Mid(0,j)+ newStr + inStr.Mid(k+oldEndingStr.GetLength());
		i=j+newCnt;
		cnt++;
	}
	if(cnt>0) return true;
	return false;
}

// other pattern uses 	GetPartSpecifics("1857-R1.tap", CString("{[0-9]+}[-_]{[0-9a-zA-Z]+}\\..*"), szProdLine, szPartNumber);
inline CString ReplacePattern(CString &inStr,  CString szRegexPattern, CString szReplacement=_T(""))
{
	CString tmp(inStr);
	CString test(inStr);;
	CAtlRegExp<> regexp;
	CAtlREMatchContext<> mc;
	CString szMatch;
	int pos=0;
	try {
		//pattern.Replace(_T("*"), _T(".*"));  // Change from Regular expression to Bourne Expression
		if(regexp.Parse(szRegexPattern) == REPARSE_ERROR_OK)
		{
			while(regexp.Match(test, &mc) )
			{
				const CAtlREMatchContext<>::RECHAR* szStart = 0;
				const CAtlREMatchContext<>::RECHAR* szEnd = 0;

				//for(UINT i=0; i< mc.m_uNumGroups; i++){
					mc.GetMatch(0, &szStart, &szEnd);
					ptrdiff_t nLength = szEnd - szStart;
					szMatch.SetString( szStart,  nLength );
					UINT n = test.Find(szMatch);
					tmp = StrReplace(tmp, n+pos, (int) nLength, szReplacement) ; // inStr.Replace(szMatch, szReplacement);
					pos = pos + n +  nLength - szReplacement.GetLength() ;
				//}
				test=tmp.Mid(pos);
			}
		}

	}
	catch(...) {}
	return tmp;
}

inline int FindPattern(CString inStr, CString szRegexPattern)
{
	CString tmp;
	CAtlRegExp<> regexp;
	CAtlREMatchContext<> mc;
	int n=-1;
	try {
		//pattern.Replace(_T("*"), _T(".*"));  // Change from Regular expression to Bourne Expression
		if(regexp.Parse(szRegexPattern) == REPARSE_ERROR_OK)
		{
			if(regexp.Match(inStr, &mc) )
			{
				const CAtlREMatchContext<>::RECHAR* szStart = 0;
				const CAtlREMatchContext<>::RECHAR* szEnd = 0;

				if(mc.m_uNumGroups>0)
				{
					mc.GetMatch(0, &szStart, &szEnd);
					return (int) (inStr.GetBuffer() - szEnd );
//					szProdLine.SetString( szStart,  nLength );
				}


			}
		}
	}catch(...) {}
	return n;
}

inline int HandleWindowsMessages()
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
	{
		//OutputDebugString(StringEx("After Message=%x wParam = %d  lParam = %d LOWORD(lParam) = %d HIWORD(lParam) = %d\n",msg.message, msg.wParam,msg.lParam, LOWORD(msg.lParam), HIWORD(msg.lParam)));
		if (msg.message == WM_QUIT)
			return 1;       

		::GetMessage(&msg, NULL, 0, 0);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}	

inline void CopyClipboard(CString source)
{
	// Converts TCHAR into char for ascii clipboard
	if(::OpenClipboard(NULL))
	{
		HGLOBAL clipbuffer;
		::EmptyClipboard();
		clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, sizeof(TCHAR) * (source.GetLength()+1));

#ifdef UNICODE
		WCHAR * buffer;
		buffer = (WCHAR *)::GlobalLock(clipbuffer);
		wcscpy(buffer, source);
		::GlobalUnlock(clipbuffer);	
		::SetClipboardData(CF_UNICODETEXT,clipbuffer);

#else
		char * buffer;
		buffer = (char *)::GlobalLock(clipbuffer);
		strcpy(buffer, (LPCTSTR) source);
		::GlobalUnlock(clipbuffer);		
		::SetClipboardData(CF_TEXT,clipbuffer);

#endif
		::CloseClipboard();
	}
}


#if 0
inline CString GetTimeStamp(COleDateTime inft, CString szFormat=_T("%A, %B %d %Y %H:%M:%S"))
{
	return inft.Format(szFormat);

}
#endif

inline std::string fileToText( const std::string &filename )
{
   std::ifstream fin(filename.c_str());
   return std::string((std::istreambuf_iterator<char>(fin)),std::istreambuf_iterator<char>());
}

inline CString ReadAFile(CString lpszPathName)
{
	CString sBuffer;
	HANDLE	hFile = CreateFile(lpszPathName,
		GENERIC_READ,              // open for reading 
		FILE_SHARE_READ,           // share for reading 
		NULL,                      // no security 
		OPEN_EXISTING,             // existing file only 
		FILE_ATTRIBUTE_NORMAL,     // normal file 
		NULL);                  

	if (INVALID_HANDLE_VALUE == hFile)
	{
		//m_sLastErrmsg="File INVALID_HANDLE_VALUE Error";
		return _T("");
	}
	DWORD dwBytesRead;
	DWORD dwFileSize = GetFileSize(hFile, NULL);

	BYTE * lpBuffer = new BYTE[dwFileSize+1];

	if (!ReadFile(hFile, lpBuffer, dwFileSize, &dwBytesRead, NULL) != FALSE)
	{
		return _T("");
	}

	lpBuffer[dwBytesRead]=0;
	sBuffer=lpBuffer;
	delete [] lpBuffer;        

	CloseHandle(hFile);
	return sBuffer;
}

inline CString GetExeDirectory() 
{
	TCHAR buf[1000];
	CString path;
	GetModuleFileName(NULL, buf, 1000);
	path=buf;
	path = path.Left(path.ReverseFind('\\')+1);
	return path;
}
inline CString GetIniFile()
{
	return StrFormat(_T("%s\\Setup.ini"), GetExeDirectory());

}

inline CString UpDirectory(CString szDir) 
{
	CString path = szDir.Left(szDir.ReverseFind('\\')+1);
	return path;
}

#include <fstream>

inline BOOL SaveDocument(CString filename, CString buffer)
{
	try
	{
		tfstream outputfile;
		outputfile.open (filename, tfstream::out );
		if (!outputfile.is_open())
			return FALSE;
		outputfile <<  (LPCTSTR) buffer;
		outputfile.close();
	}	
	catch (...)
	{
		return FALSE;
	}
	return TRUE;
}

inline boolean  GetFileExists(CString filename)
{
	DWORD dw = ::GetFileAttributes(filename);
	return((dw == 0xfffffffff) ? FALSE : dw );

}

inline double DVal(CString values, int n,  CString separator)
{
	CStringVector tokens=CStringVector::Tokenize(values, separator);
	if(n<0 || n>=tokens.size())
		return 0;
	return _tstof(tokens[n]);

}


inline CString dump_com_error(_com_error &e)
{
	CString tmp;
	tmp+=StrFormat(_T("Error\n"));
	tmp+=StrFormat(_T("\a\tCode = %08lx\n"), e.Error());
	tmp+=StrFormat(_T("\a\tCode meaning = %s"), e.ErrorMessage());
	tmp+=StrFormat(_T("\a\tSource = %s\n"), (LPCTSTR) e.Source());
	tmp+=StrFormat(_T("\a\tDescription = %s\n"), (LPCTSTR) e.Description());
	return tmp;
}

#include <atlapp.h>
#include <atldlgs.h>
inline bool SaveFileDialogString(CString szString, LPCTSTR szFilter)
{
	CFileDialog dlg(FALSE,
		_T("*"),
		NULL,
		OFN_HIDEREADONLY,
		szFilter);
	if( dlg.DoModal() != IDOK )
		return 1;
	SaveDocument(dlg.m_szFileName, szString);
	return 0;
}
inline CString LoadFileDialogString(LPCTSTR szFilter)
{
	CFileDialog dlg(TRUE,
		_T("*"),
		NULL,
		OFN_HIDEREADONLY,
		szFilter);
	if( dlg.DoModal() != IDOK )
		return CString();
	return ReadAFile(dlg.m_szFileName);
}


