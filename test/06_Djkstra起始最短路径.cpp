#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<int> Djkstra(vector<vector<int>>& matrix, int index)
{
	vector<int> pre;
	vector<int> dis(matrix.size());
	vector<bool> visited;
	int min, n;

	pre.assign(matrix.size(), 0);
	visited.assign(matrix.size(), false);
	visited[index] = true;
	for (size_t i = 0; i < matrix.size(); i++)
	{ 
		dis[i] = matrix[index][i];
		if (dis[i]!=100)
		{
			pre[i] = index;
		}
	}
	pre[index] = index;

	for (size_t i = 1; i < matrix.size(); i++)
	{
		min = 100;
		//找到未访问节点中路径最短的节点作为新的起始节点
		for (size_t j = 0; j < matrix.size(); j++)
		{
			if (!visited[j] && dis[j] < min)
			{
				n = j;
				min = dis[j];
			}
		}
		visited[n] = true;
		//更新距离数组
		for (size_t k = 0; k < matrix.size(); k++)
		{
			if (!visited[k] && (dis[k] > (dis[n] + matrix[n][k])))
			{
				dis[k] = dis[n] + matrix[n][k];
				pre[k] = n;
			}
		}
	}

	return dis;
}

int main6()
{
	int N = 100;
	vector<vector<int>> matrix = {
		{ N, 5,7,N,N, N, 2 },
		{ 5,  N, N,9,N,  N, 3 },
		{ 7, N,  N,  N,  8,  N,N },
		{ N,9,  N,  N,  N,4,N },
		{ N,N,  8,  N,  N,  5,  4 },
		{ N,  N,  N,4,  5,  N,  6 },
		{ 2,3,N,N,  4,  6,  N } };

	vector<int> res = Djkstra(matrix, 6);
	for (auto it : res)
		cout << it << " ";
	cout << endl;

	return 0;
} 