#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int rightmost = 0;
		int i=0;
		while (i<=rightmost&&i<n)
		{
			rightmost = max(rightmost, i + nums[i]);
			i++;
		}
		if (i == n)
			return true;
		return false;
	}
	bool canJump2(vector<int>& nums) {
		int n = nums.size();
		vector<int> index;
		for (size_t i = 0; i < n; i++)
		{
			index.push_back(nums[i]+i);
		}
		int max = index[0];
		int jump=0;
		while (jump<n&&jump<=max)
		{
			if (index[jump]>max)
				max = index[jump];
			jump++;
		}
		if (jump == n)
			return true;
		return false;
	}
};

int main()
{
	vector<int> nums({ 2,3,1,1,4 });
	Solution sol;
	cout << sol.jump(nums) << endl;

	return 0;
}
