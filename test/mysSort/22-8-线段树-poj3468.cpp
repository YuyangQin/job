#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;
#define  LL long long
const int maxn = 100010;
int N;
LL sum[maxn << 2], lazy[maxn << 2];

inline void PushUp(int i)
{
	sum[i] = sum[i << 1] + sum[i << 1 | 1];
}

inline void PushDown(int i,int l,int r,int mid)
{
	if (lazy[i])
	{
		lazy[i << 1] += lazy[i];
		sum[i << 1] += (mid - l + 1)*lazy[i << 1];
		lazy[i << 1 | 1] += lazy[i];
		sum[i << 1 | 1] += (r - mid)*lazy[i << 1 | 1];
		lazy[i] = 0;
	}
}

void build(int l,int r,int i)
{
	if (l==r)
	{
		scanf("%lld", &sum[i]);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, i << 1);
	build(mid + 1, r, i << 1 | 1);
	PushUp(i);
}

LL query(int a, int b, int l, int r, int i)
{
	if (a==l&&b==r)
	{
		return sum[i];
	}
	int mid = (l + r) >> 1;
	PushDown(i, l, r, mid);
	if (b<=mid)
	{
		return query(a, b, l, mid, i << 1);
	}
	else if (a>mid)
	{
		return query(a, b, mid + 1, r, i << 1 | 1);
	}
	else
	{
		return query(a, mid, l, mid, i << 1) + query(mid + 1, b, mid + 1, r, i << 1 | 1);
	}
}

void update(int a, int b, int c, int l, int r, int i)
{ 
	if (l>=a&&r<=b)
	{
		sum[i] += (r - l + 1)*c;
		lazy[i] += c;
		return;
	}
	int mid = (l + r) >> 1;
	PushDown(i, l, r, mid);
	if (a<=mid)
	{
		update(a, b, c, l, mid, i << 1);
	}
	if (b>mid)
	{
		update(a, b, c, mid + 1, r, i << 1 | 1);
	}
	PushUp(i);
}

int main()
{
	int  Q;
	cin >> N >> Q;
	build(1,N,1);

	int a, b;
	LL c;
	char command[5];

	for (size_t i = 0; i < Q; i++)
	{
		scanf("%s", command);
		scanf("%d%d", &a, &b);
		if (command[0]=='Q')
		{
			printf("%lld\n", query(a, b, 1, N, 1));
		}
		else
		{
			scanf("%lld", &c);
			update(a, b, c, 1, N, 1);
		}
	}

	return 0;
}
