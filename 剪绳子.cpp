#include<iostream>
#include<vector>

using namespace std;


/*
	�����ֵ ��ʹ�ö�̬�滮
	��ǰ�洢���ӳ���i <= 3ʱ������󳤶ȣ���ʱ�������Ǳ��и���ģ����ӹ���m��
	��һ��forѭ�����������ϵ��㷨���֣��ȼ����f(n)֮ǰ�����������ĳ��ȳ˻�
	�ڶ������forѭ����������ӳ���Ϊiʱ�����е��и�һ�εĿ���(�и�һ�κ�õ��ĳ���j��i - j�������ӣ�
		���Ը���maxDistence����Ķ�Ӧ�����˻����)��������˻�

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
		for (int j = 1; j <= i / 2; ++j) {  // // ѭ������дi/2��Ϊ�˼��ټ����������Ϊ����1x3��3x1ֵ��һ���ģ�����һ�μ��ɣ�
			if (max < maxDistences[j] * maxDistences[i - j]) {
				max = maxDistences[j] * maxDistences[i - j];
			}
			maxDistences[i] = max;
		}
	}
	return maxDistences[n];
}