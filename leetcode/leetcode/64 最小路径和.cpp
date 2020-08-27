#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m==0)
		{
			return 0;
		}
		int n = grid[0].size();
		for (size_t i = 1; i < n; i++)
		{
			grid[0][i] = grid[0][i - 1] + grid[0][i];
		}
		for (size_t i = 1; i < m; i++)
		{
			grid[i][0] = grid[i][0] + grid[i - 1][0];
			for (int j = 1; j < n; j++)
			{
				grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
			}
		}
		return grid[m - 1][n - 1];
	}
};

int main()
{

	return 0;
}
