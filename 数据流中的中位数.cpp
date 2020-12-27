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
    优先队列解法
*/
class MedianFinder{ 
    priority_queue<int> lo;                              // 大顶堆，升序
    priority_queue<int, vector<int>, greater<int>> hi;  // 降序，小顶堆
    //将较小的部分存在大根堆，较大的部分存在小根堆
    //大根堆元素个数 - 小根堆元素个数 = 0 或者 1

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num);                                    // 先加到大顶堆，然后把大根堆的top给小根堆，保证数据有序
        hi.push(lo.top());                               //先加到小根堆也是可以的
        lo.pop();

        if (lo.size() < hi.size()) {                     // 保证大根堆的元素个数不小于小根堆
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