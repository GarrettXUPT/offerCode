#include<iostream>
#include<vector>

using namespace std;

/*
	����Ϊn�����ӣ�����m�Σ�ʹ��Щ�����ӵĳ��ȵĳ˻��ﵽ���
	����Ŀȡ3�Ĵ���Խ�ֵ࣬Խ��

	���ӳ���С��4ʱ���򷵻�n - 1
	�����ӳ��ȵ���4������n
	�����ӳ��ȴ���4���ͽ����и��Ϊ����Ϊ3��һС�Σ�ÿ����һ��3����ͽ����۳ˣ����ȡģ
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