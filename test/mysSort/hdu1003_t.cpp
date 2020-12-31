#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int maxn = 100005;
int dp[maxn];
void test1()
{
	int t, n, cas = 0;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (size_t i = 1; i <= n; i++)
		{
			cin >> dp[i];
		}
		int l = 1, r = 1, start = 1;
		int MAX = dp[1];
		for (size_t i = 2; i <=n; i++)
		{
			if (dp[i - 1] >= 0)
				dp[i] = dp[i - 1] + dp[i];
			else
				start = i;
			if (dp[i]>MAX)
			{
				MAX = dp[i];
				l = start;
				r = i;
			}
		}
		if (cas)
		{
			cout << endl;
		}
		cout << "Case" << " " << ++cas << " :" << endl;
		cout << MAX <<" "<<l << " " << r << endl;
	}
}

int main()
{
	test1();

	return 0;
}
