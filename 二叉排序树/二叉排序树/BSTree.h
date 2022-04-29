#pragma once
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<string>
#include<queue>



using namespace std;

template<class E,class K>
struct BSTNode																			//二叉树节点类
{		
	E data;																				//数据域
	BSTNode<E, K>* left, * right;														//左右子女
	BSTNode() :left(NULL), right(NULL) {};												//构造函数
	BSTNode(const E d, BSTNode<E, K>* L = NULL, BSTNode<E, K>* R = NULL) :data(d), left(L), right(R) {};//构造函数
	~BSTNode() {};																			//析构函数
	void setData(E d) { data = d; };														//修改
	bool operator <(const E& x) { return (data < x) ? true: false; }			//重载：元素间小于
	bool operator >(const E& x) { return (data > x) ? true: false; }			//重载：元素间大于
	bool operator ==(const E& x) { return (data == x) ? true: false; }			//重载：元素间等于
};

template<class E,class K>
class BST																				//二叉搜索树类定义
{
public:

	BST() :root(NULL) {};																//构造函数
	BST(K value);																		//构造函数
	void Cread(K value);
	~BST() {};																			//析构函数
	bool Serach(const K x)const { return (Serach(x, root) != NULL) ? true:false; }		//搜索
	bool non_recursive_Search(const K x)const { return non_recursive_Search(x, root) != NULL ? true : false; }		//非递归搜索
	BST<E, K>& operator = (const BST<E, K>& R);										//重载：赋值
	void makeEmpty() { makeEmpty(root); root = NULL; }									//置空
	void PrintTree()const { PrintTree(root); }											//输出
	E Min() { return (Min(root)->data); }												//求最小
	E Max() { return (Max(root)->data); }												//求最大
	bool Insert(const E& e1) { return Insert(e1, root); }								//插入新元素
	bool non_recursive_Insert(const E& e1) { return non_recursive_Insert(e1, root); }
	bool Remove(const K x) { return Remove(x, root); }									//删除含x结点
	vector<BSTNode<E, K>*> inorderTraversal( BSTNode<E,K>* ptr);
	void WriteInFile() { WriteInFile(root);}
	void ReadoutFile();
private:
	BSTNode<E, K>* root;																//二叉搜索树的根结点指针
	K RefValue;																			//输入停止标志，用于输入
	BSTNode<E, K>* Serach(const K x, BSTNode<E, K>* ptr)const;								//递归：搜索
	BSTNode<E, K>* non_recursive_Search(const K x, BSTNode<E, K>* ptr)const;
	void makeEmpty(BSTNode<E, K>*& ptr);												//递归：置空
	void PrintTree(BSTNode<E, K>* ptr,int level=0)const;											//递归：输出
	BSTNode<E, K>* Copy(const BSTNode<E, K>* ptr);										//递归：复制
	BSTNode<E, K>* Min(BSTNode<E, K>* ptr)const;										//递归：求最小
	BSTNode<E, K>* Max(BSTNode<E, K>* ptr)const;										//递归：求最大
	bool Insert(const E& e1, BSTNode<E, K>*& ptr);										//递归：插入
	bool non_recursive_Insert(const E& e1, BSTNode<E, K>*& ptr);
	bool Remove(const K x, BSTNode<E, K>*& ptr);										//递归：删除

	void WriteInFile(BSTNode<E, K>* ptr);
	
};

template<class E,class K>
BSTNode<E, K>* BST<E, K>::Serach(const K x, BSTNode<E, K>* ptr)const {						//私有递归函数：搜索，在以ptr为根的二树搜索树搜索含x的结点
																						//找到返回该结点的地址，否则返回NULL、
	if (ptr == NULL)return NULL;
	else if (x < ptr->data)return Serach(x, ptr->left);									//到左子树继续搜索
	else if (x > ptr->data)return Serach(x, ptr->right);								//到右子树继续搜索
	else return ptr;																	//搜索成功
}

template<class E, class K>
BSTNode<E, K>* BST<E, K>::non_recursive_Search(const K x, BSTNode<E, K>* ptr) const{					//非递归版本：在以ptr为根的二叉搜索树中搜索含x的结点。
																					//若找到，则函数返回该结点的地址，																						  //否则函数返回NULL值。
	if (ptr== NULL) return NULL; 
	BSTNode<E, K>* temp = ptr; //这里temp就是递归的参数
	while (temp != NULL) {
		if (x == temp->data) return temp;
		if (x < temp->data) temp = temp->left;
		else temp = temp->right;
	}
	return NULL;
};

template<class E ,class K>
bool BST<E, K>::Insert(const E& e1, BSTNode<E, K>*& ptr) {								//私有函数：插入；在以ptr为根的二叉搜索树插入含值为e1的结点
																						//若树中含有e1，则不再插入
	if (ptr == NULL) {
		ptr = new BSTNode<E, K>(e1);													//新结点作为叶子结点插入
		if (ptr == NULL) { cerr << "Out of space" << endl; exit(1); }
		return true;
	}
	else if (e1 < ptr->data)Insert(e1, ptr->left);										//左子树插入
	else if (e1 > ptr->data)Insert(e1, ptr->right);										//右子树插入
	else return false;																	//x在树中，不再插入
}

template<class E,class K>
bool BST<E, K>::non_recursive_Insert(const E& e1, BSTNode<E, K>*& ptr) {
	BSTNode<E, K>* temp = ptr; //这里temp就是递归的参数
	BSTNode<E, K>* temp1 = ptr;
	bool flag = true;
	while (temp!=NULL)
	{
		if (e1 < temp->data) {
			temp1 = temp; temp = temp->left;
			flag = true;
		}
		else if (e1 > temp->data) {
			temp1 = temp; temp = temp->right;
			flag = false;
		}
		else return false;
	}
	if (temp == NULL) {
		temp = new BSTNode<E, K>(e1);													//新结点作为叶子结点插入
		if (flag) {
			temp1->left = temp;
		}
		else temp1->right = temp;
		//if (temp == NULL) { cerr << "Out of space" << endl; exit(1); }
		return true;
	}
}

