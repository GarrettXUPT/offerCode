#include<iostream>
#include<vector>

using namespace std;

/*
	�����е�·�����⣺���ݷ����
	������һ��ö�ٵ��������Թ��̣��Ӿ����е�һ���㿪ʼ���ĸ�������г���

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
	// �߽������ж�, ����Խ�磬��ֱ�ӷ���false��index��ʾ���ҵ��˵ڼ����ַ�
	// �����ַ�������board[i][j]��˵����·����ͨ��ֱ�ӷ���false
	if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != wordLetter[index]) {
		return false;
	}
	// ���������ַ����Ѿ�������ϣ���ô��ֱ�ӷ���true
	if (index == wordLetter.size() - 1) {
		return true;
	}
	// Ϊ��ֹ��֧��Ⱦ����board���б���
	auto copyBoard = copymatrix(board);
	// ��.Ϊ�Ѿ����ҹ��ñ�־,��������ö��
	copyBoard[i][j] = '.';
	bool res = dfs(copyBoard, wordLetter, i + 1, j, index + 1) || dfs(copyBoard, wordLetter, i - 1, j, index + 1)
		|| dfs(copyBoard, wordLetter, i, j + 1, index + 1) || dfs(copyBoard, wordLetter, i, j - 1, index + 1);
	return res;
}

bool exist(vector<vector<char>>& board, string word) {
	vector<char> wordLetter(word.begin(), word.end());
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j) {
			// �ɸ����꿪ʼ����
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