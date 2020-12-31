#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

//1、由于本题有巨大的输入数据，所以使用scanf而不是cin以避免超时
//2、由于输入的顺序，所以本题可简化为一维的树状数组，仅记录比其横坐标小的数量即可

const int maxn = 1005;
const int maxk = 1000010;
typedef long long LL;
struct Edge
{
	int x, y;
}e[maxk];
bool cmp(Edge a, Edge b)
{
	return a.x < b.x || (a.x == b.x&&a.y < b.y);
}

int n,m,k,cases;
int a[maxn], c[maxn];

int lowbit(int x)
{
	return (-x)&x;
}

void add(int i, int z)//在位置i增加a[i]
{
	for (; i <= maxn; i += lowbit(i))
	{
		c[i] += z;
	}
}

//求1~i的和
int sum(int i)
{
	int ans = 0;
	for (; i > 0; i -= lowbit(i))
	{
		ans += c[i];
	}
	return ans;
}

int main()
{	
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(c, 0, sizeof(c));
		scanf("%d%d%d", &n,&m,&k);
		for (size_t i = 0; i < k; i++)
		{
			scanf("%d %d", &e[i].x, &e[i].y);		
		}
		sort(e, e + k, cmp);
		LL ans = 0;
		for (size_t i = 0; i < k; i++)
		{
			ans += i - sum(e[i].y);
			add(e[i].y, 1);
		}
		printf("Test case %d: %lld\n", ++cases, ans);
	}

	return 0;
}
