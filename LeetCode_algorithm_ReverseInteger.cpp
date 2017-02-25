//��Ϊֵ��ע��ĵط�ʱ���жϷ�ת֮������Ƿ񳬳���ΧʱӦ��ע��Ҫ��ans/margin��Ϊans�п���Ϊ0������ע��Ӧ�ý�margin����Ϊdouble����ʼ��Ϊ0
//@author yuhaozh88
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

const double margin = double(pow(2, 31) - 1);
class Solution {
public:
	int reverse(int x) {
		if (x > 0&&x<margin) {
			queue<int>store;
			while (x != 0) {//���������в��
				store.push(x % 10);
				x = 0.1*(x - x % 10);
			}
			int ans = 0;
			double test = ans /margin;
			while (!store.empty()) {
				if (test<=0.1&&(margin - 10 * ans >= store.front())) {
					ans = 10 * ans + store.front(); 
					test = ans / margin;
					store.pop();
				}
				else {
					return 0;
				}
			}
			return ans;
		}
		else if (x < 0&&x>-margin) {
			int y = -x;
			queue<int>store;
			while (y != 0) {//��ת���ɵ����������в��
				store.push(y % 10);
				y = 0.1*(y - y % 10);
			}
			int ans = 0;
			double test = ans / margin;
			while (!store.empty()) {
				if (test<=0.1&&(margin - 10 * ans >= store.front())) {
					ans = 10 * ans + store.front();
					test=ans/margin;
					store.pop();
				}
				else {
					return 0;
				}
			}
			return -ans;
		}
		else {
			return 0;
		}
	}
};

int main()
{
	Solution s;
	cout << s.reverse(-2147483648);
	return 0;
}