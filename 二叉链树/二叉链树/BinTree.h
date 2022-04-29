#include <iostream>
#include <stdlib.h>
#include<list>
#include"LinkedQueue.h"
#include"LinkedStack.h"
#include<assert.h>
using namespace std;

template <class T>
struct BinTreeNode{                                                        //����������ඨ��
	T data;                                                                //������
	BinTreeNode<T>*leftChild,*rightChild;                                  //������Ů����
	BinTreeNode():leftChild(NULL),rightChild(NULL){};                      //���캯����������
	BinTreeNode(T x,BinTreeNode<T>*l=NULL,BinTreeNode<T>*r=NULL):data(x),leftChild(l),rightChild(r){};       //�����ݵĹ��캯��

	template<class T>
	friend bool equal(BinTreeNode<T>* a, BinTreeNode<T>* b) {
		if (a == NULL && b == NULL)return true;
		if (a != NULL && b != NULL && a->data == b->data && equal(a->leftChild, b->leftChild) && equal(a->rightChild, b->rightChild))
			return true;
		else return false;
	}
};

template <class T>
class BinaryTree{                                                          //�������ඨ��
	public:
		BinaryTree():root(NULL){}                                          //���캯��
		BinaryTree(T value):RefValue(value),root(NULL){}                   //���캯��
		BinaryTree(const BinaryTree<T>& s);                                  //���ƹ��캯��
		~BinaryTree() { destroy(root); }                                     //��������
		bool IsEmpty(){return (root==NULL)?true:false;}                      //�жϽ��շ�
		BinTreeNode<T>*Parent(BinTreeNode<T>*current){
			return (root==NULL||root==current)?NULL:Parent(root,current);     //���ظ����
		}
		BinTreeNode<T>*LeftChild(BinTreeNode<T>*current){
			return (current!=NULL)?current->leftChild:NULL;                   //��������Ů
		}
		BinTreeNode<T>*RightChild(BinTreeNode<T>*current){
			return (current!=NULL)?current->rightChild:NULL;                   //��������Ů
		}
		int Height(){return Height(root); }                                   //�������߶�
		int Size(){return Size(root);}                                        //���ؽ����
		int NodeCount() {return NodeCount(root);}								//ͳ�ƽ�����
		int LeafCount() {return LeafCount(root);}								//ͳ��Ҷ�ӽ��ĸ���
		void LeafShow(BinTreeNode<T>* subTree, list<T>& ls);
		BinTreeNode<T>*getRoot()const{return root;}                           //ȡ��
		BinTreeNode<T>* CreateBinaryTree(T* VLR, T* LVR, int n);				//����ǰ����������������
		void PrintTree(BinTreeNode<T>* subTree, int level = 0);							//��ֱ�۷�ʽ��ӡ������
		int find_node_level(BinTreeNode<T>* subTree, T& x, int h = 1);						//���Ҷ������н��ֵΪx�Ľ�����ڵĲ��
		void PrintAncestors(BinTreeNode<T>* subTree, T& x, void (*visit)(BinTreeNode<T>* p));//��ӡֵΪx������������
		int flag = 0; //����һ��ȫ�ֱ������ж��Ƿ���ҵ���ֵ


		//�ݹ�����㷨
		void preOrder(void (*visit)(BinTreeNode<T>*p)){preOrder(root,visit);}                    //ǰ�����
		void inOrder(void (*visit)(BinTreeNode<T>*p)){inOrder(root,visit);}                      //�������
		void postOrder(void (*visit)(BinTreeNode<T>*p)){postOrder(root,visit);}                  //�������

		void levelOrder(void (*visit)(BinTreeNode<T>* p));              //��������
		int Insert(const T item);                                             //������Ԫ��
		BinTreeNode<T>* Find(T item)const { Find(root, item);  };                                     //����

		void CreateBinTree(istream&in,BinTreeNode<T>*&subTree);               //���뽨��
		BinTreeNode<T>*root;                                                  //�������ĸ�ָ��
		T RefValue;															//���������ֹͣ��־
		void Traverse(BinTreeNode<T>*subTree,ostream&out);                       //ǰ��������

