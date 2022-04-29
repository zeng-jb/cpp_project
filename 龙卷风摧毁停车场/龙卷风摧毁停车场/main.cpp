#include<iostream>
#include"ParkingLot.h"
using namespace std;

void menu() {
	cout << "停车场管理系统；" << endl;
	cout << "         （1）初始化" << endl;
	cout << "         （2）车辆进库" << endl;
	cout << "         （3）车辆离开" << endl;
	cout << "         （4）输出停车场所有车牌号" << endl;
	cout << "         （5）输出候车区所有车牌号" << endl;
	cout << "         （6）退出系统" << endl;
	cout << "请输入操作序号：" << endl;
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
		case 1:A.created(); break;                //设置停车场最大存放的车辆数
		case 2:A.carcome(); break;                //车辆进库操作函数
		case 3:A.carleave(); break;               //车辆离开操作函数
		case 4:A.putAll(); break;                 //输出停车场内所有的车辆车牌信息
		case 5:A.putWait(); break;                //输出候车区内所有的车辆车牌信息
		case 6:exit(0);
		default:
			cout << "输入错误，请重新输入；" << endl;
			break;
		}
		//A.puttime();
	}
}