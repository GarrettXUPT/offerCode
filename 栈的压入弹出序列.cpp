#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
	算法流程
	1、辅助栈，弹出序列的索引i
	2、遍历压栈序列：各元素记为num
		a. 元素num入栈
		b. 循环出栈：若stack的栈顶元素=弹出序列元素poped[i]，则执行出栈并i++
	3、返回值：若stack为空，则弹出序列合法
*/

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	// 辅助栈
	stack<int> tmpStack;
	int i = 0;
	for (auto& ele : pushed) {
		// 将push数组中的元素压入辅助栈
		tmpStack.push(ele);
		// 若栈顶元素与对应位置的栈顶元素相同，则将其出栈，并表示该位置可以出栈成功
		while (!tmpStack.empty() && tmpStack.top() == popped[i]) {
			tmpStack.pop();
			i++;
		}
	}
	// 若该栈为空，则表示都可以出栈成功
	return tmpStack.empty();
}