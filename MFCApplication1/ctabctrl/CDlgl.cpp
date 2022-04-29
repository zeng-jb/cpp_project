// CDlgl.cpp: 实现文件
//

#include "pch.h"
#include "ctabctrl.h"
#include "CDlgl.h"
#include "afxdialogex.h"


// CDlgl 对话框

IMPLEMENT_DYNAMIC(CDlgl, CDialogEx)

CDlgl::CDlgl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDlgl::~CDlgl()
{
}

void CDlgl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgl, CDialogEx)
END_MESSAGE_MAP()


// CDlgl 消息处理程序
