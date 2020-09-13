#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Floyd(vector<vector<int>>& matrix)
{
	int length = matrix.size();
	vector<vector<int>> dis(matrix);
	vector<vector<int>> pre(length);
	
	for (size_t i = 0; i < length; i++)
	{
		pre[i].assign(length, i);
	}

	//中间点
	for (size_t i = 0; i < length; i++)
	{
		//起始点
		for (size_t j = 0; j < length; j++)
		{
			//终点
			for (size_t k = 0; k < length; k++)
			{
				if (dis[j][i]+dis[i][k]<dis[j][k])
				{
					dis[j][k] = dis[j][i] + dis[i][k];
					pre[j][k] = pre[k][i];
				}
			}
		}
	}

	return dis;
}

int main7()
{
	int N = 100;
	vector<vector<int>> matrix = {
		{ 0, 5,7,N,N, N, 2 },
		{ 5,  0, N,9,N,  N, 3 },
		{ 7, N,  0,  N,  8,  N,N },
		{ N,9,  N,  0,  N,4,N },
		{ N,N,  8,  N,  0,  5,  4 },
		{ N,  N,  N,4,  5,  0,  6 },
		{ 2,3,N,N,  4,  6,  0 } };

	vector<vector<int>> dis = Floyd(matrix);

	for (size_t i = 0; i < dis.size(); i++)
	{
		for (auto it : dis[i])
			printf("%-3d", it);
		cout << endl;
	}

	return 0;
}
