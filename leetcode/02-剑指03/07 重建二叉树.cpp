#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#if 1
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		for (int i = 0; i < inorder.size(); i++)
		{
			treeMap.insert(make_pair(inorder[i], i));
		}
		return recursion(0, preorder.size()-1, 0,preorder,inorder);
	}
	TreeNode* recursion(int l, int r, int rootindex, vector<int>& preorder, vector<int>& inorder)
	{
		if (l > r)
			return NULL;

		TreeNode* root = new TreeNode(preorder[rootindex]);
		int mid = (treeMap.find(preorder[rootindex]))->second;		
		
		//遍历左子树
		root->left = recursion(l, mid - 1, rootindex + 1, preorder, inorder);
		//遍历右子树
		root->right = recursion(mid + 1, r, rootindex + (mid - l) + 1, preorder, inorder);
		return root;
	}
	map<int,int> treeMap;
};
#endif

void printTree(TreeNode* root)
{
	if (root!=NULL)
	{

		cout << root->val << " ";
		printTree(root->left);
		printTree(root->right);
	}
}

void main()
{
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };


	map<int,int> map1;

	
	Solution s;

	TreeNode * root = s.buildTree(preorder, inorder);
	printTree(root);
#if 0
	TreeNode* root = new TreeNode(3);
	TreeNode* root2 = new TreeNode(9);
	TreeNode* root3 = new TreeNode(20);
	TreeNode* root4 = new TreeNode(15);
	TreeNode* root5 = new TreeNode(7);
	
	root->left = root2;
	root->right = root3;
	root3->left = root4;
	root3->right = root5;

	
#endif
}