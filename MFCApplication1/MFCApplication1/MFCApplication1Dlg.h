
// MFCApplication1Dlg.h: 头文件
//

#pragma once
#include"CDlgExec1.h"

// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

private:
	CDlgExec1 dlg;
	

public:
	CStatic n_text;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	//afx_msg void OnStnClickedText();
	afx_msg void OnStnClickedPic();
	CStatic m_pic;
	afx_msg void OnBnClickedButton5();
	CButton m_btn;
//	CButton m_edit1;
//	CButton m_edit2;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnEnChangeEdit1();
private:
	CString m_text1;
public:
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	int k;
};
