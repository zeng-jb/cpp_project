#pragma once
#include<iostream>
using namespace std;
void MERGE(int num[], int low, int mid, int high) {
	int i = low, j = mid, k = i;
	int* tmp = new int[high+1];
	while (i < mid && j <= high)
	{
		if (num[i] < num[j])tmp[k] = num[i++];
		else tmp[k] = num[j++];
		k++;
	}
	if (i == mid) {
		while (j <= high) tmp[k++] = num[j++];
	}
	else {
		while (i < mid)   tmp[k++] = num[i++];
	}


	for (i = low; i <= high; i++) num[i] = tmp[i];
}

void mergesort(int data[], int low, int high) {
	
	if (low < high) {
		int mid = (low + high) / 2;
		mergesort(data, low, mid);
		mergesort(data, mid + 1, high);
		MERGE(data, low, mid, high);
	}
}