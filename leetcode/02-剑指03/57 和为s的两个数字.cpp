#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//双指针
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		int i = 0;
		int j = nums.size() - 1;
		while (i<j)
		{
			if (nums[i] + nums[j] == target)
			{
				res = { nums[i],nums[j] };
				break;
			}
			else if(nums[i]+nums[j]>target)
			{
				j--;
			}
			else
			{
				i++;
			}
		}		
		return res;
	}
};
//二分法
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		int n = nums.size();
		for (size_t i = 0; i < n; i++)
		{
			int tmp = target- nums[i];
			int begin = i + 1;
			int end = n - 1;
			while (begin<=end)
			{
				int mid = (begin + end) >> 1;
				if (nums[mid]==tmp)
				{
					res = { tmp,target - tmp };
					break;
				}
				else if(nums[mid]>tmp)
				{
					end = mid - 1;
				}
				else
				{
					begin = mid + 1;
				}
			}
		}
		return res;
	}
};

int main()
{

	return 0;
}
