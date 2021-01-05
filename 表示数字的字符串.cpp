#include<iostream>
#include<vector>

using namespace std;

// 去除两端空格
void trim(string& s) {
	if (s.empty())
	{
		return;
	}
	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
}

bool isNumber(string s) {
	if (s.empty()) {
		return false;
	}
	// 标记是否遇到对应情况
	bool numSeen = false;
	bool dotSeen = false;
	bool eSeen = false;
	trim(s);
	vector<char> chVec(s.begin(), s.end());
	for (int i = 0; i < chVec.size(); ++i) {
		if (chVec[i] >= '0' && chVec[i] <= '9') {
			numSeen = true;
		}
		else if (chVec[i] == '.') {
			// .前不能有.或者是e
			if (dotSeen || eSeen) {
				return false;
			}
			dotSeen = true;
		}
		else if (chVec[i] == 'e' || chVec[i] == 'E') {
			// e之前不能存在e，必须出现数字
			if (eSeen || !numSeen) {
				return false;
			}
			eSeen = true;
			numSeen = false;  // 重置numSeen，排除123e或者是123e+的情况，确保e后面仍然具有数字
		}
		else if (chVec[i] == '+' || chVec[i] == '-') {
			if (i != 0 && chVec[i - 1] != 'e' && chVec[i - 1] != 'E') {
				return false;
			}
		}
		else  // 其他不合法的字符
		{
			return false;
		}
	}
	return numSeen;
}

int main() {
	cout << isNumber("-1E-16") << endl;
	return 0;
}