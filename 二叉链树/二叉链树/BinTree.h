#include <iostream>
#include <stdlib.h>
#include<list>
#include"LinkedQueue.h"
#include"LinkedStack.h"
#include<assert.h>
using namespace std;

template <class T>
struct BinTreeNode{                                                        //二叉树结点类定义
	T data;                                                                //数据域
	BinTreeNode<T>*leftChild,*rightChild;                                  //左右子女链域
	BinTreeNode():leftChild(NULL),rightChild(NULL){};                      //构造函数不含数据
	BinTreeNode(T x,BinTreeNode<T>*l=NULL,BinTreeNode<T>*r=NULL):data(x),leftChild(l),rightChild(r){};       //含数据的构造函数

	template<class T>
	friend bool equal(BinTreeNode<T>* a, BinTreeNode<T>* b) {
		if (a == NULL && b == NULL)return true;
		if (a != NULL && b != NULL && a->data == b->data && equal(a->leftChild, b->leftChild) && equal(a->rightChild, b->rightChild))
			return true;
		else return false;
	}
};

template <class T>
class BinaryTree{                                                          //二叉树类定义
	public:
		BinaryTree():root(NULL){}                                          //构造函数
		BinaryTree(T value):RefValue(value),root(NULL){}                   //构造函数
		BinaryTree(const BinaryTree<T>& s);                                  //复制构造函数
		~BinaryTree() { destroy(root); }                                     //析构函数
		bool IsEmpty(){return (root==NULL)?true:false;}                      //判断结点空否
		BinTreeNode<T>*Parent(BinTreeNode<T>*current){
			return (root==NULL||root==current)?NULL:Parent(root,current);     //返回父结点
		}
		BinTreeNode<T>*LeftChild(BinTreeNode<T>*current){
			return (current!=NULL)?current->leftChild:NULL;                   //返回左子女
		}
		BinTreeNode<T>*RightChild(BinTreeNode<T>*current){
			return (current!=NULL)?current->rightChild:NULL;                   //返回右子女
		}
		int Height(){return Height(root); }                                   //返回树高度
		int Size(){return Size(root);}                                        //返回结点数
		int NodeCount() {return NodeCount(root);}								//统计结点个数
		int LeafCount() {return LeafCount(root);}								//统计叶子结点的个数
		void LeafShow(BinTreeNode<T>* subTree, list<T>& ls);
		BinTreeNode<T>*getRoot()const{return root;}                           //取根
		BinTreeNode<T>* CreateBinaryTree(T* VLR, T* LVR, int n);				//根据前序和中序构造二叉树。
		void PrintTree(BinTreeNode<T>* subTree, int level = 0);							//以直观方式打印二叉树
		int find_node_level(BinTreeNode<T>* subTree, T& x, int h = 1);						//查找二叉树中结点值为x的结点所在的层次
		void PrintAncestors(BinTreeNode<T>* subTree, T& x, void (*visit)(BinTreeNode<T>* p));//打印值为x结点的所有祖先
		int flag = 0; //定义一个全局变量来判断是否查找到了值


		//递归遍历算法
		void preOrder(void (*visit)(BinTreeNode<T>*p)){preOrder(root,visit);}                    //前序遍历
		void inOrder(void (*visit)(BinTreeNode<T>*p)){inOrder(root,visit);}                      //中序遍历
		void postOrder(void (*visit)(BinTreeNode<T>*p)){postOrder(root,visit);}                  //后序遍历

		void levelOrder(void (*visit)(BinTreeNode<T>* p));              //层次序遍历
		int Insert(const T item);                                             //插入新元素
		BinTreeNode<T>* Find(T item)const { Find(root, item);  };                                     //搜索

		void CreateBinTree(istream&in,BinTreeNode<T>*&subTree);               //读入建树
		BinTreeNode<T>*root;                                                  //二叉树的根指针
		T RefValue;															//数据输入的停止标志
		void Traverse(BinTreeNode<T>*subTree,ostream&out);                       //前序遍历输出

		//非递归遍历算法
		void preOrder_un_recursive(void (*visit)(BinTreeNode<T>* p)) { preOrder_un_recursive(root, visit); }                    //前序遍历
		void inOrder_un_recursive(void (*visit)(BinTreeNode<T>* p)) { inOrder_un_recursive(root, visit); }                      //中序遍历
		void postOrder_un_recursive(void (*visit)(BinTreeNode<T>* p)) { postOrder_un_recursive(root, visit); }                  //后序遍历

		
	protected:
		bool Insert(BinTreeNode<T>*&subTree,const T&x);                       //插入
		void destroy(BinTreeNode<T>*subTree);                                 //删除
		bool Find(BinTreeNode<T>*& subTree, const T& x)const;                  //查找
		BinTreeNode<T>*Copy(BinTreeNode<T>*orignode);                          //复制
		int Height(BinTreeNode<T>*subTree);                                     //返回树高度
		int Size(BinTreeNode<T>*subTree);                                       //返回结点数
		int NodeCount(BinTreeNode<T>* subTree);									//统计结点个数
		int LeafCount(BinTreeNode<T>* subTree);									//统计叶子结点的个数
		
