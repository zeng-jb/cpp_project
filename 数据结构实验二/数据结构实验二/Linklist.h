#pragma once
#include <iostream>
using namespace std;

template<class T>
struct Node
{
	T data;                         //������
	Node* link;                     //��ָ����
};

template<class T>
class Linklist
{
public:
	Linklist();                    //���캯��
	~Linklist();                   //��������
	void Creat();                   //��ʼ������
	void inputFront(T endTag);     //ͷ�巨��������
	void inputRear(T endTag);      //β�巨
	bool Insert(int i, T& x);      //���뺯��
	bool Remove(int i);            //ɾ������
	void Search(T& x);             //���Һ���
	void Inverse();          //���ú���
	void Resolve();           //�ֽ⺯��
	void output();             //�������
	int Length();               //�����
private: 
	Node<T>* first;                //ͷָ��
};

template<class T>
Linklist<T>::Linklist()           
{
	first = new Node<T>;
	first->data = 0;     //����ͷ���
	first->link = NULL;
}

template<class T>
Linklist<T>::~Linklist()
{
	delete first;
}

template<class T>
void Linklist<T>::Creat()          //��ʼ���������ù��캯����ʼ��
{
	//~Linklist();
	Linklist();
	cout << "��ʼ������ɹ���" << endl;
}



template<class T>
void Linklist<T>::inputFront(T endTag)
{
	Node<T>* newNode;
	T val;
	//first = new Node<T>;
	if (first == NULL) { cerr << "�ڴ�������" << endl; exit(1); }
	cin >> val;
	while (val != endTag) {
		newNode = new Node<T>;
		newNode->data = val;
		if (newNode == NULL) { cerr << "�ڴ�������" << endl; exit(1); }
		newNode->link = first->link;
		first->link = newNode;
		cin >> val;
	}
}

template<class T>
void Linklist<T>::inputRear(T endTag)
{
	Node<T>* newNode, * last;
	T val;
	//first = new Node<T>;
	if (first == NULL) { cerr << "�ڴ�������" << endl; exit(1); }
	cin >> val;
	last = first;
	while (val != endTag) {
		newNode = new Node<T>;
		newNode->data = val;
		if (newNode == NULL) { cerr << "�ڴ�������" << endl; exit(1); }
		last->link = newNode;
		last = newNode;
		cin >> val;
	}
	last->link = NULL;
}

template<class T>
bool Linklist<T>::Insert(int i, T& x)
{
	if (i < 0)return NULL;
	Node<T> * current = first;
	int k = 0;
	while (current != NULL && k < i-1) {
		current = current->link; k++;
	}
	if (current == NULL || current->link == NULL)return false;
	Node<T>* newNode=new Node<T>;
	if (newNode == NULL) { cout << "�ڴ�������" << endl; exit(1); }
	newNode->data = x;
	newNode->link = current->link;
	current->link = newNode;
	return true;
}

template<class T>
bool Linklist<T>::Remove(int i) 
{
	Node<T>* current = first->link;
	int k = 1;
	while (current->link != NULL && k < i - 1) {
		current = current->link;
		k++;
	}
	if (current->link == NULL)return false;
	Node<T>* del = current->link;
	current->link = del->link;
	delete del;
	return true;
}

template<class T>
void Linklist<T>::Search(T& x)
{
	int i = 1;
	Node<T>* current = first->link;
	while (current!=NULL)
	{
		
		if (current->data == x) {
			
			cout << "���ҳɹ����ڵ�" << i << "λ" << endl;
			
		}
		current = current->link;
		i++;
	}
}

template<class T>
void Linklist<T>::output()
{
	Node<T>* current = first->link;
	cout << "����Ԫ�����У�" << endl;
	while (current!=NULL)
	{
		cout << current->data << " ";
		current = current->link;
	}
	cout << endl;
}

template<class T>
int Linklist<T>::Length()
{
	int i = 0;
	Node<T>* current = first->link;
	while (current!=NULL)
	{
		i++;
		current = current->link;
	}
	return i;
}

template<class T>
void Linklist<T>::Inverse()
{
	Node<T>* first1, * first2;
	first1 = (Node<T>*)malloc(sizeof(Node<T>));
	first2 = (Node<T>*)malloc(sizeof(Node<T>));
	first1->link = NULL;
	first2->link = NULL;

	Node<T>* p, * q, * t;
	t = first->link; p = first1; q = first2;

	//if (first == NULL || first->link == NULL) { cerr << "������" << endl; }
	while (t != NULL)
	{
		if (t->data % 2!=0) {            //jishu
			p->link = t;
			p = t;
		}
		else {
			q->link = t;
			q = t;
		}
		t = t->link;
	}

	p->link = NULL;
	q->link = NULL;
	p = first1->link; q = first2->link;
	cout << "��������" << endl;
	while (p!=NULL)
	{
		cout << p->data << " ";
		p = p->link;
	}

	cout << endl<<"ż������" << endl;
	while (q!= NULL)
	{
		cout << q->data << " ";
		q = q->link;
	}
	cout << endl;
}



template<class T>
void Linklist<T>::Resolve()             //���ú���
{
	Node<T>* p, * q, * t;
	int tdata;
	p = first->link;                                                           //����ͷ�ڵ�
	if (p == NULL) { cerr << "�ձ�" << endl; exit(1); }                      //�ձ��ж�
	q = p->link;
	if (q == NULL) { cerr << "ֻ��һ��Ԫ�أ�" << endl; return; }               //ֻ��һ��Ԫ�ص�ʱ��
	t = q->link;
	if (t==NULL) {                                                            //ֻ������Ԫ�ص�ʱ�򣬻��ཻ����
		tdata = p->data;
		p->data = q->data;
		q->data = tdata;
		return;
	}
	p->link = NULL;                                                          //���ڿ�
	while (t != NULL) {
		q->link = p;
		first->link = q;

		p = q;
		q = t;
		t = t->link;
	}
	first->link = q;
	q->link = p;
}