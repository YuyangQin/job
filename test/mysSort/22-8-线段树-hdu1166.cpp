#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int maxn = 50010;
int sum[maxn << 2];

void build(int l, int r, int root)
{
	if (l==r)
	{
		scanf("%d", &sum[root]);
		return;
	}

	int mid = (l + r) / 2;
	build(l, mid, 2*root);
	build(mid + 1, r, 2*root+1);

	sum[root] = sum[2 * root] + sum[2 * root + 1];
}

void update(int i, int v, int l, int r, int root)
{
	if (l==r)
	{
		sum[root] += v;
		return;
	}
	int mid = (l + r) / 2;
	if (i<=mid)
	{
		update(i, v, l, mid, 2 * root);
	}
	else
	{
		update(i, v, mid + 1, r, 2 * root + 1);
	}
	sum[root] = sum[2 * root] + sum[2 * root + 1];
}

int query(int left, int right, int l, int r, int root)
{
	if (left==l&&right==r)
	{
		return sum[root];
	}
	int mid = (l + r) / 2;
	if (right<=mid)
	{
		return query(left, right, l, mid, root * 2);
	}
	else if (left>mid)
	{
		return query(left, right, mid + 1, r, 2 * root + 1);
	}
	else
	{
		return query(left, mid, l, mid, root * 2)+ query(mid+1, right, mid + 1, r, 2 * root + 1);
	}
}

int main()
{
	int N, T;
	cin >> T;
	for (size_t i = 1; i <= T; i++)
	{
		printf("Case %d:\n", i);
		cin >> N;		
		build(1, N, 1);
		int j, k;
		string commands;
		while (cin>>commands)
		{
			if (commands=="End")
				break;
			cin >> k >> j;
			if (commands=="Query")
			{
				cout << query(k, j, 1, N, 1) << endl;
			}
			else
			{
				if (commands=="Sub")
				{
					j = -j;
				}
				update(k, j, 1, N, 1);
			}
		}
	}	

	return 0;
}