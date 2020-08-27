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
	vector<vector<int>> res;
	vector<int>tmp;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {		
		recur(root, sum);
		return res;
	}
	void recur(TreeNode* root, int sum)
	{
		if (root == NULL)
			return;
		sum -= root->val;
		tmp.push_back(root->val);
		if (sum == 0&&root->left == NULL&&root->right == NULL)
			res.push_back(tmp);
		recur(root->left, sum); 
		recur(root->right, sum);
		tmp.pop_back();
	}
};

void main()
{

}
