//#pragma once
//#include<iostream>
//using namespace std;
//template<class T>
//struct TreeNode
//{
//	T data;														//���Ľ����
//	TreeNode<T>* firstChild, * nextSibling;						//������ݣ���Ů�ֵ�ָ��
//	TreeNode(T value = 0, TreeNode<T>* fc = NULL, TreeNode<T>* ns = NULL) :data(value), firstChild(fc), nextSibling(ns) {};//���캯��
//	T getData() { return data; }
//};
//template<class T>
//class Tree {													//����
//private:
//	TreeNode<T> * currnet;								//��ָ�룬��ǰָ��
//	bool Find(TreeNode<T>* p, T value);							//���Ը�Ϊp�Ľ������Tֵ
//	void RemovesubTree(TreeNode<T>* p);							//ɾ�����Ϊp��ָ��
//	bool FindParent(TreeNode<T>* t, TreeNode<T>* p);			//��˫��
//
//	
//public:
//	Tree() { root = currnet = NULL; }							//���캯������������
//	bool Root();												//Ѱ�Ҹ�
//	bool IsEmpty() { return root = NULL; }						//�п���
//	bool FindChild();											//�ҵ�һ����Ů
//	bool NextSibling();											//�ҵ�ǰ������һ���ֵ�
//	bool Parent();												//�ҵ�ǰ����˫��
//	bool Find(T target);										//��������T���
//
//	void ClearTree() { ClearTree(root); }
//	void preOrder() { preOrder(root); }
//private:
//	void InitTree(TreeNode<T>* t) { root = NULL; }
//	void ClearTree(TreeNode<T>* t);
//	void DestroyTree(TreeNode<T>* t);
//	int getDegree(TreeNode<T>* t);
//	int leaveCount(TreeNode<T>* t);
//	void preOrder(TreeNode<T>* t);
//	TreeNode<T>* root;
//};
//
//template<class T>
//bool Tree<T>::Root() {
//	if (root == NULL) { currnet = NULL; return false; }
//	else { currnet = root; return true; }
//}
//
//template<class T>
//bool Tree<T>::Parent() {
//	TreeNode<T>* p = currnet;
//	if (currnet == NULL || currnet == root) { currnet = NULL; return false; }
//	return FindParent(root, p);
//}
//
//template<class T>
//bool Tree<T>::FindParent(TreeNode<T>* t, TreeNode<T>* p) {
//	TreeNode<T>* q = t->firstChild; bool succ;
//	while (q!=NULL&&q!=p)
//	{
//		if ((succ = FindChild(q, p)) == true)return succ;
//		q = q->nextSibling;
//	}
//	if (q != NULL && q == p) { currnet = t; return true; }
//	else { currnet = NULL; return false; }
//}
//
//template<class T>
//bool Tree<T>::FindChild() {
//	if (currnet != NULL && currnet->firstChild != NULL) {
//		currnet = currnet->firstChild; return true;
//	}
//	currnet = NULL; return false;
//}
//
//template<class T>
//bool Tree<T>::NextSibling() {
//	if (currnet != NULL && currnet->nextSibling != NULL) {
//		currnet = currnet->nextSibling;
//		return true;
//	}
//	currnet = NULL; return false;
//}
//
//template<class T>
//bool Tree<T>::Find(T value) {
//	if (IsEmpty())return false;
//	return Find(root, value);
//}
//
//template<class T>
//bool Tree<T>::Find(TreeNode<T>* p, T value) {
//	bool result = false;
//	if (p->data == value) { return true; currnet = p; }
//	else {
//		TreeNode<T>* q = p->firstChild;
//		while (q!=NULL&&!(result=Find(q,value)))
//		{
//			q = q->nextSibling;
//		}
//	}
//	return result;
//}
//
//template<class T>
//void Tree<T>::ClearTree(TreeNode<T>* t) {
//	T ch;
//	cin >> ch;
//	if (ch == '#') t = NULL;
//	else {
//		t = new TreeNode<T>;
//		if (!t)exit(0);
//		t->data = ch;
//		ClearTree(t->firstChild);
//		ClearTree(t->nextSibling);
//	}
//}
//
//template<class T>
//void Tree<T>::DestroyTree(TreeNode<T>* t) {
//	if (!t)return;
//	DestroyTree(t->firstChild);
//	DestroyTree(t->nextSibling);
//	delete t;
//}
//
//template<class T>
//int Tree<T>::getDegree(TreeNode<T>* t) {
//	int num = 0;
//	if (!t)return 0;
//	if (!t->firstChild)return 1;
//	for (TreeNode<T>* p = t->firstChild; p; p = p->nextSibling)num++;
//	/*for (TreeNode<T>* p = t->firstChild; p; p = p->nextSibling) {
//		int num1 = getDegree(p);
//		if (num1 > num)num = num1;
//	}*/
//	return num;
//}
//
//template<class T>
//int Tree<T>::leaveCount(TreeNode<T>* t) {
//	int count = 0;
//	if (!t)return 0;
//	if (!t->firstChild)return 1;
//	for (TreeNode<T>* p = t->firstChild; p; p = p->nextSibling)count += leaveCount(p);
//	return count;
//}
//
//template<class T>
//void Tree<T>::preOrder(TreeNode<T>* t) {
//	if (t) {
//		cout << t->getData();
//		preOrder(t->firstChild);
//		preOrder(t->nextSibling);
//	}
//}

