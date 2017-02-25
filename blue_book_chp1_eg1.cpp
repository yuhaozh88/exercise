//@author yuhaozh88
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2;
const int M = 1;

int main()
{
	int n[N];
	int m[M];
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> m[i];
	}
	sort(n, n + N);
	sort(m, m + M);
	int cost = 0;
	int num=0;
	for (int i=0; i < M; i++) {//i represents the number of the warriors, j represents the number of the heads of the dragons
		if (m[i] >= n[num]) {
			cost += m[i];
			num++;
		}
		if (num == N) {
			break;
		}
	}
	if (num == N) {
		cout << cost;
		return 0;
	}
	cout << "the dragon survives!";
	return 0;
}