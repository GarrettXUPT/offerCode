#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

pair<bool, int> getKey(map<int, int>& check, char target, string s) {
	auto begin = check.begin();
	while (begin != check.end()) {
		if (s[begin->first] == target) {
			return make_pair( true, begin->first );
		}
		begin++;
	}
	return  make_pair(false, -1);
}

char firstUniqChar(string s) {
	if (s.size() == 1) {
		return s[0];
	}
	else if (s.empty()) {
		return ' ';
	}
	map<int, int> checkMap;
	for (int i = 0; i < s.size(); ++i) {
		auto flag = getKey(checkMap, s[i], s);
		if (flag.first) {
			checkMap[getKey(checkMap, s[i], s).second]++;
		}
		else
		{
			checkMap.insert({ i, 1 });
		}
	}

	auto begin = checkMap.begin();
	while (begin != checkMap.end()) {
		if (begin->second == 1) {
			return s[begin->first];
		}
		begin++;
	}
	return ' ';
}


/*
	ÓÐÐò¹þÏ£±í
*/
char firstUniqChar(string s) {
	vector<char> keys;
	unordered_map<char, bool> dic;
	for (char c : s) {
		if (dic.find(c) == dic.end())
			keys.push_back(c);
		dic[c] = dic.find(c) == dic.end();
	}
	for (char c : keys) {
		if (dic[c]) return c;
	}
	return ' ';
}

int main() {
	cout << firstUniqChar("leetcode") << endl;
	return 0;
}