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
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == NULL)
			return NULL;
		recur(root);
		return root;
	}
	void recur(TreeNode* root)
	{
		if (root == NULL)
			return;

		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		mirrorTree(root->left);
		mirrorTree(root->right);
	}
};

void main()
{
}