// StepNCAnnotatorView.cpp : implementation of the CStepNCAnnotatorView class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "StepNCAnnotatorView.h"

BOOL CStepNCAnnotatorView::PreTranslateMessage(MSG* pMsg)
{
	if((pMsg->message < WM_KEYFIRST || pMsg->message > WM_KEYLAST) &&
	   (pMsg->message < WM_MOUSEFIRST || pMsg->message > WM_MOUSELAST))
		return FALSE;

	// give HTML page a chance to translate this message
	return (BOOL)SendMessage(WM_FORWARDMSG, 0, (LPARAM)pMsg);
}
