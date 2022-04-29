#pragma once


// CD拉过来 对话框

class CD拉过来 : public CDialogEx
{
	DECLARE_DYNAMIC(CD拉过来)

public:
	CD拉过来(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CD拉过来();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
