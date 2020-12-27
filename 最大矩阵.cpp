#include<iostream>
#include<vector>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
	int len = matrix.size();
	if (len == 0) {
		return 0;
	}
	int vecLen = matrix[0].size();

	// 使用该矩阵，记录每个元素左边连续为1的数量
	vector<vector<int>> left(len, vector<int>(vecLen, 0));
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < vecLen; ++j) {
			if (matrix[i][j] == '1') {  // 第i行第j列左边连续出现1的数量
				left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
			}
		}
	}
	// 对于矩阵中的任意一个点，枚举以该点为右下角的全1矩阵
	// 当考察以matrix[i][j]matrix[i][j] 为右下角的矩形时，我们枚举满足 0≤k≤i 的所有可能的 k，此时矩阵的最大宽度就为
	// left[i][j], left[i - 1][j]......left[k][j]中的最小值
	int ret = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < vecLen; ++j) {
			if (matrix[i][j] == '0') {
				continue;
			}
			int width = left[i][j];
			int area = width * 1;
			for (int k = i - 1; k >= 0; --k) {
				width = min(width, left[k][j]);
				area = max(area, (i - k + 1) * width);
			}
			ret = max(ret, area);
		}
	}
	return ret;
}