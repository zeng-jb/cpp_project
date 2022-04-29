#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
const int stackIncereament = 20;
template <class T>
class DoubleStack {
public:
	DoubleStack();                 //建立一个空栈 构造函数
	DoubleStack(const DoubleStack<T>& x);      //复制构造函数
	~DoubleStack() { delete[]elements; }      //析构函数
	void Push(const T& x,bool d=1);                  //进栈 d=1表示在一号栈
	bool Pop(T& x,bool d=1);                         //退栈 d=0表示在0号栈
	bool getTop(T& x,bool d=1)const;                      //得到栈顶值
	bool IsEmpty()const;          //判断栈空
	bool IsFull()const;        //判断栈满
	int getSize()const;      //计算栈元素个数
	friend ostream& operator<< <T>(ostream& cout, DoubleStack<T>& s);//输出栈中元素的重载操作<<



private:
	T* elements;            //存放栈中元素的栈数组
	int top[2];                //两个栈顶指针
	int maxSize;            //最大数
	void overflowProcess(); //溢出处理
};



template<class T>
DoubleStack<T>::DoubleStack(){
	
	top[0] = -1;
	top[1] = maxSize;

	elements = new T[maxSize];             //创栈
	assert(elements != NULL);                 //断言；
};

template<class T>
DoubleStack<T>::DoubleStack(const DoubleStack<T>& x) {        //复制构造函数
	elements = new T[maxSize];
	assert(elements != NULL);

	top[0] = x.top[0];
	top[1] = x.top[1];
	for (int i = 0; i <= top[0]; i++)
		elements[i] = x.elements[i];
	for (int j = maxSize - 1; j >= top[1]; j--)
		elements[j] = x.elements[j];
};

template<class T>
void DoubleStack<T>::overflowProcess() {            //溢出处理
	//私有函数，扩充栈的存储空间
	T* newArray = new T[maxSize + stackIncereament];
	if (newArray == NULL) { cerr << "存储分配失败" << endl; exit(1); }
	for (int i = 0; i < top[1]; i++) newArray[i] = elements[i];
	maxSize = maxSize + stackIncereament;
	delete[]elements;
	elements = newArray;
};

template<class T>
void DoubleStack<T>::Push(const T& x,bool d) {
	//进栈
	if (IsFull() == true) overflowProcess();         //栈满溢出处理
	if (d) {
		elements[++(top[0])] = x;
	}
	else {
		elements[--(top[1])] = x;
	}                          
};

template<class T>
bool DoubleStack<T>::Pop(T& x,bool d) {
	//出栈
	if (IsEmpty() == true) return false;               //栈空返回
	if (d) {
		x = elements[--(top[1])]; 
	}
	else {
		x = elements[++(top[0])];
	}
	                             
	return true;                                    //退栈成功
};

template<class T>
bool DoubleStack<T>::getTop(T& x,bool d)const {
	//返回栈顶地址
	if (IsEmpty() == true) return false;           //判断栈空
	if (d) {
		x = elements[(top[1])];
	}
	else {
		x = elements[(top[0])];
	}
                            //返回栈顶元素
	return true;
};

template<class T>
bool DoubleStack<T>::IsEmpty()const {
	if (top[0] == -1 && top[1] == maxSize)
		return true;
	else
		return false;
}

template<class T>
bool DoubleStack<T>::IsFull()const {
	if (top[0] + 1 == top[1] || top[0] == top[1] - 1)
		return true;
	else
		return false;
}

template<class T>
int DoubleStack<T>::getSize()const {
	return top[1] + 1;
}

template<class T>
ostream& operator<<(ostream& os, DoubleStack<T>& s) {
	//输出栈中元素重载操作
	os << "top1 = " << s.top[1] << endl;             //输出栈顶位置
	for (int i = 0; i <= s.top[1]; i++) {
		os << i << ":" << s.elements[i] << endl;  //逐个输出栈中元素值
	}
	return os;
	os << "top0 = " << s.top[0] << endl;             //输出栈顶位置
	for (int i = 0; i <= s.top[0]; i++) {
		os << i << ":" << s.elements[i] << endl;  //逐个输出栈中元素值
	}
	return os;
};
