#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//Œª‘ÀÀ„
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		int n = 1 << nums.size();
		for (size_t i = 0; i < n; i++)
		{
			vector<int> path;
			for (int j = 0; j < nums.size(); j++)
			{
				if (i&(1<<j))
				{
					path.push_back(nums[j]);
				}
			}
			res.push_back(path);
		}
		return res;
	}
};

//ªÿÀ›
class Solution1 {
public:
	void generate(const vector<int>& nums, vector<int>& path, int step, vector<vector<int>>& res)
	{
		if (step>=nums.size())
		{
			return;
		}
		path.push_back(nums[step]);
		res.push_back(path);
		generate(nums, path, step+1, res);
		path.pop_back();
		generate(nums, path, step+1, res);
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> path;
		res.push_back(path);
		generate(nums, path, 0, res);
		return res;
	}
};


int main78()
{
	vector<int> nums = { 1,2,3 };
	Solution s;
	vector<vector<int>> res = s.subsets(nums);

	for (size_t i = 0; i < res.size(); i++)
	{
		for (auto it : res[i])
			cout << it << " ";
		cout << endl;
	}

	return 0;
}
