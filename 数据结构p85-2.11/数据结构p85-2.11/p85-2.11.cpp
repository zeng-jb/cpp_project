#define arraySize 100
#include  <iostream>
using namespace std;

void selctmaxmin(int a[],int n) {
	int max, min;
	int i = 0;
	max = a[i];
	min = a[i];
	for (i = 1; i < n; i++) {
		if (max < a[i]) max = a[i];
		if (min > a[i]) min = a[i];
	}
	cout << max << " " << min << endl;
}
int main()
{
	int a[arraySize], n;
	cout << "请输入数组大小n" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	selctmaxmin(a,n);
}
