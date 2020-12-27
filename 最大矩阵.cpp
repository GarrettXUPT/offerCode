#include<iostream>
#include<vector>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
	int len = matrix.size();
	if (len == 0) {
		return 0;
	}
	int vecLen = matrix[0].size();

	// ʹ�øþ��󣬼�¼ÿ��Ԫ���������Ϊ1������
	vector<vector<int>> left(len, vector<int>(vecLen, 0));
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < vecLen; ++j) {
			if (matrix[i][j] == '1') {  // ��i�е�j�������������1������
				left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
			}
		}
	}
	// ���ھ����е�����һ���㣬ö���Ըõ�Ϊ���½ǵ�ȫ1����
	// ��������matrix[i][j]matrix[i][j] Ϊ���½ǵľ���ʱ������ö������ 0��k��i �����п��ܵ� k����ʱ���������Ⱦ�Ϊ
	// left[i][j], left[i - 1][j]......left[k][j]�е���Сֵ
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