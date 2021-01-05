#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }
    ListNode* headATmp = headA;
    ListNode* headBTmp = headB;
    int i = 0;
    int count = 0;
    while (headATmp != nullptr) {
        while (count > 0) {
            headBTmp = headB;
            headATmp = headATmp->next;
            count--;
        }
        if (headBTmp == headATmp) {
            return headATmp;
        }
        if (headBTmp == nullptr) {
            count = 1;
        }
        else {
            headBTmp = headBTmp->next;
        }
    }
    return nullptr;
}