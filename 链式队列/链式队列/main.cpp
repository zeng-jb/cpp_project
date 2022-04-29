#include<iostream>
#include"LinkedQueue.h"
using namespace std;

void main() {
	LinkedQueue<int>Q;                                   //定义整形链队Q
	int x, n;
	cout << "请输入链式队列的长度：" << endl;
	cin >> n;
	cout << "请输入队列元素值（空隔分开）" << endl;
	for (int i = 0; i < n; i++) {                                    //入队列操作
		//cout << "请输入第" << i + 1 << "个元素" << endl;
		cin >> x;
		Q.EnQueue(x);
	}
	cout << "出列顺序时：" << endl;
	Q.queue1212();                                 //调用排队函数
	system("pause");
	//cout << Q << endl;
}