template<class E,class K>
BST<E, K>::BST(K value) {																//输入一个元素序列，建立一颗二叉搜索树
	E x; root = NULL; RefValue = value;													//置空树
	cin >> x;																			//输入数据
	while (x!=RefValue)																//输入结束标志
	{
		Insert(x, root);																//插入
		cin >> x;
	}
}

template<class E, class K>
void BST<E, K>::Cread(K value) {																//输入一个元素序列，建立一颗二叉搜索树
	E x; root = NULL; RefValue = value;													//置空树
	cin >> x;																			//输入数据
	while (x!= RefValue)																//输入结束标志
	{
		Insert(x, root);																//插入
		cin >> x;
	}
}

template<class E,class K>
bool BST<E, K>::Remove(const K x, BSTNode<E, K>*& ptr) {								//私有函数：在以ptr为根的二叉搜索树删除含x的结点
																						//若删除成功则新根通过ptr返回
	BSTNode<E, K>* temp;
	if (ptr != NULL) {
		if (x < ptr->data)Remove(x, ptr->left);											//在左子树中执行删除
		else if (x > ptr->data)Remove(x, ptr->right);									//在右子树中执行删除
		else if (ptr->left != NULL && ptr->right != NULL) {								//ptr指示关键码为x的结点，他有两个子女
			temp = ptr->right;															//到右子树搜索中序的下一个结点
			while (temp->left != NULL)temp = temp->left;
			ptr->data = temp->data;														//用该结点数据代替根结点数据
			Remove(ptr->data, ptr->right);
		}
		else {																			//ptr指示关键码为x的结点，他只有一个或零个子女
			temp = ptr;
			if (ptr->left == NULL)ptr = ptr->right;
			else ptr = ptr->left;
			delete temp;
			return true;
		}
	}
	else 
	return false;
}

template<class E,class K>
BST<E, K>&BST<E,K>::operator = (const BST<E, K>& R) {
	return R;
}

template<class E,class K>
BSTNode<E, K>* BST<E, K>::Min(BSTNode<E, K>* ptr)const {
	if (ptr->left != NULL)Min(ptr->left);
	else return ptr;
}

template<class E, class K>
BSTNode<E, K>* BST<E, K>::Max(BSTNode<E, K>* ptr)const {
	if (ptr->right != NULL)Min(ptr->right);
	else return ptr;
}

template<class E,class K>
void BST<E, K>::makeEmpty(BSTNode<E, K>*& ptr) {
	if (ptr != NULL) {
		makeEmpty(ptr->left);
		makeEmpty(ptr->right);
		delete ptr;
	}
}

template<class E,class K>
BSTNode<E, K>* BST<E, K>::Copy(const BSTNode<E, K>* ptr) {
	if (ptr == NULL)return NULL;
	BSTNode<E,K> *temp = new BSTNode<E, K>;
	temp->data = ptr->data;
	temp->left = Copy(ptr->left);
	temp->right = Copy(ptr->right);
	return temp;
}

template<class E,class K>
/**
 * 中序遍历返回节点数组
 * @param root 根节点
 * @return 中序遍历节点数组
 */
vector<BSTNode<E,K>*> BST<E,K>::inorderTraversal(BSTNode<E,K>* ptr) {
	vector<BSTNode<E,K>*> res;
	stack<BSTNode<E,K>*> stk;
	while (ptr != NULL || !stk.empty()) {
		while (ptr != NULL) {
			stk.push(ptr);
			ptr = ptr->left;
		}
		ptr = stk.top();
		stk.pop();
		res.push_back(ptr);
		ptr = ptr->right;
	}
	return res;
}

template<class E,class K>
void BST<E,K>::PrintTree(BSTNode<E,K>* ptr ,int level)const {
	int i;
	if (ptr) {
		PrintTree(ptr->right, level + 1);
		for (i = 0; i < level; i++) printf("     ");
		cout << ptr->data;
		if (ptr->left == NULL && ptr->right == NULL)cout<< endl;
		else cout << " <  "<< endl;
		PrintTree(ptr->left, level + 1);
	}
}



template<class E,class K>
void BST<E,K>::WriteInFile(BSTNode<E, K>* ptr) {
	FILE* fp;
	fp = fopen("BSTFile", "w+");
	BSTNode<E, K>* temp = ptr;
	stack<BSTNode<E, K>*>S;
	S.push(NULL);
	while(temp != NULL) {
		fprintf(fp, "%d ", temp->data);
		if (temp->right != NULL)S.push(temp->right);	//预留右子树指针在栈中												//访问结点
		if (temp->left != NULL)temp = temp->left;		//进左子树				
		else {
			temp = S.top(); S.pop();
		}										//若左子树为空
	}
	fclose(fp);
}

template<class E,class K>
void BST<E, K>::ReadoutFile() {
	FILE* fp;
	root = NULL;
	fp = fopen("BSTFile", "r+");
	char buf[1024] = { 0 };	
	int a[20] = { 0 };
	int i = 0,  x;
	while ((fscanf(fp, "%s", buf))!=EOF)
	{								
		cout << buf<<" ";
		x = atoi(buf);
		a[i++] = x;
	}
	cout << endl;
	BST<E, K>*b = new BST<E, K>;
	for (i = 0; a[i] != 0; i++) {
		b->Insert(a[i]);
		//cout << a[i] << " ";
	}
	b->PrintTree();
	fclose(fp);
}