		BinTreeNode<T>*Parent(BinTreeNode<T>*subTree,BinTreeNode<T>*current);   //返回父结点
		BinTreeNode<T>*Find(BinTreeNode<T>*subTree,const T&x)const;            //搜寻x
		//递归遍历
		void preOrder(BinTreeNode<T>*subTree,void(*visit)(BinTreeNode<T>*p));    //前序遍历
		void inOrder(BinTreeNode<T>*subTree,void(*visit)(BinTreeNode<T>*p));     //中序遍历
		void postOrder(BinTreeNode<T>*subTree,void(*visit)(BinTreeNode<T>*p));   //后序遍历
		//非递归遍历
		void preOrder_un_recursive(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* p));                    //前序遍历
		void inOrder_un_recursive(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* p));                     //中序遍历
		void postOrder_un_recursive(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* p));                  //后序遍历

public:
		friend istream & operator >> (istream&in,BinTreeNode<T>&Tree);             //重载操作输入
		friend ostream & operator << (ostream&out,BinTreeNode<T>&Tree);           //重载操作输出

		friend bool operator ==(const BinaryTree<T>& s, const BinaryTree<T>& t) {
			return (equal(s.root, t.root)) ? true : false;
		}
};

template <class T>
void BinaryTree<T>::destroy(BinTreeNode<T>*subTree){                           //私有函数，删除sub根子树
	if(subTree!=NULL){
		destroy(subTree->leftChild);                                           //递归删除左子树
		destroy(subTree->rightChild);
		delete subTree;                                                         //递归sub
	}
}

template <class T>
BinTreeNode<T>*BinaryTree<T>::Parent(BinTreeNode<T>*subTree,BinTreeNode<T>*current){            //私有函数，从sub开始搜索curre的父结点返回
	if(subTree==NULL)return NULL;
	if (subTree->leftChild == current || subTree->rightChild == current)return subTree;         //找到，返回父结点sub
	BinTreeNode<T>* p;
	if ((p = Parent(subTree->leftChild, current)) != NULL)return p;                             //递归在左子树找
	else return Parent(subTree->rightChild, current);                                           //右子树递归
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Find(BinTreeNode<T>* subTree, const T& x)const {
	if (subTree == NULL) return NULL;
	if (subTree->data == x)return subTree;
	BinTreeNode<T>* Lresult = Find(subTree->leftChild, x);
	BinTreeNode<T>* Rresult = Find(subTree->rightChild, x);
	//时间复杂度为O(n),最坏的情况是所有元素都遍历了也没找到
	//空间复杂度也是O(n)
	return Lresult == NULL ? Rresult : Lresult;
}

template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T>* subTree, ostream& out) {                             //私有函数，搜索sub并输出二叉树
	if (subTree != NULL) {
		out << subTree->data << ' ';                                                              //输出sub值
		Traverse(subTree->leftChild, out);                                                        //递归搜索输出左子树
		Traverse(subTree->rightChild, out); 
	}
}

template<class T>
istream& operator >> (istream& in, BinaryTree<T>& Tree) {                                        //重载操作，输入建立一颗二叉树
	Tree.CreateBinTree(cin, Tree.root);                                                                //建立
	return in;
}

template<class T>
ostream& operator << (ostream& out, BinaryTree<T>& Tree) {                                       //重载操作，输出二叉树
	//out << "二叉树的前序遍历\n";
	//Tree.Traverse(Tree.root,out);                                                               //搜索二叉树，根开始
	out <<"横向打印："<< endl<<endl;
	Tree.PrintTree(Tree.root);
	out << endl;
	return out;
}

//递归遍历算法
template<class T>
void BinaryTree<T>::preOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* p)) {    //递归函数，前序遍历
	if (subTree != NULL) {																	//递归结束条件
		visit(subTree);                                                                     //访问根结点
		preOrder(subTree->leftChild, visit);                                                 //前序遍历左子树
		preOrder(subTree->rightChild, visit);												//前序遍历右子树
	}
}

template<class T>
void BinaryTree<T>::inOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* p)) {     //递归函数，中序函数
	if (subTree != NULL) {
		inOrder(subTree->leftChild, visit);
		visit(subTree);
		inOrder(subTree->rightChild, visit);
	}
}

