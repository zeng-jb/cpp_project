#pragma once
#include<assert.h>
//#include"Queue.h"
#include<iostream>
const int maxSize = 50;
using namespace std;

//template<class T>
//struct LinkNode                                //ָ��
//{
//	T data;                                    //������
//	LinkNode<T>* link;                          //ָ����
//};

template<class T>
class SeqQueue/*:public Queue<T>    */               //ѭ�����е��ඨ��
{
public:
	SeqQueue(int sz = 10) ;                          //���캯��
	~SeqQueue() { delete[]element; }              //��������
	bool EnQueue(const T& x);                     //�����в�������x������У���������������
	bool DeQueue(T& x);                           //�����в��գ��˳���ͷԪ��x
	bool getFront(T& x);                          //���ض�ͷԪ��ֵ
	void makeEmpty() { front = rear = 0; }            //�������ÿ�
	bool IsEmpty()const { return(front == rear) ? true : false; }                //�ж϶��пշ�
	bool IsFull()const { return((rear + 1) % maxSize == front) ? true : false; }  //�ж϶�������
	int getSize()const { return(rear - front + maxSize) % maxSize; }              //�õ����г���
	friend ostream& operator<< <T>(ostream& os, SeqQueue<T>& Q);                 //<<���غ�������


private:
	int rear, front;                             //��β����ͷָ��
	T* element;                                 //��Ŷ��е�Ԫ������
	int maxSize;                                  //�������ֵ
};

template<class T>
SeqQueue<T>::SeqQueue(int sz) {
	front = 0;
	rear = 0;
	maxSize = sz;                                  //����sz����ֵ
	element = new T[maxSize];                    //����max�Ŀ�����
	assert(element != NULL);                            //���ԣ���̬�洢����ɹ����
}

template<class T>
bool SeqQueue<T>::EnQueue(const T& x) {             //����Ԫ��x���
	if (IsFull() == true)return false;              //���������˳�
	element[rear] = x;                                  //����βָ�����
	rear = (rear + 1) % maxSize;                     //βָ���һ
	return true;
}

template<class T>
bool SeqQueue<T>::DeQueue(T& x) {                   //�˳���ͷԪ��x
	if (IsEmpty() == true) return false;               //�Կ��˳�
	x = element[front];                                      //x����ͷֵ
	front = (front + 1) % maxSize;                   //ͷָ���һ
	return true;
}

template<class T>
bool SeqQueue<T>::getFront(T& x){                  //�õ���ͷԪ��
	if (IsEmpty() == true)return false;                     //�����˳�����
	x = element[front];                           //��ֵ��x
	return true;
}

template<class T>
ostream& operator<<(ostream& os, SeqQueue<T>& Q) {                   //���ز���<< 
	//os << "front=" << Q.front << ",rear=" << Q.rear << endl;
	//for (int i = Q.front; i != Q.rear; i = (i + 1) % maxSize) {       //���һ���޷����
	//	os << i << ":" << Q.element[i] << endl;
	//}
	//return os;

	//os << "front=" << Q.front << ",rear=" << Q.rear << endl;
	for (int i = Q.front; i != Q.rear; i = (i + 1) % maxSize) {       //���һ���޷����
		os <<"������"<< i <<"�����ĳ���Ϊ "<< ":" << Q.element[i] << endl;           //���غ������������Ϣ
	}
	return os;
}