		//�ǵݹ�����㷨
		void preOrder_un_recursive(void (*visit)(BinTreeNode<T>* p)) { preOrder_un_recursive(root, visit); }                    //ǰ�����
		void inOrder_un_recursive(void (*visit)(BinTreeNode<T>* p)) { inOrder_un_recursive(root, visit); }                      //�������
		void postOrder_un_recursive(void (*visit)(BinTreeNode<T>* p)) { postOrder_un_recursive(root, visit); }                  //�������

		
	protected:
		bool Insert(BinTreeNode<T>*&subTree,const T&x);                       //����
		void destroy(BinTreeNode<T>*subTree);                                 //ɾ��
		bool Find(BinTreeNode<T>*& subTree, const T& x)const;                  //����
		BinTreeNode<T>*Copy(BinTreeNode<T>*orignode);                          //����
		int Height(BinTreeNode<T>*subTree);                                     //�������߶�
		int Size(BinTreeNode<T>*subTree);                                       //���ؽ����
		int NodeCount(BinTreeNode<T>* subTree);									//ͳ�ƽ�����
		int LeafCount(BinTreeNode<T>* subTree);									//ͳ��Ҷ�ӽ��ĸ���
		
		BinTreeNode<T>*Parent(BinTreeNode<T>*subTree,BinTreeNode<T>*current);   //���ظ����
		BinTreeNode<T>*Find(BinTreeNode<T>*subTree,const T&x)const;            //��Ѱx
		//�ݹ����
		void preOrder(BinTreeNode<T>*subTree,void(*visit)(BinTreeNode<T>*p));    //ǰ�����
		void inOrder(BinTreeNode<T>*subTree,void(*visit)(BinTreeNode<T>*p));     //�������
		void postOrder(BinTreeNode<T>*subTree,void(*visit)(BinTreeNode<T>*p));   //�������
		//�ǵݹ����
		void preOrder_un_recursive(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* p));                    //ǰ�����
		void inOrder_un_recursive(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* p));                     //�������
		void postOrder_un_recursive(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* p));                  //�������

public:
		friend istream & operator >> (istream&in,BinTreeNode<T>&Tree);             //���ز�������
		friend ostream & operator << (ostream&out,BinTreeNode<T>&Tree);           //���ز������

		friend bool operator ==(const BinaryTree<T>& s, const BinaryTree<T>& t) {
			return (equal(s.root, t.root)) ? true : false;
		}
};

template <class T>
void BinaryTree<T>::destroy(BinTreeNode<T>*subTree){                           //˽�к�����ɾ��sub������
	if(subTree!=NULL){
		destroy(subTree->leftChild);                                           //�ݹ�ɾ��������
		destroy(subTree->rightChild);
		delete subTree;                                                         //�ݹ�sub
	}
}

template <class T>
BinTreeNode<T>*BinaryTree<T>::Parent(BinTreeNode<T>*subTree,BinTreeNode<T>*current){            //˽�к�������sub��ʼ����curre�ĸ���㷵��
	if(subTree==NULL)return NULL;
	if (subTree->leftChild == current || subTree->rightChild == current)return subTree;         //�ҵ������ظ����sub
	BinTreeNode<T>* p;
	if ((p = Parent(subTree->leftChild, current)) != NULL)return p;                             //�ݹ�����������
	else return Parent(subTree->rightChild, current);                                           //�������ݹ�
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Find(BinTreeNode<T>* subTree, const T& x)const {
	if (subTree == NULL) return NULL;
	if (subTree->data == x)return subTree;
	BinTreeNode<T>* Lresult = Find(subTree->leftChild, x);
	BinTreeNode<T>* Rresult = Find(subTree->rightChild, x);
	//ʱ�临�Ӷ�ΪO(n),������������Ԫ�ض�������Ҳû�ҵ�
	//�ռ临�Ӷ�Ҳ��O(n)
	return Lresult == NULL ? Rresult : Lresult;
}

template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T>* subTree, ostream& out) {                             //˽�к���������sub�����������
	if (subTree != NULL) {
		out << subTree->data << ' ';                                                              //���subֵ
		Traverse(subTree->leftChild, out);                                                        //�ݹ��������������
		Traverse(subTree->rightChild, out); 
	}
}

template<class T>
istream& operator >> (istream& in, BinaryTree<T>& Tree) {                                        //���ز��������뽨��һ�Ŷ�����
	Tree.CreateBinTree(cin, Tree.root);                                                                //����
	return in;
}

template<class T>
ostream& operator << (ostream& out, BinaryTree<T>& Tree) {                                       //���ز��������������
	//out << "��������ǰ�����\n";
	//Tree.Traverse(Tree.root,out);                                                               //����������������ʼ
	out <<"�����ӡ��"<< endl<<endl;
	Tree.PrintTree(Tree.root);
	out << endl;
	return out;
}

