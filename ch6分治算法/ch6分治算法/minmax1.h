#pragma once
//�ݹ鷵�����ֵ��Сֵ
#include <iostream>
using namespace std;
void minmax(int a[], int& low, int& high) {
	int min=0, max=n;
	if (max - min == 1) {
		if (a[min] < a[max]) {
			low = a[min]; high = a[max];
		}
	}
	else {
		int mid = (min + max) / 2;
		low = min; high = mid;
		minmax(a,low,high)
	}
}