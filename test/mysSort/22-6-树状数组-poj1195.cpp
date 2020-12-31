#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int maxn = 1030;
int c[maxn][maxn], n;

int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int y,int a)
{
	for (size_t i = x; i <= n; i+=lowbit(i))
	{
		for (int j = y; j <= n; j += lowbit(j))
			c[i][j] += a;
	}
}

int sum(int x, int y)
{
	int ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		for (int j = y; j > 0; j -= lowbit(j))
			ans += c[i][j];
	return ans;
}
int sum(int x1, int y1, int x2, int y2)
{
	return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
}

int main()
{
	int command,x,y,a,l,b,r,t;
	cin >> command >> n;
	while (cin>>command)
	{
		if (command == 1)
		{
			cin >> x >> y >> a;
			add(x + 1, y + 1, a);
		}
		else if (command == 2)
		{
			cin >> l >> b >> r >> t;
			cout << sum(l + 1, b + 1, r + 1, t + 1) << endl;
		}
		else
		{
			break;
		}
	}

	return 0;
}
/*
0 4
1 1 2 3 
2 0 0 2 2
1 1 1 2 
1 1 2 -1 
2 1 1 2 3 
3
*/