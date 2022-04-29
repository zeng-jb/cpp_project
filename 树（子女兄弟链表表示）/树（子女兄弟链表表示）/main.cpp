//#include<iostream>
//#include"Tree.h"
//using namespace std;
//void main() {
//	Tree<char> CSTree;
//	cout << "��������" << endl;
//	CSTree.ClearTree();
//	cout << "ǰ�����" << endl;
//	CSTree.preOrder();
//	
//}

#include<iostream>
#include"Tree.h"
using namespace std;
int main()
{
	/* ----���Ը�ֵ����
	CSTree<char> csTree;
	CSTree<char> csTree1;
	cout<<"����������##��ʾ����:"<<endl;
	csTree1.createCSTree();
	csTree = csTree1;//���ø�ֵ����
	*/

	//���Ը�ֵ���캯��

	CSTree<char> csTree1;
	cout << "����������##��ʾ����:" << endl;
	csTree1.createCSTree();
	CSTree<char> csTree = csTree1;//���ÿ������캯��

	//---һ�����
	cout << "�������Ϊ:";
	csTree.preOrderTraverse();
	cout << "�������Ϊ:";
	csTree.postOrderTraverse();
	cout << "��α���Ϊ:";
	csTree.levelOrderTraverse();
	cout << "���ĸ߶�Ϊ��" << csTree.heightCSTree() << endl;
	cout << "���Ŀ��Ϊ��" << csTree.widthCSTree() << endl;
	cout << "���Ķ�Ϊ��" << csTree.getDegreeCSTree() << endl;
	cout << "���Ľ�����Ϊ��" << csTree.nodeCountCSTree() << endl;
	cout << "����Ҷ�ӽ��Ϊ��" << csTree.LeavesCountCSTree() << endl;
	char item = 'f';
	CSNode<char>* cur = NULL;
	if (csTree.findCSNode(item, cur))
	{
		cout << item << "�Ĳ�Σ�" << csTree.nodeLevelCSTree(item) << endl;

		cout << item << "������Ϊ:";
		csTree.getAllParentCSTree(item);

		CSNode<char>* ret = NULL;
		if (csTree.getParentCSTree(item, ret))
		{
			cout << item << "�ĸ���Ϊ:" << ret->getData() << endl;
		}
		else
		{
			cout << item << "û��˫�ף�" << endl;
		}
		if (csTree.getleftChild(cur, ret))
		{
			if (ret->data == cur->data)
			{
				cout << item << "��������ֵ�Ϊ�Լ���" << endl;
			}
			else
			{
				cout << item << "��������ֵ�Ϊ:" << ret->getData() << endl;
			}
		}
		else
		{
			cout << item << "û��������ֵܣ�" << endl;
		}
		if (csTree.getrightSibling(cur, ret))
		{
			if (ret->data == cur->data)
			{
				cout << item << "�����ҵ��ֵ�Ϊ�Լ���" << endl;
			}
			else
			{
				cout << item << "�����ұߵ��ֵ�Ϊ:" << ret->getData() << endl;
			}
		}
		else
		{
			cout << item << "û�����ұߵ��ֵ�" << endl;
		}
		cout << item << "�������ֵ�Ϊ:";
		bool isFind = csTree.getAllSibling(item);
		cout << endl;
		if (!isFind)
		{
			cout << item << "û���ֵܣ�" << endl;
		}
		cout << item << "�����к���Ϊ:";
		isFind = csTree.getAllChildren(item);
		cout << endl;
		if (!isFind)
		{
			cout << item << "û�к��ӣ�" << endl;
		}
	}
	else
	{
		cout << "���" << item << "�����ڣ�" << endl;
	}
	csTree.destoryCSTree();
	system("pause");
	return 1;
}