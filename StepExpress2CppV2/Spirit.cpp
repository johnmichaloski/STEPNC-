//
// Spirit.cpp : main source file for Spirit.exe
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#include "stdafx.h"

#include "resource.h"
#include "OutDebug.h"

#include "StepParser.h"


#include "SpiritView.h"
#include "aboutdlg.h" 
#include "MainFrm.h"
#include "atlstr.h"
#include "Misc.h"
#include "Express2Html.h"

CAppModule _Module;

static std::string str="<xarg> ::= X '(' <real_val>  ')';\n"
"<yarg> ::= Y '(' <real_val>  ')';\n"
"<zarg> ::= Z '(' <real_val>  ')';\n"

;


int Run(LPTSTR /*lpstrCmdLine*/ = NULL, int nCmdShow = SW_SHOWDEFAULT)
{
	CMessageLoop theLoop;
	_Module.AddMessageLoop(&theLoop);

	CMainFrame wndMain;
	DebugFileOut debugfile(CString(GetExeDirectory() + "debug.txt"));
	
	basic_debugbuf debugbuf(2048);
	std::cout.rdbuf(&debugfile);
	cout<< "Test Me" << endl;
	CStepNCParser step;
//	step.ExpressParseIt(CStringVector(CString("machining_schema") , CString("milling_schema"), CString()));
	// step.CreateCPPClasses("stepnc_schema");
	step.ExpressParseIt(CStringVector(CString("part203"), CString()));
	step.CreateCPPClasses("ap203");

	//html.Express2Html();

	// This creates the xml help <entity-name> <description> ... </description> <attr1> ... </entity-name>
	//html.Express2XmlHelp();
#if 0
	CString path = "C:\\Program Files\\NIST\\proj\\Tests\\StepNCAnnotator\\HTMLHelp\\Classes\\";




	step.ExpressParseIt(CStringVector(1,   CString("milling_schema")));
	CExpress2Html html(step);
	html.Xml2StdMap("milling", (LPCTSTR) (::GetExeDirectory() + "MillingWithDescription.txt"));
	html.Express2HtmlHelp((LPCTSTR) (path+"milling_schema\\"));
	step.Clear();

	html.Xml2StdMap("machining", (LPCTSTR) (::GetExeDirectory() + "MachiningWithDescription.txt"));
	step.ExpressParseIt(CStringVector(1,   CString("machining_schema")));
	html.Express2HtmlHelp((LPCTSTR) (path+"machining_schema\\"));

#endif
	if(wndMain.CreateEx() == NULL)
	{
		ATLTRACE(_T("Main window creation failed!\n"));
		return 0;
	}

	wndMain.ShowWindow(nCmdShow);

	int nRet = theLoop.Run();

	_Module.RemoveMessageLoop();
	return nRet;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int nCmdShow)
{
	HRESULT hRes = ::CoInitialize(NULL);
// If you are running on NT 4.0 or higher you can use the following call instead to 
// make the EXE free threaded. This means that calls come in on a random RPC thread.
//	HRESULT hRes = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	ATLASSERT(SUCCEEDED(hRes));

	// this resolves ATL window thunking problem when Microsoft Layer for Unicode (MSLU) is used
	::DefWindowProc(NULL, 0, 0, 0L);

	AtlInitCommonControls(ICC_BAR_CLASSES);	// add flags to support other controls

	hRes = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	int nRet = Run(lpstrCmdLine, nCmdShow);

	_Module.Term();
	::CoUninitialize();

	return nRet;
}
