
#include<iostream>
#include<vector>

using namespace std;

int fib1(int n) {
	if (n < 2) {
		return n;
	}
	return (fib1(n - 2) + fib1(n - 1)) % int(pow(10, 9) + 7);
}

int fib(int n) {
	int a = 0, b = 1, sum;
	for (int i = 0; i < n; i++) {
		sum = (a + b) % (int(pow(10, 9) + 7));
		a = b;
		b = sum;
	}
	return a;
}

int main() {
	cout << fib(39) << endl;
	return 0;
}