#pragma once
#include<iostream>
#include"SeqQueue.h"
#include"Seqstack.h"
using namespace std;

struct date                   //����ͣ����ͣ��ʱ��
{
	int hour;
	int min;
};

class ParkingLot
{
public:
	ParkingLot() {};              //���캯��
	~ParkingLot() {};               //��������
	void created();                //��ʼ������
	void carcome();              //��������
	void carleave();               //�����뿪
	void cash(int index);                  //ͣ����
	void putAll();                 //���ͣ���������г�����Ϣ
	void putWait();                 //������������г�����Ϣ
	void puttime();                 //���ͣ��ʱ��
private:
	Seqstack<int> stack;             //������ͣ����������ջ
	SeqQueue<int> queue;              //�����ź�����ѭ������
	date time1[10] = {0};               //��ͣ����ʱ���ʼ��0
	date time2[10] = {0};                //��ͣ����ʱ���ʼ��0
	int maxSize;                 //ͣ�������ͣ������
	int num = 0;                 //��ǰͣ������
};

void ParkingLot::created() {                            //��ʼ������������ջ���������Ŀ
	int n;
	cout << "������ͣ��������ͣ��������" << endl;
	cin >> n;
	//for (int i = 0; i < n; i++) {
	//	stack.Push(i + 1);
	//}
	//cout << stack;
	maxSize = n;

	num = 0;
	cout << "��ʼ���ɹ���" << endl;
}

void ParkingLot::cash(int index) {                      //����ͣ���Ѻ���
	int cash = 0;
	int h, m;
	h = time2[index].hour - time1[index].hour;
	m = time2[index].min - time1[index].min;
	if (m < 0) {                                        //�������δ������Сʱ-1������+60
		h = h - 1;
		m = m + 60;
	}
	cash = 3 * h;
	if (m > 0)cash += 3;                                //����һСʱ��һСʱ��
	cout << "ͣ����ʱ��Ϊ " << h << " Сʱ" << m << " ����" << endl;
	cout << "ͣ���ķ���Ϊ " << cash << " ��Ԫ��" << endl;
}

void ParkingLot::carcome() {                               //�������⺯��
	int k;                                                         //�����α�����ʾ����
	int i=num;
	cout << "�����������ĳ��ƺţ�" << endl;
	cin >> k;
	if (i<maxSize) {                                         //��������������������������ջ
		cout << "�����뵽���ʱ��(�ո��ֿ�)��" << endl;
		cin >> time1[i].hour >> time1[i].min;               //�����ջ/���������ʱ��
		stack.Push(k);                                        //��ջ
		cout << "ͣ���ɹ���" << endl;
		cout << "��ͣ������λ��" << stack.getSize() << endl;     //�����ǰ��������λ��
		i++;
		num++;
	}
	else {
		cout << "�Բ���ͣ�������������ں����Ⱥ�" << endl;
		queue.EnQueue(k);                                            //������������ջ��������������ѭ�����м�����
		cout << "�ں�����λ��" << queue.getSize() << endl;
	}
}

void ParkingLot::carleave() {                                 //�����г����뿪��������
	int k;                                                      //�����α�ʾ������
	int x;                                                      //ջ���߶����е���Ԫ��
	int i = num-1;                                              //�������ʱ�亯��i,����ʱ�亯����0��ʼ����˳�����-1
	int flag = 0;                                             //�жϳ����뿪
	Seqstack<int> stack1;                                //���泵��������ʱ�õ�ѭ��ջ
	cout << "������Ҫ�뿪���������ƺţ�" << endl;
	cin >> k;
	if (stack.IsEmpty() == true)cout << "�Բ���ͣ�����գ�" << endl;
	while(stack.IsEmpty() == false){
		stack.Pop(x);                                          //��������
		if (x == k) {                                          //�����������ƥ��
			cout << "�뿪��ʱ��(�ո��ֿ�)��" << endl;
			cin >> time2[i].hour >> time2[i].min;              //�뿪��ʱ��
			cash(i);                                           //����ͣ���Ѽ��㺯��
			flag = 1;
			num -= 1;                                          //��������һ
			break;
		}
		else {                                                 //���������Ϣ��ƥ��
			stack1.Push(x);                                    //������������Ϣ������ʱջ��
			i--;
			if (stack.IsEmpty() == true) {                     //��ջΪ�����˳�
				cout << "�Բ�����ͣ����û�ж�Ӧ�˳��Ƶĳ�" << endl;
				break;
			}
		}
	 }	
	if (flag == 1) {
		if (!queue.IsEmpty()) {                                  //���в�Ϊ�գ�����
			queue.DeQueue(x);                                    //������һ������
			stack.Push(x);                                       //��ջ���뵱ǰ����λ��
			time1[i].hour = time2[i].hour;                        //��ջʱ��Ϊ��һ����ջʱ��
			time1[i].min = time2[i].min;
			num += 1;                                            //ͣ�����ڳ���+1
		}
			//time2[i].hour = time2[i].min = 0;
			flag = 0;
		}
	while (stack1.IsEmpty()==false)                             //��ʱջ��Ϊ��
	{
			stack1.Pop(x);                                      //��˳���ջ���뵽ͣ������
			stack.Push(x);
	}
	//stack1.~Seqstack();
	if (num < maxSize) {                                        //ʱ�亯������ͣ�����ڳ�����С�������
		for (; i < 9; i++) {                                     //��iλ��֮���ȫ��ǰ��
			time1[i].hour = time1[i + 1].hour;
			time1[i].min = time1[i + 1].min;
		}
	}
}

void ParkingLot::putAll() {
	cout << "ͣ������ͣ�������" << endl;
	cout << stack << endl;
}
void ParkingLot::putWait() {
	cout << "������ͣ�������" << endl;
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