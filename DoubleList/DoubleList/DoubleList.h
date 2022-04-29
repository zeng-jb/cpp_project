#pragma once
#include <iostream>
using namespace std;

template <class T>
struct DblNode {
	T data;
	DblNode<T>* lLink, * rLink;
	DblNode(DblNode<T>* left = NULL, DblNode<T>* right = NULL) :lLink(left), rLink(right) {};  //���캯��
	DblNode(T value, DblNode<T>* left = NULL, DblNode<T>* right = NULL) :data(value), lLink(left), rLink(right){};  //���캯��
};

template <class T>
class DblLink {
public:
	DblLink(T uniqueVal);                //���캯������������ͷ���
	~DblLink() {};                            //���������ͷ��ڴ�
	int Length()const;                   //����˫����ĳ���
	bool IsEmpty() { return first->rLink == first; }      //�ж�˫�����Ƿ��
	DblNode<T>* getHead() { return first; }               //ȡ����ͷ����ַ
	void setHead(DblLink<T>* ptr) { first = ptr; }        //���ø���ͷ����ַ
	DblNode<T>* Search(const T& x);                //���������غ�̷�����ҵ���x��ֵ
	DblNode<T>* Locate(int i, int d);              //�������ж�λ���Ϊi�Ľڵ㣬d=0��ǰ������d/=0����̷���
	bool Insert(int i, const T& x, int d);           //�ڵ�i���ڵ����뺬��x���½ڵ㣬d=0��ǰ������d/=00����̷���
	bool Remove(int i, T& x, int d);                  //ɾ����i���ڵ㣬d=0��ǰ������d/=0����̷���


private:
	DblNode<T>* first;
};

template<class T>
DblLink<T>::DblLink(T uniqueVal) {
	//���캯��������˫������ĸ���ͷ��㣬�����ض������ֵ
	first = new DblNode<T>(uniqueVal);
	if (first == NULL) { cerr << "�洢�������" << endl; exit(1);}
	first->lLink = first->rLink = first;
}

template<class T>
int DblLink<T>::Length()const {
	//���������ͷ����˫������ĳ��ȣ�ͨ����������
	DblNode<T>* current = first->rLink; int count = 0;
	while (current != first) { current = current->rLink; count++; }
	return count;
}

template<class T>
DblNode<T>* DblLink<T>::Search(const T& x) {          //����x�Ľڵ�
	DblNode<T>* current = first->rLink;
	while (current != first && current->rLink != x) {
		current = current->rLink;
	}
	if (current != first) return current;     //�����ɹ�
	else return NULL;                         //����ʧ��
}

template<class T>
DblNode<T>* DblLink<T>::Locate(int i, int d) {
	//�ڵ�i���ڵ����뺬��x���½ڵ㣬d=0��ǰ������d/=00����̷���

	if (first->rLink == first || i = 0)return first;   //
	DblNode<T>* current;
	if (d != 0)current = first->rLink;               //��������
	else current = first->lLink;

	for (int j = 1; j < i; j++) {
		if (current == first)break;                //��̫���˳�����
		else if (d == 0) {
			current = current->lLink;
		}
		else {
			current = current->rLink;
		}
	}
		if (current != first) return current;         //�����ɹ�
		else return NULL;                             //����ʧ��
	
}

template<class T>
bool DblLink<T>::Insert(int i, const T& x, int d) {
	//����һ��x���½ڵ㣬�����䰴d������뵽��i���ڵ�֮��
	DblNode<T>* current = Locate(i, d);                //���ҵ�i���ڵ�
	if (current == NULL)return false;                  //i����������ʧ��
	DblNode<T>* newNode = new DblNode<T>(x);
	if (newNode == NULL) { cerr << "�洢����ʧ�ܣ�" << endl; exit(1); }

	if (d == 0) {                                     //ǰ���������
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
	return true; //����ɹ�

}

template<class T>
bool DblLink<T>::Remove(int i, T& x, int d) {
	//������ͷ����˫��������d����ɾ��i���ڵ�
	DblNode<T>* current = Locate(i, d);               //���ҵ�i���ڵ�
	if (current == NULL) return false;                  //i������ɾ��ʧ��
	current->rLink->lLink = current->lLink;
	current->lLink->rLink = current->rLink;
	x = current->data;
	delete current;
	return true;
}