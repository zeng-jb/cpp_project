//#include <iostream>
//#include<time.h>
//using namespace std;
//
//void MERGE(int num[], int low, int mid, int high) {
//	int i = low, j = mid, k = i;
//	int* tmp = new int[high + 1];
//	while (i<mid&&j<=high)
//	{
//		if (num[i] < num[j])tmp[k] = num[i++];
//		else tmp[k] = num[j++];
//		k++;
//	}
//	if (i == mid) {
//		while (j<=high) tmp[k++] = num[j++];
//	}
//	else {
//		while (i<mid)   tmp[k++] = num[i++];
//	}
//
//	
//	for (i = low; i <= high; i++) num[i] = tmp[i];
//}
//
//void BOTTOMUPSORT(int A[],int n) {
//	int t = 1;
//	while (t<n)
//	{
//		int i = 0;
//		while ((i+t*2)<=n)
//		{
//			MERGE(A, i, i+t, i+t*2-1);
//			i = i + t*2;
//		}
//		if (i + t < n) MERGE(A, i, i + t, n-1);
//		t = t * 2;
//	}
//}
//
////void main() {
////	//int A[8] = { 9,4,5,2,1,7,4,6 };
////	//int n = 8;
////
////	//BOTTOMUPSORT(A,n);
////	//MERGE(A, 0, 4, 7);
////	int a[11];
////	srand((unsigned int(time(NULL))));
////	for (int i = 0; i < 11; i++) a[i] = rand() % 10;
////	BOTTOMUPSORT(a, 11);
////	for (int i = 0; i < 11; i++) {
////		cout << " " << a[i];
////	}
////	cout << endl;
////}