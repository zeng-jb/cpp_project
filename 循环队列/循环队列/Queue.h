#pragma once

const int maxSize = 50;
//enum bool{false,true};
template<class T>
class Queue {
public:
	Queue() {};                                                  //���캯��
	~Queue() {};                                                   //��������
	virtual bool EnQueue(const T& x) = 0;                        //��Ԫ��x�������
	virtual bool DeQueue(T& x) = 0;                             //��ͷԪ�س�����
	virtual bool getFront(T& x) = 0;                            //��ȡ��ͷԪ�ص�ֵ
	virtual bool IsEmpty()const = 0;                             //�ж϶��пշ�
	virtual bool IsFull()const = 0;                            //�ж϶�������
	virtual int getSize()const = 0;                             //�����Ԫ�ظ���

};