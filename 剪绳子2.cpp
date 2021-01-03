#include<iostream>
#include<vector>

using namespace std;

/*
	将长为n的绳子，剪成m段，使这些段绳子的长度的乘积达到最大
	该题目取3的次数越多，值越大

	绳子长度小于4时，则返回n - 1
	若绳子长度等于4，返回n
	若绳子长度大于4，就将其切割成为长度为3的一小段，每次切一段3，则就将其累乘，最后取模
*/

int cuttingRope(int n) {
	if (n == 2) return 1;
	if (n == 3) return 3;
	if (n == 4) return 4;
	long res = 0;
	while (n > 4) {
		res *= 3;
		res = res % (int(pow(10, 9)) + 7);
		n -= 3;
	}
	return (res * n % (int(pow(10, 9)) + 7));
}