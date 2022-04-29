#pragma once
#include <iostream>
using namespace std;

template <class T>
struct DblNode {
	T data;
	DblNode<T>* lLink, * rLink;
	DblNode(DblNode<T>* left = NULL, DblNode<T>* right = NULL) :lLink(left), rLink(right) {};  //构造函数
	DblNode(T value, DblNode<T>* left = NULL, DblNode<T>* right = NULL) :data(value), lLink(left), rLink(right){};  //构造函数
};

template <class T>
class DblLink {
public:
	DblLink(T uniqueVal);                //构造函数：建立附加头结点
	~DblLink() {};                            //析构函数释放内存
	int Length()const;                   //计算双链表的长度
	bool IsEmpty() { return first->rLink == first; }      //判断双链表是否空
	DblNode<T>* getHead() { return first; }               //取附加头结点地址
	void setHead(DblLink<T>* ptr) { first = ptr; }        //设置附加头结点地址
	DblNode<T>* Search(const T& x);                //在链表中沿后继方向查找等于x的值
	DblNode<T>* Locate(int i, int d);              //在链表中定位序号为i的节点，d=0按前驱方向，d/=0按后继方向
	bool Insert(int i, const T& x, int d);           //在第i个节点后插入含有x的新节点，d=0按前驱方向，d/=00按后继方向
	bool Remove(int i, T& x, int d);                  //删除第i个节点，d=0按前驱方向，d/=0按后继方向


private:
	DblNode<T>* first;
};

template<class T>
DblLink<T>::DblLink(T uniqueVal) {
	//构造函数：建立双向链表的附加头结点，包含特定情况的值
	first = new DblNode<T>(uniqueVal);
	if (first == NULL) { cerr << "存储分配错误！" << endl; exit(1);}
	first->lLink = first->rLink = first;
}

template<class T>
int DblLink<T>::Length()const {
	//计算带附加头结点的双向链表的长度，通过函数返回
	DblNode<T>* current = first->rLink; int count = 0;
	while (current != first) { current = current->rLink; count++; }
	return count;
}

template<class T>
DblNode<T>* DblLink<T>::Search(const T& x) {          //查找x的节点
	DblNode<T>* current = first->rLink;
	while (current != first && current->rLink != x) {
		current = current->rLink;
	}
	if (current != first) return current;     //搜索成功
	else return NULL;                         //搜索失败
}

template<class T>
DblNode<T>* DblLink<T>::Locate(int i, int d) {
	//在第i个节点后插入含有x的新节点，d=0按前驱方向，d/=00按后继方向

	if (first->rLink == first || i = 0)return first;   //
	DblNode<T>* current;
	if (d != 0)current = first->rLink;               //搜索方向
	else current = first->lLink;

	for (int j = 1; j < i; j++) {
		if (current == first)break;                //链太短退出搜索
		else if (d == 0) {
			current = current->lLink;
		}
		else {
			current = current->rLink;
		}
	}
		if (current != first) return current;         //搜索成功
		else return NULL;                             //搜索失败
	
}

template<class T>
bool DblLink<T>::Insert(int i, const T& x, int d) {
	//建立一个x的新节点，并将其按d方向插入到第i个节点之后
	DblNode<T>* current = Locate(i, d);                //查找第i个节点
	if (current == NULL)return false;                  //i不合理，插入失败
	DblNode<T>* newNode = new DblNode<T>(x);
	if (newNode == NULL) { cerr << "存储分配失败！" << endl; exit(1); }

	if (d == 0) {                                     //前驱方向插入
		newNode->lLink = current->lLink;
		current->lLink = newNode;
		newNode->lLink->rLink = newNode;
		newNode->rLink = current;
	}
	else {
		newNode->rLink = current->rLink;
		current->rLink = newNode;
		newNode->rLink->lLink = newNode;
		newNode->lLink = current;
	}
	return true; //插入成功

}

template<class T>
bool DblLink<T>::Remove(int i, T& x, int d) {
	//带附加头结点的双向链表按照d方向删除i个节点
	DblNode<T>* current = Locate(i, d);               //查找第i个节点
	if (current == NULL) return false;                  //i不合理，删除失败
	current->rLink->lLink = current->lLink;
	current->lLink->rLink = current->rLink;
	x = current->data;
	delete current;
	return true;
}