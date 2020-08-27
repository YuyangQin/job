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
	
	vector<int> levelOrder(TreeNode* root) {
		vector<int> res;
		if (root == NULL)
			return res;

		queue<TreeNode*> myque;		
		myque.push(root);	
		while (!myque.empty())
		{
			TreeNode* tmp = myque.front();
			myque.pop();
			res.push_back(tmp->val);
			if (tmp->left != NULL)
				myque.push(tmp->left);
			if (tmp->right != NULL)
				myque.push(tmp->right);
		}
		return res;
	}
};

void main()
{

}
