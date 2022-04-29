#pragma once
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<string>
#include<queue>



using namespace std;

template<class E,class K>
struct BSTNode																			//�������ڵ���
{		
	E data;																				//������
	BSTNode<E, K>* left, * right;														//������Ů
	BSTNode() :left(NULL), right(NULL) {};												//���캯��
	BSTNode(const E d, BSTNode<E, K>* L = NULL, BSTNode<E, K>* R = NULL) :data(d), left(L), right(R) {};//���캯��
	~BSTNode() {};																			//��������
	void setData(E d) { data = d; };														//�޸�
	bool operator <(const E& x) { return (data < x) ? true: false; }			//���أ�Ԫ�ؼ�С��
	bool operator >(const E& x) { return (data > x) ? true: false; }			//���أ�Ԫ�ؼ����
	bool operator ==(const E& x) { return (data == x) ? true: false; }			//���أ�Ԫ�ؼ����
};

template<class E,class K>
class BST																				//�����������ඨ��
{
public:

	BST() :root(NULL) {};																//���캯��
	BST(K value);																		//���캯��
	void Cread(K value);
	~BST() {};																			//��������
	bool Serach(const K x)const { return (Serach(x, root) != NULL) ? true:false; }		//����
	bool non_recursive_Search(const K x)const { return non_recursive_Search(x, root) != NULL ? true : false; }		//�ǵݹ�����
	BST<E, K>& operator = (const BST<E, K>& R);										//���أ���ֵ
	void makeEmpty() { makeEmpty(root); root = NULL; }									//�ÿ�
	void PrintTree()const { PrintTree(root); }											//���
	E Min() { return (Min(root)->data); }												//����С
	E Max() { return (Max(root)->data); }												//�����
	bool Insert(const E& e1) { return Insert(e1, root); }								//������Ԫ��
	bool non_recursive_Insert(const E& e1) { return non_recursive_Insert(e1, root); }
	bool Remove(const K x) { return Remove(x, root); }									//ɾ����x���
	vector<BSTNode<E, K>*> inorderTraversal( BSTNode<E,K>* ptr);
	void WriteInFile() { WriteInFile(root);}
	void ReadoutFile();
private:
	BSTNode<E, K>* root;																//�����������ĸ����ָ��
	K RefValue;																			//����ֹͣ��־����������
	BSTNode<E, K>* Serach(const K x, BSTNode<E, K>* ptr)const;								//�ݹ飺����
	BSTNode<E, K>* non_recursive_Search(const K x, BSTNode<E, K>* ptr)const;
	void makeEmpty(BSTNode<E, K>*& ptr);												//�ݹ飺�ÿ�
	void PrintTree(BSTNode<E, K>* ptr,int level=0)const;											//�ݹ飺���
	BSTNode<E, K>* Copy(const BSTNode<E, K>* ptr);										//�ݹ飺����
	BSTNode<E, K>* Min(BSTNode<E, K>* ptr)const;										//�ݹ飺����С
	BSTNode<E, K>* Max(BSTNode<E, K>* ptr)const;										//�ݹ飺�����
	bool Insert(const E& e1, BSTNode<E, K>*& ptr);										//�ݹ飺����
	bool non_recursive_Insert(const E& e1, BSTNode<E, K>*& ptr);
	bool Remove(const K x, BSTNode<E, K>*& ptr);										//�ݹ飺ɾ��

	void WriteInFile(BSTNode<E, K>* ptr);
	
};

template<class E,class K>
BSTNode<E, K>* BST<E, K>::Serach(const K x, BSTNode<E, K>* ptr)const {						//˽�еݹ麯��������������ptrΪ���Ķ���������������x�Ľ��
																						//�ҵ����ظý��ĵ�ַ�����򷵻�NULL��
	if (ptr == NULL)return NULL;
	else if (x < ptr->data)return Serach(x, ptr->left);									//����������������
	else if (x > ptr->data)return Serach(x, ptr->right);								//����������������
	else return ptr;																	//�����ɹ�
}

