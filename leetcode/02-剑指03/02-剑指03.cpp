#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {

		sort(nums.begin(), nums.end());
		int i = 0;
		while (nums[i]!=nums[i+1])
		{
			i++;
		}
		return nums[i];
	}
};

void main()
{
	vector<int> a = { 5,7,5,6,7,3 };
	Solution s;
	cout << s.findRepeatNumber(a) << endl;
}