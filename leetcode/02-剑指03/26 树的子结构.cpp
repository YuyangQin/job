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
	bool isSub = false;
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == NULL || B == NULL)
			return false;
		
		findNode(A, B);
		
		return isSub;
	}	
	void findNode(TreeNode* A, TreeNode* B)
	{
		if (A == NULL||isSub==true)
			return;

		if (A->val == B->val)
			if (isSubTree(A, B) == true)
				isSub = true;
		
		findNode(A->left, B);
		findNode(A->right, B);
	}
	bool isSubTree(TreeNode* A, TreeNode* B)
	{		
		
		if (B == NULL)
			return true;
		if (A == NULL)
			return false;
		if (A->val != B->val)
			return false;
			
		if ((isSubTree(A->left, B->left) == true) && (isSubTree(A->right, B->right) == true))
			return true;
		else
			return false;
	}
};

void main()
{
}