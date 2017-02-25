//��������01����̬�滮����dp���鲻�Ͻ��н���ļ�¼��ע��dp[i][j]��ʾ�ӵ�i+1��������ʼװ������Ϊj�ı������ջ������ֵ
//@author yuhaozh88
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 4;//N bag(s)
const int W = 5;//total weight of the bag(s)

class bag
{
public :
	int weight;
	int value;
public :
	bag() { weight = 0; value = 0; }
	bag(int in_w, int in_v) { weight = in_w; value = in_v; }
};

int main()
{
	int dp[N + 1][W + 1];//array to sotre the record of different conditions
	for (int i = 0; i < N + 1; i++) {//initialize the array
		for (int j = 0; j < N + 1; j++) {
			dp[i][j] = 0;
		}
	}
	bag arr[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i].weight >> arr[i].value;
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < W + 1; j++) {//the int j is acctually control the weight of the amount of weight left
			if (j >= arr[i].weight) {//this bag can be taken in
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - arr[i].weight] + arr[i].value);
			}
			else {
				dp[i][j] = dp[i + 1][j];
			}
		}
	}
	cout << dp[0][W];

}