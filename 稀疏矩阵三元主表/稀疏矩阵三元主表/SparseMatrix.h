#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;
const int DafaultSize = 100;

template <class T>
struct Trituple                                              //��Ԫ����Trituple
{
	int row, col;                                            //��0Ԫ�ص��кš��к�
	T value;                                                 //����Ԫ�ص�ֵ
	Trituple<T>& operator=(Trituple<T>& x)                   //��㸳ֵ
	{
		row = x.row; col = x.col; value = x.value;
	}
};

template<class T>
class SparseMatrix                                            //ϡ������������
{
public:
	friend ostream& operator << (ostream& out, SparseMatrix<T>& M);        //��Ԫ������������ط���������
	friend ostream& operator >> (ostream& in, SparseMatrix<T>& M);         //��Ԫ���������������������أ�
public:
	SparseMatrix(int maxSz=DafaultSize);                                           //���캯��
	SparseMatrix(SparseMatrix<T>& x);                                             //���ƹ��캯��
	~SparseMatrix() { delete[]smArray; }                                          //��������
	SparseMatrix<T>& operator=(SparseMatrix<T>& x);
	SparseMatrix<T> Transpose();                                                   //ת�þ���
	SparseMatrix<T> Add(SparseMatrix<T>& b);                                       //�����b���
	SparseMatrix<T> Multiply(SparseMatrix<T>& b);                                    //�����b���
private:
	int Rows, Cols, Terms;
	Trituple<T>* smArray;
	int maxTerms;
};

template<class T>
SparseMatrix<T>::SparseMatrix(int maxSz) :maxTerms(maxSz) {
	if (maxSz < 1) {
		cerr << "�����ʼ��ֵ��" << endl; exit(1);
	}
	smArray = new Trituple<T>[maxSz];
	if (smArray == NULL) {
		cerr << "�洢�����" << endl; exit(1);
	}
	Rows = Cols = Terms = 0;
}

template<class T>
SparseMatrix<T>::SparseMatrix(SparseMatrix<T>& x) {
	Rows = x.Rows; Cols = x.Cols; Terms = x.Terms;
	maxTerms = x.maxTerms;
	smArray = new Trituple<T>[maxTerms];
	if (smArray == NULL) {
		cerr << "�洢�����" << endl; exit(1);
	}
	for (int i = 0; i < Terms; i++) {
		smArray[i] = x.smArray[i];                                           //������=���ơ�
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
SparseMatrix<T>SparseMatrix<T>::Transpose() {                           //ϡ�����ת������
	SparseMatrix<T>b(maxTerms);                                         //����һ��ϡ�������Ķ���b
	b.Rows = Cols;                                                       //����b������=����a������
	b.Cols = Rows;                                                      //����b������=����a������
	b.Terms = Terms;                                                    //����b�ķ���Ԫ��������
	if (Terms > 0) {
		int k, i,CurrentB = 0;                                         //���λ��ָ��
	
		for (int k = 0; k < Cols; k++) {                                       //���к���ɨ�裬��cols��
			for (int i = 0; i < Terms; i++) {                                  //���������ҵ��к�Ϊk����Ԫ��
				if (smArray[i].col == k) {
					b.smArray[CurrentB].row = k;
					b.smArray[CurrentB].col = smArray[i].row;
					b.smArray[CurrentB].value = smArray[i].value;
					CurrentB++;                                            //���λ��ָ���һ
				}
			}
		}
	}
	return b;
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::Add(SparseMatrix<T>& b) {           //����ϡ��������
	SparseMatrix<T>result(Rows, Cols);                           //����������Ԫ��
	if (Rows != b.Rows || Cols = b.Cols) {
		cout << "Incompatible matrices" << endl;                   //����������һ��
		return result;                                            //���ؿվ���
	}
	int i = 0, j = 0, index_a, index_b;
	result.Terms = 0;
	while (i < Terms && j < b.Terms)
	{
		index_a = Cols * smArray[i].row + smArray[i].col;
		index_b = Cols * b.smArray[j].row + b.smArray[j].col;
		if (index_a < index_b) {                                  //A��bǰ��
			result.smArray[result, Terms] = smArray[i];
			i++;
		}
		else if (index_a > index_b) {                              //A��b����
			result.smArray[result, Terms] = b.smArray[j];
		}
		else {                                                      //A��b��ͬλ��
			result.smArray[result, Terms] = smArray[i];
			result.smArray[result, Terms].value = smArray[i].value + b.smArray[j].value;
			i++; j++;
		}
		result.Terms++;
	}
	//����ʣ�µ�Ԫ��
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
	SparseMatrix<T> result(Rows, Cols);                                  //����������Ԫ���
	if (Cols != b.Rows) {
		cerr << "Incompatible matrices" << endl;
		return result;                                  //A������b�����������
	}
	if (Terms == maxTerms || b.Terms == maxTerms) {
		cerr << "One additonal space in a or b needed" << endl;
		return result;                                    //�ռ䲻�㣬���ؿվ���
	}
	int* rowSize = new int[b.Rows];                         //����b���з���Ԫ�ظ���
	int* rowStart = new int[b.Rows + 1];                    //����b��������Ԫ�鿪ʼ��λ��
	T* temp = new T[b.Cols];                                //�ݴ�ÿһ�еļ�����
	int i, Current, lastInResult, RowA, ColA, ColB;
	for (i = 0; i < b.Rows; i++) rowSize[i] = 0;
	for (i = 0; i < b.Terms; i++) rowSize[b.smArray[i].row]++;
	rowStart[0] = 0;
	for (i = 0; i <= b.Rows; i++)rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
	Current = 0; lastInResult = -1;                           //aɨ��ָ�뼰result��ָ��

	while (Current<Terms)
	{
		RowA = smArray[Current].row;                               //��ǰ���к�
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