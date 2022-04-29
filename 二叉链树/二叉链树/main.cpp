#include<iostream>
#include"BinTree.h"
#include"LinkedQueue.h"
#include"LinkedStack.h"
using namespace std;

//void CreateBinTree(istream& in, BinTreeNode<char>*& BT) {                            //��������in���������
//	stack<BinTreeNode<char>*>s;
//	BT = NULL;																					//�ÿն�����
//	BinTreeNode<char>* p, * t; int k;															//��k��Ϊ��Ǵ�����������
//	char ch;
//	in >> ch;                                                                                  //��in����һ���ַ�
//	while (ch!=RefValue)																		//����ַ�˳����
//	{
//		switch (ch)
//		{
//		case '(':s.push(p); k = 1; break;														//��������
//		case ')':s.pop(t); break;                                                              //�˳�����
//		case ',':k = 2; break;
//		default:p = new BinTreeNode<char>(ch);
//			if (BT == NULL)BT = p;
//			else if (k == 1) {
//				s.top(t); t->leftChild = p;													//����*t������Ů
//			}
//			else {
//				s.top(t); t->rightChild = p;                                                //����*t����Ů
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
	if (BT != NULL) {																	//��Ϊ��ʱ�����ݹ�
		cout << BT->data << endl;														//���������ֵ
		if (BT->leftChild != NULL || BT->rightChild != NULL) {
			cout << '(';																//���������
			PrintBTree(BT->leftChild);													//���������
			cout << ',';																//���ŷָ���
			if (BT->rightChild != NULL) PrintBTree(BT->rightChild);						//����������Ϊ�գ����
			cout << ')';																//���������
		}
	}
}
void menu() {
	cout << "   \t\t\t\t1------����һ�ö��������������н��ֵΨһ��\n\
				2------ǰ������ݹ��㷨 \n\
				3------ǰ������ǵݹ��㷨 \n\
				4------��������ݹ��㷨 \n\
				5------��������ǵݹ��㷨 \n\
				6------��������ݹ��㷨 \n\
				7------��������ǵݹ��㷨 \n\
				8------������ \n\
				9------��Ҷ������ \n\
				10---- - ���������ֵΪ x �Ľ��Ĳ�� \n\
				11---- - ���ֵΪ x �Ľ����������� \n\
				12---- - ���ò�α������������������ÿһ��Ľ�㣨ÿ�����һ������н�㣩\n\
				13---- - �˳�\n";
	
}
//void main() {
//	int choice;
//	BinaryTree<char> BT;
//	
//	menu();
//	while (1)
//	{
//		cout << "�����������ţ�" << endl;
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1:														//��������AB#CD##E##F#GH###
//			cout << "��������Խ������ֵ: ";							//���ԣ�-+a##*b##-c##d##/e##f##
//			cin >> BT.RefValue;
//			cin >> BT;
//			cout << "������ֱ�۷�ʽ��ӡ��" << endl;
//			cout << BT << endl;
//			break;
//		case 2:
//			cout << "ǰ��������������Ԫ��" << endl;
//			//cout << BT;
//			BT.preOrder(Vis);
//			cout << endl;
//			break;
//		case 3:
//			cout << "�ǵݹ�ǰ��������������" << endl;
//			BT.preOrder_un_recursive(Vis);
//			cout << endl;
//			break;
//		case 4:
//			cout << "����������������" << endl;
//			BT.inOrder(Vis);
//			cout << endl;
//			break;
//		case 5:
//			cout << "�ǵݹ�����������������" << endl;
//			BT.inOrder_un_recursive(Vis);
//			cout << endl;
//			break;
//		case 6:
//			cout << "����������������Ԫ��" << endl;
//			BT.postOrder(Vis);
//			cout << endl;
//			break;
//		case 7:
//			cout << "�ǵݹ����������������" << endl;
//			BT.postOrder_un_recursive(Vis);
//			cout << endl;
//			break;
//		case 8:
//			cout << "�������ĸ߶�:" << endl;
//			cout << BT.Height() << endl;
//			break;
//		case 9:
//			cout << "��������Ҷ������:" << endl;
//			cout << BT.LeafCount() << endl;
//			break;
//		case 10:
//			cout << "������Ҫ���ҵ�Ԫ��ֵ��" << endl;
//			char c;
//			cin >> c;
//			cout << c << " Ԫ��ֵ������ڲ�Σ�" << endl;
//			cout<<BT.find_node_level(BT.root, c);
//			cout << endl;
//			break;
//		case 11:
//			cout << "��������Ҫ���ҵ�xԪ��ֵ��" << endl;
//			char d;
//			cin >> d;
//			cout << d<<" Ԫ��ֵ���������ȣ�����Ψһ���ͽ������" << endl;
//			BT.PrintAncestors(BT.root, d, Vis);
//			cout << endl;
//			BT.flag = 0;
//			break;
//		case 12:
//			cout << "��������������" << endl;
//			BT.levelOrder(Vis);
//			cout << endl;
//			break;
//		case 13:exit(0);
//		default:
//			cout << "�����������������룺" << endl;
//			
//		}
//	}
//}

void main() {

	////1.�Զ����������洢�ṹ����дһ���㷨�������������������н������㷨
	////�������ӣ�-+a##*b##-c##d##/e##f##
	//BinaryTree<char> BT;
	//BT.RefValue = '#';
	//cin >> BT;
	////cout << BT << endl;
	//BT.preOrder(Vis);
	//cout << endl;
	//cout << "�����������������" << endl;
	//BT.preOrder(sowp);
	////cout << BT << endl;
	//BT.preOrder(Vis);
	//cout << endl;

	////2��һ�þ���n��������ȫ����������ڶ�������˳��洢�ṹ�У��Ա�д�ǵݹ��㷨�Ը����������������
	////���ӣ�-+a##*b##-c##d##/e##f##           a##
	//BinaryTree<char>BT1, BT2;
	//BT1.RefValue = BT2.RefValue = '#';
	//cout << "����һ��������";
	//cin >> BT1;
	//cout <<endl<< "����һ��������";
	//cin >> BT2;
	//if ((BT1==BT2)==true)cout << "������������ͬ" << endl;
	//else cout << "����ͬ" << endl;
	//	

	////4�����һ��ʵ��һ�ö��������Ƶ��㷨��
	////�������ӣ�-+a##*b##-c##d##/e##f##
	//BinaryTree<char> BT,BT1;
	//BT.RefValue =BT1.RefValue= '#';
	//cout << "��һ�Ŷ�����" << endl;
	//cin >> BT;
	//BT.preOrder(Vis);
	//cout <<endl<< "����һ�Ŷ�������ǰ����������" << endl;
	//BT1 = BT;
	//BT1.preOrder(Vis);
	//exit(1);

	////5����дһ����������������Ҷ�ӽ������������ӳɵ�������㷨��
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

	//  ��ԭ������:����һ�ö�������������������������Ҫ��ö������ĸ߶�
	//�������ӣ� ǰ��:ABDGCEF ����:DGBAECF 
	char pre[50], in[50];
	int n;
	cout << "�����������ǰ�������" << endl;
	cin >> pre;
	cout << "��������������������" << endl;
	cin >> in;
	n = strlen(pre);
	BinaryTree<char>BT;
	BT.RefValue = '#';
	BT.root=BT.CreateBinaryTree(pre, in, n);
	//BT.preOrder(Vis);
	//cout << BT << endl;
	cout << "�������ĸ߶�Ϊ��" << BT.Height() << endl;
}