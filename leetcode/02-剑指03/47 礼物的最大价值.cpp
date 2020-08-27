#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		for (size_t i = 1; i < m; i++)
		{
			grid[i][0] += grid[i - 1][0];
		}
		for (size_t j = 1; j < n; j++)
		{
			grid[0][j] += grid[0][j - 1];
		}
		
		for (size_t i = 1; i < m; i++)
		{
			for (size_t j = 1; j < n; j++)
			{
				
				grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
			}
		}
		return grid[m - 1][n - 1];
	}
};

int main()
{
	vector<int> v1({ 1,2,5 });
	vector<int> v2({ 3,2,1 });
	vector<vector<int>> grid;
	grid.push_back(v1);
	grid.push_back(v2);

	Solution s;
	cout << s.maxValue(grid) << endl;

	return 0;
}
