#include<iostream>
#include"DoubleStack.h"
using namespace std;
void Menu() {
	cout << "---------双栈结构操作菜单--------" << endl;
	cout << "        （1）判断是否栈空        " << endl;
	cout << "        （2）判断是否栈满        " << endl;
	cout << "        （3）插入                " << endl;
	cout << "        （4）删除                " << endl;
	cout << "--------（5）退出----------------" << endl;
}

void main()
{
	DoubleStack<int> s;
	int x;
	int choice;
	int n;
	bool d;
	bool flag;

	while (1)
	{
		Menu();

		cout << "请输入序号：" << endl;
		cin >> choice;

		if (choice == 5) break;
		switch (choice)
		{
		case 1:
			flag = s.IsEmpty();
			if (flag == true) cout << "空表" << endl;
			else cout << "非空表" << endl;
			break;
		case 2:
			flag=s.IsFull();
			if (flag == true) cout << "已满表" << endl;
			else cout << "未满表" << endl;
			break;
		case 3:
			cout << "请输入需要插入N个值" << endl;
			cin >> n;
			cout << "希望从栈顶还是栈底输入（1为栈顶，0为栈底）；" << endl;
			cin >> d;
			for (int i = 0; i < n; i++) {
				s.Push(x, d);
			}
			cout << s << endl;
			 break;
		case 4:

			cout << "希望从栈顶还是栈底删除（1为栈顶，0为栈底）；" << endl;
			cin >> d;
			s.Pop(x, d);
			
			cout << s << endl;
			 break;

		default:
			cout << "输入错误，请重新输入：" << endl;
			break;
		}

	}
}