#pragma once
#ifndef stack_h
#define stack_h
const int maxSize = 50;

template<class T>
class Stack {
public:
	Stack() {};              //���캯��
	~Stack() {};
	virtual void Push(const T& x)=0 ;            //��Ԫ�ؽ�ջ
	virtual bool Pop(T& x)=0 ;                   //ջ��Ԫ�س�ջ��x����
	virtual bool getTop(T& x)const = 0;           //��ȡջ��Ԫ�أ�x����
	virtual bool IsEmpty()const = 0;              //�ж�ջ�շ�
	virtual bool IsFull()const = 0;               //�ж�ջ����
	virtual int getSize()const = 0;               //����ջ��Ԫ�ظ���
};








#endif // !stack_h


