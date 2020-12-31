#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

//以区间最值查询为例(RMQ)，实现线段树
//----------------------------------------线段树所需空间为4*n
const int maxn = 10002;
const int inf = 0x3f3f3f3f;
int n, a[maxn];

struct Node
{
	int l, r, mx;
}tree[4 * maxn];

//构建
void build(int k, int l, int r)
{
	tree[k].l = l;
	tree[k].r = r;
	if (l==r)
	{
		tree[k].mx = a[l];
		return;
	}
	int mid = (l + r) / 2;
	int lc = k << 1;
	int rc = lc + 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	tree[k].mx = max(tree[lc].mx, tree[rc].mx);
}

//单点更新
void update(int k,int i,int v)
{
	if (tree[k].l==tree[k].r&&tree[k].l==i)
	{
		tree[k].mx = v;
		return;
	}
	int mid = (tree[k].l + tree[k].r) / 2;
	int lc = k * 2;
	int rc = k * 2 + 1;
	if (i<=mid)
	{
		update(lc, i, v);
	}
	else
	{
		update(rc, i, v);
	}
	tree[k].mx = max(tree[lc].mx, tree[rc].mx);
}

//区间查询
int query(int k,int l,int r)
{
	if (tree[k].l<=l&&tree[k].r>=r)
	{
		return tree[k].mx;
	}
	int mid = (tree[k].l + tree[k].r) / 2;
	int lc = k * 2;
	int rc = k * 2 + 1;
	int MAX = -inf;
	if (l<=mid)
	{
		MAX = max(MAX, query(lc, l, mid));
	}
	if (r>mid)
	{
		MAX = max(MAX, query(rc, r, mid + 1));
	}
	return MAX;
}

int main()
{
	cin >> n;
	for (size_t i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	build(1, 1, n);
	int l, r;
	cout << "请输入需要查询的区间l,r" << endl;
	cin >> l >> r;
	cout << query(1, l, r) << endl;
	cout << "请输入需要修改的下表i和值v" << endl;
	cin >> l >> r;
	cout << "请输入需要查询的区间l,r" << endl;
	cin >> l >> r;
	cout << query(1, l, r) << endl;

	return 0;
}
