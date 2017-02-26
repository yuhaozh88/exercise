//@author yuhaozh88
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) {//负数没有回文数
			return false;
		}
		else {//整数或者0
			int copy = x;
			int test = 0;
			while (copy != 0) {
				int temp = copy % 10;
				copy = (copy - temp) / 10;
				test = 10 * test + temp;
			}
			if (test == x) {
				return true;
			}
			else {
				return false;
			}
		}
	}
};
