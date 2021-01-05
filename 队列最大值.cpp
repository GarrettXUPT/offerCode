#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

class MaxQueue {
public:
    MaxQueue() {

    }

    int max_value() {
        if (deq.empty()) {
            return -1;
        }
        return *max_element(deq.begin(), deq.end());
    }

    void push_back(int value) {
        deq.push_back(value);
    }

    int pop_front() {
        if (deq.empty()) {
            return -1;
        }
        int value = deq.front();
        deq.pop_front();
        return value;

    }
private:
    deque<int> deq;
    deque<int> maxDeq;
};