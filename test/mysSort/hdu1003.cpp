#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

void test1()
{
	int T;
	while (cin >> T)
	{
		int num = 1;
		int l, r, start;
		while (T--)
		{
			l = 1;
			r = 1;
			start = 1;
			int N;
			cin >> N;
			vector<int> dp(N + 1);
			dp[0] = 0;
			cin >> dp[1];
			int max = dp[1];

			for (size_t i = 2; i <= N; i++)
			{
				cin >> dp[i];
				if (dp[i - 1] >= 0)
				{
					dp[i] = dp[i - 1] + dp[i];
				}
				else
				{
					start = i;
				}
				if (dp[i]>max)
				{
					max = dp[i];
					l = start;
					r = i;
				}

			}
			cout << "Case " << num++ << " :" << endl;
			cout << max << " " << l << " " << r << endl;
			if (T)
			{
				cout << endl;
			}
		}
	}
}

int main()
{
	test1();

	return 0;
}