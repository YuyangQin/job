#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//栈思想
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		vector<int> myStack;
		myStack.push_back(nums[0]);
		for (size_t i = 1; i < n; i++)
		{
			if (nums[i] > myStack.back())
			{
				myStack.push_back(nums[i]);
			}
			else
			{
				for (size_t j = 0; j < myStack.size(); j++)
				{
					if (nums[i] <= myStack[j])
					{
						myStack[j] = nums[i];
						break;
					}
				}
			}
		}
		return myStack.size();
	}
};

//动态规划
class Solution1 {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (n==0)
		{
			return 0;
		}
		vector<int> dp(n, 1);
		int max = 1;
		for (size_t i = 1; i < n; i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (nums[j]<nums[i]&&dp[j]+1>dp[i])
				{
					dp[i] = dp[j] + 1;
				}
			}
			if (dp[i]>max)
			{
				max = dp[i];
			}
		}
		return max;
	}
};

int main()
{

	return 0;
}
