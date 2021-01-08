#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

/*
	数字翻译为字符串可能的情况

	动态规划
	使用f(i)可以表示以第i位结尾的前缀串翻译的方案数
	考虑第i位单独翻译和前一位连接起来再对f[i]做贡献，单独对f[i]进行翻译的贡献为f[i - 1]
	若第i-1位存在，并且i - 1位数字与第i位数字连接形成的x满足10 <= x <= 25，那么就可以将第i位和第i - 1位连接起来
	对f[i]的贡献为f[i - 2]否则为0.
	f[i] = f[i - 1] + f[i - 2] (i - 1>= 0 , 10 <= x <= 25)
	边界条件：f[-1] = 0 f[0] = 1
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
	动态规划：
		1、用dp[i]表示前i个数有多少个翻译方法
		2、假如第i个数单独翻译，那么dp[i] = dp[i - 1]
		3、假如第i个数与第i - 1个数进行组合翻译：
			1. 两个数的组合处于[10,25]的区间，既可以组合翻译，又可以单独翻译dp[i] = dp[i - 1] + dp[i - 2]
			2. 两个数的组合不处于该区间，那么不可以组合，还是要单独翻译，也就是与第2点一样 dp[i] = dp[i - 1]
		4、若是两个数的组合处于[10, 25]的区间，dp[i] = dp[i - 1] + dp[i - 2],当两个数的组合不在[10,25]区间内，dp[i] = dp[i - 1]
*/

int translateNum(int num) {
	if (num < 10) { return 1; }
	string s = to_string(num);
	int len = s.length();
	vector<int> dp(len + 1);
	dp[1] = 1; // 显而易见 dp[1] = 1
	dp[0] = 1; // 比如 num = 12，有两种方法，即 dp[2] = dp[1] + dp[0]，可得 dp[0] = 1

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