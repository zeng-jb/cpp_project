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
	MinHeap(int sz = maxHeapSize);												//���캯���������ն�
	MinHeap(E arr[],int n);														//���캯����ͨ��һ�����齨��
	~MinHeap() { delete[]heap; }												//��������
	bool Insert(const E& x);													//����
	bool RemoveMin(E& x);														//ɾ���Ѷ��ϵ���СԪ��
	bool IsEmpty()const { return (currentSize == 0) ? true : false; }			//�ж϶ѿ�
	bool IsFull()const { return (currentSize ==maxHeapSize) ? true : false; }	//�ж϶���
	void MakeEmpty() { currentSize = 0; }										//�ÿն�
private:
	E* heap;																	//�����С����Ԫ�ص�����
	int currentSize;															//��С���е�ǰԪ�ظ���
	//int maxHeapSize;															//��С�����Ԫ�ظ���
	void siftDown(int start, int m);											//�»�������С��
	void siftUp(int start);														//��start��0�ϻ�������С��
};

template<class T,class E>
MinHeap<T,E>::MinHeap(int sz) {
	int N=DefaultSize;
	maxHeapSize = ((N < sz) ? sz :N);
	heap = new E[maxHeapSize];													//�����Ѵ洢�ռ�
	if (heap == NULL) { cerr << "�Ѵ���ʧ�ܣ�" << endl; exit(1); }
	currentSize = 0;															//��ǰ�Ѵ�С
}
template<class T,class E>
MinHeap<T, E>::MinHeap(E arr[], int n) {
	int N = DefaultSize;
	maxHeapSize =( (N < n) ? n : N);
	heap = new E[maxHeapSize];
	if (heap == NULL) { cerr << "�Ѵ洢����ʧ�ܣ�" << endl; exit(1); }
	for (int i = 0; i < n; i++) {
		heap[i] = arr[i];
	}
	currentSize = n;															//���ƶ����飬������ǰ��С
	int currentPos = (currentSize - 2) / 2;										//�ҵ����λ�ã����ķ�֧���
	while (currentPos>=0)														//�Ե���������ɶ�
	{
		siftDown(currentPos, currentSize - 1);									//�ֲ����������»�����
		currentPos--;															//����ǰ��һ����֧���
	}
}

template<class T,class E>
void MinHeap<T, E>::siftDown(int start, int m) {
	//˽�к������ӽ��start��mΪ֮���������±Ƚϣ������Ů��ֵС�ڸ�����ֵ��
	//��ؼ���С���ϸ����������²�Ƚϣ�������һ�����Ͼֲ�����Ϊ��С��
	int i = start, j = 2 * i + 1;												//j��i������Ůλ��
	E temp = heap[i];
	while (j<=m)																//����Ƿ����λ��
	{
		if (j<m && heap[j]>heap[j + 1])j++;										//��jָ������Ů����С��
		if ( heap[j] > temp)break;												//С��������
		else { heap[i] = heap[j]; i = j; j = 2 * j + 1; }						//����С�����ƣ�i��j�½�
	}
	heap[i] = temp;																//�ط�temp���ݴ��Ԫ��
}

template<class T,class E>
void MinHeap<T, E>::siftUp(int start) {
	//˽�к������ӽ��start��0Ϊֹ���������ϱȽϣ������Ů��ֵС�ڸ�����ֵ
	//�������໥���������������Ͼֲ�����Ϊ��С�ѡ��ؼ���ȽϷ���<="��E�ж���
	int j = start, i = (j - 1) / 2;
	E temp = heap[j];
	while (j>0)																	//�ظ����·������ֱ���
	{
		if (temp > heap[i])break;												//�����ֵС��������
		else { heap[j] = heap[i]; j = i; i = (i - 1) / 2; }						//�������
	}
	heap[j] = temp;																//�ط�
}

template<class T,class E>
bool MinHeap<T, E>::Insert(const E& x) {
	if (currentSize == maxHeapSize) { cerr << "Heap Full!" << endl; return false; }//����������false
	heap[currentSize] = x;														//����
	siftUp(currentSize);														//���ϵ���
	currentSize++;																//�Ѽ�����1
	return true;																
}

template<class T,class E>
bool MinHeap<T, E>::RemoveMin(E& x) {
	if (!currentSize) { cerr << "Heap Empty" << endl; return false; }			//�ѿգ�����false
	x = heap[0]; heap[0] = heap[currentSize - 1];								//���Ԫ�ز��䵽�����
	currentSize--;
	siftDown(0, currentSize - 1);												//���������»�����
	return true;
}