/*
#include"BSTree.h"
void menu(){
	cout << "\t\t1��������һ�ö���������\n\
		2�����ڶ����������в���һ��ֵ���ݹ��㷨��\n\
		3�����ڶ����������в���һ��ֵ���ǵݹ��㷨��\n\
		4�����ڶ����������в���һ��ֵ���ݹ��㷨��\n\
		5�����ڶ����������в���һ��ֵ���ǵݹ��㷨��\n\
		6�����ڶ�����������ɾ��һ��ֵ \n\
		7������������� \n\
		8���������ļ�\n\
		9������ȡ�ļ�\n\
		10�����˳�\n";
	cout << "����������ţ���" << endl;
}
void main() {
	BST<int, int>bst;
	
	int choice;
	int value;
	//0 53 78 65 17 87 09 81 45 23 0
	while (true)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "������ֹ���֣�" << endl;
			cin >> value;
			bst.Cread(value);
			cout << "�����ɹ�����ӡ����" << endl;
			bst.PrintTree();
			break;
		case 2:
			cout << "������Ҫ�����ֵvalue" << endl;
			cin >> value;
			if (bst.Insert(value))cout << "����ɹ���" << endl;
			else cout << "����ʧ�ܣ�����ͬ��ֵ��" << endl;
			break;
		case 3:
			cout << "������Ҫ�����ֵvalue(�ǵݹ�)" << endl;
			cin >> value;
			if (bst.non_recursive_Insert(value))cout << "����ɹ���" << endl;
			else cout << "����ʧ�ܣ�����ͬ��ֵ��" << endl;
			break;
		case 4:
			cout << "������Ҫ���ҵ�ֵvalue" << endl;
			cin >> value;
			if (bst.Serach(value))cout << "�����ɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			break;
		case 5:
			cout << "������Ҫ���ҵ�ֵvalue(�ǵݹ�)" << endl;
			cin >> value;
			if (bst.non_recursive_Search(value))cout << "�����ɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			break;
		case 6:
			cout << "����Ҫɾ����ֵvalue" << endl;
			cin >> value;
			if (bst.Remove(value)==true)cout << "ɾ���ɹ���" << endl;
			else cout << "ɾ��ʧ�ܣ������ڸý�㣡" << endl;
			break;
		case 7:
			cout << "��ӡ������������" << endl;
			bst.PrintTree();
			break;
		case 8:
			bst.WriteInFile();
			cout << "д��ɹ���" << endl;
			break;
		case 9:
			bst.ReadoutFile();
			cout << "��ȡ�ɹ�!" << endl;
			break;
		case 10:
			exit(1);
		default:
			cout << "����������������룡" << endl;
			break;
		}
	}
}
*/



#include"BSTStudent.h"
void menu() {
	cout << "\t\t1�����½�ѧ��ͨѶ¼\n\
		2������ѧ��ͨѶ¼����ѧ����Ϣ\n\
		3������ͨѶ¼ɾ��ѧ����Ϣ\n\
		4�������ļ��ж�ȡͨѶ¼��Ϣ\n\
		5�������ļ�д��ѧ��ͨѶ¼��Ϣ\n\
		6������ͨѶ¼�в�ѯѧ����Ϣ\n\
		7��������Ļ�����ȫ��ѧ����Ϣ\n\
		8�����˳�\n";
	cout << "�����������ţ�" << endl;
}
void main() {
	
	BST<BSTStu, int>bst;
	//bst.Cread(0);
	//bst.PrintTree();
	
	/*
		2001 ���α�1 1998 07 15 �� 123456 ����ʦ����ѧ
		2002 ���α�2 1998 07 15 �� 123456 ����ʦ����ѧ
		2003 ���α�3 1998 07 15 �� 123456 ����ʦ����ѧ
		2004 ���α�4 1998 07 15 �� 123456 ����ʦ����ѧ
		0 0 0 0 0 0 0 0

		2005    ���α�5 1998 07 15       ��      111111  ����ʦ��
	*/
	int choice;
	int value;						//ѧ��
	BSTStu stu;						//һ��ѧ����Ϣ

	while (true)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "��˳��������Ϣ��ȫ0�������������" << endl;
			bst.Cread(0);
			cout << "�����ɹ�����ӡͨѶ¼��" << endl;
			bst.PrintTree();
			break;
		case 2:
			cout << "������Ҫ�����ѧ����Ϣ(����ѧ��Ψһ)" << endl;
			stu.input(stu);
			if (bst.Insert(stu))cout << "����ɹ���" << endl;
			else cout << "����ʧ�ܣ�����ͬ��ѧ����Ϣ��" << endl;
			break;
		case 3:
			cout << "����Ҫɾ����ѧ����Ϣ(����ɾ����ѧ��ѧ�ţ�" << endl;
			cin >> value;
			if (bst.Remove(value) == true)cout << "ɾ���ɹ���" << endl;
			else cout << "ɾ��ʧ�ܣ������ڸ�ѧ����Ϣ��" << endl;
			break;
		case 4:
			bst.ReadoutFile();
			cout << "��ȡ�ɹ�!" << endl;
			break;
		case 5:
			bst.WriteInFile();
			cout << "д��ɹ���" << endl;
			break;
		case 6:
			cout << "������Ҫ���ҵ�ѧ��ѧ��" << endl;
			cin >> value;
			if (bst.Serach(value))cout << "�����ɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			break;
		case 7:
			bst.PrintTree();
			break;
		case 8:
			exit(1);
		default:
			cout << "����������������룡" << endl;
			break;
		}
	}
}
