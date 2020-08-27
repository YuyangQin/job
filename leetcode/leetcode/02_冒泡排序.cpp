#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& nums)
{
	for (int i = 0; i < nums.size()-1; i++)
	{
		for (int j = nums.size()-1; j >i ; j--)
		{
			if (nums[j-1] > nums[j])
				swap(nums[j-1], nums[j]);
		}
	}
}

void main1()
{
	vector<int> nums = { 5,3,6,2,1,0,9 };
	bubbleSort(nums);
	for (auto it : nums)
		cout << it << " ";
	cout << endl;
}
