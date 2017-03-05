//@author yuhaozh88
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string str = "";
		char temp;
		int min_length = 1000;
		for (int i = 0; i < strs.size() - 1; i++) {
			if (strs[i].length() < min_length) {
				min_length = strs[i].length();
			}
		}
		for (int i = 0; i < min_length; i++) {
			temp = strs[0][i];
			for (int j = 0; j < strs.size(); j++) {
				if (strs[j][i] != temp) {
					return str;
				}
			}
			str += temp;
		}
		return str;
	}
};