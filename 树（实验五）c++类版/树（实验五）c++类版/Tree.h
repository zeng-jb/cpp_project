#pragma once
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#define MAX_SIZE 100
#define MAX_SONS 10									//结点的度


typedef struct
{
	char Fname[20];									//单位
	char Sname[20];									//下级单位或人数
}RecType;											//R数组的结构体定义

typedef struct node
{
	char data[20];									//结点值：单位名称或者数值
	struct node* sons[MAX_SONS];					//指向孩子结点
}TSonNode;											//孩子链存储结构体定义

template<class T>
class Tree {										//子女链表示法树的类定义
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
	void readFile(RecType R[], int& n);				//读文件
	TSonNode* createTree(char root[], RecType R[], int n);	//创建树
	void displayTree(TSonNode* t);					//输出打印树
	void destroyTree(TSonNode* t);					//销毁树
	TSonNode* findNode(TSonNode* t, char x[]);		//寻找结点x指针
	int childCount(TSonNode* t);					//计算t指向的孩子结点个数
	int sonNum(TSonNode* t, char x[]);				//计算x单位的下一级单位数
	int leafCount(TSonNode* t);						//计算叶子结点数
	int classNum(TSonNode* t, char x[]);			//计算x单位的班级个数
	int leafSum(TSonNode* t);						//计算叶子结点数值和
	int studentNum(TSonNode* t, char x[]);			//计算x结点学生总数

	TSonNode* t;									//子女链表表示树t
	RecType R[MAX_SIZE];							//R数组
	int n;											//记录R数组下标个数
	char ch[20] = { "计算机学院" };
	char ch1[20] = { "电信学院" };
};

template<class T>
void Tree<T>::readFile(RecType R[], int& n) {
	n = 0;
	ifstream infile("abc.txt", ios::in | ios::_Nocreate);//从文件中读取
	if (!infile) { cerr << "open error!" << endl; exit(1); }
	while (!infile.eof())							//不为空时
	{
		infile >> R[n].Fname;						//写入R数组单位
		infile >> R[n].Sname;						//下级单位或数值
		n++;										//个数+
	}
}

template<class T>
TSonNode* Tree<T>::createTree(char root[], RecType R[], int n) {
	TSonNode*t = new TSonNode();
	//t = (TSonNode*)malloc(sizeof(TSonNode));
	strcpy_s(t->data, root);						//将root值复制到树中
	for (int k = 0; k < MAX_SONS; k++)t->sons[k] = NULL;//初始化孩子结点的度
	int i = 0, j = 0;
	while (i<n)
	{
		if (strcmp(R[i].Fname, root) == 0) {		//如果结点相等
			t->sons[j] = createTree(R[i].Sname, R, n);	//递归创建该结点的孩子结点
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
		printf("%s", t->data);						//打印结点内容
		if (t->sons[0] != NULL) {					//该结点度不为空
			cout << "(";
			for (int i = 0; i < MAX_SONS; i++) {
				displayTree(t->sons[i]);			//递归输出
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
			if (t->sons[i] != NULL)destroyTree(t->sons[i]);//递归
			else break;
		}
		delete t;									//删除结点t
	}
}

template<class T>
TSonNode* Tree<T>::findNode(TSonNode* t, char x[]) {
	TSonNode* p;
	if (t == NULL)return NULL;
	else if (strcmp(t->data, x) == 0)return t;		//返回该结点
	else {
		for (int i = 0; i < MAX_SONS; i++) {
			if (t->sons[i] != NULL) {
				p = findNode(t->sons[i], x);		//递归寻找结点
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
		if (t->sons[i] != NULL)num++;				//结点的度不为空，num+
		else break;
	}
	return num;
}

template<class T>
int Tree<T>::sonNum(TSonNode* t, char x[]) {
	TSonNode* p;
	p = findNode(t, x);								//寻找该结点p
	if (p == NULL)return 0;
	else return childCount(p);						//计算结点p的孩子个数
}

template<class T>
int Tree<T>::leafCount(TSonNode* t) {
	int num = 0;
	if (t == NULL)return 0;
	else {
		if (t->sons[0] == NULL)num++;				//结点无度，叶子结点个数num+
		else {
			for (int i = 0; i < MAX_SONS; i++) {
				if (t->sons[i] != NULL)num += leafCount(t->sons[i]);//递归
				else break;
			}
		}
		return num;
	}
}

template<class T>
int Tree<T>::classNum(TSonNode* t, char x[]) {		//计算班级个数
	TSonNode* p;
	p = findNode(t, x);								//寻找该结点p
	if (p == NULL)return 0;
	else return leafCount(p);						//计算该结点p的叶子结点个数
}

template<class T>
int Tree<T>::leafSum(TSonNode* t) {					//计算叶子结点的数值和
	int sum = 0;
	if (t == NULL)return 0;
	else {
		if (t->sons[0] == NULL)return atoi(t->data);//是叶子结点，返回结点数值
		else {
			for (int i = 0; i < MAX_SONS; i++) {
				if (t->sons[i] != NULL)sum += leafSum(t->sons[i]);//递归调用
				else break;
			}
		}
		return sum;									//返回叶子结点数值和
	}
}

template<class T>
int Tree<T>::studentNum(TSonNode* t, char x[]) {	//计算学生总数
	TSonNode* p;
	p = findNode(t, x);								//寻找该结点p
	if (p == NULL)return 0;
	else return leafSum(p);							//计算该结点p的叶子结点数值和
}