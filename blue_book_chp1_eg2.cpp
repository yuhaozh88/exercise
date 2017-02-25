//Ì°ĞÄËã·¨
//@author yuhaozh88
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3;

class soldier
{
public :
	int bi;
	int ji;
public :
	soldier() { bi = 0; ji = 0; }
};
int main()
{
	soldier Soldier[N];
	for (int i = 0; i < N; i++) {
		cin>>Soldier[i].bi>>Soldier[i].ji;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (Soldier[j].ji < Soldier[j].ji) {
				swap(Soldier[j], Soldier[j + 1]);
			}
		}
	}
	int time_b = 0;
	int time_j = 0;
	for (int i = 0; i < N; i++) {
		time_j += Soldier[i].ji;
	}
	for (int i = 1; i < N; i++) {
		if (Soldier[i].bi < Soldier[i-1].ji) {
			time_j -= Soldier[i - 1].ji - Soldier[i].bi;
		}
	}
	cout << Soldier[0].bi + time_j;
}