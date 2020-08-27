#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//深度遍历 当前节点的深度为左、右子树最大深度加1
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

//层序遍历
class Solution1 {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		int ret=0;
		queue<TreeNode*> treeQ;
		treeQ.push(root);
		while (!treeQ.empty())
		{
			int n = treeQ.size();
			for (int i = 0; i < n; i++)
			{
				TreeNode* tmp = treeQ.front();
				treeQ.pop();
				if (tmp->left)
				{
					treeQ.push(tmp->left);
				}
				if (tmp->right)
				{
					treeQ.push(tmp->right);
				}
			}
			ret++;
		}
		return ret;
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

	cout << s.maxDepth(&t3) << endl;

	return 0;
}
