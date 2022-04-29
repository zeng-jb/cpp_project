#include<iostream>
using namespace std;

//QUICKSORT
//划分算法，先序遍历
int w=0;
int low = 0, high;
void SPLIT(int a[], int w) {
	int i = low;
	int x = a[low];
	int item;
	for (int j = low; j < high; j++) {
		if (a[j] <= x) {
			i = i + 1;
			if (i != j) {
				item = a[i]; a[i] = a[j]; a[j] = item;
			}
		}
	}
	item = a[i]; a[i] = a[low]; a[low] = item;
	w = i;

}

void QUICKSORT(int a[], int low, int high) {
	if (low < high) {
		SPLIT(a, w);
		QUICKSORT(a, low, w - 1);
		QUICKSORT(a, w + 1, high);
	}
}
