//最为值得注意的地方时在判断反转之后的数是否超出范围时应该注意要用ans/margin因为ans有可能为0，并且注意应该将margin设置为double否则始终为0
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
			while (x != 0) {//将整数进行拆分
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
			while (y != 0) {//将转化成的正整数进行拆分
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