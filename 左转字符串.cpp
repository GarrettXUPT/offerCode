#include<iostream>
#include<string>

using namespace std;

string reverseLeftWords(string s, int n) {
	int len = s.length();
	if (len == 0) {
		return "";
	}
	// ½µÎ¬
	int moveLen = n % len;
	auto begin = s.begin();
	string secondStr = s.substr(0, moveLen);
	string firstStr = s.substr(moveLen, len - moveLen);
	return firstStr + secondStr;
}

int main() {
	cout << reverseLeftWords("abcdefg", 2) << endl;
	return 0;
}