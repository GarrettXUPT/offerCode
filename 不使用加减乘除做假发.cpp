#include<iostream>
#include<vector>

using namespace std;

int add(int a, int b) {
	while (b != 0) {
		int plus = (a & b) << 1;  // 进位
		int temp = a ^ b; // 除进位以外数值
		b = plus;
		a = temp;
	} 
	return a;
}

int main() {
	cout << add(-2, 1) << endl;
	return  0;
}