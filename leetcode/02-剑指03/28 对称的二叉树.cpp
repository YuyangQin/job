#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		return isSame(root->left, root->right);
	}
	bool isSame(TreeNode* root, TreeNode* rroot)
	{
		if (root == NULL&&rroot == NULL)
			return true;
		if (root == NULL || rroot == NULL)
			return false;
		if (root->val != rroot->val)
			return false;
		return (isSame(root->left, rroot->right) && isSame(root->right, rroot->left));
	}
};

void main()
{
	Solution s;
	TreeNode* root = &TreeNode(1);
	root->left = &TreeNode(2);
	root->right = &TreeNode(2);
	root->left->right = &TreeNode(3);
	root->right->right = &TreeNode(3);

	cout << s.isSymmetric(root) << endl;
}