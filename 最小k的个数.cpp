#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> getLeastNumbers(vector<int>& arr, int k) {
	if (arr.size() < k) {
		return {};
	}
	vector<int> retVec;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < k; ++i) {
		retVec.push_back(arr[i]);
	}
	return retVec;
}