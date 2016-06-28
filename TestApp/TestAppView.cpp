
// TestAppView.cpp : implementation of the CTestAppView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestApp.h"
#endif

#include "TestAppDoc.h"
#include "TestAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestAppView

IMPLEMENT_DYNCREATE(CTestAppView, CView)

BEGIN_MESSAGE_MAP(CTestAppView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestAppView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestAppView construction/destruction

CTestAppView::CTestAppView()
{
	// TODO: add construction code here

}

CTestAppView::~CTestAppView()
{
}

BOOL CTestAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestAppView drawing

void CTestAppView::OnDraw(CDC* /*pDC*/)
{
	CTestAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTestAppView printing


void CTestAppView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestAppView diagnostics

#ifdef _DEBUG
void CTestAppView::AssertValid() const
{
	CView::AssertValid();
}

void CTestAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestAppDoc* CTestAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestAppDoc)));
	return (CTestAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestAppView message handlers
