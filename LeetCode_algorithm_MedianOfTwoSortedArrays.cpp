//这道题格外重要的一点就是由于连个数组的长度不相同，所以进行截短的时候不能直接截掉当前数组长度的一般，而是应该取两者之中较短的长度
//@author yuhaozh88
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int N = nums1.size();
		int M = nums2.size();
		if (N == 0 && M != 0) {
			if (M % 2 == 0) {
				int mid = M / 2;
				return 0.5*(double(nums2[mid - 1]) + double(nums2[mid]));
			}
			else {
				int mid = M / 2;
				return double(nums2[mid]);
			}
		}
		else if (N != 0 && M == 0) {
			if (N % 2 == 0) {
				int mid = N / 2;
				return 0.5*(double(nums1[mid - 1]) + double(nums1[mid]));
			}
			else {
				int mid = N / 2;
				return double(nums1[mid]);
			}
		}
		else {
			if ((N + M) % 2 == 0) {//总共有偶数个数字的情况
				int total = M + N - 2;
				int low = 0;
				int high = 0;
				int begin_n = 0;
				int begin_m = 0;
				int end_n = N - 1;
				int end_m = M - 1;
				int mid_n = 0.5*(begin_n + end_n);
				int mid_m = 0.5*(begin_m + end_m);
				while (!((low + high == total) || ((mid_n - begin_n <= 1 || -mid_n + end_n <= 1) || (mid_m - begin_m <= 1 || -mid_m + end_m <= 1)))) {
					if (nums1[mid_n] <= nums2[mid_m]) {
						int length = min(mid_n - begin_n - 1, end_m - mid_m - 1);
						low += length;
						begin_n += length;
						mid_n = 0.5*(begin_n + end_n);
						high += length;
						end_m -= length;
						mid_m = 0.5*(begin_m + end_m);
					}
					else {
						int length = min(end_n - mid_n - 1, mid_m - begin_m - 1);
						high += length;
						end_n -= length;
						mid_n = 0.5*(begin_n + end_n);
						low += length;
						begin_m += length;
						mid_m = 0.5*(begin_m + end_m);
					}
				}
				if ((low + high) != total) {
					vector<int> temp;
					for (int i = begin_n; i <= end_n; i++) {
						temp.push_back(nums1[i]);
					}
					for (int i = begin_m; i <= end_m; i++) {
						temp.push_back(nums2[i]);
					}
					int size = temp.size();
					sort(temp.begin(), temp.end());
					return 0.5*(double(temp[0.5*total - low]) + double(temp[size - 1 - (0.5*total - high)]));
				}
				else {
					return 0.5*(double(nums1[mid_n]) + double(nums2[mid_m]));
				}
			}
			else {//总共有奇数个数字的情况
				int total = M + N - 1;
				int low = 0;
				int high = 0;
				int begin_n = 0;
				int begin_m = 0;
				int end_n = N - 1;
				int end_m = M - 1;
				int mid_n = 0.5*(begin_n + end_n);
				int mid_m = 0.5*(begin_m + end_m);
				while (!((low + high == total) || ((mid_n - begin_n <= 1 || -mid_n + end_n <= 1) || (mid_m - begin_m <= 1 || -mid_m + end_m <= 1)))) {
					if (nums1[mid_n] <= nums2[mid_m]) {
						int length = min(mid_n - begin_n - 1, end_m - mid_m - 1);
						low += length;
						begin_n += length;
						mid_n = 0.5*(begin_n + end_n);
						high += length;
						end_m -= length;
						mid_m = 0.5*(begin_m + end_m);
					}
					else {
						int length = min(end_n - mid_n - 1, mid_m - begin_m - 1);
						high += length;
						end_n -= length;
						mid_n = 0.5*(begin_n + end_n);
						low += length;
						begin_m += length;
						mid_m = 0.5*(begin_m + end_m);
					}
				}
				vector<int> temp;
				for (int i = begin_n; i <= end_n; i++) {
					temp.push_back(nums1[i]);
				}
				for (int i = begin_m; i <= end_m; i++) {
					temp.push_back(nums2[i]);
				}
				sort(temp.begin(), temp.end());
				return double(temp[0.5*total - low]);

			}
		}
	}
};

int main()
{
	vector<int> nums1;
	vector<int> nums2;
	nums1.push_back(1);
	nums1.push_back(5);
	nums1.push_back(100);
	nums1.push_back(190);
	nums2.push_back(7);
	Solution s;
	cout<<s.findMedianSortedArrays(nums1, nums2);
	return 0;

}

