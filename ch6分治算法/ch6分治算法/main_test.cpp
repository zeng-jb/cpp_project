#include"RADIXSORT.h"
#include"MERGESORT.h"
int main() {
	////»ùÊýÅÅÐò
	//int data[8] = { 7467,1247,3275,6792,9187,9134,4675,1239 };
	//int k = 4, n = 8;
	//radixsort(data,n, k);
	//for (int i = 0; i < 8; i++) {
	//	cout << data[i] << endl;
	//}

	//¹é²¢ÅÅÐò
	int data[8] = { 9,4,5,2,1,7,4,6 };
	int n = 8,l = 1;
	mergesort(data, l-1, n);
	for (int i = 0; i < n; i++) {
		cout << data[i] << " ";
	}
}