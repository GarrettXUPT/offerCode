#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

bool isStraight(vector<int>& nums) {
	int len = nums.size();
	sort(nums.begin(), nums.end());
	int zeroCount = 0, zeroPos = 0;
	int tmpValue = -1;
	for (int i = 0; i < len; ++i) {
		if (nums[i] == 0) {
			zeroCount++;
			zeroPos++;
		}
		else{
			if (i != 0 && nums[i - 1] == nums[i]) {
				return false;
			}else if (i != 0 && nums[i - 1] != nums[i] - 1 && nums[i - 1] != 0) {
				zeroCount--;
				if (zeroCount < 0) {
					return false;
				}
			}
			tmpValue = nums[i];
		}
	}
	if (tmpValue - nums[zeroPos] > 4) {
		return false;
	}
	return true;
}

int main() {
	vector<int> vec{ 8,7,11,0,9 };
	cout << isStraight(vec) << endl;
	return 0;
}