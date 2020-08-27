#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> path;
		dfs(root, 0, sum, res, path);
		return res;
	}
	void dfs(TreeNode* node, int tmp_sum,int sum, vector<vector<int>>& res, vector<int>& path)
	{
		if (!node)
			return;
		path.push_back(node->val);
		tmp_sum += node->val;
		if (!node->left&&!node->right)
		{
			if (tmp_sum == sum)
				res.push_back(path);
		}
		dfs(node->left, tmp_sum, sum, res, path);
		dfs(node->right, tmp_sum, sum, res, path);
		path.pop_back();
	}
};

int main()
{

	return 0;
}