#include <iostream>
using namespace std;
const int MaxCSTreeSize = 20;
template<class T>
class CSNode
{
public:
	T data;
	CSNode* firstchild;
	CSNode* nextsibling;
public:
	CSNode();
	CSNode(CSNode* fchild, CSNode* nextsibling, T newdata);
	CSNode* getFirstChild();
	CSNode* getNextSibling();
	T getData();
	void setFirstChild(T newData);
	void setNextsibling(T newData);
	void showInputChild();//��ʾ���ڵ㲢�����������ĺ���
};

template<class T>
CSNode<T>::CSNode() :firstchild(NULL), nextsibling(NULL)
{ }

template<class T>
CSNode<T>::CSNode(CSNode* fchild, CSNode* nextsibling, T newdata) : firstchild(fchild), nextsibling(nextsibling), data(newdata)
{ }

template<class T>
CSNode<T>* CSNode<T>::getFirstChild()
{
	return firstchild;
}

template<class T>
CSNode<T>* CSNode<T>::getNextSibling()//ģ���ࣺ���ǰ���ģ�������Ķ�Ҫ��<>���������ڷ���ֵ������������
{						//ģ�����к�����������ʵ�ֵ�ʱ��Ҫ�и�ð	template<class T>  ��ʾ���Ǹ�ģ����ĺ����������벻ͬ����				
	return nextsibling;
}

template<class T>
T CSNode<T>::getData()
{
	return data;
}

template<class T>
void CSNode<T>::setFirstChild(T newData)
{
	firstchild->data = newData;
}

template<class T>
void CSNode<T>::setNextsibling(T newData)
{
	nextsibling->data = newData;
}

template<class T>
void CSNode<T>::showInputChild()
{
	cout << "������" << data << "�ĺ���:";
}

