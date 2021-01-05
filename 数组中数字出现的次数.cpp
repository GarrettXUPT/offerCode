#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

vector<int> singleNumbers(vector<int>& nums) {
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
	vector<int> retVec;
	auto begin = posMap.begin();
	while (begin != posMap.end()) {
		if (begin->second == 1) {
			retVec.push_back(nums[begin->first]);
		}
		if (retVec.size() == 2) {
			break;
		}
		begin++;
	}
	return retVec;
}

int main() {
	vector<int> vec{ 1,2,10,4,1,4,3,3 };
	auto res = singleNumbers(vec);
	for (auto& ele : res) {
		cout << ele << " ";
	}
	cout << endl;
	return 0;
}