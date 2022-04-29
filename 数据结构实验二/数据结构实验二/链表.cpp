#include <iostream>
#include"Linklist.h"
#define ElemType int

using namespace std;

void Menu()
{
	cout << "������˵���ţ�" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "          ��1����ʼ��;                        ��2������Ľ�����" << endl;
	cout << "          ��3�����룻                         ��4��ɾ����      " << endl;
	cout << "          ��5�����ң�                         ��6���������������Ԫ�ظ�����" << endl;
	cout << "          ��7������Ԫ�ص�����                 ��8���ֽ�����"   << endl;
	cout << "          ��9���˳���                                          " << endl;
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
			cout << "��������ţ�/t��1��ͷ���뽨������ /t��2��β���뽨������ " << endl;
			cin >> i;
			if (i == 1) {
				cout << "����������Ԫ����ֵ����-1������" << endl;
				list.inputFront(endTag);
			}
			else if (i == 2) {
				cout << "����������Ԫ����ֵ����-1������" << endl;
				list.inputRear(endTag);
			}
			else {
				cout << "������Ŵ���" << endl;
			}
			list.output();
			break;
		}
		case 3: {
			cout << "��������Ҫ�����λ�ú�Ԫ��ֵ��" << endl;
			cin >> i >> x;
			flag=list.Insert(i, x); 
			if (flag == true)  cout << "����ɹ���" << endl; 
			else cout << "����ʧ�ܣ�" << endl;
			list.output();
			break; 
		}
		case 4: {
			cout << "��������Ҫɾ����λ�ã�" << endl;
			cin >> i;
			flag=list.Remove(i);
			if (flag)  cout << "ɾ���ɹ���" << endl;
			else cout << "ɾ��ʧ�ܣ�" << endl;
			list.output();
			break;
		}
		case 5: {
			cout << "����������ҵ�Ԫ��ֵx��" << endl;
			cin >> x;
			list.Search(x);
			list.output();
			break; 
		}
		case 6: {
			list.output();
			cout << "������Ϊ" << list.Length() << endl;
			break;
		}
		case 7: {
			cout << "ԭ������Ϊ��" << endl;
			list.output();
			cout << "���ú�" << endl;
			list.Resolve();
			list.output();
			break;
		}
		case 8: {
			cout << "ԭ�������ǣ�" << endl;
			list.output();
			cout << "���з���ż��" << endl;
			list.Inverse();
			break;
		}
		default: {cout << "����������������룺" << endl; }
			break;
		}
	}
}