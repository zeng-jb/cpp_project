#include <iostream>
#include <cstdlib>
#define anrrySize 100
#define MaxInt 0x7fffffff      //int����� 2��32�η�-1
using namespace std;
void jiecheng(int A[], int n ,int& s  ) {
	A[0] = 1;
	if (n != 0) {
		int i, bounds = MaxInt / n / 2;
		for (i = 1; i < n; i++) {
			A[i] = A[i - 1] * i * 2;
			if (A[i] > bounds) {
			//	cerr << "failed at " << i << endl;  //��1����cerrִ�� �������
			//	exit(1);                            //��1��exit�˳�

			//	return 0;           //(2)��������ֵ0����ʾ����

				s = 0; return;     //(3)
			}
		}
		A[n] = A[n - 1] * n * 2;
	}
	cout << "A[" << n << "]=" << A[n] << endl;

	//return 1;     //(2)��������ֵ1����ʾ��ȷ
}
void main() {
	int A[anrrySize];
	int i;
	int s;   //�������α���������
	for (i = 0; i < anrrySize; i++) {
		jiecheng(A, i,s);

		if (!s) {
			cerr << "failed at " << i << endl; 
			break;
		}
	}
}