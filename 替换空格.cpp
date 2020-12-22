#include<iostream>
#include<vector>

using namespace std;

string replaceSpace(string s) {
	string replace = "%20";
	string retStr = "";
	auto begin = s.begin();
	while (begin != s.end()) {
		if (*begin == ' ') {
			retStr += replace;
		}
		else
		{
			retStr += *begin;
		}
		begin++;
	}
	return retStr;
}

int main() {
	cout << replaceSpace("We are happy.") << endl;
	return 0;
}