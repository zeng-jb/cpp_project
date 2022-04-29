#pragma once
#include <iostream>
#include <ctype.h>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node* link;
};

template <class T>
class List
{
public:
	List() ;    //构造函数
	~List() {};   //析构函数
	void Createlist();   //尾插法构造链表
	void Sort(int& a, int& b, int& c); //排序函数a数b字母c字符
	void Output(Node<T> *t);  //输出函数
	void Circlink(Node<T>*& a1, Node<T>*& b1, Node<T>*& c1, int a, int b, int c);   //循环链表操作
	void SearchDelete();                      //查找删除函数
	void Print();                               //输出函数
private:
	Node<T>* first;     //表头指针
};


//#include <iostream>

//#include "class.h"
//using namespace std;

template <class T>
List<T>::List() {
	first = new Node<T>;
	first->link = NULL;
}
/*
template<class T>
List<T>::List() {

}
*/
template<class T>
void List<T>::Createlist()
{
	int n;
	cout << "请输入链表的长度；" << endl;
	cin >> n;
	cout << "请输入链表的数据元素（数字字母元素）；" << endl;
	char* c = new char[n];              //将输入的数据存储在char数组中再放入链表
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	Node<T>* newNode = new Node<T>, * p;
	newNode = first;
	if (newNode == NULL) { cerr << "内存分配错误；" << endl; exit(1); }
	for (int i = 0; i < n; i++) {
		p = new Node<T>;
		p->data = c[i];
		p->link = NULL;
		newNode->link = p;
		newNode = p;
	}
}

template <class T>
void List<T>::Output(Node<T>* t)
{
	if (t != 0) {
		Node<T>* p = t;
		do {
			cout << p->data << " ";
			p=p->link;
		} while (p != t);
		cout << endl;
	}
	else {
		cout << "链表没有元素；" << endl;
	}
}

template<class T>
void List<T>::Sort(int& a, int& b, int& c)
{
	a = b = c = 0;          //a代表数字，b代表英文字母，c代表其他字符
	Node<T>* head1 = first, * head2 = first, * head3 = first;      //创建三个指向头指针的指针
	Node<T>* current;

	while (head1->link != 0) {
		current = head1;
		head1 = head1->link;
		c++;                             //少一次循环
		if (isdigit(head1->data)) {       //isdigit函数是ctype.h的头文件里的一个判断字符是否为数字的函数
			current->link = head1->link;
			head1->link = first->link;
			first->link = head1;
			head1 = current;
			a++;
			if (current == first) head1 = first->link;     //如果第一个字符符合条件
		}
	}
	while (head2->link != 0) {
		current = head2;
		head2 = head2->link;
		if (isalpha(head2->data)) {      //isalpha函数是ctype.h头文件里的一个判断字符是否为英文字母的函数
			current->link = head2->link;
			head2->link = first->link;
			first->link = head2;
			head2 = current;
			b++;
			if (current == first) head2 = first->link;
		}
	}
	c = c - a - b;
}

template<class T>
void List<T>::Circlink(Node<T>*& a1, Node<T>*& b1, Node<T>*& c1, int a, int b, int c) {
	char t;
	a1 = b1 = c1 = 0;
	int i;
	Node<T>* current = first->link;
	if (a) {                 //数字
		a1 = current;
		for (i = 1; i < a; i++) {
			t = current->data;
			current = current->link;
		}
		b1 = current->link;
		current->link = a1;
		a1 = current;
	}
	if (b) {                 //英文字母
		if (a == 0)   b1 = first->link;
		current = b1;
		for (i = 1; i < b; i++) {
			t = current->data;
			current = current->link;
		}
		c1 = current->link;
		current->link = b1;
		b1 = current;
	}
	if (c) {             //其他字符
		if (b == 0 && a == 0)  c1 = first->link;
		if (a == 0 && b != 0) { c1 = b1; b1 = 0; }
		current = c1;
		for (i = 1; i < c; i++) {
			t = current->data;
			current = current->link;
		}
		current->link = c1;
		c1 = current;
	}
}

template<class T>
void List<T>::SearchDelete() {
	int min;
	Node<T> *p,*del,*delpre;

	p = first->link;
	min = first->link->data;
	while (p!=NULL)
	{
		if (min > p->data) {
			min = p->data;
		}
		p = p->link;
	}
	cout << "元素最小值为：" << (int)(min-'0') << endl;

	delpre = first;
	del = delpre->link;
//	p = del;
	while (delpre->link!=NULL)
	{
/*		if (del->data == min) {
			delpre->link = del->link;
			delete del;
//			Node<T>* del = new Node<T>;
			del = delpre->link;
			break;

		}
		else {
			del = p->link;
			delpre = delpre->link;
			
		}
		p = p->link;
*/
		if (delpre->link->data == min) {
			del = delpre->link;
			delpre->link = del->link;
			delete del;
		}
		else {
			delpre = delpre->link;
		}
	}


}

template<class T>
void List<T>::Print()
{
	Node<T>* current = first->link;
	while (current != NULL) {
		cout <<(int)( current->data-'0' )<< " ";
		current=current->link;
	}
	cout << endl;
}