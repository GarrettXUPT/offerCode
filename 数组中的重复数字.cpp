#include<iostream>
#include<vector>
#include<set>

using namespace std;

int findRepeatNumber(vector<int>& nums) {
	for (auto& ele : nums) {
		if (count(nums.begin(), nums.end(), ele) > 1) {
			return ele;
		}
	}
	return -1;
}


int findRepeatNumber(vector<int>& nums) {
	set<int> checkSet;
	for (auto& ele : nums) {
		if (checkSet.find(ele) != checkSet.end()) {
			return ele;
		}
		else
		{
			checkSet.insert(ele);
		}
	}
	return -1;
}



