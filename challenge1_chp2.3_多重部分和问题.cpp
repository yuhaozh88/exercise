#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3;
const int K = 7;
int main()
{
	int a[N];
	int m[N];
	bool dp[N + 1][N + 1];
	dp[0][0] = true;
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N + 1; j++) {
			dp[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> m[i];
	}
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j <= K; j++) {
			for (int t = 0; t <= m[i] && t*a[i] <= j; t++) {
				dp[i + 1][j] |= dp[i][j - t*a[i]];
			}
		}
	}
	if (dp[N][K]) { cout << "yes"; return 0; }
	cout << "no";
	return 0;
}