//�ݹ�����㷨
template<class T>
void BinaryTree<T>::preOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* p)) {    //�ݹ麯����ǰ�����
	if (subTree != NULL) {																	//�ݹ��������
		visit(subTree);                                                                     //���ʸ����
		preOrder(subTree->leftChild, visit);                                                 //ǰ�����������
		preOrder(subTree->rightChild, visit);												//ǰ�����������
	}
}

template<class T>
void BinaryTree<T>::inOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* p)) {     //�ݹ麯����������
	if (subTree != NULL) {
		inOrder(subTree->leftChild, visit);
		visit(subTree);
		inOrder(subTree->rightChild, visit);
	}
}

template<class T>
void BinaryTree<T>::postOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* p)) {   //�ݹ麯����������
	if (subTree != NULL) {
		postOrder(subTree->leftChild, visit);
		postOrder(subTree->rightChild, visit);
		visit(subTree);
	}
}

template<class T>
int BinaryTree<T>::Size(BinTreeNode<T>* subTree){											//˽�к���������subΪ��������������
	if (subTree == NULL)return 0;                                                            //�ݹ�������ս��Ϊ0
	else return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}

template <class T>
int BinaryTree<T>::Height(BinTreeNode<T>* subTree) {										//����subΪ���������߶�
	if (subTree == NULL)return 0;                                                           //�ݹ�����������߶�Ϊ0
	else {
		return max(Height(subTree->leftChild), Height(subTree->rightChild)) + 1;
	}
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& s) {												//���к��������ƹ��캯��
	root = Copy(s.root);
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Copy(BinTreeNode<T>* orignode) {								//˽�к���������ָ�룬һoriΪ���Ķ�����
	if (orignode == NULL)return NULL;														//��Ϊ�գ����ؿ�
	BinTreeNode<T> * temp = new BinTreeNode<T>;												//�����½��
	temp->data = orignode->data;															//��������
	temp->leftChild = Copy(orignode->leftChild);											//����������
	temp->rightChild = Copy(orignode->rightChild);											//����������
	return temp;																			//���ظ�ָ��
}

template<class T>
void BinaryTree<T> ::CreateBinTree(istream& in, BinTreeNode<T>*& subTree) {                //˽�к������Եݹ鷽ʽ����������
	T item;
	if (!in.eof()) {																		//δ���꣬���벢����
		in >> item;																			//��������ֵ
		if (item != RefValue) {
			subTree = new BinTreeNode<T>(item);												//���������
			if (subTree == NULL) {
				cerr << "�ڴ�������" << endl;
				exit(1);
			}
			CreateBinTree(in, subTree->leftChild);											//�ݹ齨��������
			CreateBinTree(in, subTree->rightChild);											//�ݹ齨��������
		}
		else subTree = NULL;																	//���ָ���������ָ��
	}
}

template<class T>
int BinaryTree<T>::NodeCount(BinTreeNode<T>* subTree) {
	//ͳ�ƶ������н��ĸ���
	if (subTree == NULL) return 0;
	else return NodeCount(subTree->leftChild) + NodeCount(subTree->rightChild) + 1;
}

template<class T>
int BinaryTree<T>::LeafCount(BinTreeNode<T>* subTree) {
	//ͳ�ƶ�������Ҷ�ӽ��ĸ���
	if (!subTree) return 0;
	if (!subTree->leftChild&& !subTree->rightChild) {//�������������������������Ϊ��,˵���ö��������ڵ�ΪҶ�ӽڵ�,��1.
		return 1;
	}
	else {
		return LeafCount(subTree->leftChild) + LeafCount(subTree->rightChild);
	}
	
}

//�ǵݹ�����㷨
template<class T>
void BinaryTree<T>::preOrder_un_recursive(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* p)) {		//ǰ�����
	LinkedStack<BinTreeNode<T>*>S;
	BinTreeNode<T>* p = root;										//��ʼ��
	S.Push(NULL);
	while (p!=NULL)
	{
		visit(p);
		if (p->rightChild != NULL)S.Push(p->rightChild);	//Ԥ��������ָ����ջ��												//���ʽ��
		if (p->leftChild != NULL)p = p->leftChild;		//��������				
		else S.Pop(p);										//��������Ϊ��
	}
}

