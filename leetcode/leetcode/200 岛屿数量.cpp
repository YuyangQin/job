#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:	
	int numIslands(vector<vector<char>>& grid) {
		int res = 0;
		int m = grid.size();
		if (m<=0)
		{
			return 0;
		}
		int n = grid[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (size_t i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == '1'&&visited[i][j] == false)
				{
					dfs(i, j, grid, visited);
					res++;
				}
			}
		}
		return res;
	}
	void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited)
	{
		static const int dx[] = { 0,1,0,-1 };
		static const int dy[] = { 1,0,-1,0 };
		visited[x][y] = true;

		for (size_t i = 0; i < 4; i++)
		{
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (newx<0||newy<0||newx >= grid.size()|| newy >= grid[0].size()||grid[newx][newy]=='0'|| visited[newx][newy] == true)
			{
				continue;
			}
			dfs(newx, newy, grid, visited);
		}
	}
};

int main()
{
	vector<vector<char>> grid = { { '1', '1', '1' },{ '0', '1', '0' },{  '1', '1', '1' } };
	Solution s;
	cout << s.numIslands(grid) << endl;
	
	return 0;
}
