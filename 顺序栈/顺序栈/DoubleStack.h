#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
const int stackIncereament = 20;
template <class T>
class DoubleStack {
public:
	DoubleStack();                 //����һ����ջ ���캯��
	DoubleStack(const DoubleStack<T>& x);      //���ƹ��캯��
	~DoubleStack() { delete[]elements; }      //��������
	void Push(const T& x,bool d=1);                  //��ջ d=1��ʾ��һ��ջ
	bool Pop(T& x,bool d=1);                         //��ջ d=0��ʾ��0��ջ
	bool getTop(T& x,bool d=1)const;                      //�õ�ջ��ֵ
	bool IsEmpty()const;          //�ж�ջ��
	bool IsFull()const;        //�ж�ջ��
	int getSize()const;      //����ջԪ�ظ���
	friend ostream& operator<< <T>(ostream& cout, DoubleStack<T>& s);//���ջ��Ԫ�ص����ز���<<



private:
	T* elements;            //���ջ��Ԫ�ص�ջ����
	int top[2];                //����ջ��ָ��
	int maxSize;            //�����
	void overflowProcess(); //�������
};



template<class T>
DoubleStack<T>::DoubleStack(){
	
	top[0] = -1;
	top[1] = maxSize;

	elements = new T[maxSize];             //��ջ
	assert(elements != NULL);                 //���ԣ�
};

template<class T>
DoubleStack<T>::DoubleStack(const DoubleStack<T>& x) {        //���ƹ��캯��
	elements = new T[maxSize];
	assert(elements != NULL);

	top[0] = x.top[0];
	top[1] = x.top[1];
	for (int i = 0; i <= top[0]; i++)
		elements[i] = x.elements[i];
	for (int j = maxSize - 1; j >= top[1]; j--)
		elements[j] = x.elements[j];
};

template<class T>
void DoubleStack<T>::overflowProcess() {            //�������
	//˽�к���������ջ�Ĵ洢�ռ�
	T* newArray = new T[maxSize + stackIncereament];
	if (newArray == NULL) { cerr << "�洢����ʧ��" << endl; exit(1); }
	for (int i = 0; i < top[1]; i++) newArray[i] = elements[i];
	maxSize = maxSize + stackIncereament;
	delete[]elements;
	elements = newArray;
};

template<class T>
void DoubleStack<T>::Push(const T& x,bool d) {
	//��ջ
	if (IsFull() == true) overflowProcess();         //ջ���������
	if (d) {
		elements[++(top[0])] = x;
	}
	else {
		elements[--(top[1])] = x;
	}                          
};

template<class T>
bool DoubleStack<T>::Pop(T& x,bool d) {
	//��ջ
	if (IsEmpty() == true) return false;               //ջ�շ���
	if (d) {
		x = elements[--(top[1])]; 
	}
	else {
		x = elements[++(top[0])];
	}
	                             
	return true;                                    //��ջ�ɹ�
};

template<class T>
bool DoubleStack<T>::getTop(T& x,bool d)const {
	//����ջ����ַ
	if (IsEmpty() == true) return false;           //�ж�ջ��
	if (d) {
		x = elements[(top[1])];
	}
	else {
		x = elements[(top[0])];
	}
                            //����ջ��Ԫ��
	return true;
};

template<class T>
bool DoubleStack<T>::IsEmpty()const {
	if (top[0] == -1 && top[1] == maxSize)
		return true;
	else
		return false;
}

template<class T>
bool DoubleStack<T>::IsFull()const {
	if (top[0] + 1 == top[1] || top[0] == top[1] - 1)
		return true;
	else
		return false;
}

template<class T>
int DoubleStack<T>::getSize()const {
	return top[1] + 1;
}

template<class T>
ostream& operator<<(ostream& os, DoubleStack<T>& s) {
	//���ջ��Ԫ�����ز���
	os << "top1 = " << s.top[1] << endl;             //���ջ��λ��
	for (int i = 0; i <= s.top[1]; i++) {
		os << i << ":" << s.elements[i] << endl;  //������ջ��Ԫ��ֵ
	}
	return os;
	os << "top0 = " << s.top[0] << endl;             //���ջ��λ��
	for (int i = 0; i <= s.top[0]; i++) {
		os << i << ":" << s.elements[i] << endl;  //������ջ��Ԫ��ֵ
	}
	return os;
};
