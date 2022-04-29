#include<iostream>
using namespace std;

int a[1000001];
int main()
{
	int n,i=0;
	
	int b[6] = { 0,0,1,1,0,1 };
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &a[i++]);
	}
	for (; n < i; n++) {
		for (int j = 0; j < 6; j++) {
			if (b[j] == 0)continue;
			if (b[j] == a[n]) {
				printf("%d", j);
				b[j]++;
				break;
			}
		}
	}
	return 0;
}