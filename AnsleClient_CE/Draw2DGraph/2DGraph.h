#pragma once

#include <Afxtempl.h>
// C2DGraph
/////////////////////////////////
#define X_MAX 500
#define Y_MAX 2000
#define PIXEL 2
#define TIMER_ECG 100		//单位为毫秒（ms）
#define TIMER_ARGS 200	//单位为毫秒（ms）
/////////////////////////////////
class C2DGraph : public CWnd
{
	DECLARE_DYNAMIC(C2DGraph)

public:
	C2DGraph();
	virtual ~C2DGraph();
public:
	//控件创建的虚方法覆盖
	virtual BOOL Create(LPCTSTR lpszClassName, 
						LPCTSTR lpszWindowName, 
						DWORD dwStyle, 
						const RECT& rect, 
						CWnd* pParentWnd, 
						UINT nID, 
						CCreateContext* pContext) ;

protected:
	//
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
private:
	//将用户添加的点值转换成屏幕坐标
	CPoint GpToSp(CPoint& point);
private:
	//绘制屏幕点
	void DrawPoints();
public:
	//用于刷新控件显示
	void InvalidateCtrl();
public:
	//在曲线末尾添加一个点
	void AppendPoint(DWORD dwPointY);
	//删除曲线第一点
	void DeleteFirstPoint();
private:
	//存储线中的点Y坐标
	CList<DWORD,DWORD> m_lstPointsY;   

	//画表格边框设备环境
	CDC m_dcGrid;

	//表格边框设备环境缓冲位图
	CBitmap m_bitmapGrid ; 
	CBitmap *m_pOldBitmapGrid;

	//用来画线的设备环境
	CDC m_dcLine;  

	//画线设备环境缓冲位图
	CBitmap m_bitmapLine; 
	CBitmap *m_pOldBitmapLine;

public:
	COLORREF m_crBackColor; //控件背景色
	COLORREF m_crGridColor; //表格边框颜色
	COLORREF m_crLineColor; //曲线颜色
	COLORREF m_crTextColor; //输出文本颜色

	double m_dXMaxValue ; //X轴最大值
	double m_dXMinValue ; //X轴最小值
	double m_dYMaxValue ; //Y轴最大值
	double m_dYMinValue ; //Y轴最小值

    LPCTSTR m_strXCaption ; //X轴标题
	LPCTSTR m_strYCaption ; //Y轴标题


};