template<class T>
class CSTree
{
public:
	CSTree();
	CSTree(const CSTree<T>& csTree);
	~CSTree();
	const CSTree<T>& operator=(const CSTree<T>& csTree);
	void  createCSTree(); //��������   
	void  InitCSTree();   //��ʼ����   
	void  destoryCSTree();//������   
	bool  isEmptyCSTree();//������Ƿ�Ϊ��    
	void  preOrderTraverse();//�������   
	void  postOrderTraverse(); //�������   
	void  levelOrderTraverse();//�������   
	int   heightCSTree();//���߶�   
	int   widthCSTree(); //����� 
	int   getDegreeCSTree();//���Ķ�--�������н��ȵ����ֵ
	int   nodeCountCSTree();  //��������
	int   LeavesCountCSTree();//��Ҷ�Ӹ���   
	int   nodeLevelCSTree(T item);//���item�ڵĲ��
	int   getChildrenCount(const CSNode<T>* p)const;//���ؽ�㺢�Ӹ���
	void  getAllParentCSTree(T item)const;//��item����������   
	void  longPathCSNode();//�����ÿ��Ҷ�ӽ�㵽�������·�� ----- δʵ��
	bool  findCSNode(const T item, CSNode<T>*& ret)const; //���ҽ�� 
	bool  getParentCSTree(const T item, CSNode<T>*& ret)const;//���ҽ��item�ĸ��׽��
	bool  getleftChild(const CSNode<T>* p, CSNode<T>*& ret) const;   //��������ߵ��ֵ�
	bool  getrightSibling(const CSNode<T>* p, CSNode<T>*& ret) const;  //�������ұߵ��ֵ�
	bool  getAllSibling(const T item) const; //��������ֵ�
	bool  getAllChildren(T item);//������еĺ���
private:
	void create(CSNode<T>*& p);//��pΪ����������
	void  copyTree(CSNode<T>*& copyTreeRoot, CSNode<T>* otherTreeRoot);
	//����otherTreeRootΪ���ڵ�Ĳ��ֿ�����copyTreeRootΪ���ڵ�Ĳ���   
	void  destory(CSNode<T>*& p, int& num);
	//������pΪ���ڵ�Ĳ���    
	void  preOrder(CSNode<T>* p);
	//���������pΪ���ڵ�Ĳ���   
	void  postOrder(CSNode<T>* p);
	//���������pΪ���ڵ�Ĳ���   
	void  levelOrder(CSNode<T>* p);
	//��α�����pΪ���ڵ�Ĳ���   
	int   height(CSNode<T>* p);
	//������pΪ���ڵ�ĸ߶�   
	int   width(CSNode<T>* p);
	//������pΪ�������Ŀ��
	int   nodeCount(CSNode<T>* p);
	//������pΪ���ڵ�Ľ�����   
	int   leavesCount(CSNode<T>* p);
	//������pΪ���ڵ��Ҷ�Ӹ���   
	void  nodeLevel(T item, CSNode<T>* p, int level, int& nlevel);
	//������pΪ���ڵ����item���ڲ�Σ����ж��Ԫ�أ���������һ���򷵻أ��������������û�г��֣��򷵻�0   
	bool  find(CSNode<T>* p, const T item, bool& isFind, CSNode<T>*& cur)const;
	//��pָ������У����� ֵΪitem��ָ��  
	bool  getParent(CSNode<T>* p, const T item, bool& isFind, bool& isFirst, CSNode<T>*& ret)const;
	//��pָ�������У���item�ĸ���
	bool getAllParent(T item, CSNode<T>* p, CSNode<T>* path[MaxCSTreeSize], int& seat, bool& isFind)const;
	//��item���������ȣ�seat��ʾ���һ�����׵��±� 
	void  longPath(CSNode<T>* p, int len, int& maxLen, CSNode<T>*& longNode);
	//�����ÿ��Ҷ�ӽ�㵽�������·��
		int getDegree(CSNode<T>* p);
	//������Ķȣ����н��ĺ������ֵ��
private:
	CSNode<T>* root;
};

template<class T>
CSTree<T>::CSTree() :root(NULL)//ע�⣬���ﹹ�캯��ҪΪroot��ֵΪ�գ�������֮��ͿձȶԵ�ʱ�򣬿��ܻ����
{ }

template<class T>
CSTree<T>::~CSTree()
{
	if (root != NULL)
	{
		int num = 0;
		destory(root, num);
		InitCSTree();
	}
}

template<class T>
void CSTree<T>::createCSTree()
{
	create(root);
}

template<class T>
void CSTree<T>::create(CSNode<T>*& p)
{
	T parent;
	T child;
	//����һ������
	int front = 0;
	int rear = 0;
	CSNode<T>* pNode = p;
	CSNode<T>* queue[MaxCSTreeSize];
	cin >> parent >> child;
	while (child != '#')
	{
		CSNode<T>* node = new CSNode<T>;
		node->data = child;
		node->firstchild = NULL;
		node->nextsibling = NULL;
		if (parent == '#')
		{
			p = node;//Ϊ��
			queue[(rear++) % MaxCSTreeSize] = node;//�����
		}
		else
		{
			pNode = queue[front];//��ȡ��ͷԪ��
			while (pNode->data != parent) //���Լ����׽ڵ��ָ�� 
			{
				front = (front + 1) % MaxCSTreeSize;
				pNode = queue[front];//��ȡ��ͷԪ��---����д��pNode = queue[front++]������Ϊ���ҵ����׵�ʱ��front��ִ����++�����׾�ֱ�ӳ������ˣ������׺����ĺ�������ʱ����Ҳ������׶������ˣ�
			}
			if (pNode->data == parent)//�Ƕ���
			{
				if (pNode->firstchild == NULL)
				{
					pNode->firstchild = node;
				}
				else
				{
					pNode = pNode->firstchild;
					while (pNode->nextsibling)
					{
						pNode = pNode->nextsibling;
					}
					pNode->nextsibling = node;
				}
			}
			if ((rear + 1) % MaxCSTreeSize != front)//�Ӳ����������
			{
				queue[(rear++) % MaxCSTreeSize] = node;//���Լ��Ķ��ӷŵ�������
			}
		}
		cin >> parent >> child;
	}
}

