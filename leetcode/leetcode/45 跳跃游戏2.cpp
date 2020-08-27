#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		if (n < 2)
			return 0;
		int max_index = nums[0];
		int cur = nums[0];
		int step = 1;
		for (size_t i = 0; i < n; i++)
		{
			if (cur<i)
			{
				cur = max_index;
				step++;
			}
			if (nums[i]+i>max_index)
			{
				max_index = nums[i] + i;
			}
		}
		return step;
	}
};

int main1()
{

	return 0;
}
