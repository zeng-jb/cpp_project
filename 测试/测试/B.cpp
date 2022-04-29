//#include <iostream>
//#include <math.h>
//
//using namespace std;
//
//#define ll long long
//
//ll gcd(ll a, ll b) {
//	ll temp1 = 1, temp2 = 1;
//	while (temp1) {
//		temp1 = a % b;
//		temp2 = a / b;
//		a = b;
//		b = temp1;
//	}
//	return a;
//}
//
//int main() {
//
//	ll a, b, n;
//	cin >> n;
//
//
//	for (int j = 0; j < n; j++) {
//		cin >> a >> b;
//		ll temp = gcd(a, b);
//		ll ans = 1, i;
//		for (i = 2; i < sqrt(temp); i++) {
//			if (temp % i == 0) {
//				ans += 2;
//			}
//		}
//		if (temp != 1) ans++;
//		if (i == sqrt(temp))ans++;
//
//		cout << ans << endl;
//	}
//
//	return 0;
//}
