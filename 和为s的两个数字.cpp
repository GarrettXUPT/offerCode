#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	if (nums.empty()) {
		return {};
	}
	set<int> checkSet;
	for (auto& ele : nums) {
		if (checkSet.find(target - ele) != checkSet.end()) {
			return { ele, target - ele };
		}
		else
		{
			checkSet.insert(ele);
		}
	}
	return {};
}