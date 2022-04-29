//#include <iostream>
//#include<string>
//#include<stdlib.h>
//#include<stdio.h>
//using namespace std;
//const int  maxn = 10000;
//
//char* str[maxn];
//
//
//
//
//void get(int n) {
//
//	for (int i = 0; i < n; i++) {
//		str[i] = new char;
//		cin >> str[i];
//		
//	}
//}
//void out(int n) {
//	int i = 0;
//	char* p;
//	p = str[0];
//	while (i<n)
//	{
//		p = *(str + i++);
//			cout << p<<endl;
//	}
//}
//void fx(int L, int R) {
//	char** p;
//	p = str;
//	for (p=p+L; p <= p+R; p++) {
//		int j = 0,num = 0;
//		while (**p+j!='\0')
//		{
//			num += (**p+j)-'0';
//			j++;
//		}
//		cout << num << endl;
//		//itoa(num, *p, 10);
//		//sprintf(*p, "%d", num);
//	}
//}
//void sortmin(int L, int R) {
//	int index;
//	int len;
//	for (int i = L; i < R; i++) {
//
//	}
//}
//int main() {
//	int n, m, o, L, R;
//	cin >> n >> m;
//	get(n);
//	out(n);
//	while (m>0)
//	{
//		m--;
//		cin >> o >> L >> R;
//		if (o == 1) fx(L, R);
//		else sortmin(L, R);
//	}
//	out(n);
//	return 0;
//}