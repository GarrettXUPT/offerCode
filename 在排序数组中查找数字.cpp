#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/*
	������ֵĴ���
*/
int search(vector<int>& nums, int target) {
	return count(nums.begin(), nums.end(), target);
}