template<class T>
void CSTree<T>::copyTree(CSNode<T>*& dstTreeRoot, CSNode<T>* srcTreeRoot)
{
	if (srcTreeRoot)
	{
		dstTreeRoot = new CSNode<T>;
		dstTreeRoot->data = srcTreeRoot->data;
		copyTree(dstTreeRoot->firstchild, srcTreeRoot->firstchild);
		copyTree(dstTreeRoot->nextsibling, srcTreeRoot->nextsibling);
	}
}

template<class T>
CSTree<T>::CSTree(const CSTree<T>& csTree)
{
	if (csTree.root == NULL)
	{
		root = NULL;
	}
	else
	{
		copyTree(this->root, csTree.root);
	}
}

template<class T>
const CSTree<T>& CSTree<T>::operator=(const CSTree<T>& csTree)
{
	if (this != &csTree)//�����Լ���ֵ
	{
		if (root != NULL)//
		{
			int num = 0;//numֻ��Ϊ�˵�����
			destory(root, num);//�Լ��г�Ա��������
		}
		if (csTree.root == NULL)
		{
			root = NULL;
		}
		else
		{
			copyTree(this->root, csTree.root);
		}
	}
	return *this;
}

template<class T>
void CSTree<T>::InitCSTree()
{
	root = NULL;
}

template<class T>
void CSTree<T>::destoryCSTree()
{
	int num = 0;
	destory(root, num);
	root = NULL;
	cout << "������" << num << "�����" << endl;
}
/*ʹ�ú���������--����ֱ�ӰѸ�������һ��Ķ���������������ټ���*/
template<class T>
void CSTree<T>::destory(CSNode<T>*& p, int& num)
{
	if (!p)//�սڵ�
	{
		return;
	}
	destory(p->firstchild, num);
	destory(p->nextsibling, num);
	delete p;
	num++;
}

template<class T>
bool CSTree<T>::isEmptyCSTree()
{
	if (root == NULL)
	{
		return true;
	}
	return false;
}

template<class T>
void CSTree<T>::preOrderTraverse()
{
	preOrder(root);
	cout << endl;
}

/*�������������ת��ɶ�����������������һ����*/
template<class T>
void CSTree<T>::preOrder(CSNode<T>* p)
{
	if (p)
	{
		cout << p->getData();
		preOrder(p->firstchild);
		preOrder(p->nextsibling);
	}
}

template<class T>
void CSTree<T>::postOrderTraverse()
{
	postOrder(root);
	cout << endl;
}

/*���ĺ��������ת��ɶ�����������������һ����*/
template<class T>
void CSTree<T>::postOrder(CSNode<T>* p)
{
	if (p)
	{
		postOrder(p->firstchild);
		cout << p->getData();
		postOrder(p->nextsibling);
	}
}

template<class T>
void CSTree<T>::levelOrderTraverse()
{
	levelOrder(root);
	cout << endl;
}
/*���Ĳ�α����Ͷ������Ĳ�α���˼·��һ���ģ���ӵĶ��Ǹý������к���*/
template<class T>
void CSTree<T>::levelOrder(CSNode<T>* p)
{
	//����һ������
	int front = 0;
	int rear = 0;
	CSNode<T>* queue[MaxCSTreeSize];
	if (!p)
	{
		return;
	}
	queue[(rear++) % MaxCSTreeSize] = p;
	while (front < rear)
	{
		CSNode<T>* t = queue[(front++) % MaxCSTreeSize];
		cout << t->data;
		for (CSNode<T>* pNode = t->firstchild; pNode; pNode = pNode->nextsibling)
		{
			queue[(rear++) % MaxCSTreeSize] = pNode;
		}
	}
}

