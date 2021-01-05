#include<iostream>
#include<vector>

using namespace std;

/*
    Լɪ�����⣬Ԫ�ظ���Ϊn��һֱȥ�����ǵ�m����
    f(n, m) = (f(n - 1) + m) % n
*/

int lastRemaining(int n, int m) {
    int f = 0;
    for (int i = 2; i != n + 1; ++i) {
        f = (m + f) % i;
    }
    return f;
}

