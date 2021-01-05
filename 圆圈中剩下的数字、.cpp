#include<iostream>
#include<vector>

using namespace std;

/*
    约瑟夫环问题，元素个数为n，一直去掉的是第m个数
    f(n, m) = (f(n - 1) + m) % n
*/

int lastRemaining(int n, int m) {
    int f = 0;
    for (int i = 2; i != n + 1; ++i) {
        f = (m + f) % i;
    }
    return f;
}

