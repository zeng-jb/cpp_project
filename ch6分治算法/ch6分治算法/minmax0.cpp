#include <iostream>
using namespace std;

void minmax(int a[],int n,int& min, int& max) {
	max = a[0]; min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] < min)min = a[i];
		if (a[i] > max)max = a[i];
	}
}

//void main() {
//	//int a[5] = {1,2,3,5,9};
//	int a[6] = { 10,25,0,-1,9,2 };
//	int n = sizeof(a) / sizeof(a[0]);
//	int min, max;
//	minmax(a, n, min, max);
//	cout << "max:" << max << " " << "min:" << min << endl;
//}