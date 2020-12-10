
// FinalProjectView.h: CFinalProjectView 클래스의 인터페이스
//

#pragma once


class CFinalProjectView : public CView
{
protected: // serialization에서만 만들어집니다.
	CFinalProjectView() noexcept;
	DECLARE_DYNCREATE(CFinalProjectView)

// 특성입니다.
public:
	CFinalProjectDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CFinalProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPlayingButterfly();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CPoint m_pt;
	int m_xStep;
	int m_yStep;
	int m_WinRight;
	int m_WinBottom;
	afx_msg void OnPlayingChild();
	int m_kind;
	int m_count;
	CPoint m_Child;
};

#ifndef _DEBUG  // FinalProjectView.cpp의 디버그 버전
inline CFinalProjectDoc* CFinalProjectView::GetDocument() const
   { return reinterpret_cast<CFinalProjectDoc*>(m_pDocument); }
#endif

