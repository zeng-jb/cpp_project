#pragma once
#include<iostream>
#include<math.h>
#define N 3
using namespace std;

int d[N][N];
void Floyd(int n) {
	for (int k = 0; k < n; k++) {
		for (int  i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}
void print_F(int n) {
	cout << "所有点对的最短路径如下：" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
}