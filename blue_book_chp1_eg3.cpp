//原题目是几个人拿着金币如何流转最少的次数使得每个人都能得到相等的金币，而后通过一系列的转化将其转变为中位数的问题
//@author yuhaozh88
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 4;

int main() {
	int total = 0;
	int C[N+1];
	int temp = 0;
	for (int i = 1; i < N+1; i++) {
		cin >> temp;
		total += temp;
		C[i] = total;
	}
	int M = total / N;
	for (int i = 1; i < N ; i++) {
		C[i] -= i*M;
	}
	sort(&C[1], &C[N]);
	int position = 0;
	if (N % 2 != 0) {//奇数个数据的中位数是中间的那个数
		position = C[int(N / 2) + 1];
	}
	else {//偶数个数据的中位数等于中间的两个数的平均数
		int temp = N / 2;
		position = 0.5*(C[temp] + C[temp + 1]);
	}
	int amount = 0;
	for (int i = 1; i < N; i++) {
		amount += abs(position - C[i]);
	}
	amount += abs(position);
	cout << amount;
	return 0;
}