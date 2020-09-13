#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

void test1()
{
	int n;
	while (cin >> n)
	{
		vector<int> nums(n);
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}
		cout << n - 1 << endl;
	}
}

int main()
{
	test1();

	return 0;
}
