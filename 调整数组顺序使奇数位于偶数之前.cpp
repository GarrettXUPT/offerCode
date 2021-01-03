#include<iostream>
#include<vector>

using namespace std;

vector<int> exchange(vector<int>& nums) {
	int len = nums.size();
	if (len == 0) {
		return {};
	}
	vector<int> oddVec;
	vector<int> evenVec;
	auto begin = nums.begin();
	while (begin != nums.end()) {
		if (*begin % 2 == 1) {
			oddVec.push_back(*begin);
		}
		else
		{
			evenVec.push_back(*begin);
		}
		begin++;
	}
	for (auto& ele : evenVec) {
		oddVec.push_back(ele);
	}
	return oddVec;
}


int main() {

}