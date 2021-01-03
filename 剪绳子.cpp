#include<iostream>
#include<vector>

using namespace std;


/*
	求最大值 可使用动态规划
	提前存储绳子长度i <= 3时绳子最大长度，此时的绳子是被切割过的，绳子共有m段
	第一个for循环是由下向上的算法体现，先计算出f(n)之前所有绳子最大的长度乘积
	第二个外层for循环是求出绳子长度为i时，所有的切割一次的可能(切割一次后得到的长度j和i - j两段绳子，
		可以根据maxDistence储存的对应的最大乘积获得)，求出最大乘积

*/

int cuttingRope(int n) {
	if (n < 2) return 0;
	else if (n == 2) return 1;
	else if (n == 3) return 2;
	vector<int> maxDistences(n + 1);
	for (int i = 0; i < 4; ++i) {
		maxDistences[i] = i;
	}

	for (int i = 4; i <= n; ++i) {
		int max = 0;
		for (int j = 1; j <= i / 2; ++j) {  // // 循环体中写i/2是为了减少计算次数（因为比如1x3和3x1值是一样的，计算一次即可）
			if (max < maxDistences[j] * maxDistences[i - j]) {
				max = maxDistences[j] * maxDistences[i - j];
			}
			maxDistences[i] = max;
		}
	}
	return maxDistences[n];
}