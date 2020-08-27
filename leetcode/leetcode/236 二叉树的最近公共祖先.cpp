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
	bool flag = false;
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* res =NULL;
		vector<TreeNode*> pv;
		vector<TreeNode*> qv;
		dfs(root, p, pv);
		flag = false;
		dfs(root, q, qv);
		int short_len = pv.size() < qv.size() ? pv.size() : qv.size();
		for (size_t i = 0; i < short_len; i++)
		{
			if (pv[i] == qv[i])
				res = pv[i];
		}
		return res;
	}
	void dfs(TreeNode* node, TreeNode*& p, vector<TreeNode*>& path)
	{
		if (!node || flag)
			return;
		path.push_back(node);
		if (node == p)
		{
			flag = true;
		}
		dfs(node->left, p, path);
		dfs(node->right, p, path);
		if (!flag)
		{
			path.pop_back();
		}		
	}
};

int main()
{
	TreeNode t0(0);
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(5);
	TreeNode t6(6);
	TreeNode t7(7);
	TreeNode t8(8);

	t3.left = &t5;
	t3.right = &t1;
	t5.left = &t6;
	t5.right = &t2;
	t2.left = &t7;
	t2.right = &t4;
	t1.left = &t0;
	t1.right = &t8;

	Solution s;
	cout << s.lowestCommonAncestor(&t3, &t5, &t4)->val << endl;

	return 0;
}
