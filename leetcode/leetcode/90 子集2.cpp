#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		set<vector<int>> uset;
		vector<int> path;
		//res.push_back(path);
		sort(nums.begin(), nums.end());
		dfs(nums, path, 0, res);
		//dfs(nums, path, 0, res, uset);

		return res;
	}
	void dfs(const vector<int>& nums, vector<int>& path, int step, vector<vector<int>>& res)
	{
		res.push_back(path);
		for (size_t i = step; i < nums.size(); i++)
		{
			if (i != step&&nums[i] == nums[i - 1])
				continue;
			path.push_back(nums[i]);
			dfs(nums, path, i + 1, res);
			path.pop_back();
		}
	}

	void dfs2(vector<int>& nums, vector<int>& path, int i, vector<vector<int>>& res, set<vector<int>>& uset)
	{
		if (i >= nums.size())
		{
			return;
		}
		path.push_back(nums[i]);
		if (uset.find(path) == uset.end())
		{
			uset.insert(path);
			res.push_back(path);
		}		
		dfs2(nums, path, i + 1, res, uset);
		path.pop_back();
		dfs2(nums, path, i + 1, res, uset);
	}
};

int main()
{
	vector<int> nums = { 1,2,2 };
	Solution s;
	vector<vector<int>> res = s.subsetsWithDup(nums);


	return 0;
}
