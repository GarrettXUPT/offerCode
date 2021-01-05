#include<iostream>
#include<vector>

using namespace std;

// ȥ�����˿ո�
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
	// ����Ƿ�������Ӧ���
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
			// .ǰ������.������e
			if (dotSeen || eSeen) {
				return false;
			}
			dotSeen = true;
		}
		else if (chVec[i] == 'e' || chVec[i] == 'E') {
			// e֮ǰ���ܴ���e�������������
			if (eSeen || !numSeen) {
				return false;
			}
			eSeen = true;
			numSeen = false;  // ����numSeen���ų�123e������123e+�������ȷ��e������Ȼ��������
		}
		else if (chVec[i] == '+' || chVec[i] == '-') {
			if (i != 0 && chVec[i - 1] != 'e' && chVec[i - 1] != 'E') {
				return false;
			}
		}
		else  // �������Ϸ����ַ�
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