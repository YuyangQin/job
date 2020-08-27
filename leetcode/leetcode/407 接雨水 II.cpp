#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct MyStruct
{
	int x;
	int y;
	int height;
	MyStruct(int x, int y, int height) :x(x), y(y), height(height) {}
};
struct cmp
{
	bool operator()(const MyStruct&a, const MyStruct& b)
	{
		return a.height > b.height;
	}
};

class Solution {
public:
	
	int trapRainWater(vector<vector<int>>& heightMap) {		
		if (heightMap.size()<3|| heightMap.size()<3)
		{
			return 0;
		}
		int m = heightMap.size();
		int n = heightMap[0].size();
		int res = 0;
		static const int dx[] = { 0,1,0,-1 };
		static const int dy[] = { 1,0,-1,0 };

		vector<vector<int>> visited(m,vector<int>(n,0));
		priority_queue<MyStruct, vector<MyStruct>, cmp> Q;
		for (size_t i = 0; i < m; i++)
		{
			Q.push(MyStruct(i, 0, heightMap[i][0]));
			visited[i][0] = 1;
			Q.push(MyStruct(i, n-1, heightMap[i][n-1]));
			visited[i][n - 1] = 1;
		}
		for (size_t i = 1; i < n-1; i++)
		{
			Q.push(MyStruct(0, i, heightMap[0][i]));
			visited[0][i] = 1;
			Q.push(MyStruct( m - 1, i, heightMap[m - 1][i]));
			visited[m - 1][i] = 1;
		}
		
		//int newx, newy, x, y, height;
		while (!Q.empty())
		{
			int x = Q.top().x;
			int y = Q.top().y;
			int height = Q.top().height;
			Q.pop();
			for (size_t i = 0; i < 4; i++)
			{
				int newx = x + dx[i];
				int newy = y + dy[i];
				if (0 > newx || 0 > newy || newx>=m || newy>=n ||
					visited[newx][newy] == 1)
				{
					continue;
				}
				if (heightMap[newx][newy]<height)
				{
					res += height - heightMap[newx][newy];		
					heightMap[newx][newy] = height;
				}
				visited[newx][newy] = 1;
				Q.push(MyStruct(newx, newy, heightMap[newx][newy]));
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> heightMap = { {1, 4, 3, 1, 3, 2},{3, 2, 1, 3, 2, 4},{2, 3, 3, 2, 3, 1} };
	cout << s.trapRainWater(heightMap) << endl;

	return 0;
}
