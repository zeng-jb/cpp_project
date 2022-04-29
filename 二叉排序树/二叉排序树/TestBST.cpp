/*
#include"BSTree.h"
void menu(){
	cout << "\t\t1——建立一棵二叉排序树\n\
		2——在二叉排序树中插入一个值（递归算法）\n\
		3——在二叉排序树中插入一个值（非递归算法）\n\
		4——在二叉排序树中查找一个值（递归算法）\n\
		5——在二叉排序树中查找一个值（非递归算法）\n\
		6——在二叉排序树中删除一个值 \n\
		7——输出二叉树 \n\
		8——存入文件\n\
		9——读取文件\n\
		10——退出\n";
	cout << "请输入操作号：！" << endl;
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
			cout << "输入中止数字！" << endl;
			cin >> value;
			bst.Cread(value);
			cout << "建立成功！打印树！" << endl;
			bst.PrintTree();
			break;
		case 2:
			cout << "请输入要插入的值value" << endl;
			cin >> value;
			if (bst.Insert(value))cout << "插入成功！" << endl;
			else cout << "插入失败，有相同的值！" << endl;
			break;
		case 3:
			cout << "请输入要插入的值value(非递归)" << endl;
			cin >> value;
			if (bst.non_recursive_Insert(value))cout << "插入成功！" << endl;
			else cout << "插入失败，有相同的值！" << endl;
			break;
		case 4:
			cout << "请输入要查找的值value" << endl;
			cin >> value;
			if (bst.Serach(value))cout << "搜索成功！" << endl;
			else cout << "搜索失败！" << endl;
			break;
		case 5:
			cout << "请输入要查找的值value(非递归)" << endl;
			cin >> value;
			if (bst.non_recursive_Search(value))cout << "搜索成功！" << endl;
			else cout << "搜索失败！" << endl;
			break;
		case 6:
			cout << "输入要删除的值value" << endl;
			cin >> value;
			if (bst.Remove(value)==true)cout << "删除成功！" << endl;
			else cout << "删除失败！不存在该结点！" << endl;
			break;
		case 7:
			cout << "打印二叉排序树！" << endl;
			bst.PrintTree();
			break;
		case 8:
			bst.WriteInFile();
			cout << "写入成功！" << endl;
			break;
		case 9:
			bst.ReadoutFile();
			cout << "读取成功!" << endl;
			break;
		case 10:
			exit(1);
		default:
			cout << "输入错误！请输入输入！" << endl;
			break;
		}
	}
}
*/



#include"BSTStudent.h"
void menu() {
	cout << "\t\t1——新建学生通讯录\n\
		2——向学生通讯录插入学生信息\n\
		3——在通讯录删除学生信息\n\
		4——从文件中读取通讯录信息\n\
		5——向文件写入学生通讯录信息\n\
		6——在通讯录中查询学生信息\n\
		7——在屏幕中输出全部学生信息\n\
		8——退出\n";
	cout << "请输入操作序号：" << endl;
}
void main() {
	
	BST<BSTStu, int>bst;
	//bst.Cread(0);
	//bst.PrintTree();
	
	/*
		2001 曾嘉彬1 1998 07 15 男 123456 华南师范大学
		2002 曾嘉彬2 1998 07 15 男 123456 华南师范大学
		2003 曾嘉彬3 1998 07 15 男 123456 华南师范大学
		2004 曾嘉彬4 1998 07 15 男 123456 华南师范大学
		0 0 0 0 0 0 0 0

		2005    曾嘉彬5 1998 07 15       男      111111  华南师范
	*/
	int choice;
	int value;						//学号
	BSTStu stu;						//一个学生信息

	while (true)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "按顺序输入信息，全0代表输入结束！" << endl;
			bst.Cread(0);
			cout << "建立成功！打印通讯录！" << endl;
			bst.PrintTree();
			break;
		case 2:
			cout << "请输入要插入的学生信息(假设学号唯一)" << endl;
			stu.input(stu);
			if (bst.Insert(stu))cout << "插入成功！" << endl;
			else cout << "插入失败，有相同的学生信息！" << endl;
			break;
		case 3:
			cout << "输入要删除的学生信息(输入删除的学生学号）" << endl;
			cin >> value;
			if (bst.Remove(value) == true)cout << "删除成功！" << endl;
			else cout << "删除失败！不存在该学生信息！" << endl;
			break;
		case 4:
			bst.ReadoutFile();
			cout << "读取成功!" << endl;
			break;
		case 5:
			bst.WriteInFile();
			cout << "写入成功！" << endl;
			break;
		case 6:
			cout << "请输入要查找的学生学号" << endl;
			cin >> value;
			if (bst.Serach(value))cout << "搜索成功！" << endl;
			else cout << "搜索失败！" << endl;
			break;
		case 7:
			bst.PrintTree();
			break;
		case 8:
			exit(1);
		default:
			cout << "输入错误！请输入输入！" << endl;
			break;
		}
	}
}
