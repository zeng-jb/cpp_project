#pragma once
#include<iostream>
#include<assert.h>
//#include"Queue.h"
using namespace std;

template<class T>
struct LinkNode                                //ָ��
{
	T data;                                    //������
	LinkNode<T>* link;                          //ָ����
	LinkNode(LinkNode<T>* ptr = NULL) { link = ptr; }                           //��ָ��Ĺ��캯��
	LinkNode(const T&item, LinkNode<T>* ptr = NULL) { data=item,link = ptr; }   //ָ������������Ĺ��캯��
};

template<class T>
class LinkedQueue//:public Queue<T>
{
public:
	LinkedQueue() :front(NULL), rear(NULL) {}        //���캯��
	~LinkedQueue() { makeEmpty(); }                   //��������
	bool EnQueue(const T& x);                        //��Ԫ��x�������
	bool DeQueue(T& x);                             //��ͷԪ�س�����
	bool getFront(T& x);                            //��ȡ��ͷԪ�ص�ֵ
	bool IsEmpty()const { return(front == NULL) ? true : false; }                             //�ж϶��пշ�
	//bool IsFull()const;                            //�ж϶�������
	int getSize()const;                                //���ӳ���
	void makeEmpty();                                  //ʹ�ӿ�
	friend ostream& operator<< <T>(ostream& os, LinkedQueue<T>& Q);            //����<<��������
	void queue1212();                                                        //�����ŶӺ���
private:
	LinkNode<T>* front, * rear;                  //��ͷ����βָ��
};

template<class T>
void LinkedQueue<T>::makeEmpty() {                      //ʹ���ӿ�
	LinkNode<T>* p;                                   //����ָ��ָ��ͷ���
	while (front!=NULL)
	{
		p = front;
		front = front->link;                       //ͷ������
		delete p;                                  //ɾ�����p
	}
}

template<class T>
bool LinkedQueue<T>::EnQueue(const T& x) {         //��Ӻ���
	if (front == NULL) {                           //ͷ������Ϊ��
		front = rear = new LinkNode<T>(x);          //����ͷβ���
		if (front == NULL)return false;             //�ж�ͷ���Ϊ�����˳�
	}
	else
	{
		rear->link = new LinkNode<T>(x);           //ͷ��㲻Ϊ���򴴽�β���ָ��
		if (rear->link == NULL)return false;        //β�������˳�
		rear = rear->link;                          //β�������
	}
	return true;                                   //����true
}

template<class T>
bool LinkedQueue<T>::DeQueue(T& x) {             //���Ӻ���
	if (IsEmpty() == true)return false;          //�ӿ��򷵻�false
	LinkNode<T>* p = front;                      //�����½ڵ�pָ��ͷ���
	x = front->data;                             //ͷ���ָ��Ԫ��ֵ����x
	front = front->link;                         //ͷ�������
	delete p;                                    //ɾ���ڵ�p
	return true;                                 //����true
}

template<class T>
bool LinkedQueue<T>::getFront(T& x) {            //�ö���ͷָ��Ԫ��ֵ
	if (IsEmpty() == true)return false;           //�����˳�
	x = front->data;                              //ͷ���ָ��ֵ����x
	return true;                                  //����
}

template<class T>
int LinkedQueue<T>::getSize()const {              //������г���
	LinkNode<T>* p= front;                        //�����½ڵ�pָ��ͷ���
	int k=0;                                      //��ʼ������kΪ0
	while (p!=NULL)                               //p��Ϊ��ʱ
	{
		p = p->link;                              //�ڵ�p����
		k++;                                      //���ȼ�һ
	}
	return k;                                     //����k����ֵ
}

template<class T>
ostream& operator << (ostream& os, LinkedQueue<T>& Q) {    //���ز�����<<����
	os << "������Ԫ�ظ����У�" << Q.getSize() << endl;     //������г���
	LinkNode<T>* p = Q.front;
	int i = 0;
	while (p!=NULL)
	{
		os << ++i << ":" << p->data << endl;               //���������Ԫ�ز�����
		p = p->link;
	}
	return os;
}

template<class T>
void LinkedQueue<T>::queue1212() {                      //�����ŶӺ���
	T x, y;                                             //����ȡֵԪ��
	while (front->link != NULL)                         //ͷָ��ָ��Ϊ��ʱ
	{
		DeQueue(x);                                      //����
		cout << x << " ";                                //���xԪ��ֵ��Ҳ���ǵ��Ŷ�������1ʱ����
		DeQueue(y);                                      //����y
		EnQueue(y);                                      //���y������һ�����Ӻ�ڶ���Ҳ���Ӳ����ٴ����

	}
	cout << y << endl;                                   //����ѭ������л������һ��Ԫ�أ�����ٴ����yԪ��ֵ
}