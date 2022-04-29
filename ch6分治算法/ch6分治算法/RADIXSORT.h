#pragma once
#include<iostream>
using namespace std;
//Ͱ���� �����ֵ���飬����n��ÿ����λ��m
void radixsort(int data[], int n, int m) {
	int k = m;
	int* tmp = new int[n];
	int* count = new int[10];		//������
	int index,i,j;
	int radix = 1;
	for (i = 1; i <= k; i++) {		//����kλ������
		for (int j = 0; j < 10; j++) {
			count[j] = 0;			//ÿ�η���ǰ��ռ�����
		}
		for (j = 0; j < n; j++) {
			index = (data[j] / radix) % 10;
			count[index]++;
		}
		for (j = 1; j < 10; j++) {
			count[j] = count[j - 1] + count[j];	//��tmp�е�λ�����η����ÿ��Ͱ
		}
		for (j = n - 1; j >= 0; j--) {
			index = (data[j] / radix) % 10;
			tmp[count[index] - 1] = data[j];	//������Ͱ�����������ռ���tmp��
			count[index]--;
		}
		for (j = 0; j < n; j++) {
			data[j] = tmp[j];		//����ʱ���鸴�Ƶ�data��
		}
		radix = radix * 10;
	}
	delete[]tmp;
	delete[]count;
}