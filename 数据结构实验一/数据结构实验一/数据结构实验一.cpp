#include <iostream>
#include <stdlib.h>
#define maxSize 100      //设置数组最大值
#define Status int       //设置顺序表参数类型
#define ElemType int     //设置数组的参数类型
using namespace std;

typedef struct                               //创建顺序表结构
{
	ElemType data[maxSize];            //顺序表元素
	int length;                        //顺序表当前长度
}Sqelist;

Status Initlist(Sqelist& L) {         //初始化顺序表函数，构造出一个空的顺序表
	memset(L.data, 0, sizeof(0));      //初始化顺序表数据为0
	L.length = 0;                      //初始化顺序表长度为0
	return 0;
}

bool Creatlist(Sqelist& L, int n) {     //创建长度为n的顺序表，输入n个数值
	if (n < 0 || n>maxSize) false;      //判断长度是否越界
	for (int i = 0; i < n; i++) {
		cin >> L.data[i];
		L.length++;                    //长度加一
	}
	return true;
}

bool Insertlist(Sqelist& L, int i, ElemType x) {    //插入对应位置元素值函数
	if (i<0 || i>L.length + 1) {                    //判断给出位置有无越界
		cout << "插入位置无效； " << endl;
		return false;
	}
	if (i >= maxSize) {                             //判断是否表满
		cout << "顺序表已满； " << endl;
		return false;
	}
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j-1];
	}
	L.data[i-1] = x;
	L.length++;                                    //顺序表长度加一
	return true;
}

bool Removelist(Sqelist& L, int i) {           //删除对应位置元素值函数
	if (i<0 || i>L.length + 1) {               //判断给出位置有无越界
		cout << "删除位置无效；" << endl;
		return false;
	}
	for (int j = i-1; j < L.length; j++) {
		L.data[j] = L.data[j + 1];
	}
	L.length--;                               //删除后顺序表长度减一
	return true;
}

int Searchlist(Sqelist L, ElemType x) {        //查找元素值函数，从0到length按顺序查找
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == x) {
			//cout << "i+1" << endl;
			return (i+1);                     //存在则返回该数值下标
		}
	}
	return 0;                                //无返回0
}

void output(Sqelist L) {            //输出顺序表函数
	cout << "当前顺序表所有元素 ：" << endl;
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i]<<" ";
	}
	cout << endl;
}

void Creat(Sqelist &L) {              //创建顺序表函数
	cout << "请输入您想要创建的顺序表长度： " << endl;
	int n;
	bool flag;
	L.length = 0;
	cin >> n;
	cout << "请输入" << n << "个数（空格分开）：" << endl;
	flag = Creatlist(L, n);          //调用Creatlist函数进行输入数值操作
	if (flag == true) {
		cout << "创建成功；" << endl;
		output(L);
	}
	else { cout << "输入长度非法； " << endl; }
}

void Insert(Sqelist& L) {           //插入函数
	int i;
	ElemType x;
	bool flag;
	cout << "插入之前的元素序列：" << endl;
	output(L);
	cout << "请输入想要插入的位置i和元素值x ： " << endl;
	cin >> i >> x;
	flag = Insertlist(L, i, x);     //调用Insertlist函数进行插入元素操作
	if (flag == true) {
		cout << "插入成功；" << endl << "插入后元素序列： " << endl;
		output(L);
	}
}

void Remove(Sqelist& L) {           //删除函数
	int i;
	bool flag;
	cout << "删除前的元素序列：" << endl;
	output(L);
	cout << "请输入想要删除的位置：" << endl;
	cin >> i;
	flag = Removelist(L, i);        //调用Removelist函数进行删除某位数值操作
	if (flag == true) {
		cout << "删除成功；" << endl << "删除后的元素序列：" << endl;
		output(L);
	}
}

void Search(Sqelist& L) {          //查找函数
	ElemType x;
	output(L);
	int flag;
	cout << "想要查找元素值：" << endl;
	cin >> x;
	flag = Searchlist(L, x);         //调用Searchlist函数进行查找元素值操作
	if (flag!=0) {
		cout << "该元素的位置在第" << flag << "位;" << endl;
	}
	else { cout << "没有找到该元素；" << endl; }

}

void menu() {
	cout << "             1.初始化       " << endl;
	cout << "             2.插入         " << endl;
	cout << "             3.删除         " << endl;
	cout << "             4.查找         " << endl;
	cout << "             5.退出         " << endl;
}

void main() {
	Sqelist L;
	int index;                             //序号
	Initlist(L);                           //初始化顺序表，创建空表
	while (1) {
		cout << "请输入菜单序号:" << endl;
		menu();                                //菜单栏
		cin >> index;
		if (index == 5) break;
		switch (index)
		{
			case 1: { Creat(L);            break; }        //初始化
			case 2: { Insert(L);           break; }        //插入
			case 3: { Remove(L);           break; }        //删除
			case 4: { Search(L);           break; }        //查找
			default:  cout << "输入错误，请重新输入：" << endl;
				break;
		}
	}
}
