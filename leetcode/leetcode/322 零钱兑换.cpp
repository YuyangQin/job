#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1,-1);
		dp[0] = 0;
		int n = coins.size();
		for (size_t i = 1; i <= amount; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (i >= coins[j] && dp[i-coins[j]]!=-1 )
				{
					if (dp[i]==-1||dp[i-coins[j]] + 1 < dp[i])
					{
						dp[i] = dp[i-coins[j]] + 1;
					}					
				}
			}
		}
		return dp[amount];
	}
};

int main()
{
	vector<int> coins = { 1,2,5 };
	Solution s;
	cout << s.coinChange(coins,11) << endl;

	return 0;
}
