
// ParkingLotDlg.h: 头文件
//

#pragma once
#include<string>
#include<list>

using namespace std;
struct Car
{
	int time0;
	int time1;
	CString car;
};

// CParkingLotDlg 对话框
class CParkingLotDlg : public CDialogEx
{
// 构造
public:
	CParkingLotDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PARKINGLOT_DIALOG };
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

//	Cdelete m_dlg;
private:
	CComboBox m_combo;
	int m_time;
	
	CString m_car;

	
	

	

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton2();
	
	CListCtrl m_list1;
	CListCtrl m_list2;
	Car car[6], wcar[6];
	int n, count, waitnum;
	
	static CParkingLotDlg* pParkingLotDlg;
};
