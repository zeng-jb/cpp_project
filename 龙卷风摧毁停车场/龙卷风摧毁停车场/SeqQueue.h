#pragma once
#include<assert.h>
//#include"Queue.h"
#include<iostream>
const int maxSize = 50;
using namespace std;

//template<class T>
//struct LinkNode                                //指针
//{
//	T data;                                    //数据域
//	LinkNode<T>* link;                          //指针域
//};

template<class T>
class SeqQueue/*:public Queue<T>    */               //循环队列的类定义
{
public:
	SeqQueue(int sz = 10) ;                          //构造函数
	~SeqQueue() { delete[]element; }              //析构函数
	bool EnQueue(const T& x);                     //若队列不满，则将x进入队列，否则队列溢出处理
	bool DeQueue(T& x);                           //若队列不空，退出队头元素x
	bool getFront(T& x);                          //返回队头元素值
	void makeEmpty() { front = rear = 0; }            //将队列置空
	bool IsEmpty()const { return(front == rear) ? true : false; }                //判断队列空否
	bool IsFull()const { return((rear + 1) % maxSize == front) ? true : false; }  //判断队列满否
	int getSize()const { return(rear - front + maxSize) % maxSize; }              //得到队列长度
	friend ostream& operator<< <T>(ostream& os, SeqQueue<T>& Q);                 //<<重载函数操作


private:
	int rear, front;                             //队尾、队头指针
	T* element;                                 //存放队列的元素数组
	int maxSize;                                  //数组最大值
};

template<class T>
SeqQueue<T>::SeqQueue(int sz) {
	front = 0;
	rear = 0;
	maxSize = sz;                                  //创建sz最大的值
	element = new T[maxSize];                    //创建max的空数组
	assert(element != NULL);                            //断言；动态存储分配成功与否
}

template<class T>
bool SeqQueue<T>::EnQueue(const T& x) {             //将新元素x入队
	if (IsFull() == true)return false;              //队列满则退出
	element[rear] = x;                                  //按照尾指针入队
	rear = (rear + 1) % maxSize;                     //尾指针加一
	return true;
}

template<class T>
bool SeqQueue<T>::DeQueue(T& x) {                   //退出队头元素x
	if (IsEmpty() == true) return false;               //对空退出
	x = element[front];                                      //x返回头值
	front = (front + 1) % maxSize;                   //头指针加一
	return true;
}

template<class T>
bool SeqQueue<T>::getFront(T& x){                  //得到队头元素
	if (IsEmpty() == true)return false;                     //空则退出返回
	x = element[front];                           //赋值与x
	return true;
}

template<class T>
ostream& operator<<(ostream& os, SeqQueue<T>& Q) {                   //重载操作<< 
	//os << "front=" << Q.front << ",rear=" << Q.rear << endl;
	//for (int i = Q.front; i != Q.rear; i = (i + 1) % maxSize) {       //最后一个无法输出
	//	os << i << ":" << Q.element[i] << endl;
	//}
	//return os;

	//os << "front=" << Q.front << ",rear=" << Q.rear << endl;
	for (int i = Q.front; i != Q.rear; i = (i + 1) % maxSize) {       //最后一个无法输出
		os <<"候车区第"<< i <<"辆车的车牌为 "<< ":" << Q.element[i] << endl;           //重载候车区输出车辆信息
	}
	return os;
}