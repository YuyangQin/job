#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<double> twoSum(int n) {
		vector<double> res;
		vector<vector<int>> dp(n+1, vector<int>(6 * n + 1));
		for (size_t i = 1; i <= 6; i++)
		{
			dp[1][i] = 1;
		}
		for (size_t i = 2; i <= n; i++)
		{
			for (int j = i; j <= 6 * i; j++)
			{
				for (size_t k = 1; k <= 6; k++)
				{
					if (j - k <= 0)
						break;
					dp[i][j] += dp[i - 1][j - k];
				}
			}
		}
		double all = pow(6, n);
		return res;
	}
};

int main()
{
	Solution s;
	s.twoSum(2);

	return 0;
}
