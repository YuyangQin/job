#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//方法三、递归，找满足条件父节点
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || root == p || root == q) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left == NULL) return right;
		if (right == NULL) return left;
		return root;
	}
};

//方法二、使用哈希表存储父节点
class Solution2 {
public:
	unordered_map<int, TreeNode*> fa;
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		unordered_map<int, bool> visited;
		preOrder(root);
		fa[root->val] = NULL;
		while (p)
		{
			visited[p->val] = true;
			p = fa[p->val];
		}
		while (q)
		{
			if (visited[q->val]) return q;
			q = fa[q->val];
		}
		return NULL;
	}
	void preOrder(TreeNode* root)
	{
		if (root->left)
		{
			fa[root->left->val] = root;
			preOrder(root->left);
		}
		if (root->right)
		{
			fa[root->right->val] = root;
			preOrder(root->right);
		}		
	}
};

//方法一、使用vector存储
class Solution1 {
public:
	int flag = 0;
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> vp;
		vector<TreeNode*> vq;
		preOrder(root, p, vp);
		flag = 0;
		preOrder(root, q, vq);
		int len = min(vp.size(), vq.size());
		for (size_t i = 0; i < len; i++)
		{
			if (vp[i] != vq[i])
				return vp[i-1];
		}
		return vp[len-1];
	}
	void preOrder(TreeNode* root, TreeNode* node, vector<TreeNode*>& vnode)
	{
		if (!root||flag==1)
		{
			return;
		}
		vnode.push_back(root);
		if (root->val==node->val)
		{
			flag = 1;
			return;
		}
		preOrder(root->left, node, vnode);
		preOrder(root->right, node, vnode);
		if (flag==0)
		{
			vnode.pop_back();
		}		
	}
};

int main()
{

	return 0;
}
