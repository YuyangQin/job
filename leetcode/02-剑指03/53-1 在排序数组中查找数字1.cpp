#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int pos;
	int search(vector<int>& nums, int target) {
		binary_search(nums, 0, nums.size() - 1, target);
		if (pos==-1)
		{
			return 0;
		}
		int i = pos+1;
		int j = pos-1;
		int count = 1;
		while (i<nums.size()&&nums[i]==target)
		{
			count++;
			i++;
		}
		while (j>=0 && nums[j] == target)
		{
			count++;
			j--;
		}
		return count;
	}
	void binary_search(vector<int>& nums, int left, int right,int& target)
	{
		if (left > right)
		{
			pos = -1;
			return;
		}
		int mid = (left + right) >> 1;
		if (nums[mid]==target)
		{
			pos = mid;
			return;
		}
		else if(nums[mid]<target)
		{
			binary_search(nums, mid + 1, right,target);
		}
		else
		{
			binary_search(nums, left, mid-1,target);
		}
	}
};

int main()
{

	return 0;
}
