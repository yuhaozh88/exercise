//���������������aka LCS��LCS��һ���������ģ��������ַ����е����λ��һ������ͬ��
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
				dp[i + 1][j + 1] = dp[i][j] + 1;//����ж������ַ�����ĳһλ�ַ���ȣ���ô���ǵ���󹫹������г���һ����֮ǰ���ȼ�һ
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);//����ַ�����ĳһλ����ͬ��ô��ת��Ϊ������������ֵ
			}
		}
	}
	cout << dp[N][M];
	return 0;
}