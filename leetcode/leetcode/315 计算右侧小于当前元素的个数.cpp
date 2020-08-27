#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct MyNode
{
	int val;
	int count;
	struct MyNode* left;
	struct MyNode* right;
	MyNode(int x)
	{
		val = x;
		count = 0;
		left = NULL;
		right = NULL;
	}
};

void buildTree(MyNode* root, MyNode* node,int &count_small)
{
	if (node->val>root->val)
	{
		count_small += root->count + 1;
		if (root->right)
		{
			buildTree(root->right, node, count_small);
		}
		else
		{
			root->right = node;
		}
	}
	else
	{
		root->count++;
		if (root->left)
		{
			buildTree(root->left, node, count_small);
		}
		else
		{
			root->left = node;
		}
	}
}

//¶þ²æÅÅÐòÊ÷
class Solution1 {
public:
	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		if (n==0)
		{
			return{};
		}
		vector<int> res(n);
		vector<MyNode*> BST;
		for (size_t i = 0; i < n; i++)
		{
			BST.push_back(new MyNode(nums[i]));
		}

		res[n - 1] = 0;
		for (int i = n-2; i >= 0; i--)
		{
			int count_small = 0;
			buildTree(BST[n - 1], BST[i], count_small);
			res[i] = count_small;
		}

		for (size_t i = 0; i < n; i++)
		{
			delete BST[i];
		}
		return res;
	}
};

//¹é²¢ÅÅÐò
class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<pair<int, int>> vec;
		vector<int> count;
		for (size_t i = 0; i < nums.size(); i++)
		{
			vec.push_back(make_pair(nums[i], i));
			count.push_back(0);
		}
		mergeSort(vec, count);
		return count;
	}
	void mergeSort(vector<pair<int, int>>& vec, vector<int>& count)
	{
		if (vec.size()<2)
		{
			return;
		}
		vector<pair<int, int>> sub1;
		vector<pair<int, int>> sub2;
		int mid = (vec.size()) >> 1;
		for (size_t i = 0; i < mid; i++)
		{
			sub1.push_back(vec[i]);
		}
		for (size_t i = mid; i < vec.size(); i++)
		{
			sub2.push_back(vec[i]);
		}
		mergeSort(sub1, count);
		mergeSort(sub2, count);
		vec.clear();
		mergeArray(sub1, sub2, vec, count);
	}
	void mergeArray(vector<pair<int, int>>& sub1, vector<pair<int, int>>& sub2, vector<pair<int, int>>& vec, vector<int>& count)
	{
		int i = 0;
		int j = 0;
		while (i<sub1.size()&&j<sub2.size())
		{
			if (sub1[i].first <= sub2[j].first)
			{
				count[sub1[i].second] += j;
				vec.push_back(sub1[i]);
				i++;
			}
			else
			{
				vec.push_back(sub2[j]);
				j++;
			}
		}
		while (i<sub1.size())
		{
			count[sub1[i].second] += j;
			vec.push_back(sub1[i]);
			i++;
		}
		while (j<sub2.size())
		{
			vec.push_back(sub2[j]);
			j++;
		}
	}
};

int main()
{
	vector<int> v = { 2,0,1 };
	Solution1  s;
	vector<int> res = s.countSmaller(v);
	for (auto it : res)
		cout << it << " ";

	return 0;
}
