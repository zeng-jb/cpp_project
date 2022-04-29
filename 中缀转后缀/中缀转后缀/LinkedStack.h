#pragma once
#include<iostream>
#include<assert.h>
//#include"Stack.h"
using namespace std;
template<class T>
struct LinkNode                            //����ڵ㶨��
{
	T data;                               //������
	LinkNode<T>* link;                      //ָ����
	LinkNode(LinkNode<T>* ptr = NULL) { link = ptr; }                             //����ʼ��ָ���Ա�Ĺ��캯��
	LinkNode(const T&item, LinkNode<T>* ptr = NULL) {data=item, link = ptr; }     //��ʼ��������ָ���Ա�Ĺ��캯��
};

template<class T>
class LinkedStack//:public Stack<T>             //��ʽջ���ඨ��
{
public:
	LinkedStack() :top (NULL){}                         //���캯��
	~LinkedStack() { makeEmpty(); }                           //��������
	void Push(const T& x);                    //��ջ
	bool Pop(T& x);                             //��ջ
	bool getTop(T& x)const;                    //��ȡջ��Ԫ��
	bool IsEmpty()const { return (top == NULL) ? true : false; }       //�ж�ջ�շ�
	int getSize()const;                       //��ջ��Ԫ�صĸ���
	void makeEmpty();                       //���ջ������
	friend ostream& operator<< <T>(ostream& os, LinkedStack<T>& s);       //���ջ�е�Ԫ�ص����ز���

	void PrintMatchedPairs(string str);           //����ƥ���㷨

private:
	LinkNode<T>* top;
};

template<class T>
void LinkedStack<T>::makeEmpty()
{
	//���ɾ����ʽջ��Ԫ��ֱ��ջ��Ϊ��
	LinkNode<T>* p;
	while (top != NULL) {
		p = top;
		top = top->link;
		delete p;
	}
}

template<class T>
void LinkedStack<T>::Push(const T&x)
{
	//����Ԫ��x����ջ��������ͷ
	top = new LinkNode<T>(x, top);             //�����µĺ�x�Ľڵ�
	assert(top != NULL);                      //�����½ڵ�ʧ���˳�
}

template<class T>
bool LinkedStack<T>::Pop(T& x) {
	//ɾ��ջ����Ԫ�أ�����x
	if (IsEmpty() == true)return false;         //ջ������
	LinkNode<T>* p = top;                     //��ջ��Ԫ��
	top = top->link;                          //ջ��ָ����һ
	x = p->data;                             //ȡx
	delete p;                                   //�ͷ�p
	return true;
}

template<class T>
bool LinkedStack<T>::getTop(T& x)const {
	//����ջ��Ԫ��
	if (IsEmpty() == true) return false;   //ջ�շ���false
	x = top->data;
	return true;
}

template<class T>
int LinkedStack<T>::getSize()const {
	LinkNode<T>* p = top;
	int k = 0;
	while (p!=NULL)
	{
		p = p->link;
		k++;
	}
	return k;
}

template<class T>
ostream& operator<< (ostream& os, LinkedStack<T>& s) {
	os << "ջ��Ԫ�ظ���=" << s.getSize() << endl;
	LinkNode<T>* p = s.top;
	int i = 0;
	while (p != NULL)
	{
		os << ++i << ":" << p->data << endl;
		p = p->link;
	}
	return os;
};

template<class T>

void LinkedStack<T>::PrintMatchedPairs(string str) {                     //��������ƥ�亯�� ����������ǣ������������������getSize����ÿ�ζ���0
	int i;
	T j;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(')Push(str[i]);
		else if (str[i] == ')') {
			if (Pop(j) == true) {
				cout <<getSize()+1<<" "<< j << "��" << i+1 << " "<<str[i]<<"ƥ��" << endl;
			}
			else {
				cout << "û�����" << i+1 << " " << str[i] << "��������ƥ��������ţ�" << endl;
			}
		}
	}
	while (IsEmpty()==false)
	{
		Pop(j);
		cout << "û�����" <<getSize()+1 << " "<< j << "��������ƥ��������ţ�" << endl;
	}
}

//�����ʽջ����n��
//LinkNode<T>* s = new LinkNode<T>[n];