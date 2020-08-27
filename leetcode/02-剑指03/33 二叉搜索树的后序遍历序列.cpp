#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <limits>
#include <stack>

using namespace std;

class Solution {
public:
	//单调栈
	bool verifyPostorder(vector<int>& postorder) {
		int root = INT_MAX;
		stack<int> mystack;
		for (int i = postorder.size()-1 ; i >= 0; i--)
		{
			if (postorder[i] > root)
				return false;
			while (!mystack.empty() && postorder[i] < mystack.top())
			{
				root = mystack.top();
				mystack.pop();
			}
				
			mystack.push(postorder[i]);
		}
		return true;
	}
	//递归
	bool verifyPostorder1(vector<int>& postorder) {
		return recur(0, postorder.size() - 1, postorder);
	}
	//代码优化版
	bool recur(int begin, int end, vector<int>& postorder)
	{
		if (begin >= end)
			return true;
		int i = begin;
		while (postorder[i] < postorder[end]) i++;
		int j = i;
		while (postorder[i] > postorder[end]) i++;
		return i == end&&recur(begin, j - 1, postorder) && recur(j, end-1, postorder);
	}
	bool recur1(int begin, int end, vector<int>& postorder)
	{
		if (begin >= end)
			return true;

		int left,right;
		int i;
		if (postorder[end-1]>postorder[end])
		{
			right = end - 1;
			for (i = end-2; i >= 0; i--)
			{
				if (postorder[i] < postorder[end])
					break;
			}
			left = i;
		}
		else
		{
			left = end - 1;
			right = -1;
		}
		for (int i = left-1; i >=begin ; i--)
		{
			if (postorder[i] > postorder[end])
				return false;
		}
		
		return recur(begin, left, postorder) && recur(left + 1, end-1, postorder);
	}
};

void main()
{
	Solution s;
	vector<int> v = { 1,2,3,4,5 };
	cout << s.verifyPostorder(v) << endl;;
}
