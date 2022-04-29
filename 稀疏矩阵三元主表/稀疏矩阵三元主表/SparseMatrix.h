#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;
const int DafaultSize = 100;

template <class T>
struct Trituple                                              //三元组类Trituple
{
	int row, col;                                            //非0元素的行号、列号
	T value;                                                 //非零元素的值
	Trituple<T>& operator=(Trituple<T>& x)                   //结点赋值
	{
		row = x.row; col = x.col; value = x.value;
	}
};

template<class T>
class SparseMatrix                                            //稀疏矩阵的类声明
{
public:
	friend ostream& operator << (ostream& out, SparseMatrix<T>& M);        //有元函数，输出重载符的声明；
	friend ostream& operator >> (ostream& in, SparseMatrix<T>& M);         //友元函数，输入流操作符重载；
public:
	SparseMatrix(int maxSz=DafaultSize);                                           //构造函数
	SparseMatrix(SparseMatrix<T>& x);                                             //复制构造函数
	~SparseMatrix() { delete[]smArray; }                                          //析构函数
	SparseMatrix<T>& operator=(SparseMatrix<T>& x);
	SparseMatrix<T> Transpose();                                                   //转置矩阵
	SparseMatrix<T> Add(SparseMatrix<T>& b);                                       //与矩阵b相加
	SparseMatrix<T> Multiply(SparseMatrix<T>& b);                                    //与矩阵b相乘
private:
	int Rows, Cols, Terms;
	Trituple<T>* smArray;
	int maxTerms;
};

template<class T>
SparseMatrix<T>::SparseMatrix(int maxSz) :maxTerms(maxSz) {
	if (maxSz < 1) {
		cerr << "矩阵初始化值错" << endl; exit(1);
	}
	smArray = new Trituple<T>[maxSz];
	if (smArray == NULL) {
		cerr << "存储分配错" << endl; exit(1);
	}
	Rows = Cols = Terms = 0;
}

template<class T>
SparseMatrix<T>::SparseMatrix(SparseMatrix<T>& x) {
	Rows = x.Rows; Cols = x.Cols; Terms = x.Terms;
	maxTerms = x.maxTerms;
	smArray = new Trituple<T>[maxTerms];
	if (smArray == NULL) {
		cerr << "存储分配错" << endl; exit(1);
	}
	for (int i = 0; i < Terms; i++) {
		smArray[i] = x.smArray[i];                                           //逐个结点=复制。
	}
}

template<class T>
ostream& operator<< (ostream out, SparseMatrix<T>& M) {
	out << "rows = " << M.Rows << endl;
	out << "cols = " << M.Cols << endl;
	out << "Nonzero terms = " << M.Terms << endl;
	for (int i = 0; i < M.Terms; i++) {
		out << "M[" << M.smArray[i].row << "][" << M.smArray[i].col << "]=" << M.smArray[i].value << endl;
	}
	return out;
}

template<class T>
ostream& operator>>(ostream in, SparseMatrix<T>& M) {
	cout << "Enter number of rows,columns,and terms" << endl;
	in >> M.Rows >> M.Cols >> M.Terms;
	if (M.Terms > maxTerms) {
		cerr << "NUmber of terms overflow!" << endl; exit(1);
	}
	for (int i = 0; i < M.Terms; i++) {
		cout << "Enter row,column,and value of term:" << i + 1 << endl;
		in >> M.smArray[i].row >> M.smArray[i].col >> M.smArray[i].value;
	}
	return in;
}

