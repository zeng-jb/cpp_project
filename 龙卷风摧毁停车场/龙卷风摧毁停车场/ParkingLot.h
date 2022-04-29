#pragma once
#include<iostream>
#include"SeqQueue.h"
#include"Seqstack.h"
using namespace std;

struct date                   //定义停车场停车时间
{
	int hour;
	int min;
};

class ParkingLot
{
public:
	ParkingLot() {};              //构造函数
	~ParkingLot() {};               //析构函数
	void created();                //初始化函数
	void carcome();              //汽车到达
	void carleave();               //汽车离开
	void cash(int index);                  //停车费
	void putAll();                 //输出停车场中所有车辆信息
	void putWait();                 //输出候车区中所有车辆信息
	void puttime();                 //输出停车时间
private:
	Seqstack<int> stack;             //定义存放停车场的有限栈
	SeqQueue<int> queue;              //定义存放候车区的循环队列
	date time1[10] = {0};               //进停车场时间初始化0
	date time2[10] = {0};                //出停车场时间初始化0
	int maxSize;                 //停车场最大停车数量
	int num = 0;                 //当前停车数量
};

void ParkingLot::created() {                            //初始化函数，设置栈的最大存放数目
	int n;
	cout << "请输入停车场最大的停车数量；" << endl;
	cin >> n;
	//for (int i = 0; i < n; i++) {
	//	stack.Push(i + 1);
	//}
	//cout << stack;
	maxSize = n;

	num = 0;
	cout << "初始化成功；" << endl;
}

void ParkingLot::cash(int index) {                      //计算停车费函数
	int cash = 0;
	int h, m;
	h = time2[index].hour - time1[index].hour;
	m = time2[index].min - time1[index].min;
	if (m < 0) {                                        //如果分钟未复数，小时-1，分钟+60
		h = h - 1;
		m = m + 60;
	}
	cash = 3 * h;
	if (m > 0)cash += 3;                                //不足一小时按一小时算
	cout << "停车的时间为 " << h << " 小时" << m << " 分钟" << endl;
	cout << "停车的费用为 " << cash << " （元）" << endl;
}

void ParkingLot::carcome() {                               //车辆进库函数
	int k;                                                         //用整形变量表示车牌
	int i=num;
	cout << "请输入汽车的车牌号；" << endl;
	cin >> k;
	if (i<maxSize) {                                         //当车辆数少于最大数，则继续进栈
		cout << "请输入到达的时间(空隔分开)：" << endl;
		cin >> time1[i].hour >> time1[i].min;               //输入进栈/车辆进库的时间
		stack.Push(k);                                        //进栈
		cout << "停车成功！" << endl;
		cout << "在停车场的位置" << stack.getSize() << endl;     //输出当前车辆所在位置
		i++;
		num++;
	}
	else {
		cout << "对不起，停车场已满；请在候车区等候；" << endl;
		queue.EnQueue(k);                                            //当车辆数大于栈的最大数，则进入循环队列即候车区
		cout << "在候车区的位置" << queue.getSize() << endl;
	}
}

void ParkingLot::carleave() {                                 //车库中车辆离开操作函数
	int k;                                                      //用整形表示车牌数
	int x;                                                      //栈或者队列中弹出元素
	int i = num-1;                                              //定义调用时间函数i,由于时间函数从0开始，因此车辆数-1
	int flag = 0;                                             //判断车辆离开
	Seqstack<int> stack1;                                //里面车出来的临时用的循环栈
	cout << "请输入要离开的汽车车牌号；" << endl;
	cin >> k;
	if (stack.IsEmpty() == true)cout << "对不起，停车场空！" << endl;
	while(stack.IsEmpty() == false){
		stack.Pop(x);                                          //车辆弹出
		if (x == k) {                                          //如果车辆车牌匹配
			cout << "离开的时间(空隔分开)；" << endl;
			cin >> time2[i].hour >> time2[i].min;              //离开的时间
			cash(i);                                           //调用停车费计算函数
			flag = 1;
			num -= 1;                                          //车辆数减一
			break;
		}
		else {                                                 //如果车牌信息不匹配
			stack1.Push(x);                                    //将弹出车牌信息存入临时栈中
			i--;
			if (stack.IsEmpty() == true) {                     //弹栈为空则退出
				cout << "对不起，在停车场没有对应此车牌的车" << endl;
				break;
			}
		}
	 }	
	if (flag == 1) {
		if (!queue.IsEmpty()) {                                  //队列不为空，候车区
			queue.DeQueue(x);                                    //候车区第一辆出队
			stack.Push(x);                                       //进栈进入当前所在位置
			time1[i].hour = time2[i].hour;                        //进栈时间为上一辆出栈时间
			time1[i].min = time2[i].min;
			num += 1;                                            //停车场内车辆+1
		}
			//time2[i].hour = time2[i].min = 0;
			flag = 0;
		}
	while (stack1.IsEmpty()==false)                             //临时栈不为空
	{
			stack1.Pop(x);                                      //按顺序出栈进入到停车场中
			stack.Push(x);
	}
	//stack1.~Seqstack();
	if (num < maxSize) {                                        //时间函数，当停车场内车辆数小于最大数
		for (; i < 9; i++) {                                     //将i位置之后的全部前移
			time1[i].hour = time1[i + 1].hour;
			time1[i].min = time1[i + 1].min;
		}
	}
}

void ParkingLot::putAll() {
	cout << "停车场内停车情况：" << endl;
	cout << stack << endl;
}
void ParkingLot::putWait() {
	cout << "候车区内停车情况：" << endl;
	cout << queue << endl;
}
void ParkingLot::puttime() {
	for (int i = 0; i < 10; i++) {
		cout << time1[i].hour << ":" << time1[i].min << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << time2[i].hour << ":" << time2[i].min << " ";
	}
	cout << endl;
}