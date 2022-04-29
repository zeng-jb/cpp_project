#pragma once
#ifndef SeqStack_h
#define SeqStack_h


#include<iostream>
//#include"stack.h"
#include<assert.h>       //���Ի���
using namespace std;

const int stackIncereament = 20;


////���ǰ������
//template <typename T>
//class SeqStack;
//
////��Ԫ����������
//template <typename T>
//ostream& operator<<(ostream& out, Seqstack<T>& s);

template <class T>
class Seqstack /*:public Stack<T>*/ {
public:
	Seqstack(int sz = 50);                 //����һ����ջ
	~Seqstack() { delete[]elements; }      //��������
	void Push(const T& x);                  //��ջ
	bool Pop(T& x);                         //��ջ
	bool getTop(T& x)const;                      //�õ�ջ��ֵ
	bool IsEmpty()const;          //�ж�ջ��
	bool IsFull()const;        //�ж�ջ��
	int getSize()const;      //����ջԪ�ظ���
	friend ostream& operator<< <T>(ostream& cout, Seqstack<T>& s);//���ջ��Ԫ�ص����ز���<<

	bool Symmetry(string str);               //�ж��ַ����Գƺ���
	void invore(int n);                       //ʮ����װ�������ƺ���

private:
	T* elements;            //���ջ��Ԫ�ص�ջ����
	int top;                //ջ��ָ��
	int maxSize;            //�����
	void overflowProcess(); //�������
};

template<class T>
Seqstack<T>::Seqstack(int sz) :top(-1), maxSize(sz) {
	//��sz���ջ�����ɹ��򱨴�
	elements = new T[maxSize];             //��ջ
	assert(elements != NULL);                 //���ԣ�
};

template<class T>
void Seqstack<T>::overflowProcess() {            //�������
	//˽�к���������ջ�Ĵ洢�ռ�
	T* newArray = new T[maxSize + stackIncereament];
	if (newArray == NULL) { cerr << "�洢����ʧ��" << endl; exit(1); }
	for (int i = 0; i < top; i++) newArray[i] = elements[i];
	maxSize = maxSize + stackIncereament;
	delete[]elements;
	elements = newArray;
};

template<class T>
void Seqstack<T>::Push(const T& x) {
	//��ջ
	if (IsFull() == true) overflowProcess();         //ջ���������
	elements[++top] = x;                                //ջ��ָ���1�ٽ�ջ
};

template<class T>
bool Seqstack<T>::Pop(T& x) {
	//��ջ
	if (IsEmpty() == true) return false;               //ջ�շ���
	x = elements[top--];                              //ջ��ָ���һ
	return true;                                    //��ջ�ɹ�
};

template<class T>
bool Seqstack<T>::getTop(T& x)const {
	//����ջ����ַ
	if (IsEmpty() == true) return false;           //�ж�ջ��
	x = elements[top];                            //����ջ��Ԫ��
	return true;
};

template<class T>
bool Seqstack<T>::IsEmpty()const { 
	return(top == -1) ? true : false; 
}

template<class T>
bool Seqstack<T>::IsFull()const { 
	return(top == maxSize - 1) ? true : false; 
}

template<class T>
int Seqstack<T>::getSize()const {
	return top + 1; 
}

template<class T>
ostream& operator<<(ostream& os, Seqstack<T>& s) {
	//���ջ��Ԫ�����ز���
	//os << "top = " << s.top << endl;             //���ջ��λ��
	//for (int i = 0; i <= s.top; i++) {
	//	os << i << ":" << s.elements[i] << endl;  //������ջ��Ԫ��ֵ
	//}
	//return os;

	//os << "top = " << s.top << endl;             //���ջ��λ��
	for (int i = 0; i <= s.top; i++) {
		os <<"ͣ�����е�"<<i+1 <<"�����ĳ���Ϊ "<< ":" << s.elements[i] << endl;  //������ջ��Ԫ��ֵ
	}
	return os;
};

template<class T>
bool Seqstack<T>::Symmetry(string str)            //��ջ�ж�Ԫ��ֵ�Ƿ�Գ�
{
	int i ;
	T e;                                          //popȡֵ

	for (i = 0; str[i] != '\0'; i++) {            //�ַ�����ջ
		Push(str[i]);
	}
	for (i = 0; str[i] != '\0'; i++) {            //��ջ����ȡe���ַ����Ա�
		 Pop(e);
		if (str[i] != e) return false;
	}
	return true;
}

template<class T>
void Seqstack<T>::invore(int n) {                 //ʮ����ת�������ƺ�����ջ���
	T x;
	int i = 0;
	do
	{
		Push(n % 2);
		n = n / 2;
	} while (n / 2 > 0||n%2!=0);
	do
	{
		Pop(x);
		cout <<x<<" ";
	} while (IsEmpty() != true);
}


#endif // !SeqStack_h