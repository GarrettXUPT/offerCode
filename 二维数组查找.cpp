#include<iostream>
#include<vector>

using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	if (matrix.empty()) {
		return false;
	}
	else if (matrix[0].empty()) {
		return false;
	}
	int i = 0; int j = 0;
	while (1) {
		if (matrix[i][j] < target) {
			if (j == matrix[0].size() - 1) {  // 当比较位置已经到最右端，则只能向下移动
				if (i == matrix.size() - 1) {
					return false;
				}
				i++; 
			}
			else
			{
				j++;
			}
		}else if (matrix[i][j] > target) {
			if (j < 0 || i > matrix.size() - 1) {
				break;
			}
			while (matrix[i][j] > target) {
				j--;
				if (j < 0) {
					return false;
				}
			}
			if (matrix[i][j] == target) {
				return true;
			}
			i++;
		}
		if (matrix[i][j] == target) {
			return true;
		}
	}
	return false;
}

int main() {
	vector<vector<int>> matrix{ {1,2,3,4,5 }, { 6,7,8,9,10 }, { 11,12,13,14,15 }, { 16,17,18,19,20 }, { 21,22,23,24,25 }};
	cout << findNumberIn2DArray(matrix, 19) << endl;
	return 0;
}