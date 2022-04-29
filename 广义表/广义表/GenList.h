#pragma once
#include<iostream>
#include<assert.h>
#include<stdlib.h>

template<class T>
struct Items                                               //返回值的类结构定义
{
	int utype;                                             //=0/1/2
	union                                                  //联合
	{
		int ref;                                           //utype=0；附加头结点，存放引用计数
		T value;                                           //utype=1；存放数值；
		GenListNode<T>* hlink;                             //utype=2；存放指向子表的指针
	}info;
	Items():utype(0),info.ref(0){}                           //构造函数
	Items(Items<T>& RL) { utype = RL.utype; info = RL.info; }   //复制构造函数
};

template<class T>
struct GenListNode                                            //广义表结点类定义
{
public:
	GenListNode() :utype(0),tlink(NULL) ,info.ref(0);         //构造函数
	GenListNode(GenListNode<T>& RL) {                              //复制构造函数
		utype = RL.utype; tlink = RL.tlink; info = RL.info;
	}
private:
	int utype;                                             //=0/1/2
	GenListNode<T>* tlink;                                  //指向同一层下一个结点的指针
	union                                                  //联合
	{
		int ref;                                           //utype=0；附加头结点，存放引用计数
		T value;                                           //utype=1；存放数值；
		GenListNode<T>* hlink;                             //utype=2；存放指向子表的指针
	}info;
};

template<class T>
class GenList {                                              //广义表的类定义
public:
	GenList();                                              //构造函数
	~GenList();                                             //析构函数
	bool Head(Items& x);                                    //返回表头元素x
	bool Tail(GenList<T>& lt);                              //返回表尾it
	GenListNode<T>* First();                                //返回第一个元素
	GenListNode<T>* Next(GenListNode<T>* elem);             //返回表元素elem的直接后继元素
	void Copy(const GenList<T>& R);                         //广义表的复制
	int Length();                                           //计算广义表的长度
	int depth();                                            //计算一个非递归表的深度
	friend isstream& operator >>(istream& in, GenList<T>& L);//友元操作符>>
private:
	GenListNode<T>* first;                                   //广义表的头指针
	GenListNode<T>* Copy(GenListNode<T>* ls);                //复制一个ls指示的无共享非递归表
	int Length(GenListNode<T>* ls);                          //求ls指示的广义表长度
	int depth(GenListNode<T>* ls);                           //计算由ls指示的非递归表深度
	bool equal(GenListNode<T>* s, GenListNode<T>* t);        //判断s和t两个为表头的表是否相等
	void Remove(GenListNode<T>* ls);                         //释放以ls为附加头结点的广义表
	void Createlist(istream& in, GenListNode<T>*& ls);       //从输入流对象中输入广义表的字符串描述，建立一个带附加头结点的广义表结构
};

template<class T>
GenList<T>::GenList() {
	first = new GenListNode;                                 //构造函数，建立附加头结点
	assert(first != NULL);
}

template<class T>
bool GenList<T>::Head(Items<T>& x) {                         //返回第一个元素值x
	if (first->tlink == NULL) return false;
	else {
		x.utype = first->tlink->utype;
		x.info = first->tlink->info;
		return true;
	}
}

template<class T>
bool GenList<T>::Tail(GenList<T>& lt) {                       //通过lt返回广义表除表头元素以外其他元素组成的表
	if (first->tlink == NULL) return false;
	else {
		lt.first->utype = 0;
		lt.first->info.ref = 0;
		lt.first->tlink = Copy(first->tlink->tlink);
		return true;
	}
}

template<class T>
GenListNode<T>* GenList<T>::First() {                        //返回广义表第一个元素
	if (first->tlink == NULL) return NULL;
	else return first->tlink;
}

template<class T>
GenListNode<T>* GenList<T>::Next(GenListNode<T>* elem) {        //返回表元素elem的直接后继元素
	if (elem->tlink == NULL)return NULL;
	else return elem->tlink;
}

