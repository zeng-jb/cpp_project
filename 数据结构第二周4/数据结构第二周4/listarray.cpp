
#include <iostream>
#define arraySize 100
using namespace std;

void listaray(int a[], int n) {
	int tmp;
	int i = 0,j=n-1;
	while (i < j) {
		while (i < j && a[i] % 2) {
			i++;
		}
		while (i < j && a[j] % 2 == 0) {
			j--;
		}
		if (i < j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	for (i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	int n, a[arraySize];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	listaray(a, n);
}