#include <iostream>
#define arrySize 100
using namespace std;

void selct(int a[], int b[], int m, int n) {
	int i=0, j=0, k=0;
	int c[arrySize] = { 0 };
	while (i < m && j < n&&k<m+n) {
		if (a[i] < b[j]&&i<m) {
			c[k] = a[i++];
		}
		else {
			c[k] = b[j++];
		}
		k++;
	}
	if (i == m) {
		for (; j < n; j++) {
			c[k++] = b[j];
		}
	}
	else {
		for (; i < m; i++) {
			c[k++] = a[i];
		}
	}

	for (i = 0; i < k; i++) {
		cout << c[i] << " ";
	}
}

int main() {
	int m, n, a[arrySize], b[arrySize];

	cout << "请输入m和n的大小" << endl;
	cin >> m >> n;
	cout << "请输入两个整形数组a和b" << endl;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < n; j++) {
		cin >> b[j];
	}

	selct(a, b, m, n);
}

//该程序的时间复杂度为O（n) = T (n);