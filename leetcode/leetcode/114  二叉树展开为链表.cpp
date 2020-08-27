#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
	void flatten(TreeNode* root) {
		TreeNode* last= NULL;
		preorder(root,last);
	}
	void preorder(TreeNode*& node, TreeNode*& last)
	{
		if (!node)
			return;
		if (!node->left && !node->right)
		{
			last = node;
			return;
		}
		TreeNode* left = node->left;
		TreeNode* right = node->right;
		TreeNode* right_last = NULL;
		TreeNode* left_last = NULL;	
		if (left)
		{
			preorder(left, left_last);
			node->right = left;
			node->left = NULL;
			last = left_last;
		}
		if (right)
		{
			preorder(right, right_last);
			if (left_last)
			{
				left_last->right = right;
			}
			last = right_last;
		}	
	}
	void dfs(TreeNode*& node, TreeNode*& last)
	{
		if (!node)
			return;
		
		if (!node->left&&!node->right)
		{
			last = node;
			return;
		}
		TreeNode* left = node->left;
		TreeNode* right = node->right;
		dfs(left,  last);
		if (left)
		{
			node->right = left;
			node->left = NULL;
			if (right)
			{
				last->right = right;
				last = right;
			}
		}		
		dfs(right, last);
	}
};

int main()
{

	return 0;
}
