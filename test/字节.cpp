#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void test1()
{
	int n;
	while (cin>>n)
	{
		if(n<=1)
		{
			cout << n << endl;
			continue;
		}
		vector<vector<long>> dp(n + 1, vector<long>(3, 0));
		dp[0][1] = 1;
		dp[0][2] = 1;
		dp[1][1] = 1;
		for (size_t i = 2; i <= n; i++)
		{
			dp[i][1] = dp[i - 1][1] + dp[i - 1][2];
			dp[i][2] = dp[i - 2][1];
		}
		cout << dp[n][1] + dp[n][2] << endl;
	}
}

void test2()
{
	int n;
	while (cin >> n)
	{
		vector<int> nums(n);
		cin >> nums[0];
		vector<int> L(n, 0);
		int leftMax = nums[0];
		vector<int> R(n, 0);
		int j;
		for (size_t i = 1; i < n; i++)
		{
			cin >> nums[i];
			if (leftMax>nums[i])
			{
				j = i - 1;
				while (j >= 0)
				{
					if (nums[j]>nums[i])
					{
						L[i] = j + 1;
						break;
					}
					j--;
				}
			}
			else
			{
				leftMax = nums[i];
			}
		}
		int rightMax = nums[n - 1];
		for (int i = n - 2; i >= 00; i--)
		{
			if (rightMax > nums[i])
			{
				j = i + 1;
				while (j < n)
				{
					if (nums[j]>nums[i])
					{
						R[i] = j + 1;
						break;
					}
					j++;
				}
			}
			else
			{
				rightMax = nums[i];
			}
		}
		int max = 0;
		for (size_t i = 0; i < n; i++)
		{
			if (L[i] * R[i]>max)
			{
				max = L[i] * R[i];
			}
		}
		cout << max << endl;
	}
}
void test2_new()
{
	int n;
	while (cin >> n)
	{
		vector<int> nums(n);
		cin >> nums[0];
		vector<int> L(n);
		vector<int> R(n);
		stack<int> stk;
		stack<int> stk2;
		for (size_t i = 0; i < n; i++)
		{
			cin >> nums[i];
			while (!stk.empty()&&nums[stk.top()]<=nums[i])
			{
				stk.pop();
			}
			if (!stk.empty())
			{
				L[i] = stk.top() + 1;
			}
			stk.push(i);
		}
		
		for (int i = n - 1; i >= 0; i--)
		{
			while (!stk2.empty() && nums[stk2.top()] <= nums[i])
			{
				stk2.pop();
			}
			if (!stk2.empty())
			{
				R[i] = stk2.top() + 1;
			}
			stk2.push(i);
		}
		long max = 0;
		for (size_t i = 0; i < n; i++)
		{
			if (L[i] * R[i]>max)
			{
				max = L[i] * R[i];
			}
		}
		cout << max << endl;
	}
}


int main()
{
	test2();

	return 0;
}
