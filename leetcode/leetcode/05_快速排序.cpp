#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>

using namespace std;

void fastSort(vector<int>& nums, int begin, int end)
{
	if (begin >= end)
		return;
	int l = begin;
	int r = end;
	
	int temp=nums[begin];
	
	while (l < r)
	{
		while (l<r&&nums[r]>=temp) r--;
		while (l<r&&nums[l]<temp) l++;
		if (l < r)
			swap(nums[l], nums[r]);
	}
	nums[l] = temp;
	fastSort(nums, begin, r-1);
	fastSort(nums, r + 1, end);
}
void quickSort(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r;
		// 拿出第一个元素, 保存到x中,第一个位置成为一个坑
		int x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x)	j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i] < x)	i++;
			if (i < j)
				s[j--] = s[i];
		}
		//此时 i=j,将保存在x中的数填入坑中
		s[i] = x;
		quickSort(s, l, i - 1); // 递归调用 
		quickSort(s, i + 1, r);
	}
}



int main()
{
	vector<int> nums1 = { 4,5,3,6,2,1,0,9,4 };
	fastSort(nums1, 0, 8);
	for (auto it : nums1)
		cout << it << " ";
	cout << endl;
	int nums[] = { 4,5,3,6,2,1,0,9,4 };
	quickSort(nums,0,8);
	for (auto it : nums)
		cout << it << " ";
	cout << endl;
	return 0;
}
