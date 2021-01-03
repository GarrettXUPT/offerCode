#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x) {};
};

TreeNode* bulidTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.empty()) {
		return nullptr;
	}
	TreeNode* root = new TreeNode(preorder[0]);
	int preLen = preorder.size();
	stack<TreeNode*> stk;
	stk.push(root);
	int inorderIndex = 0;
	for (int i = 1; i < preLen; ++i) {
		int preorderVal = preorder[i];
		TreeNode* node = stk.top();
		if (node->val != inorder[inorderIndex]) {
			node->left = new TreeNode(preorderVal);
			stk.push(node->left);
		}
		else
		{
			while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
				node = stk.top();
				stk.pop();
				inorderIndex++;
			}
			node->right = new TreeNode(preorderVal);
			stk.push(node->right);
		}
	}
	return root;
}

int main() {
	vector<int> preOrder{ 3,9,20,15,7 };
	vector<int> inorder{ 9,3,15,20,7 };
	bulidTree(preOrder, inorder);
	return 0;
}