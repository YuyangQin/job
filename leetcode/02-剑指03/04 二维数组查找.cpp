#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (!matrix.empty())
		{
			int m = 0;
			int n = matrix[0].size() - 1;
			while ((m < matrix.size()) && (n >= 0))
			{
				if (matrix[m][n] < target)
				{
					m++;
				}
				else if(matrix[m][n] > target)
				{
					n--;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
};

void main()
{
	vector<int> v1 = { 1, 4, 7, 11, 15 };
	vector<int> v2 = { 2,   5,  8, 12, 19 };
	vector<int> v3= { 3,   6,  5, 16, 22 };
	vector<int> v4 = { 10, 13, 14, 17, 24 };

	vector<vector<int>> matrix;
	vector<vector<int>> matrix1;
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);

	Solution s;

	bool b = s.findNumberIn2DArray(matrix, 100);
	cout << b << endl;

}