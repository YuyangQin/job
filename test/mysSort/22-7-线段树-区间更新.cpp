#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

//��������ֵ��ѯΪ��(RMQ)��ʵ���߶���
//----------------------------------------�߶�������ռ�Ϊ4*n
const int maxn = 10002;
const int inf = 0x3f3f3f3f;
int n, a[maxn];

struct Node
{
	int l, r, mx, lz;
}tree[4 * maxn];

//����
void build(int k, int l, int r)
{
	tree[k].l = l;
	tree[k].r = r;
	tree[k].lz = -1;
	if (l == r)
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

void lazy(int k, int v)
{
	tree[k].mx = v;
	tree[k].lz = v;
}

void pushdown(int k)
{
	lazy(2 * k, tree[k].lz);
	lazy(2 * k + 1, tree[k].lz);
	tree[k].lz = -1;
}
//�������
void update(int k, int l, int r, int v)
{
	if (tree[k].lz != -1)
	{
		pushdown(k);
	}
	if (tree[k].l >= l&&tree[k].r <= r)
	{
		lazy(k, v);
		return;
	}
	int mid = (tree[k].l + tree[k].r) / 2;
	int lc = k * 2;
	int rc = k * 2 + 1;
	if (l <= mid)
	{
		update(lc, l, mid, v);
	}
	if (r>mid)
	{
		update(rc, mid + 1, r, v);
	}
	tree[k].mx = max(tree[lc].mx, tree[rc].mx);
}

int query(int k, int l, int r)
{
	if (tree[k].l >= l&&tree[k].r <= r)
	{
		return tree[k].mx;
	}
	if (tree[k].lz != -1)
	{
		pushdown(k);
	}
	int mid = (tree[k].l + tree[k].r) / 2;
	int lc = k * 2;
	int rc = k * 2 + 1;
	int MAX = -inf;
	if (l <= mid)
	{
		MAX = max(MAX, query(lc, l, mid));
	}
	if (r>mid)
	{
		MAX = max(MAX, query(rc, mid + 1, r));
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
	int l, r,v;
	cout << "��������Ҫ��ѯ������l,r" << endl;
	cin >> l >> r;
	cout << query(1, l, r) << endl;
	cout << "��������Ҫ�޸ĵ�����l,r��ֵv" << endl;

	cin >> l >> r >> v;
	update(1, l, r, v);
	cout << "��������Ҫ��ѯ������l,r" << endl;
	cin >> l >> r;
	cout << query(1, l, r) << endl;

	return 0;
}
/*
10
5 3 7 2 12 1 6 4 8 15
1 10
3 7 2
6 8
*/