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
	//方法二、迭代
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val > q->val) { // 保证 p->val < q->val,以减少判断次数
			TreeNode* tmp = p;
			p = q;
			q = tmp;
		}
		while (root) {
			if (root->val < p->val) 
				root = root->right;
			else if (root->val > q->val) 
				root = root->left;
			else break;
		}
		return root;
	}

	//方法一、递归
	TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root->val > p->val&&root->val > q->val)
		{
			return lowestCommonAncestor(root->left, p, q);
		}
		else if (root->val < p->val&&root->val < q->val)
		{
			return lowestCommonAncestor(root->right, p, q);
		}
		return root;
	}
};

int main()
{

	return 0;
}
