#include<iostream>
#include<vector>

using namespace std;

int add(int a, int b) {
	while (b != 0) {
		int plus = (a & b) << 1;  // ��λ
		int temp = a ^ b; // ����λ������ֵ
		b = plus;
		a = temp;
	} 
	return a;
}

int main() {
	cout << add(-2, 1) << endl;
	return  0;
}