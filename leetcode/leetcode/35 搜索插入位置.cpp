#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int i = 0;
		int j = nums.size() - 1;
		while (i <= j)
		{
			int mid = (i + j) >> 1;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
			{
				if (mid == nums.size() - 1 || nums[i + 1]>target)
					return mid + 1;
				i = mid + 1;
			}
			else
			{
				if (mid == 0 || nums[i - 1]<target)
					return mid;
				j = mid - 1;
			}
		}
		return i;
	}
};

int main()
{
	vector<int> v({ 1,3,5,6 });
	Solution s;
	cout << s.searchInsert(v, 0);

	return 0;
}
