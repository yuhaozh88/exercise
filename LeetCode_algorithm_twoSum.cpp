//@author yuhaozh88
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>copy;
		for (int i = 0; i < nums.size(); i++) {
			copy.push_back(nums[i]);
		}
		sort(copy.begin(), copy.end());
		int begin = 0;
		int end = copy.size()-1;
		vector<int> ans;
		while (begin < end) {
			if (copy[begin] + copy[end] < target) {
				begin++;
			}
			else if (copy[begin] + copy[end] > target) {
				end--;
			}
			else {
				ans = find(nums, copy, begin, end);
				break;
			}
		}
		return ans;
	};
	vector<int> find(vector<int>& nums, vector<int>& copy, int x, int y) {
		int temp1 = copy[x];
		int temp2 = copy[y];
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == temp1 || nums[i] == temp2) {
				ans.push_back(i);
			}
		}
		return ans;
	}
};
