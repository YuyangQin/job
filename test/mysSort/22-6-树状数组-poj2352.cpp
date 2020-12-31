#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

//1、由于本题有巨大的输入数据，所以使用scanf而不是cin以避免超时
//2、由于输入的顺序，所以本题可简化为一维的树状数组，仅记录比其横坐标小的数量即可

const int maxn = 32005;
int n;

int lowbit(int x)
{
	return (-x)&x;
}

//一维树状数组
//单点添加
int a[maxn], c[maxn];
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

//求区间和
int sum(int i, int j)
{
	return sum(j) - sum(i - 1);
}

int main()
{
	int x, y;
	scanf("%d", &n);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d %d", &x,&y);

		x++;
		a[sum(x)]++;
		add(x, 1);
	}
	for (size_t i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}

	return 0;
}
