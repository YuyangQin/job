#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		if (n==0)
		{
			return 0;
		}
		for (int i = n-2; i >= 0; i--)
		{
			for (size_t j = 0; j <= i; j++)
			{
				triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return triangle[0][0];
	}
};

int main()
{
	vector<vector<int>> triangle = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3} };
	Solution s;
	cout << s.minimumTotal(triangle) << endl;

	return 0;
}