template<class T>
void BinaryTree<T>::postOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* p)) {   //递归函数，后序函数
	if (subTree != NULL) {
		postOrder(subTree->leftChild, visit);
		postOrder(subTree->rightChild, visit);
		visit(subTree);
	}
}

template<class T>
int BinaryTree<T>::Size(BinTreeNode<T>* subTree){											//私有函数，计算sub为根二叉树结点个数
	if (subTree == NULL)return 0;                                                            //递归结束，空结点为0
	else return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}

template <class T>
int BinaryTree<T>::Height(BinTreeNode<T>* subTree) {										//计算sub为根二叉树高度
	if (subTree == NULL)return 0;                                                           //递归结束，空数高度为0
	else {
		return max(Height(subTree->leftChild), Height(subTree->rightChild)) + 1;
	}
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& s) {												//公有函数，复制构造函数
	root = Copy(s.root);
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Copy(BinTreeNode<T>* orignode) {								//私有函数，返回指针，一ori为根的二叉树
	if (orignode == NULL)return NULL;														//根为空，返回空
	BinTreeNode<T> * temp = new BinTreeNode<T>;												//创建新结点
	temp->data = orignode->data;															//传送数据
	temp->leftChild = Copy(orignode->leftChild);											//复制左子树
	temp->rightChild = Copy(orignode->rightChild);											//复制右子树
	return temp;																			//返回根指针
}

template<class T>
void BinaryTree<T> ::CreateBinTree(istream& in, BinTreeNode<T>*& subTree) {                //私有函数，以递归方式建立二叉树
	T item;
	if (!in.eof()) {																		//未读完，读入并建树
		in >> item;																			//读入根结点值
		if (item != RefValue) {
			subTree = new BinTreeNode<T>(item);												//建立根结点
			if (subTree == NULL) {
				cerr << "内存分配错误！" << endl;
				exit(1);
			}
			CreateBinTree(in, subTree->leftChild);											//递归建立左子树
			CreateBinTree(in, subTree->rightChild);											//递归建立右子树
		}
		else subTree = NULL;																	//封闭指向空子树的指针
	}
}

template<class T>
int BinaryTree<T>::NodeCount(BinTreeNode<T>* subTree) {
	//统计二叉树中结点的个数
	if (subTree == NULL) return 0;
	else return NodeCount(subTree->leftChild) + NodeCount(subTree->rightChild) + 1;
}

template<class T>
int BinaryTree<T>::LeafCount(BinTreeNode<T>* subTree) {
	//统计二叉树中叶子结点的个数
	if (!subTree) return 0;
	if (!subTree->leftChild&& !subTree->rightChild) {//如果二叉树左子树和右子树皆为空,说明该二叉树根节点为叶子节点,加1.
		return 1;
	}
	else {
		return LeafCount(subTree->leftChild) + LeafCount(subTree->rightChild);
	}
	
}

//非递归遍历算法
template<class T>
void BinaryTree<T>::preOrder_un_recursive(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* p)) {		//前序遍历
	LinkedStack<BinTreeNode<T>*>S;
	BinTreeNode<T>* p = root;										//初始化
	S.Push(NULL);
	while (p!=NULL)
	{
		visit(p);
		if (p->rightChild != NULL)S.Push(p->rightChild);	//预留右子树指针在栈中												//访问结点
		if (p->leftChild != NULL)p = p->leftChild;		//进左子树				
		else S.Pop(p);										//若左子树为空
	}
}

template<class T>
void BinaryTree<T>::inOrder_un_recursive(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* p)) {		//中序遍历
	LinkedStack<BinTreeNode<T>*>S;
	BinTreeNode<T>* p = root;										//初始化,根指针遍历
	do {
		while (p!=NULL)												//遍历指针未到最左下的结点，不空
		{
			S.Push(p);												//该子树沿途结点进栈
			p = p->leftChild;										//遍历指针进到左子女结点
		}
		if (!S.IsEmpty()) {											//栈不空时退栈
			S.Pop(p);												//退栈
			visit(p);												//访问根结点
			p = p->rightChild;										//遍历指针进到右子女结点
		}
	} while (p != NULL || !S.IsEmpty());
}

template<class T>
struct stkNode														//遍历时所用栈结点的类定义
{
	BinTreeNode<T>* ptr;											//指向树结点的指针
	//enum tag{L,R}tag;													//该结点退栈标记
	int tag;														//1 L,2 R;
	stkNode(BinTreeNode<T>* N = NULL) :ptr(N), tag(1) {}			//构造函数
};

