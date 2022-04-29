// CDlgExec.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "CDlgExec.h"
#include "afxdialogex.h"


// CDlgExec 对话框

IMPLEMENT_DYNAMIC(CDlgExec, CDialogEx)

CDlgExec::CDlgExec(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EXEC, pParent)
{

}

CDlgExec::~CDlgExec()
{
}

void CDlgExec::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
//	DDX_Control(pDX, IDC_PIC, M_PIC);
}


BEGIN_MESSAGE_MAP(CDlgExec, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CDlgExec::OnEnChangeEdit1)
	ON_STN_CLICKED(IDC_PIC, &CDlgExec::OnStnClickedPic)
END_MESSAGE_MAP()


// CDlgExec 消息处理程序


void CDlgExec::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	
}


void CDlgExec::OnStnClickedPic()
{
	// TODO: 在此添加控件通知处理程序代码
}
