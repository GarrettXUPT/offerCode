#include<iostream>
#include<vector>

using namespace std;

int missingNumber(vector<int>& nums) {
	int check = 0;
	auto begin = nums.begin();
	while (begin != nums.end()) {
		if (*begin != check) {
			return check;
		}
		check++; begin++;
	}
	return nums.size();
}
