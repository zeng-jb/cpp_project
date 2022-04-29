//#include<iostream>
//#include<math.h>
//using namespace std;
//
//int main()
//{
//	int num, n, flag = 0;
//	while (cin>>num && num!=0)
//	{
//		if (num == 1) {
//			cout << "YES" << endl;
//			continue;
//		}
//		for (int i = 2; i <= sqrt(num); i++) {
//			flag = 0;
//			n = num;
//			if (n % i != 0) {
//				continue;
//			}
//			else
//			{
//				while (n!=1 && n%i==0) {
//					n /= i;
//				}
//				if (n == 1) {
//					flag = 1;
//				}
//			}
//			if (flag) {
//				cout << "YES" << endl;
//				goto here;
//			}
//		}
//		cout << "NO" << endl;
//	here:;
//	}
//}