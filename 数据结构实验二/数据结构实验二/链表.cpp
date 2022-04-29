#include <iostream>
#include"Linklist.h"
#define ElemType int

using namespace std;

void Menu()
{
	cout << "请输入菜单序号：" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "          （1）初始化;                        （2）链表的建立；" << endl;
	cout << "          （3）插入；                         （4）删除；      " << endl;
	cout << "          （5）查找；                         （6）输出表长（即表中元素个数）" << endl;
	cout << "          （7）链表元素的逆置                 （8）分解链表；"   << endl;
	cout << "          （9）退出；                                          " << endl;
	cout << "---------------------------------------------------------------" << endl;
}

void  main()
{

	int choice;
	int i; 
	Linklist<int> list;
	ElemType x;
	ElemType endTag = -1;
	bool flag;

	while (1) {
		Menu();
		cin >> choice;
		if (choice == 9) break;
		switch (choice)
		{
		case 1: {list.Creat(); break; }
		case 2: {
			int i;
			cout << "请输入序号：/t（1）头插入建立链表 /t（2）尾插入建立链表 " << endl;
			cin >> i;
			if (i == 1) {
				cout << "请输入链表元素数值（以-1结束）" << endl;
				list.inputFront(endTag);
			}
			else if (i == 2) {
				cout << "请输入链表元素数值（以-1结束）" << endl;
				list.inputRear(endTag);
			}
			else {
				cout << "输入序号错误；" << endl;
			}
			list.output();
			break;
		}
		case 3: {
			cout << "请输入想要插入的位置和元素值；" << endl;
			cin >> i >> x;
			flag=list.Insert(i, x); 
			if (flag == true)  cout << "插入成功！" << endl; 
			else cout << "插入失败！" << endl;
			list.output();
			break; 
		}
		case 4: {
			cout << "请输入想要删除的位置；" << endl;
			cin >> i;
			flag=list.Remove(i);
			if (flag)  cout << "删除成功！" << endl;
			else cout << "删除失败！" << endl;
			list.output();
			break;
		}
		case 5: {
			cout << "请输入待查找的元素值x；" << endl;
			cin >> x;
			list.Search(x);
			list.output();
			break; 
		}
		case 6: {
			list.output();
			cout << "链表长度为" << list.Length() << endl;
			break;
		}
		case 7: {
			cout << "原来序列为：" << endl;
			list.output();
			cout << "逆置后：" << endl;
			list.Resolve();
			list.output();
			break;
		}
		case 8: {
			cout << "原来序列是：" << endl;
			list.output();
			cout << "序列分奇偶后：" << endl;
			list.Inverse();
			break;
		}
		default: {cout << "输入错误，请重新输入：" << endl; }
			break;
		}
	}
}