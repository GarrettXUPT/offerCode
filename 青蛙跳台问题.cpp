#include<iostream>
#include<vector>

using namespace std;

/*
	青蛙跳台:动态规划
	dp[i + 1] = dp[i] + dp[i - 1]
	边界：
		dp[1] dp[0] = 1
*/

int numWay(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	vector<int> dp(n + 1, 0);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % int(pow(10, 9) + 7);
	}
	return dp[n];
}

int main() {
	cout << numWay(44) << endl;
	return 0;
}
