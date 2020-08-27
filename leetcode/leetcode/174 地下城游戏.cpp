#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size();
		if (m==0)
		{
			return 0;
		}
		int n = dungeon[0].size();
		dungeon[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
		for (int i = n-2; i >= 0; i--)
		{
			dungeon[m-1][i]= max(1, dungeon[m - 1][i+1] - dungeon[m - 1][i]);
		}
		for (int i = m - 2; i >= 0; i--)
		{
			dungeon[i][n - 1] = max(1, dungeon[i + 1][n - 1] - dungeon[i][n - 1]);
			for (int j = n-2; j >= 0; j--)
			{
				int minHp = min(dungeon[i + 1][j], dungeon[i][j + 1]);
				dungeon[i][j] = max(1, minHp - dungeon[i][j]);
			}
		}
		return dungeon[0][0];
	}
};

int main()
{
	vector<vector<int>> dungeon = { {-2, -3, 3}, {-5, -10, 1}, {10, 30, -5} };
	Solution s;
	cout << s.calculateMinimumHP(dungeon) << endl;

	return 0;
}
