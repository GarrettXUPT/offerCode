#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/*
	计算出现的次数
*/
int search(vector<int>& nums, int target) {
	return count(nums.begin(), nums.end(), target);
}