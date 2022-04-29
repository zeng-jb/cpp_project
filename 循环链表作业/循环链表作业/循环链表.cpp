#include <iostream>
#include"class.h"

using namespace std;

void main()
{
/*
    //1、已知一个单链表中的数据元素含有三类字符（即字母字符，数字字符和其它字符），
	//试编写算法，构造三个循环链表，使每个循环链表中只含有同一类的字符，且利用原表中的结点空间作为这三个表的结点空间。
	List<char> list;
	Node<char>* a1, * b1, * c1;
	int a, b, c;

	list.Createlist();
	list.Sort(a, b, c);
	list.Circlink(a1, b1, c1, a, b, c);

	cout << "英文字母元素：" << endl;
	list.Output(a1);
	cout << "数字字符元素：" << endl;
	list.Output(b1);
	cout << "其他字符元素：" << endl;
	list.Output(c1);
	*/

 //2、试编写一个算法，找出一个循环链表中的最小值并删除。
	List<int> list;
	list.Createlist();
	list.SearchDelete();
	cout << "删除后元素序列：" << endl;
	list.Print();



	system("pause");
}