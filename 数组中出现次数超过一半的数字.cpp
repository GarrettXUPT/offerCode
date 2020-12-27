#include<iostream>
#include<vector>
#include<map>


using namespace std;

int majorityElement(vector<int>& nums) {
	int len = nums.size();
	if (len == 0) {
		return -1;
	}
	else if (len == 1) {
		return nums[0];
	}
	map<int, int> checkMap;
	auto begin = nums.begin();
	while (begin != nums.end()) {
		if (checkMap.find(*begin) != checkMap.end()) {
			checkMap[*begin]++;
			if (checkMap.at(*begin) > (len / 2)) {
				return *begin;
			}
		}
		else
		{
			checkMap.insert({ *begin, 1 });
		}
		begin++;
	}
	return -1;
}