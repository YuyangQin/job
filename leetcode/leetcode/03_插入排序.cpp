#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int>& nums)
{
	int i, j;
	int temp;
	for (i = 1; i < nums.size(); i++)
	{
		temp = nums[i];
		for (j = i; j > 0 &&(nums[j-1]>temp); j--)
		{
			nums[j] = nums[j - 1];
		}
		if (i != j)
			nums[j] = temp;
	}
}

void main02()
{
	vector<int> nums = { 5,3,6,2,1,0,9 };
	insertSort(nums);
	for (auto it : nums)
		cout << it << " ";
	cout << endl;
}
