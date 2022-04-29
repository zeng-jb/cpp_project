//#include"LCS.h"
//#include"MATCHAIN.h"
#include"FLOYD.h"
#include"KNAPSACK.h"
//LCS
//int main()
//{
//    char a[] = "xyxxzxyzxy";
//    char b[] = "zxzyyzxxyxxz";
//    int len1 = strlen(a);
//    int len2 = strlen(b);
//
//    printLCS(a, b, len1, len2);
//
//    for (int x = 0; x <= len1; x++) {
//        for (int y = 0; y <= len2; y++) {
//            cout << " " << L[x][y];
//        }
//        cout << endl;
//    }
//
//    return 0;
//}



//int main()
//{
//
//	int p[N + 1] = { 30,35,15,5,10,20,25 };
//	int m[N + 1][N + 1] = { 0 };
//	int s[N + 1][N + 1] = { 0 };
//	int i, j;
//	matrix_chain_order(p, N + 1, m, s);
//	cout << "m value is: " << endl;
//	for (i = 1; i <= N; ++i)
//	{
//		for (j = 1; j <= N; ++j)
//			cout << m[i][j] << " ";
//		cout << endl;
//	}
//	cout << "s value is: " << endl;
//	for (i = 1; i <= N; ++i)
//	{
//		for (j = 1; j <= N; ++j)
//			cout << s[i][j] << " ";
//		cout << endl;
//	}
//	cout << "The result is:" << endl;
//	print_optimal_parents(s, 1, N);
//	return 0;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n + 1; i++) {
//		cin >> p[i];
//		r[i] = p[i];
//	}
//		
//		
//	matrix();
//	cout << m[1][n] << endl;
//
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= n; j++) {
//			cout << " " << m[i][j];
//		}
//		cout << endl;
//	}
//
//	matchain();
//	cout << C[1][n] << endl;
//
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= n; j++) {
//			cout << " " << C[i][j];
//		}
//		cout << endl;
//	}
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= n; j++) {
//			cout << " " << s[i][j];
//		}
//		cout << endl;
//	}
//	
//	print_M( 1, n);
//	return 0;
//}

//int main() {
//	//cin >> n;
//	//for (int i = 0; i < n; i++) {
//	//	for (int j = 0; j < n; j++) {
//	//		cin >> d[i][j];
//	//	}
//	//}
//	int n = 3;
//	 d[N][N] = { {0,2,9},{8,0,6},{1,65535,0} };
//	Floyd(n);
//	print_F(n);
//}
int main()
{
	findMax();
	findWhat(4, 9);
	print();

	return 0;
}