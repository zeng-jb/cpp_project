#include<iostream>
#include"ParkingLot.h"
using namespace std;

void menu() {
	cout << "ͣ��������ϵͳ��" << endl;
	cout << "         ��1����ʼ��" << endl;
	cout << "         ��2����������" << endl;
	cout << "         ��3�������뿪" << endl;
	cout << "         ��4�����ͣ�������г��ƺ�" << endl;
	cout << "         ��5������������г��ƺ�" << endl;
	cout << "         ��6���˳�ϵͳ" << endl;
	cout << "�����������ţ�" << endl;
}
void main()
{	
	
	ParkingLot A;
	int choice;
	while (1) {
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:A.created(); break;                //����ͣ��������ŵĳ�����
		case 2:A.carcome(); break;                //���������������
		case 3:A.carleave(); break;               //�����뿪��������
		case 4:A.putAll(); break;                 //���ͣ���������еĳ���������Ϣ
		case 5:A.putWait(); break;                //������������еĳ���������Ϣ
		case 6:exit(0);
		default:
			cout << "����������������룻" << endl;
			break;
		}
		//A.puttime();
	}
}