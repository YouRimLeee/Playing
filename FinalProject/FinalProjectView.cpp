
// FinalProjectView.cpp: CFinalProjectView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "FinalProject.h"
#endif

#include "FinalProjectDoc.h"
#include "FinalProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFinalProjectView

IMPLEMENT_DYNCREATE(CFinalProjectView, CView)

BEGIN_MESSAGE_MAP(CFinalProjectView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_PLAYING_BUTTERFLY, &CFinalProjectView::OnPlayingButterfly)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CFinalProjectView 생성/소멸

CFinalProjectView::CFinalProjectView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CFinalProjectView::~CFinalProjectView()
{
}

BOOL CFinalProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CFinalProjectView 그리기

void CFinalProjectView::OnDraw(CDC* pDC)
{
	CFinalProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBitmap forest;
	forest.LoadBitmapW(IDB_BIT_FOREST);
	CDC mdc;
	mdc.CreateCompatibleDC(pDC);
	//배경 숲
	mdc.SelectObject(forest);
	pDC->BitBlt(0, 0, 1200, 700, &mdc, 0, 0, SRCCOPY);
	CImage butterfly;
	butterfly.Load(L"res/butterfly.png");
	butterfly.Draw(*pDC, m_pt.x - 50, m_pt.y - 50);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CFinalProjectView 인쇄

BOOL CFinalProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CFinalProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CFinalProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CFinalProjectView 진단

#ifdef _DEBUG
void CFinalProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CFinalProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFinalProjectDoc* CFinalProjectView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFinalProjectDoc)));
	return (CFinalProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CFinalProjectView 메시지 처리기


void CFinalProjectView::OnPlayingButterfly()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CFinalProjectView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	SetTimer(1, 100, NULL); 
	m_xStep = (int)(point.x - m_pt.x) / 10;
	m_yStep = (int)(point.y - m_pt.y) / 10;

	CView::OnLButtonDown(nFlags, point);
}


void CFinalProjectView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_pt.x = m_pt.x + m_xStep;
	m_pt.y = m_pt.y + m_yStep;
	if ((m_pt.x - 50) < 0 || (m_pt.x + 50) > m_WinRight) //왼쪽벽 또는 오른쪽벽
	{
		m_pt.x = (m_xStep < 0) ? 50 : (m_WinRight - 50);//m_pt.x - m_xStep;
		m_pt.y = m_pt.y - m_yStep;
		m_xStep = m_xStep * -1;
	}
	if ((m_pt.y - 50) < 0 || (m_pt.y + 50) > m_WinBottom) // 윗쪽 벽 또는 아랫쪽 벽
	{
		m_pt.x = m_pt.x - m_xStep;
		m_pt.y = (m_yStep < 0) ? 50 : (m_WinBottom - 50);//m_pt.y - m_yStep;
		m_yStep = m_yStep * -1;
	}
	Invalidate();

	CView::OnTimer(nIDEvent);
}


void CFinalProjectView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	m_WinRight = cx;
	m_WinBottom = cy;
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
