//#include <cstdio>
//#include <iostream>
//#define _CRT_SECURE_NO_DEPRECATE
//using namespace std;
//int dp[3][1000004];
//
//int main()
//{
//	int T, n;
//	cin >> T;
//	while (T--)
//	{
//		int a, b, c;
//		cin >> n;
//		scanf_s("%d %d %d", &a, &b, &c);
//		dp[0][1] = a; dp[1][1] = b; dp[2][1] = c;
//		for (int i = 2; i <= n; i++) {
//			scanf_s("%d %d %d", &a, &b, &c);
//			dp[0][i] = max(dp[0][i - 2], max(dp[1][i - 1], dp[2][i-1])) + a;
//			dp[1][i] = max(dp[1][i - 2], max(dp[0][i - 1], dp[2][i-1])) + b;
//			dp[2][i] = max(dp[2][i - 2], max(dp[0][i - 1], dp[1][i-1])) + c;
//		}
//		//cout << max(dp[0][n], max(dp[1][n], dp[2][n])) << endl;
//		printf_s("%d\n", max(dp[0][n], max(dp[1][n], dp[2][n])));
//	}
//	return 0;
//}