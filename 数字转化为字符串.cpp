#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

/*
	���ַ���Ϊ�ַ������ܵ����

	��̬�滮
	ʹ��f(i)���Ա�ʾ�Ե�iλ��β��ǰ׺������ķ�����
	���ǵ�iλ���������ǰһλ���������ٶ�f[i]�����ף�������f[i]���з���Ĺ���Ϊf[i - 1]
	����i-1λ���ڣ�����i - 1λ�������iλ���������γɵ�x����10 <= x <= 25����ô�Ϳ��Խ���iλ�͵�i - 1λ��������
	��f[i]�Ĺ���Ϊf[i - 2]����Ϊ0.
	f[i] = f[i - 1] + f[i - 2] (i - 1>= 0 , 10 <= x <= 25)
	�߽�������f[-1] = 0 f[0] = 1
*/

int translateNum(int num) {
	string numStr = to_string(num);
	vector<char> chVec;
	const char* ch = numStr.c_str();
	while (*ch != '\0') {
		chVec.push_back(*ch);
		ch++;
	}
	int len = numStr.length();
	if (len <= 1) {
		return 1;
	}

	int pre = 1, cur = 0;
	if (chVec[0] == '1' || (chVec[0] == '2' && chVec[1] <= '5')) {
		cur = 2;
	}
	else
	{
		cur = 1;
	}

	for (int i = 2; i < len; ++i) {
		int next = 0;
		if (chVec[i - 1] == '1' || (chVec[i - 1] == '2' && chVec[i] <= '5')) {
			next = cur + pre;
		}
		else
		{
			next = cur;
		}
		pre = cur;
		cur = next;
	}
	return cur;
}

/*
	��̬�滮��
		1����dp[i]��ʾǰi�����ж��ٸ����뷽��
		2�������i�����������룬��ôdp[i] = dp[i - 1]
		3�������i�������i - 1����������Ϸ��룺
			1. ����������ϴ���[10,25]�����䣬�ȿ�����Ϸ��룬�ֿ��Ե�������dp[i] = dp[i - 1] + dp[i - 2]
			2. ����������ϲ����ڸ����䣬��ô��������ϣ�����Ҫ�������룬Ҳ�������2��һ�� dp[i] = dp[i - 1]
		4����������������ϴ���[10, 25]�����䣬dp[i] = dp[i - 1] + dp[i - 2],������������ϲ���[10,25]�����ڣ�dp[i] = dp[i - 1]
*/

int translateNum(int num) {
	if (num < 10) { return 1; }
	string s = to_string(num);
	int len = s.length();
	vector<int> dp(len + 1);
	dp[1] = 1; // �Զ��׼� dp[1] = 1
	dp[0] = 1; // ���� num = 12�������ַ������� dp[2] = dp[1] + dp[0]���ɵ� dp[0] = 1

	for (int i = 2; i < len + 1; ++i) {
		if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '5')) {
			dp[i] = dp[i - 2] + dp[i - 1];
		}
		else {
			dp[i] = dp[i - 1];
		}
	}

	return dp[len];
}