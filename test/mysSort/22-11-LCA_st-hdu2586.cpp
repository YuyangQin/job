#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

/*
	����������st��O(nlogn)����ѯ���Ӷ�ΪO(logn),������������ѯ���Ӷ�ΪO(n)�����Ե�
��ѯ�������ٵ�ʱ�򣬹ⴴ�������ҪO(nlogn),�������ñ������
*/

const int maxn = 40005;
int n, m, k, F[maxn][20];//F[i][j]����i������2^j���Ľڵ�
int head[maxn], dist[maxn], d[maxn], cnt;//ͷ�ڵ㣬�ݸ��ڵ���룬��ȣ�����

struct Edge
{
	int to, c, next;//�ٽӵ㣬��Ȩ��
}e[maxn<<1];//����ͼ���ʳ��ȳ�2

//��ʽǰ���ǣ����˽�
void add(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].c = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void dfs(int u)//����ȣ����룬��ʼ��F[v][0]
{
	for (size_t i = head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if (v==F[u][0])
		{
			continue;
		}
		d[v] = d[u] + 1;
		dist[v] = dist[u] + e[i].c;
		F[v][0] = u;
		dfs(v);
	}
}

void ST_create()
{
	for (size_t j = 1; j <= k; j++)
	{
		for (size_t i = 1; i <= n; i++)
		{
			F[i][j] = F[F[i][j - 1]][j - 1];//i����2^(j-1)������F[i][j - 1]������2^(j-1)����F[i][j]
		}
	}
}

int LCA_ST_query(int x, int y)
{
	if (d[x]>d[y])
	{
		swap(x, y);
	}
	for (int i = k; i >=0 ; i--)//y�����ߵ���xͬһ���
	{
		if (d[F[y][i]] >= d[x])
			y = F[i][i];
	}
	if (x == y)
		return x;
	for(int i=k;i>=0;i--)//x,yһ��������
		if (F[x][i]!=F[y][i])
		{
			x = F[x][i];
			y = F[y][i];
		}
	return F[x][0];//����x�ĸ���
}

int main()
{
	int x, y, T, lca;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		k = log2(n);
		for (int i = 1; i <= n; i++)//��ʼ��
			head[i] = d[i] = dist[i] = 0;
		cnt = 0;
		for (size_t i = 1; i < n; i++)//����һ������n-1����
		{
			int x, y, z;
			cin >> x >> y >> z;
			add(x, y, z);
			add(y, x, z);
		}
		d[1] = 1;
		dfs(1);
		ST_create();
		for (size_t i = 1; i <= m; i++)
		{
			cin >> x >> y;
			lca = LCA_ST_query(x, y);
			cout << dist[x] + dist[y] - 2 * dist[lca] << endl;
		}
	}

	return 0;
}