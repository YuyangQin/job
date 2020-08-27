#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int i = 0;
		int j = nums.size() - 1;
		int ret;
		while (i <= j)
		{
			int mid = (i + j) >> 1;
			if (nums[mid] == mid)
				i = mid + 1;
			else
				j = mid - 1;
		}
		return i;
	}
};

int main()
{
	vector<int> nums = {0, 1,2 };
	Solution s;
	cout << s.missingNumber(nums) << endl;

	return 0;
}
