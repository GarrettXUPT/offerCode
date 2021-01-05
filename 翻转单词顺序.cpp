#include<iostream>
#include<vector>

using namespace std;

void trim(string& s){
    if (s.empty())
    {
        return;
    }
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
}

string reverseWords(string s) {
    if (s.empty()) {
        return "";
    }
    trim(s);
	const char* ch = s.c_str();
    string tmpStr = "";
    string ret;
	while (*ch != '\0') {
        if (*ch == ' ') {
            if (!tmpStr.empty()) {
                ret = tmpStr + " " + ret;
                tmpStr = "";            
            }
        }
        else{
            if (*ch == ' ') {
                continue;
            }
            tmpStr += *ch;
        }
        ch++;
	}
    if (tmpStr != "") {
        ret = tmpStr + " " + ret;
    }
    if (!ret.empty()) {
        ret.erase(ret.size() - 1);
    }
    return ret;
}

/*
    内存时间消耗较少
*/

void trim(string& s) {
    if (s.empty())
    {
        return;
    }
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
}

string reverseWords(string s) {
    if (s.empty()) {
        return "";
    }
    trim(s);
    const char* ch = s.c_str();
    vector<string> strVec;
    string tmpStr = "";
    while (*ch != '\0') {
        if (*ch == ' ') {
            strVec.insert(strVec.begin(), tmpStr);
            tmpStr = "";
        }
        else {
            tmpStr += *ch;
        }
        ch++;
    }
    strVec.insert(strVec.begin(), tmpStr);
    string retStr = strVec[0];
    for (int i = 1; i < strVec.size(); ++i) {
        if (strVec[i].empty()) {  // 防止中间出现空串
            continue;
        }
        retStr += " " + strVec[i];
    }
    return retStr;
}

int main() {
    auto res = reverseWords(" ");
    cout << res << endl;
    return 0;
}