template<class T>
SparseMatrix<T>SparseMatrix<T>::Transpose() {                           //稀疏矩阵转置运算
	SparseMatrix<T>b(maxTerms);                                         //创建一个稀疏矩阵类的对象b
	b.Rows = Cols;                                                       //矩阵b的行数=矩阵a的列数
	b.Cols = Rows;                                                      //矩阵b的列数=矩阵a的行数
	b.Terms = Terms;                                                    //矩阵b的非零元素数传送
	if (Terms > 0) {
		int k, i,CurrentB = 0;                                         //存放位置指针
	
		for (int k = 0; k < Cols; k++) {                                       //按列号做扫描，做cols行
			for (int i = 0; i < Terms; i++) {                                  //在数组中找到列号为k的三元组
				if (smArray[i].col == k) {
					b.smArray[CurrentB].row = k;
					b.smArray[CurrentB].col = smArray[i].row;
					b.smArray[CurrentB].value = smArray[i].value;
					CurrentB++;                                            //存放位置指针加一
				}
			}
		}
	}
	return b;
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::Add(SparseMatrix<T>& b) {           //两个稀疏矩阵相加
	SparseMatrix<T>result(Rows, Cols);                           //结果矩阵的三元表
	if (Rows != b.Rows || Cols = b.Cols) {
		cout << "Incompatible matrices" << endl;                   //两个矩阵规格不一样
		return result;                                            //返回空矩阵
	}
	int i = 0, j = 0, index_a, index_b;
	result.Terms = 0;
	while (i < Terms && j < b.Terms)
	{
		index_a = Cols * smArray[i].row + smArray[i].col;
		index_b = Cols * b.smArray[j].row + b.smArray[j].col;
		if (index_a < index_b) {                                  //A在b前面
			result.smArray[result, Terms] = smArray[i];
			i++;
		}
		else if (index_a > index_b) {                              //A在b后面
			result.smArray[result, Terms] = b.smArray[j];
		}
		else {                                                      //A与b相同位置
			result.smArray[result, Terms] = smArray[i];
			result.smArray[result, Terms].value = smArray[i].value + b.smArray[j].value;
			i++; j++;
		}
		result.Terms++;
	}
	//复制剩下的元素
	for(; i < Terms; i++) {
		result.smArry[result, Terms] = smArray[i];
		result.Terms++;
	}
	for (; j < b.Terms; j++) {
		result.smArray[result, Terms] = b.smArray[j];
		result.Terms++;
	}
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::Multiply(SparseMatrix<T>& b) {
	SparseMatrix<T> result(Rows, Cols);                                  //结果矩阵的三元组表
	if (Cols != b.Rows) {
		cerr << "Incompatible matrices" << endl;
		return result;                                  //A的列与b的行数不相等
	}
	if (Terms == maxTerms || b.Terms == maxTerms) {
		cerr << "One additonal space in a or b needed" << endl;
		return result;                                    //空间不足，返回空矩阵
	}
	int* rowSize = new int[b.Rows];                         //矩阵b各行非零元素个数
	int* rowStart = new int[b.Rows + 1];                    //矩阵b各行在三元组开始的位置
	T* temp = new T[b.Cols];                                //暂存每一行的计算结果
	int i, Current, lastInResult, RowA, ColA, ColB;
	for (i = 0; i < b.Rows; i++) rowSize[i] = 0;
	for (i = 0; i < b.Terms; i++) rowSize[b.smArray[i].row]++;
	rowStart[0] = 0;
	for (i = 0; i <= b.Rows; i++)rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
	Current = 0; lastInResult = -1;                           //a扫描指针及result存指针

	while (Current<Terms)
	{
		RowA = smArray[Current].row;                               //当前的行号
		for (i = 0; i < b.Cols; i++) temp[i] = 0;
		while (Current<Terms&&smArray[Current].row==RowA)
		{
			ColA = smArray[Current].col;
			for (i = rowStart[ColA]; i < rowStart[ColA + 1]; i++) {
				ColB = b.smArray[i].col;
				temp[ColB] += smArray[Current].value * b.smArray[i].value;
			}
			Current++;

		}
		
		for (i = 0; i < b.Cols; i++) {
			if (temp[i] != 0) {
				lastInResult++;
				result.smArray[lastInResult].row = RowA;
				result.smArray[lastInResult].col = i;
				result.smArray[lastInResult].value = temp[i];
			}
		}
	}
	result.Rows = Rows; result.Cols = b.Cols;
	result.Terms = lastInResult + 1;
	delete[]rowSize; delete[]rowStart; delete[]temp;
	return result;
}