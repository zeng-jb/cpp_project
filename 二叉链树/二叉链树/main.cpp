#include<iostream>
#include"BinTree.h"
#include"LinkedQueue.h"
#include"LinkedStack.h"
using namespace std;

//void CreateBinTree(istream& in, BinTreeNode<char>*& BT) {                            //从输入流in输入二叉树
//	stack<BinTreeNode<char>*>s;
//	BT = NULL;																					//置空二叉树
//	BinTreeNode<char>* p, * t; int k;															//用k作为标记处理左右子树
//	char ch;
//	in >> ch;                                                                                  //从in读入一个字符
//	while (ch!=RefValue)																		//逐个字符顺序处理
//	{
//		switch (ch)
//		{
//		case '(':s.push(p); k = 1; break;														//进入子树
//		case ')':s.pop(t); break;                                                              //退出子树
//		case ',':k = 2; break;
//		default:p = new BinTreeNode<char>(ch);
//			if (BT == NULL)BT = p;
//			else if (k == 1) {
//				s.top(t); t->leftChild = p;													//链入*t的左子女
//			}
//			else {
//				s.top(t); t->rightChild = p;                                                //链入*t右子女
//			}
//			break;
//		}
//		in >> ch;
//
//	}
//}
template<class T>
void Vis(BinTreeNode<T>* p) {
	cout << p->data << ' ';
}

template<class T>
void PrintBTree(BinTreeNode<T>* BT) {
	if (BT != NULL) {																	//数为空时结束递归
		cout << BT->data << endl;														//输入根结点的值
		if (BT->leftChild != NULL || BT->rightChild != NULL) {
			cout << '(';																//输出左括号
			PrintBTree(BT->leftChild);													//输出左子树
			cout << ',';																//逗号分隔符
			if (BT->rightChild != NULL) PrintBTree(BT->rightChild);						//若右子树不为空，输出
			cout << ')';																//输出右括号
		}
	}
}
void menu() {
	cout << "   \t\t\t\t1------建立一棵二叉树（假设所有结点值唯一）\n\
				2------前序遍历递归算法 \n\
				3------前序遍历非递归算法 \n\
				4------中序遍历递归算法 \n\
				5------中序遍历非递归算法 \n\
				6------后序遍历递归算法 \n\
				7------后序遍历非递归算法 \n\
				8------求树高 \n\
				9------求叶子总数 \n\
				10---- - 求二叉树中值为 x 的结点的层次 \n\
				11---- - 输出值为 x 的结点的所有祖先 \n\
				12---- - 采用层次遍历方法输出二叉树的每一层的结点（每行输出一层的所有结点）\n\
				13---- - 退出\n";
	
}
//void main() {
//	int choice;
//	BinaryTree<char> BT;
//	
//	menu();
//	while (1)
//	{
//		cout << "请输入操作序号；" << endl;
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1:														//测试例子AB#CD##E##F#GH###
//			cout << "输入符号以结束结点值: ";							//测试：-+a##*b##-c##d##/e##f##
//			cin >> BT.RefValue;
//			cin >> BT;
//			cout << "二叉树直观方式打印：" << endl;
//			cout << BT << endl;
//			break;
//		case 2:
//			cout << "前序遍历输出二叉树元素" << endl;
//			//cout << BT;
//			BT.preOrder(Vis);
//			cout << endl;
//			break;
//		case 3:
//			cout << "非递归前序遍历输出二叉树" << endl;
//			BT.preOrder_un_recursive(Vis);
//			cout << endl;
//			break;
//		case 4:
//			cout << "中序遍历输出二叉树" << endl;
//			BT.inOrder(Vis);
//			cout << endl;
//			break;
//		case 5:
//			cout << "非递归中序遍历输出二叉树" << endl;
//			BT.inOrder_un_recursive(Vis);
//			cout << endl;
//			break;
//		case 6:
//			cout << "后序遍历输出二叉树元素" << endl;
//			BT.postOrder(Vis);
//			cout << endl;
//			break;
//		case 7:
//			cout << "非递归后序遍历输出二叉树" << endl;
//			BT.postOrder_un_recursive(Vis);
//			cout << endl;
//			break;
//		case 8:
//			cout << "二叉树的高度:" << endl;
//			cout << BT.Height() << endl;
//			break;
//		case 9:
//			cout << "二叉树的叶子总数:" << endl;
//			cout << BT.LeafCount() << endl;
//			break;
//		case 10:
//			cout << "请输入要查找的元素值：" << endl;
//			char c;
//			cin >> c;
//			cout << c << " 元素值结点所在层次：" << endl;
//			cout<<BT.find_node_level(BT.root, c);
//			cout << endl;
//			break;
//		case 11:
//			cout << "请输入需要查找的x元素值：" << endl;
//			char d;
//			cin >> d;
//			cout << d<<" 元素值的所有祖先：假设唯一（就进输出）" << endl;
//			BT.PrintAncestors(BT.root, d, Vis);
//			cout << endl;
//			BT.flag = 0;
//			break;
//		case 12:
//			cout << "层次序遍历二叉树" << endl;
//			BT.levelOrder(Vis);
//			cout << endl;
//			break;
//		case 13:exit(0);
//		default:
//			cout << "输入有误，请重新输入：" << endl;
//			
//		}
//	}
//}

