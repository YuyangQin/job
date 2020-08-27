#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>

using namespace std;

void mergeArray(vector<int>& nums, vector<int>& temp, int left,int mid ,int right)
{
	int i = left;
	int j = mid+1;
	int index = 0;
	while (i < j&&i<=mid&&j<=right)
	{
		if (nums[i]<=nums[j])
			temp[index++] = nums[i++];
		else
			temp[index++] = nums[j++];
	}
	while (i<=mid)
	{
		temp[index++] = nums[i++];
	}
	while (j <= right)
	{
		temp[index++] = nums[j++];
	}

	for (int k = 0; k < index; k++)
	{
		nums[k + left] = temp[k];
	}
}

void mergeSort(vector<int>& nums, vector<int>& temp, int left,int right)
{
	if (left >= right)
		return;
	int mid = (left + right)/2 ;

	mergeSort(nums, temp,left, mid);
	mergeSort(nums, temp,mid+1, right);
	mergeArray(nums, temp, left, mid, right);
}



int main1()
{
	vector<int> nums = { 4,5,3,6,2,1,0,9,4 };
	vector<int> temp(nums.size(), 0);
	mergeSort(nums, temp,0, nums.size() - 1);
	for (auto it : nums)
		cout << it << " ";
	cout << endl;
	return 0;
}
