#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode() {};
	TreeNode(int val)
	{
		this->val = val;
		left = NULL;
		right = NULL;
	}
};
void insert(TreeNode* root, TreeNode* node)
{
	if (root==NULL)
	{
		root = node;
	}
	TreeNode* tmp = root;
	while (1)
	{
		if (tmp->val>node->val)
		{
			if (tmp->left==NULL)
			{
				tmp->left = node;
				break;
			}
			else
			{
				tmp = tmp->left;
			}
		}
		else
		{
			if (tmp->right==NULL)
			{
				tmp->right = node;
				break;
			}
			else
			{
				tmp = tmp->right;
			}			
		}
	}
}
int countLinkLength(TreeNode* root,int level)
{
	if (root==NULL)
	{
		return 0;
	}
	int left = countLinkLength(root->left, level + 1);
	int right = countLinkLength(root->right, level + 1);
	if (level==0)
	{
		return left + right + 1;
	}
	return max(left, right) + 1;
}
void test1()
{
	int n=100000,tmp;
	while (cin>>n)
	{
		vector<int> nums(n);
		cin >> nums[0];
		nums[0] = rand() % 10000 + 1;
		
		TreeNode* root=new TreeNode(nums[0]);
		for (size_t i = 1; i < n; i++)
		{
			cin >> nums[i];
			insert(root, new TreeNode(nums[i]));
		}
		int ret = countLinkLength(root, 0);
		cout << ret << endl;
	}
}

long long get(long n, long k)
{
	long sum1 = 1;
	for (long i = n; i > n - k; i--)
	{
		sum1 *= i;
		sum1 %= 1000000007;
	}
	long sum2 = 1;
	for (long i = 1; i <= k; i++)
	{
		sum2 *= i;
		sum2 %= 1000000007;
	}
	return sum1 / sum2;
}

void test2()
{
	long MAX = 1000000007;
	int N = 1005;
	long n,m,k;
	vector < vector<int >> vec(1005, vector<int >(1005));
	while (cin>>n>>m>>k)
	{
		long count = 0;
		for (long i = 3; i <= k-2; i++)
		{
			long j = k - i;
			count += get(n, i)*get(m, j) % MAX;
		}
		cout << count << endl;
	}
}



int main()
{
	test2();

	return 0;
}
