#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto it: nums)
		{
			res ^= it;
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1,2,2,3,3,4,4 };
	cout << s.singleNumber(nums) << endl;

	return 0;
}
