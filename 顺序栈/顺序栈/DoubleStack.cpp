#include<iostream>
#include"DoubleStack.h"
using namespace std;
void Menu() {
	cout << "---------˫ջ�ṹ�����˵�--------" << endl;
	cout << "        ��1���ж��Ƿ�ջ��        " << endl;
	cout << "        ��2���ж��Ƿ�ջ��        " << endl;
	cout << "        ��3������                " << endl;
	cout << "        ��4��ɾ��                " << endl;
	cout << "--------��5���˳�----------------" << endl;
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

		cout << "��������ţ�" << endl;
		cin >> choice;

		if (choice == 5) break;
		switch (choice)
		{
		case 1:
			flag = s.IsEmpty();
			if (flag == true) cout << "�ձ�" << endl;
			else cout << "�ǿձ�" << endl;
			break;
		case 2:
			flag=s.IsFull();
			if (flag == true) cout << "������" << endl;
			else cout << "δ����" << endl;
			break;
		case 3:
			cout << "��������Ҫ����N��ֵ" << endl;
			cin >> n;
			cout << "ϣ����ջ������ջ�����루1Ϊջ����0Ϊջ�ף���" << endl;
			cin >> d;
			for (int i = 0; i < n; i++) {
				s.Push(x, d);
			}
			cout << s << endl;
			 break;
		case 4:

			cout << "ϣ����ջ������ջ��ɾ����1Ϊջ����0Ϊջ�ף���" << endl;
			cin >> d;
			s.Pop(x, d);
			
			cout << s << endl;
			 break;

		default:
			cout << "����������������룺" << endl;
			break;
		}

	}
}