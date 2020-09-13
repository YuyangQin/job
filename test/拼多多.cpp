#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


int count1=0;
void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited)
{
	static const int dx[] = { 0,1,0,-1 };
	static const int dy[] = { 1,0,-1,0 };
	visited[x][y] = true;
	count1++;
	for (size_t i = 0; i < 4; i++)
	{
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (newx<0 || newy<0 || newx >= grid.size() || newy >= grid[0].size() || grid[newx][newy] ==0 || visited[newx][newy] == true)
		{
			continue;
		}
		dfs(newx, newy, grid, visited);
	}
}
void test2()
{
	int N;
	int M;
	cin >> N >> M;
	vector<vector<int>> grid(N,vector<int>(M));
	for (size_t i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
		}
	}
	int res = 0;
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	for (size_t i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == '1'&&visited[i][j] == false)
			{
				count1 = 0;
				dfs(i, j, grid, visited);
				res++;
				cout << count1 << endl;
			}
		}
	}
	
}

void test3()
{
	int n=10, m=2;
	//cin >> n >> m;
	unordered_set<int> set;
	int tmp;
	for (int i = 0; i < m; i++) {
		//cin >> tmp;
		set.insert(i+2);
	}
	vector<bool> st(n+1);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (!st[i]) {
			for (auto k : set) {
				if (i % k == 0) {
					for (int j = 1; j * k <= n; j++) {
						st[j*k] = true;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (st[i]) res++;
	}
	cout << res;
}

int main()
{
	test3();

	return 0;
}
