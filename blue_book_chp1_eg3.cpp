//ԭ��Ŀ�Ǽ��������Ž�������ת���ٵĴ���ʹ��ÿ���˶��ܵõ���ȵĽ�ң�����ͨ��һϵ�е�ת������ת��Ϊ��λ��������
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
	if (N % 2 != 0) {//���������ݵ���λ�����м���Ǹ���
		position = C[int(N / 2) + 1];
	}
	else {//ż�������ݵ���λ�������м����������ƽ����
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