template<class T>
int CSTree<T>::LeavesCountCSTree()
{
	return leavesCount(root);
}

/*���һ���ڵ����������Ϊ�գ����ΪҶ�ӽڵ�*/
template<class T>
int CSTree<T>::leavesCount(CSNode<T>* p)
{
	int count = 0;
	if (!p)//���� ����һ
	{
		return 0;
	}
	if (!p->firstchild)
	{
		return 1;
	}
	for (CSNode<T>* pNode = p->firstchild; pNode; pNode = pNode->nextsibling)
	{
		count += leavesCount(pNode);
	}
	return count;
}
/*Ѱ��item�Ľ��*/
template<class T>
int CSTree<T>::nodeLevelCSTree(T item)
{
	int nlevel = 0;
	nodeLevel(item, root, 1, nlevel);//���ȵ���һ�����
	return nlevel;
}

/*
level������ʾ�����Ѿ����ҵ��ڼ���
nlevel������ʾ��¼������ڵ����յĲ��
*/
template<class T>
void CSTree<T>::nodeLevel(T item, CSNode<T>* p, int level, int& nlevel)
{
	if (nlevel) //����η�0ʱ����ʾ�Ѿ��ҵ� -- ����һ
	{
		return;
	}
	if (!p) //���ڶ�
	{
		return;
	}
	if (p->data == item)//������
	{
		nlevel = level;
		return;
	}
	for (CSNode<T>* pNode = p->firstchild; pNode; pNode = pNode->nextsibling)//�ں��Ӵ����� --- ���
	{
		nodeLevel(item, pNode, level + 1, nlevel);
	}
}

template<class T>
int CSTree<T>::heightCSTree()
{
	return height(root);
}

/*�Ѹ����Һ��ӵ���ȱȽϣ�ȡ���ֵ*/
template<class T>
int CSTree<T>::height(CSNode<T>* p)
{
	int maxHeight = 0;
	if (!p)//��Ϊ�ڵݹ��ʱ�򲻶Կպ��ӽ����жϣ��������ܻ���Ϊ�յ��������ʱҪר�ŶԿս��д���
	{
		return 0;
	}
	if (!p->firstchild)//�����Ҷ�ӽ������
	{
		return 1;
	}
	for (CSNode<T>* pNode = p->firstchild; pNode; pNode = pNode->nextsibling)//������ж�����ӵ����
	{
		int h = height(pNode) + 1;
		if (h > maxHeight)
		{
			maxHeight = h;
		}
	}
	return maxHeight;
}


/*���Ŀ��*/
template<class T>
int CSTree<T>::widthCSTree()
{
	return width(root);
}

/*���ȵĺ��������벻��Ҫ����last������һ��Ҫע�Ⱑ*/
template<class T>
int CSTree<T>::width(CSNode<T>* p)
{
	int w = 0;
	int maxWidth = 0;
	int front = 0;
	int rear = 0;
	int last = 0;//lastָ��һ��������Ǹ�Ԫ��
	CSNode<T>* queue[MaxCSTreeSize];
	//�������
	if (!p)
	{
		maxWidth = 0;
	}
	else
	{
		queue[rear++] = p;
		while (front <= last)//�Ⱥų���������Ǹ�Ԫ����Ȼ�Ǳ����Ԫ�أ�Ҫ��������
		{
			CSNode<T>* cur = queue[front++];//���Ӵ���
			w++;
			for (CSNode<T>* pNode = cur->firstchild; pNode; pNode = pNode->nextsibling)
			{
				queue[rear++] = pNode;
			}
			if (front > last)
			{
				last = rear - 1;//��Ϊrear����ָ�򱾲�Ԫ�ص���һλ
				if (w > maxWidth)
				{
					maxWidth = w;
				}
				w = 0;
			}
		}
	}
	return maxWidth;
}

template<class T>
int CSTree<T>::nodeCountCSTree()
{
	return nodeCount(root);
}
/*������������õ�*/
template<class T>
int CSTree<T>::nodeCount(CSNode<T>* p)
{
	int sum = 0;
	if (!p)
	{
		return 0;
	}
	if (!p->firstchild)//����Ϊ�գ��ý���ΪҶ�ӽ��
	{
		return 1;
	}
	for (CSNode<T>* pNode = p->firstchild; pNode; pNode = pNode->nextsibling)
	{
		sum += nodeCount(pNode);
	}
	return sum + 1;//1�����ױ���sumΪ���ӵ��ܺ�
}