template<class E, class K>
BSTNode<E, K>* BST<E, K>::non_recursive_Search(const K x, BSTNode<E, K>* ptr) const{					//�ǵݹ�汾������ptrΪ���Ķ�����������������x�Ľ�㡣
																					//���ҵ����������ظý��ĵ�ַ��																						  //����������NULLֵ��
	if (ptr== NULL) return NULL; 
	BSTNode<E, K>* temp = ptr; //����temp���ǵݹ�Ĳ���
	while (temp != NULL) {
		if (x == temp->data) return temp;
		if (x < temp->data) temp = temp->left;
		else temp = temp->right;
	}
	return NULL;
};

template<class E ,class K>
bool BST<E, K>::Insert(const E& e1, BSTNode<E, K>*& ptr) {								//˽�к��������룻����ptrΪ���Ķ������������뺬ֵΪe1�Ľ��
																						//�����к���e1�����ٲ���
	if (ptr == NULL) {
		ptr = new BSTNode<E, K>(e1);													//�½����ΪҶ�ӽ�����
		if (ptr == NULL) { cerr << "Out of space" << endl; exit(1); }
		return true;
	}
	else if (e1 < ptr->data)Insert(e1, ptr->left);										//����������
	else if (e1 > ptr->data)Insert(e1, ptr->right);										//����������
	else return false;																	//x�����У����ٲ���
}

template<class E,class K>
bool BST<E, K>::non_recursive_Insert(const E& e1, BSTNode<E, K>*& ptr) {
	BSTNode<E, K>* temp = ptr; //����temp���ǵݹ�Ĳ���
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
		temp = new BSTNode<E, K>(e1);													//�½����ΪҶ�ӽ�����
		if (flag) {
			temp1->left = temp;
		}
		else temp1->right = temp;
		//if (temp == NULL) { cerr << "Out of space" << endl; exit(1); }
		return true;
	}
}

template<class E,class K>
BST<E, K>::BST(K value) {																//����һ��Ԫ�����У�����һ�Ŷ���������
	E x; root = NULL; RefValue = value;													//�ÿ���
	cin >> x;																			//��������
	while (x!=RefValue)																//���������־
	{
		Insert(x, root);																//����
		cin >> x;
	}
}

template<class E, class K>
void BST<E, K>::Cread(K value) {																//����һ��Ԫ�����У�����һ�Ŷ���������
	E x; root = NULL; RefValue = value;													//�ÿ���
	cin >> x;																			//��������
	while (x!= RefValue)																//���������־
	{
		Insert(x, root);																//����
		cin >> x;
	}
}

template<class E,class K>
bool BST<E, K>::Remove(const K x, BSTNode<E, K>*& ptr) {								//˽�к���������ptrΪ���Ķ���������ɾ����x�Ľ��
																						//��ɾ���ɹ����¸�ͨ��ptr����
	BSTNode<E, K>* temp;
	if (ptr != NULL) {
		if (x < ptr->data)Remove(x, ptr->left);											//����������ִ��ɾ��
		else if (x > ptr->data)Remove(x, ptr->right);									//����������ִ��ɾ��
		else if (ptr->left != NULL && ptr->right != NULL) {								//ptrָʾ�ؼ���Ϊx�Ľ�㣬����������Ů
			temp = ptr->right;															//�������������������һ�����
			while (temp->left != NULL)temp = temp->left;
			ptr->data = temp->data;														//�øý�����ݴ�����������
			Remove(ptr->data, ptr->right);
		}
		else {																			//ptrָʾ�ؼ���Ϊx�Ľ�㣬��ֻ��һ���������Ů
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
 * ����������ؽڵ�����
 * @param root ���ڵ�
 * @return ��������ڵ�����
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
		if (temp->right != NULL)S.push(temp->right);	//Ԥ��������ָ����ջ��												//���ʽ��
		if (temp->left != NULL)temp = temp->left;		//��������				
		else {
			temp = S.top(); S.pop();
		}										//��������Ϊ��
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