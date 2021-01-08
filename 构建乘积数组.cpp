#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

int mul(vector<int>& vec) {
	int res = 1;
	auto begin = vec.begin();
	while (begin != vec.end()) {
		res *= *begin;
		begin++;
	}
	return res;
}

vector<int> constructArr(vector<int>& a) {
	int len = a.size();
	
	vector<int> retVec;
	for (int i = 0; i < len; ++i) {
		vector<int> tmpVec = a;
		tmpVec.erase(tmpVec.begin() + i);
		retVec.push_back(mul(tmpVec));
	}
	return retVec;
}

vector<int> constructArr(vector<int>& a) {
	int n = a.size();
	vector<int> L(n, 1);
	vector<int> R(n, 1);
	// 由左向右进行遍历
	for (int i = 1; i < n; i++)
		L[i] = L[i - 1] * a[i - 1];
	// 由右向左进行遍历
	for (int j = n - 2; j > -1; j--)
		R[j] = R[j + 1] * a[j + 1];

	for (int i = 0; i < n; i++)
		L[i] = L[i] * R[i];
	return L;
}
