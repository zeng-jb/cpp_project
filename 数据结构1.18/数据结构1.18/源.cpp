#include <iostream>
#include <cstdlib>
#define anrrySize 100
#define MaxInt 0x7fffffff      //int的最大 2的32次方-1
using namespace std;
void jiecheng(int A[], int n ,int& s  ) {
	A[0] = 1;
	if (n != 0) {
		int i, bounds = MaxInt / n / 2;
		for (i = 1; i < n; i++) {
			A[i] = A[i - 1] * i * 2;
			if (A[i] > bounds) {
			//	cerr << "failed at " << i << endl;  //（1）用cerr执行 报告错误
			//	exit(1);                            //（1）exit退出

			//	return 0;           //(2)返回整数值0，表示错误

				s = 0; return;     //(3)
			}
		}
		A[n] = A[n - 1] * n * 2;
	}
	cout << "A[" << n << "]=" << A[n] << endl;

	//return 1;     //(2)返回整数值1，表示正确
}
void main() {
	int A[anrrySize];
	int i;
	int s;   //设置整形变量，引用
	for (i = 0; i < anrrySize; i++) {
		jiecheng(A, i,s);

		if (!s) {
			cerr << "failed at " << i << endl; 
			break;
		}
	}
}