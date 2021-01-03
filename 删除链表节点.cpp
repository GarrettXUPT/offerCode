#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

ListNode* deleteNode(ListNode* head, int val) {
	if (head == nullptr) {
		return head;
	}
	if (head->val == val) {
		head = head->next;
		return head;
	}
	ListNode* newhead = head;
	ListNode* first = head->next;
	ListNode* second = head;
	while (first != nullptr) {
		if (first->val == val) {
			second->next = first->next;
		}
			first = first->next;
			second = second->next;
	}
	return newhead;
}