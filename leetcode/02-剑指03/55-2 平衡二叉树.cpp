#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return recur(root) != -1;
	}

	int recur(TreeNode* root) {
		if (root == NULL) return 0;
		int left = recur(root->left);
		if (left == -1) return -1;
		int right = recur(root->right);
		if (right == -1) return -1;
		return abs(left - right) < 2 ? max(left, right) + 1 : -1;
	}
};

int main()
{

	return 0;
}
