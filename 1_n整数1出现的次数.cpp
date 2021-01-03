#include<iostream>
#include<vector>

using namespace std;

int countDigitOne(int n) {
	int a = 1;
	int b = 10;
	int oneCount = 0;
	while (n >= a) {
		int div = n / b; int remine = n % b;
		if (remine >= a * 2) {
			oneCount += ((div + 1) * a);
		}
		else if (remine >= a) {
			oneCount += (remine + 1 + (div - 1) * a);
		}
		else
		{
			oneCount += (div * a);
		}
		a = b;
		b = b * 10;
	}
	return oneCount;
}