template<class T> 
void GenList<T>::Copy(const GenList<T>& R) {                 //广义表复制算法
	first = Copy(R.first);                                   //公有函数，调用私有函数
}
template<class T>
GenListNode<T>* GenList<T>::Copy(GenListNode<T>* ls) {      //私有函数，复制一个ls指示的无共享的非递归表
	GenListNode<T>* q = NULL;
	if (ls != NULL) {
		q = new GenListNode<T>;                             //处理当前的结点q
		q->utype = ls->utype;                               //复制结点类型
		switch (ls->utype)                                  //根据utype传送信息
		{
		case 0:q->info.ref = ls->info.ref; break;           //附加头结点
		case 1:q->info.value = ls->info.value; break;       //原子结点
		case 2:q->info.hlink = Copy(ls->info.hlink); break; //表结点
		default:
			break;
		}
		q->tlink = Copy(ls->tlink);                         //处理同一层下一个结点为头的表
	}
	return q;
}

template<class T>
int GenList<T>::Length() {                                  //公有函数，求当前广义表长度
	return Length(first);
}
template<class T>
int GenList<T>::Length(GenListNode<T>* ls) {                //私有函数，求以ls为头指针的广义表长度
	if (ls != NULL)return 1 + Length(ls->tlink);
	else return 0;
}

template<class T>
int GenList<T>::depth() {                                 //公有函数，计算一个非递归广义表的深度
	return depth(first);
}
template <class T>
int GenList<T>::depth(GenListNode<T>*ls) {                //私有函数，计算非递归广义表深度
	if (ls->tlink == NULL)return 1;                       //空表，深度为1；
	GenListNode<T>* temp = ls->tlink;
	int m = 0, n;
	while (temp!=NULL)                                    //temp在广义表顶层横扫
	{
		if (temp->utype == 2) {                           //扫描到结点utype为表结点时
			n = depth(temp->info.hlink);                  //计算以该结点为头的广义表深度
			if (m < n)m = n;                              //取最大深度
		}
		temp = temp->tlink;
	}
	return m + 1;                                        //返回深度
}

template<class T>
bool equal(GenListNode<T>* s, GenListNode<T>* t) {           //私有函数，两表相等，函数返回true，否则返回false
	int x;
	if (s->tlink == NULL && t->tlink == NULL)return true;    //表s与t都是空表
	if (s->tlink != NULL && t->tlink != NULL && s->tlink->utype == t->tlink->utype) {               //两个表非空且结点类型相同
		if (s->tlink->utype == 1) {                                                                  //原子结点，比较对应数据
			x = (s->tlink->info.value == t->tlink->info.value) ? 1 : 0;                             
		}
		else if (s->tlink->utype == 2) {                                                            //子表结点，递归比较其他子表
			x = equal(s->tlink->info.hlink, t->tlink->info.hlink);
		}
		if (x == 1) {                                                                              //相等，递归比较同一层的下一个结点
			return equal(s->tlink, t->tlink);
		}
	}
	return false;                                                                                  //不等，返回false
}

template<class T>
void delvalue(GenListNode<T>* ls, T x) {                                                           //删除结点算法
	if (ls->tlink != NULL) {                                                                       //非空表
		GenListNode<T>* p = ls->tlink;                                                             //找附加头结点后的第一个结点
		while (p!=NULL&&(p->utype==1&&p->info.value==x))
		{
			ls->tlink = p->tlink;                                                                  //若含有x结点，删除，p指向同层的下一个结点
			delete p;
			p = ls->tlink;
		}
		if (p!=NULL) {
			if (p->utype == 2) delvalue(p->info.hlink, x);                                         //在子表中删除
			delvalue(p, x);                                                                        //在以p为表头的链表中递归删除
		}
	}
}

template<class T>
GenList<T>::~GenList() {                     //广义表的析构函数，每个附加头结点都有一个引用计数，
	Remove(first);
}
template<class T>
void GenList<T>::Remove(GenListNode<T>* ls) {                   //私有函数，释放以ls为表头指针的广义表
	ls->info.ref--;                                             //附加头结点的引用次数减一
	if (ls->info.ref <= 0) {                                    //如果减到0
		GenListNode<T>* q;
		while (ls->tlink!=NULL)                                 //横扫到顶层
		{
			q = ls->tlink;                                      //到第一个结点
			if (q->utype == 2) {                                //递归删除子表
				Remove(q->info.hlink);
				if (q->info.hlink->info.ref <= 0) delete q->info.hlink;       //删除子表附加头结点
			}
			ls->tlink = q->tlink;
			delete q;
		}
	}
}

#include<string.h>
template<class T>
void GenList<T>::Createlist(istream& in, GenListNode<T>*& ls) {

}