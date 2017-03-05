//@auhtor yuhaozh88
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int gap = 2 * numRows - 2;
		int pos = 0;
		bool type = false;
		string ans="";
		for (int i = 0; i < numRows; i++) {
			int first = 2 * i;
			int second = gap - first;
			int begin = i;
			queue<char> temp;
			while (begin < s.length() - 1) {
				ans += s[begin];
				if (type==true&&first!=0){
					begin += first;
				}
				else if (type==false&&second!=0) {
					begin += second;
				}
				else if (type == true && first == 0) {
					begin += second;
				}
				else {
					begin += first;
				}
				type = !type;
			}
		}
		return ans;
	}
};


int main()
{
	Solution s;
	string ans = s.convert("PAYPALISHIRING", 3);
	for (int i = 0; i < ans.length(); i++) {
		cout << ans[i];
	}

}