template<class T>
void BinaryTree<T>::inOrder_un_recursive(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* p)) {		//�������
	LinkedStack<BinTreeNode<T>*>S;
	BinTreeNode<T>* p = root;										//��ʼ��,��ָ�����
	do {
		while (p!=NULL)												//����ָ��δ�������µĽ�㣬����
		{
			S.Push(p);												//��������;����ջ
			p = p->leftChild;										//����ָ���������Ů���
		}
		if (!S.IsEmpty()) {											//ջ����ʱ��ջ
			S.Pop(p);												//��ջ
			visit(p);												//���ʸ����
			p = p->rightChild;										//����ָ���������Ů���
		}
	} while (p != NULL || !S.IsEmpty());
}

template<class T>
struct stkNode														//����ʱ����ջ�����ඨ��
{
	BinTreeNode<T>* ptr;											//ָ��������ָ��
	//enum tag{L,R}tag;													//�ý����ջ���
	int tag;														//1 L,2 R;
	stkNode(BinTreeNode<T>* N = NULL) :ptr(N), tag(1) {}			//���캯��
};

template<class T>
void BinaryTree<T>::postOrder_un_recursive(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* p)) {
	LinkedStack<stkNode<T>>S;
	stkNode<T>W;
	BinTreeNode<T>* p = root;										//p�Ǳ���ָ��
	do {
		while (p!=NULL)												//��������������L��ջ
		{
			W.ptr = p; W.tag = 1; S.Push(W);
			p = p->leftChild;										//�������½������ȥ
		}
		int continue1 = 1;											//����ѭ����ǣ�����R
		while (continue1&&!S.IsEmpty())
		{
			S.Pop(W); p = W.ptr;									//ջ���գ���ջ
			switch (W.tag)											//�ж�ջ����tag���
			{
			case 1:													//���������˻أ��޸�ջ��tag
				W.tag = 2; S.Push(W);
				continue1 = 0;
				p = p->rightChild;									//��������������ȥ
				break;
			case 2:
				visit(p); break;									//���������˻أ����ʸ����
			}
		}
	} while (!S.IsEmpty());											//���н��δ����������ѭ��
	//cout << endl;
}

template<class T>
void BinaryTree<T>::levelOrder(void (*visit)(BinTreeNode<T>* p)) {		//��������
	LinkedQueue<BinTreeNode<T>*>Q;
	BinTreeNode<T>* p = root;
	BinTreeNode<T>* last = root;										//��ǰ�����һ����ʼֵ��root
	BinTreeNode<T>* nlast=NULL;												//��һ�е����һ�����
	Q.EnQueue(p);
	while (!Q.IsEmpty())													//���в���
	{
		Q.DeQueue(p); visit(p);									//�˳�һ����㣬����
		if (p->leftChild != NULL) {
			Q.EnQueue(p->leftChild);	nlast = p->leftChild;
		}				//����Ů����
		if (p->rightChild != NULL) {
			Q.EnQueue(p->rightChild); nlast = p->rightChild;
		}				//����Ů����

		if (p == last) {
			cout <<endl;
			last = nlast;
		}
	}
}

template<class T>
//��ֱ�۷�ʽ��ӡ������
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
//���Ҷ������н��ֵΪx�Ľ�����ڵĲ��
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

//��ӡֵΪx������������
template<class T>
void BinaryTree<T>::PrintAncestors(BinTreeNode<T>* subTree, T& x, void (*visit)(BinTreeNode<T>* p)) {
	if (!subTree)
		return;
	if (subTree->data == x) {
		flag = 1; //��ѯ��ֵ��ʱ�� �ı��־λ
		return;
	}
	if (flag == 0)
		PrintAncestors(subTree->leftChild, x, visit); //��û�в��ҵ����ڵ��������
	if (flag == 0)
		PrintAncestors(subTree->rightChild, x, visit);//��û�в��ҵ����ڵ���Ҳ����
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
BinTreeNode<T>* BinaryTree<T>::CreateBinaryTree(T* VLR, T* LVR, int n) {			//����������㷨
	if (n <= 0)return NULL;															//n�շ��ؿ�
	int k = 0;
	while (VLR[0] != LVR[k])k++;													//����ǰ���ҵ�����ĸ����
	BinTreeNode<T>* t = new BinTreeNode<T>(VLR[0]);									//���������
	t->leftChild = CreateBinaryTree(VLR + 1, LVR, k);								//�ݹ�������ӽڵ�
	t->rightChild = CreateBinaryTree(VLR + k + 1, LVR + k + 1, n - k - 1);			//�ݹ�����Һ��ӽ��
	return t;																		//����һ����
}