template<class T>
void BinaryTree<T>::postOrder_un_recursive(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* p)) {
	LinkedStack<stkNode<T>>S;
	stkNode<T>W;
	BinTreeNode<T>* p = root;										//p是遍历指针
	do {
		while (p!=NULL)												//左子树经过结点加L进栈
		{
			W.ptr = p; W.tag = 1; S.Push(W);
			p = p->leftChild;										//往最左下结点做下去
		}
		int continue1 = 1;											//继续循环标记，用于R
		while (continue1&&!S.IsEmpty())
		{
			S.Pop(W); p = W.ptr;									//栈不空，退栈
			switch (W.tag)											//判断栈顶的tag标记
			{
			case 1:													//从左子树退回，修改栈顶tag
				W.tag = 2; S.Push(W);
				continue1 = 0;
				p = p->rightChild;									//从右子树遍历下去
				break;
			case 2:
				visit(p); break;									//从右子树退回，访问根结点
			}
		}
	} while (!S.IsEmpty());											//还有结点未遍历，继续循环
	//cout << endl;
}

template<class T>
void BinaryTree<T>::levelOrder(void (*visit)(BinTreeNode<T>* p)) {		//层次序遍历
	LinkedQueue<BinTreeNode<T>*>Q;
	BinTreeNode<T>* p = root;
	BinTreeNode<T>* last = root;										//当前行最后一个初始值，root
	BinTreeNode<T>* nlast=NULL;												//下一行的最后一个结点
	Q.EnQueue(p);
	while (!Q.IsEmpty())													//队列不空
	{
		Q.DeQueue(p); visit(p);									//退出一个结点，访问
		if (p->leftChild != NULL) {
			Q.EnQueue(p->leftChild);	nlast = p->leftChild;
		}				//左子女进队
		if (p->rightChild != NULL) {
			Q.EnQueue(p->rightChild); nlast = p->rightChild;
		}				//右子女进队

		if (p == last) {
			cout <<endl;
			last = nlast;
		}
	}
}

template<class T>
//以直观方式打印二叉树
void BinaryTree<T>::PrintTree(BinTreeNode<T>* subTree, int level )
{
	int i;
	if (subTree) {
		PrintTree(subTree->rightChild, level + 1);
		for (i = 0; i < level; i++) printf("   ");
		cout << subTree->data << endl;
		PrintTree(subTree->leftChild, level + 1);
	}
}

template<class T>
//查找二叉树中结点值为x的结点所在的层次
int BinaryTree<T>::find_node_level(BinTreeNode<T>* subTree, T& x, int h )
{
	if (subTree == NULL)
		return 0;
	else if (subTree->data == x)
		return h;
	else
	{
		int l = find_node_level(subTree->leftChild, x, h + 1);
		if (l != 0)
			return l;
		else
			return find_node_level(subTree->rightChild, x, h + 1);
	}
}

//打印值为x结点的所有祖先
template<class T>
void BinaryTree<T>::PrintAncestors(BinTreeNode<T>* subTree, T& x, void (*visit)(BinTreeNode<T>* p)) {
	if (!subTree)
		return;
	if (subTree->data == x) {
		flag = 1; //查询到值的时候 改变标志位
		return;
	}
	if (flag == 0)
		PrintAncestors(subTree->leftChild, x, visit); //若没有查找到往节点的左侧查找
	if (flag == 0)
		PrintAncestors(subTree->rightChild, x, visit);//若没有查找到往节点的右侧查找
	if (flag == 1)
		visit(subTree);
}

template<class T>
void sowp(BinTreeNode<T>* p) {
	BinTreeNode<T>* temp = new BinTreeNode<T>;
	if (temp == NULL)assert(0);
	else {
		temp = p->leftChild;
		p->leftChild = p->rightChild;
		p->rightChild = temp;
	}
}

template<class T>
void BinaryTree<T>::LeafShow(BinTreeNode<T>* subTree, list<T>& ls) {
	if (!subTree)return;
	if (!subTree->leftChild && !subTree->rightChild) {
		ls.push_back(subTree->data);
	}
	else {
		LeafShow(subTree->leftChild, ls);
		LeafShow(subTree->rightChild, ls);
	}
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::CreateBinaryTree(T* VLR, T* LVR, int n) {			//构造二叉树算法
	if (n <= 0)return NULL;															//n空返回空
	int k = 0;
	while (VLR[0] != LVR[k])k++;													//根据前序找到中序的根结点
	BinTreeNode<T>* t = new BinTreeNode<T>(VLR[0]);									//创建根结点
	t->leftChild = CreateBinaryTree(VLR + 1, LVR, k);								//递归遍历左孩子节点
	t->rightChild = CreateBinaryTree(VLR + k + 1, LVR + k + 1, n - k - 1);			//递归遍历右孩子结点
	return t;																		//返回一颗树
}