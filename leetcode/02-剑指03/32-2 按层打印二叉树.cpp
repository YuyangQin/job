#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> myres;
		if (root == NULL)
			return myres;
		queue<TreeNode*> myque;
		myque.push(root);
		while (!myque.empty())
		{
			vector<int> res;
			for (int i = myque.size(); i > 0; i--)
			{
				TreeNode* tmp = myque.front();
				myque.pop();
				res.push_back(tmp->val);
				if (tmp->left != NULL)
					myque.push(tmp->left);
				if (tmp->right != NULL)
					myque.push(tmp->right);
			}
			myres.push_back(res);
		}
		return myres;
	}
};

void main()
{
	TreeNode root = TreeNode(3);
	root.left = &TreeNode(9);
	root.right = &TreeNode(20);
	root.right->left = &TreeNode(15);
	root.right->right = &TreeNode(7);

	Solution s;
	vector<vector<int>> res = s.levelOrder(&root);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j]<<" ";
		}
		cout << endl;
	}
}
