#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

//Œª‘ÀÀ„
class Solution {
public:
	bool makesquare(vector<int>& nums) {
		if (nums.size() < 4)
			return false;
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 4 != 0)
			return false;
		int edgeSize = sum / 4;
		sort(nums.rbegin(), nums.rend());
		int n = nums.size();
		vector<int> edge_ok;
		vector<int> two_edge_ok;
		int edgeSum = 0;
		for (size_t i = 0; i < (1<<n); i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ((1<<j)&i)
				{
					edgeSum += nums[j];
				}
			}
			if (edgeSum ==edgeSize)
			{
				edge_ok.push_back(i);
			}
			edgeSum = 0;
		}
		for (size_t i = 0; i < edge_ok.size(); i++)
		{
			for (size_t j = i+1; j < edge_ok.size(); j++)
			{
				if ((edge_ok[i]&edge_ok[j])==0)
				{
					two_edge_ok.push_back(edge_ok[i] | edge_ok[j]);
				}
			}
		}
		for (size_t i = 0; i < two_edge_ok.size(); i++)
		{
			for (size_t j = i+1; j < two_edge_ok.size(); j++)
			{
				if ((two_edge_ok[i] & two_edge_ok[j]) == 0)
				{
					return true;
				}
			}
		}
		return false;
	}	
};

//DFS
class Solution1 {
public:
	bool makesquare(vector<int>& nums) {
		if (nums.size() < 4)
			return false;
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 4 != 0)
			return false;
		int edgeSize = sum / 4;
		sort(nums.rbegin(), nums.rend());
		int edges[4] = { 0 };
		
		return dfs(0, edgeSize, nums, edges);
	}
	bool dfs(int index, int& edgeSize, vector<int>& nums, int edges[4])
	{
		if (index==nums.size())
		{
			return edges[0] == edgeSize&&edges[1] == edgeSize&&edges[2] == edgeSize&&edges[3] == edgeSize;
		}
		for (size_t j = 0; j < 4; j++)
		{
			if (nums[index] + edges[j] <= edgeSize)
			{
				edges[j] += nums[index];
				if (dfs(index + 1, edgeSize, nums, edges))
				{
					return true;
				}
				edges[j] -= nums[index];
			}			
		}
		return false;
	}
};

int main()
{
	vector<int> v = { 5,5,5,5,4,4,4,4,3,3,3,3 };
	Solution s;
	cout << s.makesquare(v) << endl;

	return 0;
}
