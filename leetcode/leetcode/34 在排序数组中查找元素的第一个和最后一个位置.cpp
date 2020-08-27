#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = -1;
		int right = -1;
		int begin = 0;
		int end = nums.size() - 1;

		while (begin<=end)
		{
			int mid = (begin + end) >> 1;
			if (nums[mid]==target)
			{
				if (mid==0||nums[mid-1]!=target)
				{
					left = mid;
					break;
				}
				else
				{
					end = mid - 1;
				}
			}
			else if(nums[mid] < target)
			{
				begin = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}

		if (left==-1)
		{
			return vector<int>({ -1,-1 });
		}

		int begin = left;
		int end = nums.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) >> 1;
			if (nums[mid] == target)
			{
				if (mid == nums.size() - 1 || nums[mid + 1] != target)
				{
					right = mid;
					break;
				}
				else
				{
					begin = mid + 1;
				}
			}
			else if (nums[mid] < target)
			{
				begin = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}

		return vector<int>({ left,right });
	}
};

int main()
{

	return 0;
}
