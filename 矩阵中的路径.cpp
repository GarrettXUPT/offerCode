#include<iostream>
#include<vector>

using namespace std;

/*
	矩阵中的路径问题：回溯法求解
	类似于一种枚举的搜索尝试过程，从矩阵中的一个点开始向四个方向进行尝试

*/

vector<vector<char>> copymatrix(vector<vector<char>>& matrix) {
	vector<vector<char>> retMatrix(matrix.size(), vector<char>(matrix[0].size(), 0));
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			retMatrix[i][j] = matrix[i][j];
		}
	}
	return retMatrix;
}

bool dfs(vector<vector<char>>& board, vector<char>& wordLetter, int i, int j, int index) {
	// 边界条件判断, 若是越界，则直接返回false，index表示查找到了第几个字符
	// 若该字符不等于board[i][j]则说明该路径不通，直接返回false
	if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != wordLetter[index]) {
		return false;
	}
	// 若是所有字符都已经查找完毕，那么就直接返回true
	if (index == wordLetter.size() - 1) {
		return true;
	}
	// 为防止分支污染，将board进行备份
	auto copyBoard = copymatrix(board);
	// 将.为已经查找过得标志,上下左右枚举
	copyBoard[i][j] = '.';
	bool res = dfs(copyBoard, wordLetter, i + 1, j, index + 1) || dfs(copyBoard, wordLetter, i - 1, j, index + 1)
		|| dfs(copyBoard, wordLetter, i, j + 1, index + 1) || dfs(copyBoard, wordLetter, i, j - 1, index + 1);
	return res;
}

bool exist(vector<vector<char>>& board, string word) {
	vector<char> wordLetter(word.begin(), word.end());
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j) {
			// 由该坐标开始查找
			if (dfs(board, wordLetter, i, j, 0)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	vector<vector<char>> matrix{ {'A','B','C','E' }, { 'S','F','C','S' }, { 'A','D','E','E' } };
	string word = "ABCCED";
	cout << exist(matrix, word) << endl;
	return 0;
}