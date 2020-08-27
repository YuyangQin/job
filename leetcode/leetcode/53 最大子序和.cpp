#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		else if (n==1)
		{
			return nums[0];
		}
		int max = nums[0];
		for (size_t i = 1; i < n; i++)
		{
			if (nums[i-1]>0)
			{
				nums[i] = nums[i] + nums[i - 1];
			}
			if (max<nums[i])
			{
				max = nums[i];
			}
		}
		return max;
	}
};

int main()
{

	return 0;
}
