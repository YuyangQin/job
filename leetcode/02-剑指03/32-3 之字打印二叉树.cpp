#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
		int flag = 0;
		while (!myque.empty())
		{
			vector<int> res;
			
			stack<TreeNode*> mystack;
			for (int i = myque.size(); i > 0; i--)
			{
				TreeNode* tmp = myque.front();
				myque.pop();
				res.push_back(tmp->val);
				mystack.push(tmp);
			}
			if (flag % 2 == 1)
			{
				while (!mystack.empty())
				{
					if (mystack.top()->left != NULL)
						myque.push(mystack.top()->left);
					if (mystack.top()->right != NULL)
						myque.push(mystack.top()->right);
					mystack.pop();
				}
				
			}
			else
			{
				while (!mystack.empty())
				{
					if (mystack.top()->right != NULL)
						myque.push(mystack.top()->right);
					if (mystack.top()->left != NULL)
						myque.push(mystack.top()->left);
					mystack.pop();
				}
			}
			
			
			myres.push_back(res);
			flag++;
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
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
