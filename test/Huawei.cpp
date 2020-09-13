#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test1()
{
	vector<unsigned int> nums;
	string str;
	getline(cin, str);
	str += " ";
	size_t off = 0;
	int pos = str.find(" ", off);
	//可使用位运算
	//取奇数位：odd=num&0x55555555;
	//取偶数位：even=num&&0xaaaaaaaa;
	//奇偶交换：num==(odd<<1)^(even>>1);
	while (pos<str.size())
	{
		nums.push_back(atoi(str.substr(off, pos - off).c_str()));
		off = pos + 1;
		pos = str.find(" ", off);
	}

	int n = nums.size();
	vector<unsigned int> numLowest2Bit(n);

	int temp;
	int pre;
	int cur;
	for (int i = 0; i < n; i++)
	{
		temp = 0;
		for (size_t j = 0; j < 32; j++)
		{
			if (nums[i] & 1 << j)
				pre = 1 << j+1;
			else
			{
				pre = 0;
			}
			j++;
			if (nums[i] & 1 << j)
				cur = 1 << j-1;
			else
			{
				cur = 0;
			}
			if (j==1)
			{
				numLowest2Bit[i] = pre+ cur;
			}
			temp += pre + cur;
		}
		nums[i] = temp;
	}
	for (size_t i = 1; i < n; i++)
	{
		nums[i] >>= 2;
		if (numLowest2Bit[i-1]==1)
		{
			nums[i] += pow(2, 30);
		}
		else if (numLowest2Bit[i - 1] == 2)
		{
			nums[i] += pow(2, 31);
		}
		else if (numLowest2Bit[i - 1] == 3)
		{
			nums[i] += pow(2, 61);
		}
	}
	nums[0] >>= 2;
	if (numLowest2Bit[n - 1] == 1)
	{
		nums[0] += pow(2, 30);
	}
	else if (numLowest2Bit[n - 1] == 2)
	{
		nums[0] += pow(2, 31);
	}
	else if (numLowest2Bit[n - 1] == 3)
	{
		nums[0] += pow(2, 61);
	}

	for (size_t i = 0; i < n; i++)
	{
		cout << nums[i] << " ";
	}
}

int main()
{
	test1();

	return 0;
}
