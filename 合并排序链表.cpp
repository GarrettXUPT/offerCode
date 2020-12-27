#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr) {
		return l2;
	}
	else if (l2 == nullptr) {
		return l1;
	}

	ListNode* retNode;
	if (l1->val <= l2->val) {
		retNode = l1;
		l1 = l1->next;
	}
	else
	{
		retNode = l2;
		l2 = l2->next;
	}
	ListNode* newhead = retNode;
	while (l1 != nullptr && l2 != nullptr) {
		cout << retNode->val << endl;
		if (l1->val <= l2->val) {
			ListNode* tmp = new ListNode(l1->val);
			retNode->next = tmp;
			retNode = retNode->next;
			l1 = l1->next;
		}
		else
		{
			ListNode* tmp = new ListNode(l2->val);
			retNode->next = tmp;
			retNode = retNode->next;
			l2 = l2->next;
		}
	}
	while (l1 != nullptr) {
		ListNode* tmp = new ListNode(l1->val);
		retNode->next = tmp;
		retNode = retNode->next;
		l1 = l1->next;
	}
	while (l2 != nullptr) {
		ListNode* tmp = new ListNode(l2->val);
		retNode->next = tmp;
		retNode = retNode->next;
		l2 = l2->next;
	}
	return newhead;
}