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

vector<Edges> getEdges(vector<vector<int>>& matrix, int count)
{
	vector<Edges> myEdge(count);
	int n = matrix.size();
	int k = 0;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			if (matrix[i][j] != 100)
			{
				myEdge[k].start = i;
				myEdge[k].end = j;
				myEdge[k].weight = matrix[i][j];
				k++;
			}
		}
	}

	return myEdge;
}

void sortEdge(vector<Edges>& myEdge)
{
	int n = myEdge.size();
	Edges tmp;
	for (size_t i = 0; i < n - 1; i++)
	{
		for (size_t j = 0; j < n - i - 1; j++)
		{
			if (myEdge[j].weight>myEdge[j+1].weight)
			{
				tmp = myEdge[j];
				myEdge[j] = myEdge[j+1];
				myEdge[j+1] = tmp;
			}
		}
	}
}

int getEnds(int i, vector<int>& ends)
{
	while (ends[i]!=0)
	{
		i = ends[i];
	}
	return i;
}

vector<Edges> Kruskal(vector<Edges>& myEdge, vector<int>& ends)
{
	vector<Edges> res;
	int n = myEdge.size();
	for (size_t i = 0; i < n; i++)
	{
		int p1 = myEdge[i].start;
		int p2 = myEdge[i].end;
		int m = getEnds(p1, ends);
		int n = getEnds(p2, ends);
		if (m!=n)
		{
			ends[m] = n;
			res.push_back(myEdge[i]);
		}
	}

	return res;
}

int main5()
{
	vector<vector<int>> matrix = {
		{ 0, 12,100,100,100, 16, 14 },
		{ 12,  0, 10,100,100,  7, 100 },
		{ 100, 10,  0,  3,  5,  6,100 },
		{ 100,100,  3,  0,  4,100,100 },
		{ 100,100,  5,  4,  0,  2,  8 },
		{ 16,  7,  6,100,  2,  0,  9 },
		{ 14,100,100,100,  8,  9,  0 } };
	int count = 0;
	int n = matrix.size();
	vector<int> ends(7,0);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			if (matrix[i][j] != 100)
				count++;
		}
	}
	vector<Edges> myEdge = getEdges(matrix, count);

	sortEdge(myEdge);

	vector<Edges> res = Kruskal(myEdge, ends);



	return 0;
}