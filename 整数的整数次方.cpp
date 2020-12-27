#include<iostream>

using namespace std;

double myPow(double x, int n) {
	if (n == 0 || x == 1) {
		return 1;
	}
	long nTmp = long(n);  // �ɷ�ֹnΪ��Сֵȡ��ʱ������
	if (nTmp < 0) {
		return 1 / x * myPow(1 / x, -nTmp - 1 ); 
	}
	return (nTmp % 2 == 0) ? myPow(x * x, nTmp / 2) : myPow(x * x, nTmp / 2) * x;

}

int main() {

	cout << myPow(2, -2147483648) << endl;
	return 0;
}