#pragma once


// Cdelete 对话框

class Cdelete : public CDialogEx
{
	DECLARE_DYNAMIC(Cdelete)

public:
	Cdelete(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cdelete();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
private:
	CString m_car;
	int m_time;
	CString m_show;
public:
	afx_msg void OnBnClickedButton1();

};
