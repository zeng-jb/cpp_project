#pragma once
#include<iostream>
#include<assert.h>
//#include"Stack.h"
using namespace std;
template<class T>
struct LinkNode                            //链表节点定义
{
	T data;                               //数据域
	LinkNode<T>* link;                      //指针域
	LinkNode(LinkNode<T>* ptr = NULL) { link = ptr; }                             //仅初始化指针成员的构造函数
	LinkNode(const T&item, LinkNode<T>* ptr = NULL) {data=item, link = ptr; }     //初始化数据与指针成员的构造函数
};

template<class T>
class LinkedStack//:public Stack<T>             //链式栈的类定义
{
public:
	LinkedStack() :top (NULL){}                         //构造函数
	~LinkedStack() { makeEmpty(); }                           //析构函数
	void Push(const T& x);                    //进栈
	bool Pop(T& x);                             //退栈
	bool getTop(T& x)const;                    //读取栈顶元素
	bool IsEmpty()const { return (top == NULL) ? true : false; }       //判断栈空否
	int getSize()const;                       //求栈的元素的个数
	void makeEmpty();                       //清空栈的内容
	friend ostream& operator<< <T>(ostream& os, LinkedStack<T>& s);       //输出栈中的元素的重载操作

	void PrintMatchedPairs(string str);           //括号匹配算法

private:
	LinkNode<T>* top;
};

template<class T>
void LinkedStack<T>::makeEmpty()
{
	//逐次删除链式栈中元素直至栈顶为空
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
	//将新元素x插入栈顶，即链头
	top = new LinkNode<T>(x, top);             //创建新的含x的节点
	assert(top != NULL);                      //创建新节点失败退出
}

template<class T>
bool LinkedStack<T>::Pop(T& x) {
	//删除栈顶的元素，返回x
	if (IsEmpty() == true)return false;         //栈空则不退
	LinkNode<T>* p = top;                     //存栈顶元素
	top = top->link;                          //栈顶指针下一
	x = p->data;                             //取x
	delete p;                                   //释放p
	return true;
}

template<class T>
bool LinkedStack<T>::getTop(T& x)const {
	//返回栈顶元素
	if (IsEmpty() == true) return false;   //栈空返回false
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
	os << "栈中元素个数=" << s.getSize() << endl;
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

void LinkedStack<T>::PrintMatchedPairs(string str) {                     //（）括号匹配函数 有问题如果是（）（）（）这种情况getSize函数每次都是0
	int i;
	T j;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(')Push(str[i]);
		else if (str[i] == ')') {
			if (Pop(j) == true) {
				cout <<getSize()+1<<" "<< j << "与" << i+1 << " "<<str[i]<<"匹配" << endl;
			}
			else {
				cout << "没有与第" << i+1 << " " << str[i] << "个右括号匹配的左括号；" << endl;
			}
		}
	}
	while (IsEmpty()==false)
	{
		Pop(j);
		cout << "没有与第" <<getSize()+1 << " "<< j << "左括号想匹配的右括号；" << endl;
	}
}

//多个链式栈定义n个
//LinkNode<T>* s = new LinkNode<T>[n];