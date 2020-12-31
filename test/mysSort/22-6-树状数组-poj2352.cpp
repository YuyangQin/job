#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

//1�����ڱ����о޴���������ݣ�����ʹ��scanf������cin�Ա��ⳬʱ
//2�����������˳�����Ա���ɼ�Ϊһά����״���飬����¼���������С����������

const int maxn = 32005;
int n;

int lowbit(int x)
{
	return (-x)&x;
}

//һά��״����
//�������
int a[maxn], c[maxn];
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

//�������
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
