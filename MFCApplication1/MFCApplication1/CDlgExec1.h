#pragma once


// CDlgExec1 对话框

class CDlgExec1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgExec1)

public:
	CDlgExec1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgExec1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EXEC1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