template<class T>
bool CSTree<T>::findCSNode(const T item, CSNode<T>*& ret)const
{
	bool isFind = false;
	find(root, item, isFind, ret);
	return isFind;
}

/*ʹ����ȱ������в���*/
template<class T>
bool CSTree<T>::find(CSNode<T>* p, const T item, bool& isFind, CSNode<T>*& cur)const
{
	if (isFind)//�ҵ�ֱ�ӷ���
	{
		return isFind;
	}
	if (!p)//���Ϊ�գ�ֱ�ӷ���
	{
		cur = NULL;
		return isFind;
	}
	if (p->data == item)//�ҵ�
	{
		cur = p;
		isFind = true;
		return isFind;
	}//û�ҵ��������ݹ�
	for (CSNode<T>* pNode = p->firstchild; pNode; pNode = pNode->nextsibling)
	{
		find(pNode, item, isFind, cur);
		if (isFind)
		{
			return isFind;
		}
	}
	return isFind;
}

template<class T>
int CSTree<T>::getDegreeCSTree()
{
	return getDegree(root);
}

template<class T>
int CSTree<T>::getDegree(CSNode<T>* p)
{
	int num = 0;
	if (!p)//�ݹ����һ -- ���Ϊ��
	{
		return 0;
	}
	if (!p->firstchild)//�ݹ���ڶ� -- ���ΪҶ�ӽ��
	{
		return 1;
	}
	for (CSNode<T>* pNode = p->firstchild; pNode; pNode = pNode->nextsibling)//�������������Լ����ӵĸ��� -- ����к���
	{
		num++;
	}
	for (CSNode<T>* pNode = p->firstchild; pNode; pNode = pNode->nextsibling)//�����Լ��ĺ��ӵĶȣ������Լ��Ķ���Ƚϣ���������
	{
		int num1 = getDegree(pNode);
		if (num1 > num)
		{
			num = num1;
		}
	}
	return num;
}
template<class T>
bool CSTree<T>::getleftChild(const CSNode<T>* p, CSNode<T>*& ret)const
{
	if (!p)
	{
		return false;
	}
	else
	{
		if (getParentCSTree(p->data, ret))//�ҵ�p���ĸ���
		{
			ret = ret->firstchild;
			return true;
		}
		else
			return false;//�Ҳ������׽�㣬��ʾ���Ǹ����ڵ�
	}
}

template<class T>
bool CSTree<T>::getrightSibling(const CSNode<T>* p, CSNode<T>*& ret)const
{
	if (!p)
	{
		return false;
	}
	else
	{
		if (getParentCSTree(p->data, ret))//�ҵ�p���ĸ���
		{
			CSNode<T>* node = ret->firstchild;
			while (node->nextsibling)
			{
				node = node->nextsibling;
			}
			ret = node;
			return true;
		}
		else
			return false;//�Ҳ������׽�㣬��ʾ���Ǹ����ڵ�
	}
}

template<class T>
bool CSTree<T>::getParentCSTree(const T item, CSNode<T>*& ret) const
{
	bool isFind = false;
	bool isFirst = true;
	getParent(root, item, isFind, isFirst, ret);
	return isFind;
}

/*ʹ�ò�α����õ������*/
template<class T>
bool CSTree<T>::getParent(CSNode<T>* p, const T item, bool& isFind, bool& isFirst, CSNode<T>*& ret)const
{
	if (isFind) //����һ
	{
		return isFind;
	}
	if (!p)//pΪ�� // ���ڶ�
	{
		return false;
	}
	if (p->data == item)//����Լ� //������
	{
		if (p == root)
		{
			cout << "Ҫ����Ԫ��Ϊ����" << endl;//�����ڸ��׽��
			isFind = false;
			return isFind;
		}
		else
		{
			isFind = true;
			//����ret�����ܸ�ֵ��ֻ���ڵݹ��ȥ����ܼ����õ����׵�ָ��
			return isFind;
		}
	}
	for (CSNode<T>* pNode = p->firstchild; pNode; pNode = pNode->nextsibling)//������ + ���
	{
		getParent(pNode, item, isFind, isFirst, ret); //���һ
		if (isFind && isFirst)//���ݹ�����Ľ��������ҵ�����Ϊret��ֵ����Ϊ�ݹ��ڻ��˵�ʱ��isFind��Ҳ��true��������isFirst�ͻ���Խ��ret��ֵ����һ·����һ·��ֵ�����Ҫ�����������������Ҫ�������������ֻ�е�һ�γ�����������ʱ���Ϊ�丳ֵ
		{
			isFirst = false;
			ret = p;
			return isFind;
		}
	}
	return isFind;
}

