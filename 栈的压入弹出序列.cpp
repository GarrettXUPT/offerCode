#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
	�㷨����
	1������ջ���������е�����i
	2������ѹջ���У���Ԫ�ؼ�Ϊnum
		a. Ԫ��num��ջ
		b. ѭ����ջ����stack��ջ��Ԫ��=��������Ԫ��poped[i]����ִ�г�ջ��i++
	3������ֵ����stackΪ�գ��򵯳����кϷ�
*/

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	// ����ջ
	stack<int> tmpStack;
	int i = 0;
	for (auto& ele : pushed) {
		// ��push�����е�Ԫ��ѹ�븨��ջ
		tmpStack.push(ele);
		// ��ջ��Ԫ�����Ӧλ�õ�ջ��Ԫ����ͬ�������ջ������ʾ��λ�ÿ��Գ�ջ�ɹ�
		while (!tmpStack.empty() && tmpStack.top() == popped[i]) {
			tmpStack.pop();
			i++;
		}
	}
	// ����ջΪ�գ����ʾ�����Գ�ջ�ɹ�
	return tmpStack.empty();
}