//#include<iostream>
//#include"Tree.h"
//using namespace std;
//void main() {
//	Tree<char> CSTree;
//	cout << "建立树：" << endl;
//	CSTree.ClearTree();
//	cout << "前序遍历" << endl;
//	CSTree.preOrder();
//	
//}

#include<iostream>
#include"Tree.h"
using namespace std;
int main()
{
	/* ----测试赋值函数
	CSTree<char> csTree;
	CSTree<char> csTree1;
	cout<<"建立树，以##表示结束:"<<endl;
	csTree1.createCSTree();
	csTree = csTree1;//调用赋值函数
	*/

	//测试赋值构造函数

	CSTree<char> csTree1;
	cout << "建立树，以##表示结束:" << endl;
	csTree1.createCSTree();
	CSTree<char> csTree = csTree1;//调用拷贝构造函数

	//---一般操作
	cout << "先序遍历为:";
	csTree.preOrderTraverse();
	cout << "后序遍历为:";
	csTree.postOrderTraverse();
	cout << "层次遍历为:";
	csTree.levelOrderTraverse();
	cout << "树的高度为：" << csTree.heightCSTree() << endl;
	cout << "树的宽度为：" << csTree.widthCSTree() << endl;
	cout << "树的度为：" << csTree.getDegreeCSTree() << endl;
	cout << "树的结点个数为：" << csTree.nodeCountCSTree() << endl;
	cout << "树的叶子结点为：" << csTree.LeavesCountCSTree() << endl;
	char item = 'f';
	CSNode<char>* cur = NULL;
	if (csTree.findCSNode(item, cur))
	{
		cout << item << "的层次：" << csTree.nodeLevelCSTree(item) << endl;

		cout << item << "的祖先为:";
		csTree.getAllParentCSTree(item);

		CSNode<char>* ret = NULL;
		if (csTree.getParentCSTree(item, ret))
		{
			cout << item << "的父亲为:" << ret->getData() << endl;
		}
		else
		{
			cout << item << "没有双亲！" << endl;
		}
		if (csTree.getleftChild(cur, ret))
		{
			if (ret->data == cur->data)
			{
				cout << item << "的最左的兄弟为自己！" << endl;
			}
			else
			{
				cout << item << "的最左的兄弟为:" << ret->getData() << endl;
			}
		}
		else
		{
			cout << item << "没有最左的兄弟！" << endl;
		}
		if (csTree.getrightSibling(cur, ret))
		{
			if (ret->data == cur->data)
			{
				cout << item << "的最右的兄弟为自己！" << endl;
			}
			else
			{
				cout << item << "的最右边的兄弟为:" << ret->getData() << endl;
			}
		}
		else
		{
			cout << item << "没有最右边的兄弟" << endl;
		}
		cout << item << "的所有兄弟为:";
		bool isFind = csTree.getAllSibling(item);
		cout << endl;
		if (!isFind)
		{
			cout << item << "没有兄弟！" << endl;
		}
		cout << item << "的所有孩子为:";
		isFind = csTree.getAllChildren(item);
		cout << endl;
		if (!isFind)
		{
			cout << item << "没有孩子！" << endl;
		}
	}
	else
	{
		cout << "结点" << item << "不存在！" << endl;
	}
	csTree.destoryCSTree();
	system("pause");
	return 1;
}