template<class T>
int CSTree<T>::getChildrenCount(const CSNode<T>* p)const
{
	int count = 0;
	for (CSNode<T>* pNode = p->firstchild; pNode; pNode = pNode->nextsibling)//���㱾���Ķ�
	{
		count++;
	}
	return count;
}

template<class T>
void CSTree<T>::getAllParentCSTree(T item)const
{
	CSNode<T>* path[MaxCSTreeSize];//������Ľ��
	int len = 0;//�ݹ�Ĳ��
	int seat = 0;//����ж���˫��
	bool isFind = false;//�Ƿ��Ѿ��ҵ�
	getAllParent(item, root, path, seat, isFind);
	if (isFind)
	{
		for (int i = 0; i < seat; i++)
		{
			cout << path[i]->data;
		}
		cout << endl;
	}
	else
	{
		cout << "û���ҵ����!" << item << endl;
	}
}
//����ֱ��ʹ��ת��������������������
/*˼��:
ʹ��һ�����鱣��˫�׽��
˫�׷������飬֮�󵱴��������Լ�����������ʱ�����û�ҵ�����������Ͳ���������˫�׽�㣬ֱ�ӰѸý���Ƴ����顣
*/
template<class T>
bool CSTree<T>::getAllParent(T item, CSNode<T>* p, CSNode<T>* path[MaxCSTreeSize], int& seat, bool& isFind)const //��Ҫ˼����
{
	if (isFind)//�ҵ�ֱ�ӷ���
	{
		return isFind;
	}
	if (!p)//��������������
	{
		return false;
	}
	if (p->data == item)//���ŵ������Ҳ����������
	{
		isFind = true;
		return isFind;
	}
	else
	{
		path[seat++] = p;
		getAllParent(item, p->firstchild, path, seat, isFind);
		if (!isFind)
		{
			seat = seat - 1;//��1����Ϊ��ath[seat++]=p;����seat��ָ����һ��Ҫ��ŵ�λ�ã����ﵱִ�е���һ����ʱ��˵��������ֵ�û�ҵ�����Ϊ�����������ֵܹ�ϵ����ʱҪ������ߵĺ����Ƴ�ȥ������ֻ�軹���Һ��ӷŵ����ӵ�λ��ֱ�Ӹ��Ǿͺ�
			getAllParent(item, p->nextsibling, path, seat, isFind);
		}
	}
	return isFind;
}

template<class T>
bool CSTree<T>::getAllSibling(const T item) const
{
	//���ҵ��Լ��ĸ���
	bool isFind = false;
	CSNode<T>* ret = NULL;
	isFind = getParentCSTree(item, ret);
	if (!isFind)
	{
		//û�ҵ�����
		return false;
	}
	else
	{
		isFind = false;//ͬʱ����isFind��ʾ�ǲ����ҵ����Լ����ֵ�
		for (CSNode<T>* pNode = ret->firstchild; pNode; pNode = pNode->nextsibling)
		{
			if (pNode->data != item)
			{
				isFind = true;
				cout << pNode->data << " ";//�ֵܴ���������Ϊ��
			}

		}
		return isFind;
	}
}

template<class T>
bool CSTree<T>::getAllChildren(T item)
{
	bool isFind = false;
	CSNode<T>* parent = NULL;
	findCSNode(item, parent);
	for (CSNode<T>* pNode = parent->firstchild; pNode; pNode = pNode->nextsibling)
	{
		isFind = true;//�к���
		cout << pNode->data << " ";//�ֵܴ���������Ϊ��
	}
	return isFind;
}
