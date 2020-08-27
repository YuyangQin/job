#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<int>> visited(n, vector<int>(n, 0));
		vector<vector<string>> res;
		vector<string> tmp(n, string(n,'.'));
		dfs(0, n, visited, res, tmp);
		return res;
	}
	void dfs(int i, int n, vector<vector<int>>& visited, vector<vector<string>>& res, vector<string>& tmp)
	{
		if (i==n)
		{
			res.push_back(tmp);
			return;
		}
		for (size_t j = 0; j < n; j++)
		{
			if (visited[i][j]==0)
			{
				vector<vector<int>> tmpVisited = visited;
				put_queen(i, j, visited);
				tmp[i][j] = 'Q';
				dfs(i + 1, n, visited, res, tmp);
				visited = tmpVisited;
				tmp[i][j] = '.';
			}
		}
	}
	void put_queen(int x, int y, vector<vector<int>>& visited)
	{
		static const int dx[] = { -1,1,0,0,-1,-1,1,1 };
		static const int dy[] = { 0,0,-1,1,-1,1,-1,1 };
		for (size_t i = 0; i < visited.size(); i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int new_x = x + i*dx[j];
				int new_y = y + i*dy[j];
				if (new_x>=0&&new_x<visited.size()&&new_y>=0&&new_y<visited.size())
				{
					visited[new_x][new_y] = 1;
				}
			}
		}
	}
};

class Solution2 {
public:
	int count = 0;
	void recur(vector<int>& pos, int n, int k)
	{
		if (k == n)
		{
			count++;
			return;
		}
		for (size_t i = 0; i < n; i++)
		{
			pos[k] = i;
			if (check(pos, k))
				recur(pos, n, k + 1);
		}
	}

	bool check(vector<int>& pos, int k)
	{
		for (size_t i = 0; i < k; i++)
		{
			if (pos[i] == pos[k] || abs(pos[i] - pos[k]) == k - i)
				return false;
		}
		return true;
	}

	int totalNQueens(int n) {
		vector<int> pos(n, -1);
		recur(pos, n, 0);
		return count;
	}
};

class Solution1 {
public:
	vector<vector<string>> res;

	void recur(vector<int>& pos, int n, int k)
	{
		if (k == n)
		{
			vector<string> tmpV;
			for (int i = 0; i < n; i++)
			{
				string tmp(n, '.');
				tmp[pos[i]] = 'Q';
				tmpV.push_back(tmp);
			}
			res.push_back(tmpV);
			return;
		}
		for (size_t i = 0; i < n; i++)
		{
			pos[k] = i;
			if (check(pos, k))
				recur(pos, n, k + 1);
		}
	}

	bool check(vector<int>& pos, int k)
	{
		for (size_t i = 0; i < k; i++)
		{
			if (pos[i] == pos[k] || abs(pos[i] - pos[k]) == k - i)
				return false;
		}
		return true;
	}

	vector<vector<string>> solveNQueens(int n) {
		vector<int> pos(n, -1);
		recur(pos, n, 0);
		return res;
	}
};


int main()
{
	Solution s;
	int n = 4;	
	vector<vector<string>> res= s.solveNQueens(n);
	for (size_t i = 0; i < n; i++)
	{
		for (auto it : res[i])
			cout << it << endl;
	}

	return 0;
}
