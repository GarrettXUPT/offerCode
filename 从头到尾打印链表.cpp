#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

vector<int> reversePrint(ListNode* head) {
	if (head == nullptr) {
		return {};
	}
	vector<int> retVec;
	while (head != nullptr) {
		retVec.insert(retVec.begin(), head->val);
		head = head->next;
	}
	return retVec;
}

int main() {

}