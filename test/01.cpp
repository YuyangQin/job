#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void test1()
{
	int N=1;
	//cin >> N;
	vector<int> num(N + 1);
	vector<int> visited(N+1,0);
	
	for (size_t i = 1; i <= N; i++)
	{
		num[i] = i;
	}

	//��1 ��ʼ�������˴�Ϊ������ռλ
	num[0] = -1;
	visited[0] = 1;

	/*for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}*/

	//�ҵ����һ�����ڵ�
	int lastFather = N / 2;
	int fatherRange = 1;
	int level = 1;
	while (lastFather>fatherRange)
	{
		fatherRange += pow(2,level);
		level++;
	}

	//�����߽�
	int i = 1;
	for ( i = 1; i <= N; i*=2)
	{
		cout << num[i] << " ";
		visited[i] = 1;
	}

	//����±߽�
	if (i >= 2)
	{
		i /= 2;
		i++;
		for (; i <= N; i++)
		{
			if (visited[i]==0)
			{
				cout << num[i] << " ";
				visited[i] = 1;
			}			
		}
	}

	//������һ�����ڵ����ڱ߽�
	for ( i = lastFather+1; i <= fatherRange; i++)
	{
		if (visited[i]==0)
		{
			cout << num[i] << " ";
			visited[i] = 1;
		}
	}

	//����ұ߽�
	for ( i--; i > 1; i/=2)
	{
		if (visited[i]==0)
		{
			cout << num[i] << " ";
			visited[i] = 1;
		}
	}
}

void test3()
{
	int n, k;
	stack<int> s;
	cin >> n >> k;
	if (n<=1)
	{
		cout << n;
		return;
	}
	int left = 1;
	int right = n;
	int mid;
	while (right-left>2)
	{
		mid = (left + right) >> 1;
		s.push(mid);
		left = mid + 1;
	}

	if (right-left==2)
	{
		s.push((left + right) >> 1);
	}
	else
	{
		s.push(right);
	}

	while (k)
	{
		s.pop();
		k--;
	}

	int res = 0;
	while (!s.empty())
	{
		res += s.top();
		s.pop();
	}
	cout << res;
}


int main()
{
	test1();
	//test3();

	return 0;
}