void main() {

	////1.以二叉链表作存储结构，编写一个算法将二叉树左、右子树进行交换的算法
	////测试例子：-+a##*b##-c##d##/e##f##
	//BinaryTree<char> BT;
	//BT.RefValue = '#';
	//cin >> BT;
	////cout << BT << endl;
	//BT.preOrder(Vis);
	//cout << endl;
	//cout << "左右子树交换后输出" << endl;
	//BT.preOrder(sowp);
	////cout << BT << endl;
	//BT.preOrder(Vis);
	//cout << endl;

	////2、一棵具有n个结点的完全二叉树存放在二叉树的顺序存储结构中，试编写非递归算法对该树进行中序遍历。
	////例子：-+a##*b##-c##d##/e##f##           a##
	//BinaryTree<char>BT1, BT2;
	//BT1.RefValue = BT2.RefValue = '#';
	//cout << "建第一个二叉树";
	//cin >> BT1;
	//cout <<endl<< "建第一个二叉树";
	//cin >> BT2;
	//if ((BT1==BT2)==true)cout << "两个二叉树相同" << endl;
	//else cout << "不相同" << endl;
	//	

	////4、设计一个实现一棵二叉树复制的算法。
	////测试例子：-+a##*b##-c##d##/e##f##
	//BinaryTree<char> BT,BT1;
	//BT.RefValue =BT1.RefValue= '#';
	//cout << "建一颗二叉树" << endl;
	//cin >> BT;
	//BT.preOrder(Vis);
	//cout <<endl<< "复制一颗二叉树并前序遍历输出：" << endl;
	//BT1 = BT;
	//BT1.preOrder(Vis);
	//exit(1);

	////5、编写一个将二叉树的所有叶子结点从左向右链接成单链表的算法。
	//BinaryTree<char> BT;
	//list<char>ls;
	//list<char>::iterator i;
	//BT.RefValue = '#';
	//cin >> BT;
	//BT.LeafShow(BT.root,ls);
	//for (i = ls.begin(); i != ls.end(); i++) {
	//	if (i != ls.begin())cout << "->";
	//	cout << *i ;
	//}	
	//cout << endl;

	//  还原二叉树:给定一棵二叉树的先序遍历和中序遍历，要求该二叉树的高度
	//测试例子： 前序:ABDGCEF 中序:DGBAECF 
	char pre[50], in[50];
	int n;
	cout << "请输入二叉树前序遍历：" << endl;
	cin >> pre;
	cout << "请输入二叉树中序遍历：" << endl;
	cin >> in;
	n = strlen(pre);
	BinaryTree<char>BT;
	BT.RefValue = '#';
	BT.root=BT.CreateBinaryTree(pre, in, n);
	//BT.preOrder(Vis);
	//cout << BT << endl;
	cout << "二叉树的高度为：" << BT.Height() << endl;
}