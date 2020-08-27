#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution2 {

private:
	vector<int> candidates;
	vector<vector<int>> res;
	vector<int> path;
public:
	void DFS(int start, int target) {
		if (target == 0) {
			res.push_back(path);
			return;
		}

		for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
			cout << candidates[i] << " ";
			if (i > start && candidates[i] == candidates[i - 1])
				continue;
			
			path.push_back(candidates[i]);
			// 元素不可重复利用，使用下一个即i+1
			DFS(i + 1, target - candidates[i]);
			path.pop_back();
		}
		cout << endl;
	}

	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		DFS(0, target);
		return res;
	}
};

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> path;
		set<vector<int>> uset;
		sort(candidates.begin(), candidates.end());
		//dfs(0, 0, res, path, candidates, target, uset);
		DFS(0,0, res, path, candidates, target, uset);
		return res;
	}
	void DFS(int start, int sum, vector<vector<int>>& res, vector<int>& path, vector<int>& candidates, int target, set<vector<int>>& uset) {
		if (target == sum) {
			res.push_back(path);
			return;
		}

		for (int i = start; i < candidates.size() && sum<= target; i++) {
			if (i > start && candidates[i] == candidates[i - 1])
				continue;
			path.push_back(candidates[i]);
			sum += candidates[i];
			// 元素不可重复利用，使用下一个即i+1
			DFS(i + 1,sum, res, path, candidates, target, uset);
			path.pop_back();
			sum -= candidates[i];
		}
	}
	void dfs(int step, int sum, vector<vector<int>>& res, vector<int>& path, vector<int>& candidates, int& target, set<vector<int>>& uset)
	{
		if (sum == target)
		{
			res.push_back(path);
			return;
		}
		for (size_t i = step; i < candidates.size()&&sum<=target; i++)
		{
			if (i != step&&candidates[i] == candidates[i - 1])
				continue;
			path.push_back(candidates[i]);
			sum += candidates[i];
			dfs(i + 1, sum, res, path, candidates, target, uset);
			path.pop_back();
			sum -= candidates[i];
		}
	}

	void generate(int i, int sum, vector<vector<int>>& res, vector<int>& path, vector<int>& candidates, int& target, set<vector<int>>& uset)
	{
		if (i >= candidates.size() || sum > target)
			return;
		path.push_back(candidates[i]);
		sum += candidates[i];
		generate(i + 1, sum, res, path, candidates, target, uset);
		if (sum == target&&uset.find(path) == uset.end())
		{
			res.push_back(path);
			uset.insert(path);
		}
		path.pop_back();
		sum -= candidates[i];
		generate(i + 1, sum, res, path, candidates, target, uset);
	}
};

int main40()
{
	Solution2 s;
	vector<int> v({ 10,1,2,7,6,1,5 });
	vector<vector<int>> ret = s.combinationSum2(v, 7);

	return 0;
}
