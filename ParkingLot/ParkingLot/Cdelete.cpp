// Cdelete.cpp: 实现文件
//

#include "pch.h"
#include "ParkingLot.h"
#include "Cdelete.h"
#include "afxdialogex.h"
#include"ParkingLotDlg.h"


// Cdelete 对话框

IMPLEMENT_DYNAMIC(Cdelete, CDialogEx)

Cdelete::Cdelete(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DELETE, pParent)
	, m_car(_T(""))
	, m_time(0)
	, m_show(_T(""))
{

}

Cdelete::~Cdelete()
{
}

void Cdelete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_car);
	DDX_Text(pDX, IDC_EDIT2, m_time);
	DDX_Text(pDX, IDC_EDIT3, m_show);
}


BEGIN_MESSAGE_MAP(Cdelete, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Cdelete::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Cdelete::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cdelete 消息处理程序


void Cdelete::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}


void Cdelete::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	bool falg = false;
	int i,index;
	CParkingLotDlg* pdlg = CParkingLotDlg::pParkingLotDlg;
	for ( i = 0; i < pdlg->count; i++) {
		GetDlgItemText(IDC_EDIT1, m_car);
		if (m_car == pdlg->car[i].car) {
			falg = true;
			MessageBox(_T("出库成功"));
			index = i;
			UpdateData(true);
			pdlg->car[i].time1 = m_time;
			pdlg->count--;
			int cash = (pdlg->car[i].time1 - pdlg->car[i].time0) * 3;

			CString str;
			str.Format(_T("车辆信息：%s\r\n停车时间：%d\r\n出库时间：%d\r\n停车费用：%d\r\n"), pdlg->car[i].car, pdlg->car[i].time0, pdlg->car[i].time1, cash);
			m_show = str;
			UpdateData(false);

		}
	}
	i = index;
	if (falg == false) {
		MessageBox(TEXT("没有此车辆信息！"));
			return;
	}
	else {
		if (pdlg->wcar[0].time0 ) {                                //候车场有车
			
			pdlg->car[i].car = pdlg->wcar[0].car;
			pdlg->car[i].time0 = pdlg->car[i].time1;

			pdlg->m_list1.DeleteAllItems();
			pdlg->m_list2.DeleteAllItems();
			UpdateData(false);
			for (int j=0; j < pdlg->waitnum; j++) {
				pdlg->wcar[j].car = pdlg->wcar[j + 1].car;
				pdlg->wcar[j].time0 = pdlg->wcar[j + 1].time0;
			}
			pdlg->count++;
			pdlg->waitnum--;
			for (int j = 0; j < pdlg->count; j++)
			{
				CString str, str0;
				str.Format(TEXT("%d"), pdlg->car[j].time0);
				str0.Format(TEXT("%d"), j + 1);
				pdlg->m_list1.InsertItem(0, str0);
				pdlg->m_list1.SetItemText(0, 1, pdlg->car[j].car);
				pdlg->m_list1.SetItemText(0, 2, str);
				UpdateData(false);
			}
			for (int j = 0; j < pdlg->waitnum; j++)
			{
				CString str, str0;
				str.Format(TEXT("%d"), pdlg->wcar[j].time0);
				str0.Format(TEXT("%d"), j + 1);
				pdlg->m_list2.InsertItem(j, str0);
				pdlg->m_list2.SetItemText(j, 1, pdlg->wcar[j].car);
				pdlg->m_list2.SetItemText(j, 2, str);
				UpdateData(false);
			}
		}
		else {
			pdlg->m_list1.DeleteAllItems();
			UpdateData(false);
			for (; i < pdlg->count; i++) {
					pdlg->car[i].car = pdlg->car[i + 1].car;
					pdlg->car[i].time0 = pdlg->car[i + 1].time0;
				}
		
			for (int  j = 0; j < pdlg->count; j++)
			{
				CString str, str0;
				str.Format(TEXT("%d"), pdlg->car[j].time0);
				str0.Format(TEXT("%d"), j+1);
				pdlg->m_list1.InsertItem(0, str0);
				pdlg->m_list1.SetItemText(0, 1, pdlg->car[j].car);
				pdlg->m_list1.SetItemText(0, 2, str);
				UpdateData(false);
			}
		}
	}
	UpdateData(true);
}
