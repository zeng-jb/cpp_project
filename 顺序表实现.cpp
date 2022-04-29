/*
Project: sequence_list(���ݽṹ-˳���)
Date:    2018/09/12  20191012�޸� ���Reverse  20200819�޸� ���ClearList
Author:  Frank Yu
CreateList(SqList &L,int n) ������˳���L��˳�����n ���ܣ���������Ϊ��˳��� ʱ�临�Ӷȣ�O(n)
InitList(SqList &L) ������˳���L ���ܣ���ʼ�� ʱ�临�Ӷ�:O(1)
InsertList(SqList &L,int i,ElemType e) ����:˳���L,λ��i,Ԫ��e ���ܣ�λ��i������Ԫ��e ʱ�临�Ӷ�:O(n)
ListDelete(SqList &L,int i) ����:˳���L,λ��i ���ܣ�ɾ��λ��i��Ԫ�� ʱ�临�Ӷ�:O(n)
LocateElem(SqList L,ElemType e) ����:˳���L,Ԫ��e ���ܣ����ص�һ������e��Ԫ�ص�λ�� ʱ�临�Ӷ�:O(n)
Reverse(SqList &L) ������˳���L ���ú��� ��ԭ˳���ֱ�ӵ���
PrintList(SqList L) ����:˳���L ���ܣ�����L�������
SplitSort(SqList &L) ������˳���L ���ܣ��ֿ���ż�����ֿ�����
ClearList(SqList &L) ������˳���L ���ܣ����˳���
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define MaxSize 100
#define ElemType int
#define Status int
using namespace std;
//˳������ݽṹ
typedef struct
{
	ElemType data[MaxSize];//˳���Ԫ��
	int length;            //˳���ǰ����
}SqList;
//***************************������������*******************************//
//��ʼ��˳�����������һ���յ�˳��� 
Status InitList(SqList &L)
{
	memset(L.data, 0, sizeof(L));//��ʼ������Ϊ0
	L.length = 0;                //��ʼ������Ϊ0
	return 0;
}
//����˳����� ��ʼ��ǰn������
bool CreateList(SqList &L, int n)
{
	if (n<0 || n>MaxSize)false;//n�Ƿ�
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &L.data[i]);
		L.length++;
	}
	return true;
}
//���뺯�� λ��i�������� i��֮��Ԫ�غ���  1=<i<=length+1 
bool InsertList(SqList &L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1) //�ж�λ���Ƿ���Ч
	{
		printf("λ����Ч������\n");
		return false;
	}
	if (L.length >= MaxSize)//�жϴ洢�ռ��Ƿ�����
	{
		printf("��ǰ�洢�ռ�����������\n");
		return false;
	}
	for (int j = L.length; j >= i; j--)//λ��i��֮��Ԫ�غ���
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}
//ɾ������ ɾ��λ��i��Ԫ�� i֮���Ԫ������ǰ��
bool  ListDelete(SqList &L, int i)
{
	if (i<1 || i>L.length)
	{
		printf("λ����Ч������\n");
		return false;
	}
	for (int j = i; j <= L.length - 1; j++)//λ��i֮��Ԫ������ǰ�Ƹ���
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}
//���Һ��� ��λ�ô�С������ҵ�һ��ֵ����e��Ԫ�� ������λ��
int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i<L.length; i++)//�ӵ�λ�ò���
	{
		if (L.data[i] == e)
			return i + 1;
	}
	return 0;
}
//���ú��� ��ԭ˳���ֱ�ӵ���
void Reverse(SqList &L)
{
	if (L.length)
		for (int i = 0; i<L.length - 1 - i; i++)
		{
			int t = L.data[i];
			L.data[i] = L.data[L.length - 1 - i];
			L.data[L.length - 1 - i] = t;
		}
}
//��ż�ֿ�������
void SplitSort(SqList &L)
{
	int Even = 0;
	int Odd = L.length - 1;
	int i = 0;
	int j = L.length - 1;
	bool flag = false;
	if (L.length)
		for (; i < j; i++, j--)
		{
			while (L.data[i] % 2 != 0)i++;
			while (L.data[j] % 2 == 0)j--;
			if (L.data[i] % 2 == 0 && L.data[j] % 2 != 0&&i<j)
			{
				int temp = L.data[i];
				L.data[i] = L.data[j];
				L.data[j] = temp;
				flag = true;
			}
			if(!flag) //û�н���
			{
				Even = L.length - 1;//ȫ����
				Odd = 0; //ȫż��
			}
		}
	if (flag)
	{
		for(int i=0;i<L.length;i++)
			if (L.data[i] % 2 == 0) 
			{
				Odd = i;
				Even = i - 1;
				break;
			}
	}
	sort(L.data, L.data + Even + 1);
	sort(L.data + Odd, L.data + L.length);
}
//���˳���
void ClearList(SqList &L) {
	L.length = 0;
}
//********************************���ܺ���*****************************************//
//������ܺ��� ��λ�ô�С�������˳�������Ԫ��
void PrintList(SqList L)
{
	printf("��ǰ˳�������Ԫ��:");
	for (int i = 0; i<L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");
}
//����˳�����
void Create(SqList &L)
{
	int n; bool flag;
	L.length = 0;
	printf("������Ҫ������˳�����(>1):");
	scanf("%d", &n);
	printf("������%d�������ո������:", n);
	flag = CreateList(L, n);
	if (flag) {
		printf("�����ɹ���\n");
		PrintList(L);
	}
	else printf("���볤�ȷǷ���\n");
 
}
//���빦�ܺ��� ����InsertList���˳���Ԫ�ز��� ����PrintList������ʾ����ɹ���Ľ��
void Insert(SqList &L)
{
	int place; ElemType e; bool flag;
	printf("������Ҫ�����λ��(��1��ʼ)��Ԫ��:\n");
	scanf("%d%d", &place, &e);
	flag = InsertList(L, place, e);
	if (flag)
	{
		printf("����ɹ�������\n");
		PrintList(L);
	}
}
//ɾ�����ܺ��� ����ListDelete�������˳����ɾ�� ����PrintList������ʾ����ɹ���Ľ��
void Delete(SqList &L)
{
	int place; bool flag;
	printf("������Ҫɾ����λ��(��1��ʼ):\n");
	scanf("%d", &place);
	flag = ListDelete(L, place);
	if (flag)
	{
		printf("ɾ���ɹ�������\n");
		PrintList(L);
	}
}
//���ҹ��ܺ��� ����LocateElem����Ԫ��
void Search(SqList L)
{
	ElemType e; int flag;
	printf("������Ҫ���ҵ�ֵ:\n");
	scanf("%d", &e);
	flag = LocateElem(L, e);
	if (flag)
	{
		printf("��Ԫ��λ��Ϊ:%d\n", flag);
	}
	else
		printf("δ�ҵ���Ԫ�أ�\n");
}
//�˵�
void menu()
{
	printf("********1.����                        2.����*********\n");
	printf("********3.ɾ��                        4.����*********\n");
	printf("********5.����                        6.����ż����***\n");
	printf("********7.���                        8.���*********\n");
	printf("********9.�˳�                              *********\n");
}
int main()
{
	SqList L; int choice;
	InitList(L);
	while (1)
	{
		menu();
		printf("������˵���ţ�\n");
		scanf("%d", &choice);
		if (9 == choice) break;
		switch (choice)
		{
		case 1:Create(L); break;
		case 2:Insert(L); break;
		case 3:Delete(L); break;
		case 4:Search(L); break;
		case 5:Reverse(L); break;
		case 6:SplitSort(L); break;
		case 7:PrintList(L); break;
		case 8:ClearList(L); break;
		default:printf("������󣡣���\n");
		}
	}
	return 0;
}
