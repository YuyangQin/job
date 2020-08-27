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
	int ret;
	int kthLargest(TreeNode* root, int k) {
		inorder(root, k);
		return ret;
	}
	void inorder(TreeNode* root, int &k)
	{
		if (!root)
		{
			return;
		}
		inorder(root->right, k);
		if (k == 0)
			return;
		if (--k == 0)
		{
			ret = root->val;
		}
		inorder(root->left, k);
	}
};

int main()
{
	Solution s;
	TreeNode t3(3);
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t4(4);
	t3.left = &t1;
	t1.right = &t2;
	t3.right = &t4;

	cout << s.kthLargest(&t3, 1) << endl;

	return 0;
}
