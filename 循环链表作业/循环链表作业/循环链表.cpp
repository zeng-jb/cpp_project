#include <iostream>
#include"class.h"

using namespace std;

void main()
{
/*
    //1����֪һ���������е�����Ԫ�غ��������ַ�������ĸ�ַ��������ַ��������ַ�����
	//�Ա�д�㷨����������ѭ������ʹÿ��ѭ��������ֻ����ͬһ����ַ���������ԭ���еĽ��ռ���Ϊ��������Ľ��ռ䡣
	List<char> list;
	Node<char>* a1, * b1, * c1;
	int a, b, c;

	list.Createlist();
	list.Sort(a, b, c);
	list.Circlink(a1, b1, c1, a, b, c);

	cout << "Ӣ����ĸԪ�أ�" << endl;
	list.Output(a1);
	cout << "�����ַ�Ԫ�أ�" << endl;
	list.Output(b1);
	cout << "�����ַ�Ԫ�أ�" << endl;
	list.Output(c1);
	*/

 //2���Ա�дһ���㷨���ҳ�һ��ѭ�������е���Сֵ��ɾ����
	List<int> list;
	list.Createlist();
	list.SearchDelete();
	cout << "ɾ����Ԫ�����У�" << endl;
	list.Print();



	system("pause");
}