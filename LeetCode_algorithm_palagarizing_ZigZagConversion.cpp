//@palagiarzing yuhaozh88
#include<iostream>
#include<algorithm>
using namespace std;

class Solution
{
	public:
		string convert(string s, int numRows) {
			if (s.length() == 0 || numRows <= 1) {
				return s;
			}
			string* ans = new string [numRows];
			for (int i = 0; i < numRows; i++) {
				ans[i] = "";
			}
			int row = 0, dire = 1;
			for (int i = 0; i < s.length(); i++) {
				ans[row] += s[i];
				row += dire;
				if (row >= numRows) {
					row = numRows - 2;
					dire = -1;
				}
				if (row < 0) {
					row = 1;
					dire = 1;
				}
			}

			string ret = "";
			for (int i = 0; i < numRows; i++) {
				ret += ans[i];
			}
			return ret;
		}
};