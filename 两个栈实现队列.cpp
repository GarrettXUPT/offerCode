#include<iostream>
#include<stack>

using namespace std;

class CQueue {
public:
	CQueue() {
		
	}
	void appendTail(int value) {
		_stkFirst.push(value);
	}

	int deleteHead() {
		if (_stkFirst.empty()) {
			return -1;
		}
		for (int i = 0; i < _stkFirst.size() - 1; ++i) {
			_stkLast.push(_stkFirst.top());
			_stkFirst.pop();
		}
		int ret = _stkFirst.top();
		_stkFirst.pop();
		while (!_stkLast.empty()) {
			_stkFirst.push(_stkLast.top());
			_stkLast.pop();
		}
		return ret;
	}
private:
	stack<int> _stkFirst;
	stack<int> _stkLast;
};