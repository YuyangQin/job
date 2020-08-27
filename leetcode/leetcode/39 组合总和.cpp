#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> path;
		set<vector<int>> uset;
		sort(candidates.begin(), candidates.end());
		generate(0,0,res, path, candidates, target,uset);
		return res;
	}
	void generate(int i, int sum, vector<vector<int>>& res, vector<int>& path, vector<int>& candidates, int& target, set<vector<int>>& uset)
	{
		if (i >= candidates.size() || sum > target)
			return;
		path.push_back(candidates[i]);
		sum += candidates[i];
		generate(i + 1, sum, res, path, candidates, target,uset);
		if (sum == target&&uset.find(path)==uset.end())
		{
			res.push_back(path);
			uset.insert(path);
		}		
		path.pop_back();
		sum -= candidates[i];
		generate(i + 1, sum, res, path, candidates, target,uset);
	}
};

int main()
{
	Solution s;
	vector<int> v({ 3,4,7 });
	vector<vector<int>> ret = s.combinationSum(v, 7);

	return 0;
}
