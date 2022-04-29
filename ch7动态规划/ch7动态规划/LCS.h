#pragma once
#include <iostream>
#include<math.h>
#include<algorithm>
using namespace std;


int L[101][101];

void LCS(char a[],char b[],int len1, int len2) {
	for (int i = 0; i <= len1; i++) {
		L[i][0] = 0;
	}
	for (int j = 0; j <= len2; j++) {
		L[0][j] = 0;
	}
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (a[i-1] == b[j-1]) {
				L[i][j] = L[i - 1][j - 1] + 1;
			}
			else {
				L[i][j] = max(L[i][j - 1], L[i - 1][j]);
			}
		}
	}
}

void printLCS(char a[], char b[], int len1, int len2) {
    LCS(a, b, len1, len2);
    int i, j, z = 0;
    char c[101];
    memset(c, 0, sizeof(c));
    i = len1, j = len2;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            c[z++] = a[--i];
            j--;
        }
        else if (L[i - 1][j] < L[i][j - 1])
            j--;
        else if (L[i][j - 1] <= L[i - 1][j])
            i--;
    }
    for (i = z - 1; i >= 0; i--)
        printf("%c", c[i]);
    printf("\n");
}