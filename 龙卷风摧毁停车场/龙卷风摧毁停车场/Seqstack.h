#pragma once
#ifndef SeqStack_h
#define SeqStack_h


#include<iostream>
//#include"stack.h"
#include<assert.h>       //断言机制
using namespace std;

const int stackIncereament = 20;


////类的前置声明
//template <typename T>
//class SeqStack;
//
////友元函数的声明
//template <typename T>
//ostream& operator<<(ostream& out, Seqstack<T>& s);

template <class T>
class Seqstack /*:public Stack<T>*/ {
public:
	Seqstack(int sz = 50);                 //建立一个空栈
	~Seqstack() { delete[]elements; }      //析构函数
	void Push(const T& x);                  //进栈
	bool Pop(T& x);                         //退栈
	bool getTop(T& x)const;                      //得到栈顶值
	bool IsEmpty()const;          //判断栈空
	bool IsFull()const;        //判断栈满
	int getSize()const;      //计算栈元素个数
	friend ostream& operator<< <T>(ostream& cout, Seqstack<T>& s);//输出栈中元素的重载操作<<

	bool Symmetry(string str);               //判断字符串对称函数
	void invore(int n);                       //十进制装换二进制函数

private:
	T* elements;            //存放栈中元素的栈数组
	int top;                //栈顶指针
	int maxSize;            //最大数
	void overflowProcess(); //溢出处理
};

template<class T>
Seqstack<T>::Seqstack(int sz) :top(-1), maxSize(sz) {
	//建sz最大栈，不成功则报错
	elements = new T[maxSize];             //创栈
	assert(elements != NULL);                 //断言；
};

template<class T>
void Seqstack<T>::overflowProcess() {            //溢出处理
	//私有函数，扩充栈的存储空间
	T* newArray = new T[maxSize + stackIncereament];
	if (newArray == NULL) { cerr << "存储分配失败" << endl; exit(1); }
	for (int i = 0; i < top; i++) newArray[i] = elements[i];
	maxSize = maxSize + stackIncereament;
	delete[]elements;
	elements = newArray;
};

template<class T>
void Seqstack<T>::Push(const T& x) {
	//进栈
	if (IsFull() == true) overflowProcess();         //栈满溢出处理
	elements[++top] = x;                                //栈顶指针加1再进栈
};

template<class T>
bool Seqstack<T>::Pop(T& x) {
	//出栈
	if (IsEmpty() == true) return false;               //栈空返回
	x = elements[top--];                              //栈顶指针减一
	return true;                                    //退栈成功
};

template<class T>
bool Seqstack<T>::getTop(T& x)const {
	//返回栈顶地址
	if (IsEmpty() == true) return false;           //判断栈空
	x = elements[top];                            //返回栈顶元素
	return true;
};

template<class T>
bool Seqstack<T>::IsEmpty()const { 
	return(top == -1) ? true : false; 
}

template<class T>
bool Seqstack<T>::IsFull()const { 
	return(top == maxSize - 1) ? true : false; 
}

template<class T>
int Seqstack<T>::getSize()const {
	return top + 1; 
}

template<class T>
ostream& operator<<(ostream& os, Seqstack<T>& s) {
	//输出栈中元素重载操作
	//os << "top = " << s.top << endl;             //输出栈顶位置
	//for (int i = 0; i <= s.top; i++) {
	//	os << i << ":" << s.elements[i] << endl;  //逐个输出栈中元素值
	//}
	//return os;

	//os << "top = " << s.top << endl;             //输出栈顶位置
	for (int i = 0; i <= s.top; i++) {
		os <<"停车场中第"<<i+1 <<"辆车的车牌为 "<< ":" << s.elements[i] << endl;  //逐个输出栈中元素值
	}
	return os;
};

template<class T>
bool Seqstack<T>::Symmetry(string str)            //用栈判断元素值是否对称
{
	int i ;
	T e;                                          //pop取值

	for (i = 0; str[i] != '\0'; i++) {            //字符串进栈
		Push(str[i]);
	}
	for (i = 0; str[i] != '\0'; i++) {            //出栈，获取e与字符串对比
		 Pop(e);
		if (str[i] != e) return false;
	}
	return true;
}

template<class T>
void Seqstack<T>::invore(int n) {                 //十进制转换二进制函数用栈输出
	T x;
	int i = 0;
	do
	{
		Push(n % 2);
		n = n / 2;
	} while (n / 2 > 0||n%2!=0);
	do
	{
		Pop(x);
		cout <<x<<" ";
	} while (IsEmpty() != true);
}


#endif // !SeqStack_h