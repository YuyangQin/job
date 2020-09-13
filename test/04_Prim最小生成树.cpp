#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

typedef struct EDGES
{
	int start;
	int end;
	int weight;
}Edges;

vector<Edges> Prim(vector<vector<int>>& matrix, int nth)
{
	vector<Edges> res;
	vector<bool> visited(7, false);
	visited[nth] = true;
	int n = matrix.size();

	Edges tmp;
	int minWeight = 100;
	for (size_t k = 0; k < n-1; k++)
	{
		int h1;
		int h2;
		for (size_t i = 0; i < n; i++)
		{
			if (visited[i])
			{
				for (size_t j = 0; j < n; j++)
				{
					if (!visited[j] && matrix[i][j] != 0 && matrix[i][j]<minWeight)
					{
						minWeight = matrix[i][j];
						h1 = i;
						h2 = j;
					}
				}
			}
		}
		tmp.start = h1;
		tmp.end = h2;
		tmp.weight = matrix[h1][h2];
		visited[h2] = true;
		res.push_back(tmp);
		minWeight = 100;
	}	

	return res;
}

int main4()
{
	vector<vector<int>> matrix = {
		{ 0, 12,100,100,100, 16, 14 },
		{ 12,  0, 10,100,100,  7, 100 },
		{ 100, 10,  0,  3,  5,  6,100 },
		{ 100,100,  3,  0,  4,100,100 },
		{ 100,100,  5,  4,  0,  2,  8 },
		{ 16,  7,  6,100,  2,  0,  9 },
		{ 14,100,100,100,  8,  9,  0 } }; 
	vector<Edges> res = Prim(matrix, 4);
	for (auto it : res)
	{
		cout << it.start << " -> " << it.end << " : " << it.weight << endl;
	}

	return 0;
}
