#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty())
			return res;
		int m = matrix.size();
		int n = matrix[0].size();
		ret = m*n;
		//vector<vector<bool>> visited(m, vector<bool>(n, false));
		print(0, m, n, matrix, res);

		return res;
	}
	int sum = 0;
	int ret;
	void print(int start,int m, int n, vector<vector<int>>& matrix,vector<int>& res)
	{
		if ( start>m || start>n)
			return;
		for (int i = start; i < n&&sum < ret; i++)
		{
			res.push_back(matrix[start][i]);
			sum++;
		}
			
		for (int j = start + 1; j < m&&sum < ret; j++)
		{
			res.push_back(matrix[j][n - 1]);
			sum++;
		}
			
		for (int k = n-2; k >= start&&sum < ret; k--)
		{
			res.push_back(matrix[m-1][k]);
			sum++;
		}
		for (int l = m-2; l > start&&sum < ret; l--)
		{
			res.push_back(matrix[l][start]);
			sum++;
		}
		print(start + 1, m - 1, n - 1, matrix, res);
		return;
	}

//´íÎó´ð°¸	
	//void print(int x,int y, vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<int>& res)
	//{
	//	if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || visited[x][y] == true)
	//		return;
	//	visited[x][y] = true;
	//	res.push_back(matrix[x][y]);
	//	print(x, y + 1, matrix, visited, res);
	//	print(x + 1, y, matrix, visited, res);
	//	print(x, y - 1, matrix, visited, res);
	//	print(x - 1, y, matrix, visited, res);
	//}
};


void main()
{
	Solution s;
	vector<vector<int>> matrix;
	vector<int> v1 = { 1,2,3 };
	vector<int> v2 = { 4,5,6 };
	vector<int> v3 = { 7,8,9 };
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);

}