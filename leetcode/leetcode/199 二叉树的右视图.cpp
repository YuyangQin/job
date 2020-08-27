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
	vector<int> rightSideView(TreeNode* root) {
		if (!root)
			return vector<int>();
		vector<int> res;
		queue<TreeNode*> Q;
		Q.push(root);
		while (!Q.empty())
		{
			int i = Q.size();
			for (; i > 0; i--)
			{
				TreeNode* tmp = Q.front();
				if (i == 1)
				{
					res.push_back(tmp->val);
				}
				Q.pop();
				if (tmp->left)
				{
					Q.push(tmp->left);
				}
				if (tmp->right)
				{
					Q.push(tmp->right);
				}
			}
		}
		return res;
	}
};

class Solution1 {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		queue<pair<TreeNode*, int>> Q;
		if (root)
		{
			Q.push(make_pair(root, 0));
		}
		while (!Q.empty())
		{
			TreeNode* tmp = Q.front().first;
			int depth = Q.front().second;
			Q.pop();
			if (res.size() == depth)
			{
				res.push_back(tmp->val);
			}
			else
			{
				res[depth] = tmp->val;
			}
			if (tmp->left)
			{
				Q.push(make_pair(tmp->left,depth + 1));
			}
			if (tmp->right)
			{
				Q.push(make_pair(tmp->right, depth + 1));
			}
		}
		return res;
	}
};

int main()
{

	return 0;
}
