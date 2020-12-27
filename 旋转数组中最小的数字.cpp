#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int minArray(vector<int>& numbers) {
	int len = numbers.size();
	if (len == 0) {
		return -1;
	}
	sort(numbers.begin(), numbers.end());
	return numbers.front();
}