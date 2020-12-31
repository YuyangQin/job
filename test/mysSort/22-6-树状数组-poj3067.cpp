#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

//1�����ڱ����о޴���������ݣ�����ʹ��scanf������cin�Ա��ⳬʱ
//2�����������˳�����Ա���ɼ�Ϊһά����״���飬����¼���������С����������

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

void add(int i, int z)//��λ��i����a[i]
{
	for (; i <= maxn; i += lowbit(i))
	{
		c[i] += z;
	}
}

//��1~i�ĺ�
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
