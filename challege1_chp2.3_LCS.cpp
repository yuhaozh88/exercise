//最长公共子序列问题aka LCS，LCS不一定是连续的，但是在字符串中的相对位置一定是相同的
//@author yuhaozh88
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 4;// the length of the first string
const int M = 5;// the length of the second string

int main()
{
	int dp[N + 1][M + 1];
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < M + 1; j++) {
			dp[i][j] = 0;
		}
	}
	char s[N];
	char t[M];
	cin >> s >> t;
	cout << s << t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (s[i] == t[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;//如果判断两个字符串的某一位字符相等，那么他们的最大公共子序列长度一定是之前长度加一
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);//如果字符串的某一位不相同那么就转化为两种情况的最大值
			}
		}
	}
	cout << dp[N][M];
	return 0;
}