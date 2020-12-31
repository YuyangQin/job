#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 40005;
int n, m, tot, F[maxn << 1][20];//F[i][[j]��ʾ����[i,i+2^j-1]����ֵ�����䳤��Ϊ2^j
int head[maxn], dist[maxn], pos[maxn], seq[maxn << 1], dep[maxn << 1], cnt;
bool vis[maxn];

struct Edge
{
	int to, c, next;
}e[maxn << 1];

void add(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].c = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void dfs(int u, int d)
{
	vis[u] = true;
	pos[u] = ++tot;//u�״γ��ֵ��±�
	seq[tot] = u;//dfs��������
	dep[tot] = d;//���
	for (size_t i = head[u]; i ; i=e[i].next)
	{
		int v = e[i].to;
		int w = e[i].c;
		if (vis[v])
		{
			continue;
		}
		dist[v] = dist[u] + w;
		dfs(v, d + 1);
		seq[++tot] = u;//dfs��������
		dep[tot] = d;//���
	}
}

void ST_creat()
{
	for (int i = 0; i <= tot; i++)
	{
		F[i][0] = i;//��¼�����±���������
	}
	int k = log2(tot);
	for (size_t j = 1; j <= k; j++)
	{
		for(int i=1;i<=tot-(1<<j)+1;i++)
			if (dep[F[i][j-1]]<dep[F[i+(1<<(j-1))][j-1]])
			{
				F[i][j] = F[i][j - 1];
			}
			else
			{
				F[i][j] = F[i + (1 << j - 1)][j - 1];
			}
	}
}

int RMQ_query(int l, int r)//������l,r����ֵ
{
	int k = log2(r - l + 1);
	if (dep[F[l][k]]<dep[F[r-(1<<k)+1][k]])
	{
		return F[l][k];
	}
	else
	{
		return F[r - (1 << k) + 1][k];
	}
}

int LCA(int x, int y)
{
	int l = pos[x];
	int r = pos[y];//��ȡ��һ�γ��ֵ��±�
	if (l>r)
	{
		swap(l, r);
	}
	return seq[RMQ_query(l, r)];
}

void print()
{
	for (size_t i = 1; i <= tot; i++)
	{

	}
}

int main()
{

	return 0;
}
