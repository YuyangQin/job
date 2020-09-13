#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void test1()
{

}

void test2()
{
	string str;
	char tmp;
	while (cin >> str)
	{
		int last = str.size() - 1;
		for (int i = str.size() - 1; i >= 0; i--)
		{
			if (str[i] >= 'A'&&str[i] <= 'Z')
			{
				tmp = str[i];
				for (int j = i; j < last; j++)
				{
					str[j] = str[j + 1];
				}
				str[last] = tmp;
				last--;
			}
		}
		cout << str << endl;
	}
}

void test3()
{
	int n;
	while (cin >> n)
	{
		vector<int> nums(n);
		int maxnum = 0;
		int minnum = 0;
		int min = INT_MAX;
		int max = 0;
		int diff;
		for (size_t i = 0; i < n; i++)
		{
			cin >> nums[i];
		}
		for (size_t i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				diff = abs(nums[i] - nums[j]);
				if (diff<=min)
				{
					if (diff==min)
					{
						minnum++;
					}
					else
					{
						minnum = 1;
						min = diff;
					}
				}
				else if (diff >= max)
				{
					if (diff == max)
					{
						maxnum++;
					}
					else
					{
						maxnum = 1;
						max = diff;
					}
				}
			}
		}
		cout << minnum << " " << maxnum << endl;
	}
}

int main()
{
	test3();

	return 0;
}
