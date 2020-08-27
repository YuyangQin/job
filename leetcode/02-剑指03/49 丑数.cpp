#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> dp(n);
		dp[0] = 1;
		int a =0, b =0, c = 0;
		for (size_t i = 1; i < n; i++)
		{
			int na = dp[a] * 2;
			int nb = dp[b] * 3;
			int nc = dp[c] * 5;
			dp[i] = min(na,min(nb,nc));
			if (dp[i] == na)
				a++;
			if (dp[i] == nb)
				b++;
			if (dp[i] == nc)
				c++;
		}
		return dp[n - 1];
	}
};

int main()
{
	Solution s;
	cout << s.nthUglyNumber(10) << endl;
	return 0;
}
