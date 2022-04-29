#pragma once
#include<iostream>
#include"MinPQ.h"
using namespace std;
#define DefaultSize 10;
 int maxHeapSize= 6667;
//enum bool{
//	false,true
//};
template<class T,class E>
class MinHeap:public PQueue<T> {
public:
	MinHeap(int sz = maxHeapSize);												//构造函数：建立空堆
	MinHeap(E arr[],int n);														//构造函数：通过一个数组建堆
	~MinHeap() { delete[]heap; }												//析构函数
	bool Insert(const E& x);													//插入
	bool RemoveMin(E& x);														//删除堆顶上的最小元素
	bool IsEmpty()const { return (currentSize == 0) ? true : false; }			//判断堆空
	bool IsFull()const { return (currentSize ==maxHeapSize) ? true : false; }	//判断堆满
	void MakeEmpty() { currentSize = 0; }										//置空堆
private:
	E* heap;																	//存放最小堆中元素的数组
	int currentSize;															//最小堆中当前元素个数
	//int maxHeapSize;															//最小堆最大元素个数
	void siftDown(int start, int m);											//下滑调整最小堆
	void siftUp(int start);														//从start到0上滑调整最小堆
};

template<class T,class E>
MinHeap<T,E>::MinHeap(int sz) {
	int N=DefaultSize;
	maxHeapSize = ((N < sz) ? sz :N);
	heap = new E[maxHeapSize];													//创建堆存储空间
	if (heap == NULL) { cerr << "堆创建失败！" << endl; exit(1); }
	currentSize = 0;															//当前堆大小
}
template<class T,class E>
MinHeap<T, E>::MinHeap(E arr[], int n) {
	int N = DefaultSize;
	maxHeapSize =( (N < n) ? n : N);
	heap = new E[maxHeapSize];
	if (heap == NULL) { cerr << "堆存储分配失败！" << endl; exit(1); }
	for (int i = 0; i < n; i++) {
		heap[i] = arr[i];
	}
	currentSize = n;															//复制堆数组，建立当前大小
	int currentPos = (currentSize - 2) / 2;										//找到最初位置：最后的分支结点
	while (currentPos>=0)														//自底向上扩大成堆
	{
		siftDown(currentPos, currentSize - 1);									//局部自上向下下滑调整
		currentPos--;															//再向前换一个分支结点
	}
}

template<class T,class E>
void MinHeap<T, E>::siftDown(int start, int m) {
	//私有函数：从结点start到m为之，自上向下比较，如果子女的值小于父结点的值，
	//则关键码小的上浮，继续向下层比较，这样将一个集合局部调整为最小堆
	int i = start, j = 2 * i + 1;												//j是i的左子女位置
	E temp = heap[i];
	while (j<=m)																//检查是否到最后位置
	{
		if (j<m && heap[j]>heap[j + 1])j++;										//让j指向两子女中最小者
		if ( heap[j] > temp)break;												//小则不作调整
		else { heap[i] = heap[j]; i = j; j = 2 * j + 1; }						//否则小者上移，i，j下降
	}
	heap[i] = temp;																//回放temp中暂存的元素
}

template<class T,class E>
void MinHeap<T, E>::siftUp(int start) {
	//私有函数：从结点start到0为止，自下向上比较，如果子女的值小于父结点的值
	//则两者相互交换，这样将集合局部调整为最小堆。关键码比较符“<="在E中定义
	int j = start, i = (j - 1) / 2;
	E temp = heap[j];
	while (j>0)																	//沿父结点路径向上直达跟
	{
		if (temp > heap[i])break;												//父结点值小，不调整
		else { heap[j] = heap[i]; j = i; i = (i - 1) / 2; }						//否则调整
	}
	heap[j] = temp;																//回放
}

template<class T,class E>
bool MinHeap<T, E>::Insert(const E& x) {
	if (currentSize == maxHeapSize) { cerr << "Heap Full!" << endl; return false; }//堆满，返回false
	heap[currentSize] = x;														//插入
	siftUp(currentSize);														//向上调整
	currentSize++;																//堆计数＋1
	return true;																
}

template<class T,class E>
bool MinHeap<T, E>::RemoveMin(E& x) {
	if (!currentSize) { cerr << "Heap Empty" << endl; return false; }			//堆空，返回false
	x = heap[0]; heap[0] = heap[currentSize - 1];								//最后元素补充到根结点
	currentSize--;
	siftDown(0, currentSize - 1);												//自上向下下滑调整
	return true;
}