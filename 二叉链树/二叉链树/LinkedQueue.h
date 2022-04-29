#pragma once
#include<iostream>
#include<assert.h>
//#include"Queue.h"
using namespace std;

template<class T>
struct LinkNode                                //指针
{
	T data;                                    //数据域
	LinkNode<T>* link;                          //指针域
	LinkNode(LinkNode<T>* ptr = NULL) { link = ptr; }                           //含指针的构造函数
	LinkNode(const T&item, LinkNode<T>* ptr = NULL) { data=item,link = ptr; }   //指针域与数据与的构造函数
};

template<class T>
class LinkedQueue//:public Queue<T>
{
public:
	LinkedQueue() :front(NULL), rear(NULL) {}        //构造函数
	~LinkedQueue() { makeEmpty(); }                   //析构函数
	bool EnQueue(const T& x);                        //新元素x进入队列
	bool DeQueue(T& x);                             //队头元素出队列
	bool getFront(T& x);                            //读取队头元素的值
	bool IsEmpty()const { return(front == NULL) ? true : false; }                             //判断队列空否
	//bool IsFull()const;                            //判断队列满否
	int getSize()const;                                //链队长度
	void makeEmpty();                                  //使队空
	friend ostream& operator<< <T>(ostream& os, LinkedQueue<T>& Q);            //重载<<操作函数
	void queue1212();                                                        //定义排队函数
private:
	LinkNode<T>* front, * rear;                  //队头、队尾指针
};

template<class T>
void LinkedQueue<T>::makeEmpty() {                      //使链队空
	LinkNode<T>* p;                                   //定义指针指向头结点
	while (front!=NULL)
	{
		p = front;
		front = front->link;                       //头结点后移
		delete p;                                  //删除结点p
	}
}

template<class T>
bool LinkedQueue<T>::EnQueue(const T& x) {         //入队函数
	if (front == NULL) {                           //头结点如果为空
		front = rear = new LinkNode<T>(x);          //创建头尾结点
		if (front == NULL)return false;             //判断头结点为空则退出
	}
	else
	{
		rear->link = new LinkNode<T>(x);           //头结点不为空则创建尾结点指向
		if (rear->link == NULL)return false;        //尾结点空则退出
		rear = rear->link;                          //尾结点下移
	}
	return true;                                   //返回true
}

template<class T>
bool LinkedQueue<T>::DeQueue(T& x) {             //出队函数
	if (IsEmpty() == true)return false;          //队空则返回false
	LinkNode<T>* p = front;                      //创建新节点p指向头结点
	x = front->data;                             //头结点指向元素值赋予x
	front = front->link;                         //头结点下移
	delete p;                                    //删除节点p
	return true;                                 //返回true
}

template<class T>
bool LinkedQueue<T>::getFront(T& x) {            //得队列头指针元素值
	if (IsEmpty() == true)return false;           //空则退出
	x = front->data;                              //头结点指向值赋予x
	return true;                                  //返回
}

template<class T>
int LinkedQueue<T>::getSize()const {              //计算队列长度
	LinkNode<T>* p= front;                        //创建新节点p指向头结点
	int k=0;                                      //初始化长度k为0
	while (p!=NULL)                               //p不为空时
	{
		p = p->link;                              //节点p下移
		k++;                                      //长度加一
	}
	return k;                                     //返回k长度值
}

template<class T>
ostream& operator << (ostream& os, LinkedQueue<T>& Q) {    //重载操作符<<函数
	os << "队列中元素个数有：" << Q.getSize() << endl;     //输出队列长度
	LinkNode<T>* p = Q.front;
	int i = 0;
	while (p!=NULL)
	{
		os << ++i << ":" << p->data << endl;               //输出队列中元素并换行
		p = p->link;
	}
	return os;
}

template<class T>
void LinkedQueue<T>::queue1212() {                      //定义排队函数
	T x, y;                                             //定义取值元素
	while (front->link != NULL)                         //头指针指向不为空时
	{
		DeQueue(x);                                      //出队
		cout << x << " ";                                //输出x元素值，也就是当排队中数到1时出列
		DeQueue(y);                                      //出队y
		EnQueue(y);                                      //入队y，当第一个出队后第二个也出队并且再次入队

	}
	cout << y << endl;                                   //由于循环后队列还有最后一个元素，因此再次输出y元素值
}