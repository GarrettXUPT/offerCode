#include<iostream>
#include<algorithm>

using namespace std;

/*
	�Ȳ��������
*/
int sumNums(int n) {
	if (n == 1) {
		return 1;
	}
	int start = 1;
	return n * start + n * (n - 1) / 2;
}

int main() {
	cout << sumNums(3) << endl;
	return 0;
}