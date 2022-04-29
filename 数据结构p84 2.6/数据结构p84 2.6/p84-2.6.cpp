#include <iostream>
//#pragma comment( lib,"MSVCRTD.lib")
#define arraySize 100
using namespace std;

void salearray(int A[arraySize], int n) {
	int i = 0;
	int tmp;
	while (i <n/2) {
		tmp = A[i];
		A[i] = A[n-1-i];
		A[n-1-i] = tmp;
		i++; 
	}
	for (i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
}

int main() {
	int A[arraySize], n;

	cin >> n;   //´æ·Ån¸öÊý
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	salearray(A, n);

	
}