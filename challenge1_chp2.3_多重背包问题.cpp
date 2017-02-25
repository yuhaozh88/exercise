//此题为完全背包问题，每种类型的背包可以选择无穷多次，注意它与背包问题01的区别只在递归中的一种情况的处理
//@author yuhaozh88
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3;
const int W = 7;

class bag
{
public :
	int weight;
	int value;
public :
	bag() { weight = 0; value = 0; }
};

int main()
{
	bag arr[N];
	int dp[N + 1][W + 1];
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < W + 1; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> arr[i].weight >> arr[i].value;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < W + 1; j++) {
			if (arr[i].weight <= j) {//this bag can be taken in 
				dp[i + 1][j] = max(dp[i][j], dp[i+1][j - arr[i].weight] + arr[i].value);
			}
			else {
				dp[i + 1][j] = dp[i][j];
			}
		}
	}
	cout << dp[N][W];
	return 0;
}


//int main()
//{
//	bag arr[N];
//	int dp[N + 1][W + 1];
//	for (int i = 0; i < N + 1; i++) {
//		for (int j = 0; j < W + 1; j++) {
//			dp[i][j] = 0;
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		cin >> arr[i].weight >> arr[i].value;
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < W + 1; j++) {
//			if (arr[i].weight <= j) {//this bag can be taken in 
//				dp[i + 1][j] = max(dp[i][j], dp[i][j - arr[i].weight] + arr[i].value);
//			}
//			else {
//				dp[i + 1][j] = dp[i][j];
//			}
//		}
//	}
//	cout << dp[N][W];
//	return 0;
//}

