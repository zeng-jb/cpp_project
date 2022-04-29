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
	List() ;    //���캯��
	~List() {};   //��������
	void Createlist();   //β�巨��������
	void Sort(int& a, int& b, int& c); //������a��b��ĸc�ַ�
	void Output(Node<T> *t);  //�������
	void Circlink(Node<T>*& a1, Node<T>*& b1, Node<T>*& c1, int a, int b, int c);   //ѭ���������
	void SearchDelete();                      //����ɾ������
	void Print();                               //�������
private:
	Node<T>* first;     //��ͷָ��
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
	cout << "����������ĳ��ȣ�" << endl;
	cin >> n;
	cout << "���������������Ԫ�أ�������ĸԪ�أ���" << endl;
	char* c = new char[n];              //����������ݴ洢��char�������ٷ�������
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	Node<T>* newNode = new Node<T>, * p;
	newNode = first;
	if (newNode == NULL) { cerr << "�ڴ�������" << endl; exit(1); }
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
		cout << "����û��Ԫ�أ�" << endl;
	}
}

template<class T>
void List<T>::Sort(int& a, int& b, int& c)
{
	a = b = c = 0;          //a�������֣�b����Ӣ����ĸ��c���������ַ�
	Node<T>* head1 = first, * head2 = first, * head3 = first;      //��������ָ��ͷָ���ָ��
	Node<T>* current;

	while (head1->link != 0) {
		current = head1;
		head1 = head1->link;
		c++;                             //��һ��ѭ��
		if (isdigit(head1->data)) {       //isdigit������ctype.h��ͷ�ļ����һ���ж��ַ��Ƿ�Ϊ���ֵĺ���
			current->link = head1->link;
			head1->link = first->link;
			first->link = head1;
			head1 = current;
			a++;
			if (current == first) head1 = first->link;     //�����һ���ַ���������
		}
	}
	while (head2->link != 0) {
		current = head2;
		head2 = head2->link;
		if (isalpha(head2->data)) {      //isalpha������ctype.hͷ�ļ����һ���ж��ַ��Ƿ�ΪӢ����ĸ�ĺ���
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
	if (a) {                 //����
		a1 = current;
		for (i = 1; i < a; i++) {
			t = current->data;
			current = current->link;
		}
		b1 = current->link;
		current->link = a1;
		a1 = current;
	}
	if (b) {                 //Ӣ����ĸ
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
	if (c) {             //�����ַ�
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
	cout << "Ԫ����СֵΪ��" << (int)(min-'0') << endl;

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