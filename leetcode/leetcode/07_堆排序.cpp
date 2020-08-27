#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>

using namespace std;

void heapT2B(vector<int>& nums, int index, int len)
{
	int max = nums[index];
	for (int i = 2*index+1; i < len; i++)
	{
		int maxIndex = i;
		if ((i+1)<len&&nums[i]<=nums[i+1])
			maxIndex = i + 1;
		if (nums[maxIndex] > max)
		{
			swap(nums[index], nums[maxIndex]);
			index = maxIndex;
		}
		else
			break;
	}
}

void bulidHeap(vector<int>& nums,int len)
{
	for (int i = (len - 1) >> 1; i >= 0; i--)
		heapT2B(nums, i, len);
}

void heapSort(vector<int>& nums)
{
	bulidHeap(nums,nums.size());
	for (int i = nums.size()-1; i > 0; i--)
	{
		swap(nums[0], nums[i]);
		heapT2B(nums, 0, i);
	}
}

void main6()
{
	vector<int> nums = { 4,5,3,6,2,1,0,9,4 };
	heapSort(nums);
	for (auto it : nums)
		cout << it << " ";
	cout << endl;	
}
