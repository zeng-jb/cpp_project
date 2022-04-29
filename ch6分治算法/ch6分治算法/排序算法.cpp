//给定N个（长整型范围内的）整数，要求输出从小到大排序后的结果。
//
//本题旨在测试各种不同的排序算法在各种数据情况下的表现。各组测试数据特点如下：
//
//数据1：只有1个元素；
//数据2：11个不相同的整数，测试基本正确性；
//数据3：103个随机整数；
//数据4：104个随机整数；
//数据5：105个随机整数；
//数据6：105个顺序整数；
//数据7：105个逆序整数；
//数据8：105个基本有序的整数；
//数据9：105个随机正整数，每个数字不超过1000。
//11
//4 981 10 - 17 0 - 20 29 50 8 43 - 5

/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	vector<int> ll;
	int num;
	cin >> num;
	int input;
	int i;
	for (i = 0; i < num; ++i) {
		cin >> input;
		ll.push_back(input);
	}
	sort(ll.begin(), ll.end());
	for (i = 0; i < ll.size(); ++i) {
		if (i == ll.size() - 1) {
			cout << ll[i];
		}
		else {
			cout << ll[i] << " ";
		}

	}
	return 0;
}
*/