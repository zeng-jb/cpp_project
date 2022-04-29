#pragma once
#include <iostream>
using namespace std;

template<class T>
struct Node
{
	T data;                         //数据域
	Node* link;                     //链指针域
};

template<class T>
class Linklist
{
public:
	Linklist();                    //构造函数
	~Linklist();                   //析构函数
	void Creat();                   //初始化函数
	void inputFront(T endTag);     //头插法建立链表
	void inputRear(T endTag);      //尾插法
	bool Insert(int i, T& x);      //插入函数
	bool Remove(int i);            //删除函数
	void Search(T& x);             //查找函数
	void Inverse();          //逆置函数
	void Resolve();           //分解函数
	void output();             //输出函数
	int Length();               //计算表长
private: 
	Node<T>* first;                //头指针
};

template<class T>
Linklist<T>::Linklist()           
{
	first = new Node<T>;
	first->data = 0;     //附加头结点
	first->link = NULL;
}

template<class T>
Linklist<T>::~Linklist()
{
	delete first;
}

template<class T>
void Linklist<T>::Creat()          //初始化函数调用构造函数初始化
{
	//~Linklist();
	Linklist();
	cout << "初始化链表成功。" << endl;
}



template<class T>
void Linklist<T>::inputFront(T endTag)
{
	Node<T>* newNode;
	T val;
	//first = new Node<T>;
	if (first == NULL) { cerr << "内存分配错误！" << endl; exit(1); }
	cin >> val;
	while (val != endTag) {
		newNode = new Node<T>;
		newNode->data = val;
		if (newNode == NULL) { cerr << "内存分配错误！" << endl; exit(1); }
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
	if (first == NULL) { cerr << "内存分配错误！" << endl; exit(1); }
	cin >> val;
	last = first;
	while (val != endTag) {
		newNode = new Node<T>;
		newNode->data = val;
		if (newNode == NULL) { cerr << "内存分配错误！" << endl; exit(1); }
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
	if (newNode == NULL) { cout << "内存分配错误！" << endl; exit(1); }
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
			
			cout << "查找成功，在第" << i << "位" << endl;
			
		}
		current = current->link;
		i++;
	}
}

template<class T>
void Linklist<T>::output()
{
	Node<T>* current = first->link;
	cout << "链表元素序列：" << endl;
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

	//if (first == NULL || first->link == NULL) { cerr << "空链表；" << endl; }
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
	cout << "奇数链表：" << endl;
	while (p!=NULL)
	{
		cout << p->data << " ";
		p = p->link;
	}

	cout << endl<<"偶数链表：" << endl;
	while (q!= NULL)
	{
		cout << q->data << " ";
		q = q->link;
	}
	cout << endl;
}



template<class T>
void Linklist<T>::Resolve()             //逆置函数
{
	Node<T>* p, * q, * t;
	int tdata;
	p = first->link;                                                           //附加头节点
	if (p == NULL) { cerr << "空表！" << endl; exit(1); }                      //空表判断
	q = p->link;
	if (q == NULL) { cerr << "只有一个元素！" << endl; return; }               //只有一个元素的时候
	t = q->link;
	if (t==NULL) {                                                            //只有两个元素的时候，互相交换。
		tdata = p->data;
		p->data = q->data;
		q->data = tdata;
		return;
	}
	p->link = NULL;                                                          //等于空
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