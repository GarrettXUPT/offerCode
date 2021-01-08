#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void trim(string& s) {
	if (s.empty())
	{
		return;
	}
	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
}

int strToInt(string str) {
	
	int sigFlag = 0;
	vector<int> checkVec;

	trim(str);

	const char* ch = str.c_str();
	if (*ch == '+') {
		sigFlag = 1;
		ch++;
	}
	else if (*ch == '-') {
		sigFlag = -1;
		ch++;
	}
	else if ((*ch >= '0' && *ch <= '9')) {
		checkVec.push_back(*ch - '0');
		ch++;
	}
	else {
		return 0;
	}

	while (*ch != '\0') {
		if (*ch >= '0' && *ch <= '9') {
			checkVec.push_back(*ch - '0');
		}
		else
		{
			break;
		}
		ch++;
	}

	if (checkVec.empty()) {
		return 0;
	}

	long long ret = 0;
	int pos = 0;
	while (1) {
		if (checkVec[pos] == 0) {
			checkVec.erase(checkVec.begin() + pos);
			if (checkVec.empty()) {
				return 0;
			}
		}
		else
		{
			break;
		}
	}

	/*
		处理明显越界
	*/
	if ((checkVec.size() > 10 || (checkVec.size() == 10 && checkVec[0] > 2)) && sigFlag < 0) {
		return -long(pow(2, 31));
	}
	else if((checkVec.size() > 10 || (checkVec.size() == 10 && checkVec[0] > 2)) && sigFlag >= 0)
	{
		return int(pow(2, 31) - 1);
	}

	for (int i = checkVec.size(); i > 0; i--) {
		ret += long(pow(10, i - 1) * checkVec[checkVec.size() - i]);
	}

	/*
		处理越界
	*/
	if (ret > int(pow(2, 31) - 1) && sigFlag >= 0) {
		return int(pow(2, 31) - 1);
	}
	else if (ret > long(pow(2, 31)) && sigFlag < 0) {
		return long(pow(2, 31));
	}

	//if(ret > long(pow(2, 31)))
	return sigFlag < 0 ?  -ret : ret;
}

int main() {
	cout << strToInt("-2147483649") << endl;
	return 0;
}