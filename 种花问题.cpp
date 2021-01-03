#include<iostream>
#include<vector>

using namespace std;

/*
	使用贪心算法解决：
		1、假设花坛的i位置与j位置都种花，则 j - i >= 2,且在下标[i + 1, j - 1]范围内没有种花，则只有当j - i >= 4时，下标i和j之间可以种植更多的花
		   且可以种花的下标范围在i + 2, j - 2之间，可以种植花的位置数为p = j - i - 3，当p为奇数时，最多可以在该范围内种植(p + 1) / 2朵花，若p为偶数
		   则最多可以中p / 2朵花，也就是无论是奇数还是偶数，都可以最多种植(p + 1) / 2,即为(j - i - 2) / 2
		2、下标l左边有l个位置当l < 2时，左边不可以种花，当l > 2时，下标范围在[0, l-2]范围内可以种植，可以种植的位置为l-1个，也就是可以种l / 2个
		3、下标r右边有m - r - 1个位置，可以种花的数量为m - r - 2,可以种(m - r - 1) / 2朵花
*/

bool canPlaceFlowers(vector<int>& flowered, int n) {
	int len = flowered.size();
	// 贪心算法
	int count = 0;
	int prev = -1;  // 表示区间左限
	for (int i = 0; i < len; ++i) {
		if (flowered[i] == 1) {
			if (prev < 0) { // 第2种情况
				count += i / 2;
			}
			else    // 第1种情况
			{
				count += (i - prev - 2) / 2;
			}
			prev = i;
		}
	}
	// 计算最后一个区间的种植数
	if (prev < 0) {  // 整个区间没有花
		count += (len + 1) / 2;
	}
	else  // 第3种情况
	{
		count += (len - prev - 1) / 2;
	}
	return count >= n;
}