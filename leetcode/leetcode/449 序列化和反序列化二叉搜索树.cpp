#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Codec {
public:

	void preOreder(TreeNode* root, string& str)
	{
		if (!root)
		{
			return;
		}
		str.append(to_string(root->val) + '#');
		preOreder(root->left, str);
		preOreder(root->right,str);
	}
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res;
		preOreder(root, res);
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		vector<TreeNode*> v;
		int val = 0;
		for (size_t i = 0; i < data.size(); i++)
		{
			if (data[i]=='#')
			{
				v.push_back(new TreeNode(val));
				val = 0;
			}
			else
			{
				val += val * 10 + data[i] - '0';
			}
		}
		/*while (!data.empty())
		{
			int a = atoi(data.substr(0, data.find('#')).c_str());
			v.push_back(new TreeNode(a));
			data.erase(0, data.find('#') + 1);
		}*/
		for (size_t i = 1; i < v.size(); i++)
		{
			insertTree(v[0], v[i]);
		}
		return v[0];
	}

	void insertTree(TreeNode* root, TreeNode* &node)
	{
		if (node->val >= root->val)
		{
			if (root->right)
			{
				insertTree(root->right, node);
			}
			else
			{
				root->right = node;
			}
		}
		else
		{
			if (root->left)
			{
				insertTree(root->left, node);
			}
			else
			{
				root->left = node;
			}
		}
	}
};

int main()
{
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(5);

	t1.right = &t2;
	t2.right = &t3;
	t3.right = &t4;
	t4.right = &t5;

	Codec codec;
	codec.deserialize("1#2#4#5#3#");

	return 0;
}
