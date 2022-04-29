#pragma once
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#define MAX_SIZE 100
#define MAX_SONS 10									//���Ķ�


typedef struct
{
	char Fname[20];									//��λ
	char Sname[20];									//�¼���λ������
}RecType;											//R����Ľṹ�嶨��

typedef struct node
{
	char data[20];									//���ֵ����λ���ƻ�����ֵ
	struct node* sons[MAX_SONS];					//ָ���ӽ��
}TSonNode;											//�������洢�ṹ�嶨��

template<class T>
class Tree {										//��Ů����ʾ�������ඨ��
public:
	Tree() {};
	~Tree() {};
	void readFile() { readFile(R, n); };
	void createTree() { t=createTree(R[0].Fname, R, n); };
	void displayTree() { displayTree(t); };
	void destroyTree() { destroyTree(t); };
	int sonNum() {return sonNum(t, ch); };
	int classNum() {return classNum(t, ch); };
	int studentNum() {return studentNum(t, ch1); };
protected:
	void readFile(RecType R[], int& n);				//���ļ�
	TSonNode* createTree(char root[], RecType R[], int n);	//������
	void displayTree(TSonNode* t);					//�����ӡ��
	void destroyTree(TSonNode* t);					//������
	TSonNode* findNode(TSonNode* t, char x[]);		//Ѱ�ҽ��xָ��
	int childCount(TSonNode* t);					//����tָ��ĺ��ӽ�����
	int sonNum(TSonNode* t, char x[]);				//����x��λ����һ����λ��
	int leafCount(TSonNode* t);						//����Ҷ�ӽ����
	int classNum(TSonNode* t, char x[]);			//����x��λ�İ༶����
	int leafSum(TSonNode* t);						//����Ҷ�ӽ����ֵ��
	int studentNum(TSonNode* t, char x[]);			//����x���ѧ������

	TSonNode* t;									//��Ů�����ʾ��t
	RecType R[MAX_SIZE];							//R����
	int n;											//��¼R�����±����
	char ch[20] = { "�����ѧԺ" };
	char ch1[20] = { "����ѧԺ" };
};

template<class T>
void Tree<T>::readFile(RecType R[], int& n) {
	n = 0;
	ifstream infile("abc.txt", ios::in | ios::_Nocreate);//���ļ��ж�ȡ
	if (!infile) { cerr << "open error!" << endl; exit(1); }
	while (!infile.eof())							//��Ϊ��ʱ
	{
		infile >> R[n].Fname;						//д��R���鵥λ
		infile >> R[n].Sname;						//�¼���λ����ֵ
		n++;										//����+
	}
}

template<class T>
TSonNode* Tree<T>::createTree(char root[], RecType R[], int n) {
	TSonNode*t = new TSonNode();
	//t = (TSonNode*)malloc(sizeof(TSonNode));
	strcpy_s(t->data, root);						//��rootֵ���Ƶ�����
	for (int k = 0; k < MAX_SONS; k++)t->sons[k] = NULL;//��ʼ�����ӽ��Ķ�
	int i = 0, j = 0;
	while (i<n)
	{
		if (strcmp(R[i].Fname, root) == 0) {		//���������
			t->sons[j] = createTree(R[i].Sname, R, n);	//�ݹ鴴���ý��ĺ��ӽ��
			j++;
		}
		i++;
	}
	return t;
}

template<class T>
void Tree<T>::displayTree(TSonNode* t) {
	if (t != NULL) {
		//cout << t->data;
		printf("%s", t->data);						//��ӡ�������
		if (t->sons[0] != NULL) {					//�ý��Ȳ�Ϊ��
			cout << "(";
			for (int i = 0; i < MAX_SONS; i++) {
				displayTree(t->sons[i]);			//�ݹ����
				if (t->sons[i + 1] != NULL)cout << ".";
				else break;
			}
			cout << ")";
		}
	}
}

template<class T>
void Tree<T>::destroyTree(TSonNode* t) {
	if (t != NULL) {
		for (int i = 0; i < MAX_SONS; i++) {
			if (t->sons[i] != NULL)destroyTree(t->sons[i]);//�ݹ�
			else break;
		}
		delete t;									//ɾ�����t
	}
}

template<class T>
TSonNode* Tree<T>::findNode(TSonNode* t, char x[]) {
	TSonNode* p;
	if (t == NULL)return NULL;
	else if (strcmp(t->data, x) == 0)return t;		//���ظý��
	else {
		for (int i = 0; i < MAX_SONS; i++) {
			if (t->sons[i] != NULL) {
				p = findNode(t->sons[i], x);		//�ݹ�Ѱ�ҽ��
				if (p != NULL)return p;
			}
		}
		return NULL;
	}
}

template<class T>
int Tree<T>::childCount(TSonNode* t) {
	int num = 0;
	for (int i = 0; i < MAX_SONS; i++) {
		if (t->sons[i] != NULL)num++;				//���ĶȲ�Ϊ�գ�num+
		else break;
	}
	return num;
}

template<class T>
int Tree<T>::sonNum(TSonNode* t, char x[]) {
	TSonNode* p;
	p = findNode(t, x);								//Ѱ�Ҹý��p
	if (p == NULL)return 0;
	else return childCount(p);						//������p�ĺ��Ӹ���
}

template<class T>
int Tree<T>::leafCount(TSonNode* t) {
	int num = 0;
	if (t == NULL)return 0;
	else {
		if (t->sons[0] == NULL)num++;				//����޶ȣ�Ҷ�ӽ�����num+
		else {
			for (int i = 0; i < MAX_SONS; i++) {
				if (t->sons[i] != NULL)num += leafCount(t->sons[i]);//�ݹ�
				else break;
			}
		}
		return num;
	}
}

template<class T>
int Tree<T>::classNum(TSonNode* t, char x[]) {		//����༶����
	TSonNode* p;
	p = findNode(t, x);								//Ѱ�Ҹý��p
	if (p == NULL)return 0;
	else return leafCount(p);						//����ý��p��Ҷ�ӽ�����
}

template<class T>
int Tree<T>::leafSum(TSonNode* t) {					//����Ҷ�ӽ�����ֵ��
	int sum = 0;
	if (t == NULL)return 0;
	else {
		if (t->sons[0] == NULL)return atoi(t->data);//��Ҷ�ӽ�㣬���ؽ����ֵ
		else {
			for (int i = 0; i < MAX_SONS; i++) {
				if (t->sons[i] != NULL)sum += leafSum(t->sons[i]);//�ݹ����
				else break;
			}
		}
		return sum;									//����Ҷ�ӽ����ֵ��
	}
}

template<class T>
int Tree<T>::studentNum(TSonNode* t, char x[]) {	//����ѧ������
	TSonNode* p;
	p = findNode(t, x);								//Ѱ�Ҹý��p
	if (p == NULL)return 0;
	else return leafSum(p);							//����ý��p��Ҷ�ӽ����ֵ��
}