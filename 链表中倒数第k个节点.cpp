#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

ListNode* getKthFromEnd(ListNode* head, int k) {
	if (head == nullptr) {
		return head;
	}
	ListNode* tmpNode = head;
	ListNode* newhead = head;
	int numCount = 0;
	while (tmpNode != nullptr) {
		numCount++;
		tmpNode = tmpNode->next;
	}
	for (int i = 0; i < numCount - k; ++i) {
		newhead = newhead->next;
	}
	return newhead;
}