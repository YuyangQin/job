#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define X 8
#define Y 8

int visited[X][Y];
int flag;

using namespace std;

void print()
{
	for (int i = 0; i < X; i++)
	{
		for (size_t j = 0; j < Y; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void dfs(int x, int y,int& flag)
{
	if (x >= X || y >= Y || x < 0 || y < 0 || visited[x][y] != 0)
		return;
	flag += 1;
	visited[x][y] = flag;	
	if (flag == 64)
		print();
	dfs(x + 2, y + 1, flag);
	dfs(x + 2, y - 1, flag);
	dfs(x + 1, y - 2, flag);
	dfs(x -1, y -2, flag);
	dfs(x - 2, y - 1, flag);
	dfs(x - 2, y + 1, flag);
	dfs(x - 1, y + 2, flag);
	dfs(x + 1, y + 2, flag);
	return;
}

int main1()
{
	flag = 0;
	dfs(5,6,flag);
	if (flag < 64)
		cout << "find err" << endl;

	return 0;
}
