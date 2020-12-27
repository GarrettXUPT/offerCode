#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> printNumbers(int n) {
	vector<int> ret;
	for (unsigned long long i = 1; i < INT16_MAX; ++i) {
		string tmpStr = to_string(i);
		if (tmpStr.size() <= n) {
			ret.push_back(i);
		}
		else
		{
			break;
		}
	}
	return ret;
}

int main() {
	
	auto ret = printNumbers(5);
	/*for (auto& ele : ret) {
		cout << ele << " ";
	}
	cout << endl;*/
	
	return 0;
}