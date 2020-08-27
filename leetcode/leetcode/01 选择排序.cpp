#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>

using namespace std;

void selectSort(vector<int>& nums)
{
	int index;
	int i=0, j=0;
	for (i = 0; i < nums.size()-1; ++i)
	{
		index = i;
		for (j = i+1; j < nums.size(); ++j)
		{
			if (nums[index]>nums[j])
			{
				index = j;
			}
		}
		if (index != i)
			swap(nums[i], nums[index]);
	}
}

void main1()
{
	vector<int> nums = { 5,3,6,2,1,0,9 };
	selectSort(nums);
	for (auto it : nums)
		cout << it << " ";
	cout << endl;
}
