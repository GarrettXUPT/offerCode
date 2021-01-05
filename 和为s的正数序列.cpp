#include<iostream>
#include<vector>

using namespace std;

/*
*	m������֮��
	x + (x + 1) + ... + (x + m - 1) == target => m * x + m * (m - 1) / 2 == target
*/

vector<vector<int>> findContinuousSequence1(int target) {
	vector<vector<int>> resVec;
	int i = 1;
	while (target > 0) {
		target -= i;
		i++;
		if (target > 0 && target % i == 0) {
			vector<int> vec(i, 0);
			for (int k = target / i, j = 0; k < target / i + i; k++, j++) {
				vec[j] = k;
			}
			resVec.push_back(vec);

		}
	}
	reverse(resVec.begin(), resVec.end());
	return resVec;
}

/*
	�Ȳ��������
	�Ȳ�����֮�͵Ĺ�ʽ�� S = na + (n(n - 1) / 2) * d
	��ʱd = 1
	target = na + n(n - 1) / 2
	��֪target��β���n���������ֵ
*/
vector<vector<int>> findContinuousSequence(int target) {
	if (target <= 2) {
		return {};
	}
	vector<vector<int>> res;
	for (int i = 2; i <= target; ++i) {
		vector<int> tmpVec;
		int tmp = target - i * (i - 1) / 2;
		if (tmp <= 0) {
			break;
		}
		if (!(tmp % i)) {
			int start = tmp / i;
			for (int j = 0; j < i; ++j) {
				tmpVec.push_back(start + j);
			}
		}
		res.push_back(tmpVec);
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	findContinuousSequence(9);
	return 0;
}