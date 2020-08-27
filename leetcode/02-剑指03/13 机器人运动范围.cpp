#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int digitSum(int i)
	{
		int sum = 0;
		while (i>9)
		{		
			sum += (i / 10);
			i = i % 10;
		}
		return sum + i;
	}
	int movingCount(int m, int n, int k) {
		if (m==0&&n==0)
		{
			return 1;
		}
		vector<vector<bool>> visited(m, vector<bool>(n, false));

		 dst(0, 0, k, visited);

		 return length;
	}
	void dst(int i, int j, int k, vector<vector<bool>>& visited)
	{
		if (i < 0 || i >= visited.size() || j < 0 || j >= visited[0].size() || visited[i][j] == true||(digitSum(i)+digitSum(j))>k)
 			return;

		length += 1;
		visited[i][j] = true;

		dst(i + 1, j, k, visited);

		dst(i - 1, j, k, visited);

		dst(i, j + 1, k, visited);

		dst(i, j - 1, k, visited);
	}
	int length = 0;
};

void main()
{
	Solution s;
	
	cout << s.movingCount(3, 1, 0) << endl;
}