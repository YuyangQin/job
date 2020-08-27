#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int pre = 0;
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i]!=nums[pre])
			{
				swap(nums[i], nums[pre+1]);
				pre++;
			}
		}
		return pre + 1;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1,1,2,2,3,3, };
	cout << s.removeDuplicates(v) << endl;
	for (auto it : v)
		cout << it << " ";

	return 0;
}
