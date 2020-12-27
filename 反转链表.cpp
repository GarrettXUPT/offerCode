#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

ListNode* reverseList(ListNode* head) {
	if (head == nullptr) {
		return head;
	}
	ListNode* curr = nullptr;
	ListNode* pre = head;
	while (pre != nullptr) {
		ListNode* tmp = pre->next;
		pre->next = curr;
		curr = pre;
		pre = tmp;
	}
	return curr;
}