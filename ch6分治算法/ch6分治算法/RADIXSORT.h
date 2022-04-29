#pragma once
#include<iostream>
using namespace std;
//桶排序 存放数值数组，总数n，每个数位数m
void radixsort(int data[], int n, int m) {
	int k = m;
	int* tmp = new int[n];
	int* count = new int[10];		//计数器
	int index,i,j;
	int radix = 1;
	for (i = 1; i <= k; i++) {		//进行k位次排序
		for (int j = 0; j < 10; j++) {
			count[j] = 0;			//每次分配前清空计数器
		}
		for (j = 0; j < n; j++) {
			index = (data[j] / radix) % 10;
			count[index]++;
		}
		for (j = 1; j < 10; j++) {
			count[j] = count[j - 1] + count[j];	//将tmp中的位置依次分配给每个桶
		}
		for (j = n - 1; j >= 0; j--) {
			index = (data[j] / radix) % 10;
			tmp[count[index] - 1] = data[j];	//将所有桶中数据依次收集到tmp中
			count[index]--;
		}
		for (j = 0; j < n; j++) {
			data[j] = tmp[j];		//将临时数组复制到data中
		}
		radix = radix * 10;
	}
	delete[]tmp;
	delete[]count;
}