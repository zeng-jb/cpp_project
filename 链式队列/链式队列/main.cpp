#include<iostream>
#include"LinkedQueue.h"
using namespace std;

void main() {
	LinkedQueue<int>Q;                                   //������������Q
	int x, n;
	cout << "��������ʽ���еĳ��ȣ�" << endl;
	cin >> n;
	cout << "���������Ԫ��ֵ���ո��ֿ���" << endl;
	for (int i = 0; i < n; i++) {                                    //����в���
		//cout << "�������" << i + 1 << "��Ԫ��" << endl;
		cin >> x;
		Q.EnQueue(x);
	}
	cout << "����˳��ʱ��" << endl;
	Q.queue1212();                                 //�����ŶӺ���
	system("pause");
	//cout << Q << endl;
}