#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class MedianFinder {
    vector<int> store; // resize-able container

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        if (store.empty())
            store.push_back(num);
        else
            store.insert(lower_bound(store.begin(), store.end(), num), num);     // binary search and insertion combined
    }

    // Returns the median of current data stream
    double findMedian()
    {
        int n = store.size();
        return n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5;
    }
};

/*
    ���ȶ��нⷨ
*/
class MedianFinder{ 
    priority_queue<int> lo;                              // �󶥶ѣ�����
    priority_queue<int, vector<int>, greater<int>> hi;  // ����С����
    //����С�Ĳ��ִ��ڴ���ѣ��ϴ�Ĳ��ִ���С����
    //�����Ԫ�ظ��� - С����Ԫ�ظ��� = 0 ���� 1

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num);                                    // �ȼӵ��󶥶ѣ�Ȼ��Ѵ���ѵ�top��С���ѣ���֤��������
        hi.push(lo.top());                               //�ȼӵ�С����Ҳ�ǿ��Ե�
        lo.pop();

        if (lo.size() < hi.size()) {                     // ��֤����ѵ�Ԫ�ظ�����С��С����
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return lo.size() > hi.size() ? (double)lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */