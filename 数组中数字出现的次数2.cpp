#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int singleNumber(vector<int>& nums) {
	if (nums.empty()) {
		return {};
	}
	map<int, int> posMap;
	map<int, int> checkMap;
	for (int i = 0; i < nums.size(); ++i) {
		auto iter = checkMap.find(nums[i]);
		if (iter != checkMap.end()) {
			posMap[iter->second]++;
		}
		else
		{
			checkMap.insert({ nums[i], i });
			posMap.insert({ i, 1 });
		}
	}
	int ret;
	auto begin = posMap.begin();
	while (begin != posMap.end()) {
		if (begin->second == 1) {
			ret = nums[begin->first];
		}
		begin++;
	}
	return ret;
}