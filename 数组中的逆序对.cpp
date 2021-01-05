#include<iostream>
#include<vector>

using namespace std;

int reversePairs(vector<int>& nums) {
	int len = nums.size();
	if (len <= 1) {
		return 0;
	}
	int count = 0;
	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j < len; ++j) {
			if (nums[i] > nums[j]) {
				count++;
			}
		}
	}
	return count;
}