#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		int n = nums.size();
		if (n==1)
		{
			return nums[0];
		}
		int preTwo= nums[0];
		int preOne = max(nums[0], nums[1]);
		int res;
		for (size_t i = 2; i < n; i++)
		{
			res = max(preOne, preTwo + nums[i]);
			preTwo = preOne;
			preOne = res;
		}
		return res;
	}
};

int main()
{

	return 0;
}
