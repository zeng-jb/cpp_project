#pragma once
#pragma once
#include<iostream>
using namespace std;
#define MAXVALUE 1000000
#define N 6

void matrix_chain_order(int* p, int len, int m[N + 1][N + 1], int s[N + 1][N + 1])
{
	int i, j, k, t;
	for (i = 0; i <= N; ++i)
		m[i][i] = 0;
	for (t = 2; t <= N; t++)  //��ǰ���˾���ĳ���
	{
		for (i = 1; i <= N - t + 1; i++)  //�ӵ�һ����ʼ���𣬼��㳤��Ϊt�����ٴ���
		{
			j = i + t - 1;//����Ϊtʱ������һ��Ԫ��
			m[i][j] = MAXVALUE;  //��ʼ��Ϊ������
			for (k = i; k <= j - 1; k++)   //Ѱ�����ŵ�kֵ��ʹ�÷ֳ�������k��i��j-1֮��
			{
				int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (temp < m[i][j])
				{
					m[i][j] = temp;   //��¼�µ�ǰ����С����
					s[i][j] = k;      //��¼��ǰ������λ�ã�������ı��
				}
			}
		}
	}
}
//s�д�������ŵ�ǰ��λ��
void print_optimal_parents(int s[N + 1][N + 1], int i, int j)
{
	if (i == j)
		cout << "A" << i;
	else
	{
		cout << "(";
		print_optimal_parents(s, i, s[i][j]);
		print_optimal_parents(s, s[i][j] + 1, j);
		cout << ")";
	}
}



const int MAX = 1005;
int p[MAX];
int m[MAX][MAX];
int n;
void  matrix()
{
	int i, j, r, k;
	memset(m, 0, sizeof(m));
	for (r = 2; r <= n; r++)
	{
		for (i = 1; i <= n - r + 1; i++)
		{
			j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			for (k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
				}
			}
		}
	}
}


int C[MAX][MAX];
int r[MAX];
int s[MAX][MAX] = { 0 };
void matchain() {
	int i, j,d,k;
	for (i = 0; i <= n; i++) {
		C[i][i] = 0;
	}
	for (d = 2; d <= n; d++) {
		for (i = 1; i <= n - d+1; i++) {
			j = i + d-1;
			C[i][j] = 65535;
			for (k = i; k <= j-1; k++) {
				C[i][j] = min(C[i][j], C[i][k] + C[k+1][j] + r[i-1] * r[k] * r[j]);
				s[i][j] = d-1;
			}
		}
	}
}

//s�д�������ŵ�ǰ��λ��
void print_M( int i, int j)
{
	if (i == j)
		cout << "M" << i;
	else
	{
		cout << "(";
		print_M( i, s[i][j]);
		print_M( s[i][j] + 1, j);
		cout << ")";
	}
}