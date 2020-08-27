#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> exchange(vector<int>& nums)
	{
		vector<int> odd;
		vector<int> even;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] % 2 == 0)
				even.push_back(nums[i]);
			else
				odd.push_back(nums[i]);
		}
		odd.insert(odd.end(), even.begin(), even.end());
		return odd;
	}
	vector<int> exchange2(vector<int>& nums)
	{
		int small = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] % 2 == 1)
			{
				small++;
				if (i != small)
					swap(nums[i], nums[small]);
			}		
		}
		return nums;
	}
	
	vector<int> exchange1(vector<int>& nums) {
		int odd = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] % 2 == 1)
				odd++;
		}
		vector<int> res = nums;
		int j = odd;
		int k = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] % 2 == 1)
				res[k++] = nums[i];
			else
				res[j++] = nums[i];
		}
		return res;
	}
};

void main()
{
	Solution s;
	vector<int> nums = { 1,2,3,4 ,9};
	vector<int> v = s.exchange(nums);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}