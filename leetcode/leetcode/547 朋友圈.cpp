#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//方法三、并查集
class DisjointSet
{
public:
	int _count;
	DisjointSet(int n)
	{
		for (size_t i = 0; i < n; i++)
		{
			_id.push_back(i);
			_size.push_back(1);
		}
		_count = n;
	}
	int find(int p)
	{
		while (p != _id[p])
		{
			_id[p] = _id[_id[p]];
			p = _id[p];
		}
		return p;
	}
	void union_(int p, int q)
	{
		int i = find(p);
		int j = find(q);
		if (i == j)
			return;
		else if (_size[i]<_size[j])
		{
			_id[i] = j;
			_size[j] += _size[i];
		}
		else
		{
			_id[j] = i;
			_size[i] += _size[j];

		}
		_count--;
	}
private:
	vector<int> _id;
	vector<int> _size;
	
};
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		DisjointSet ds(n);
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (M[i][j] == 1)
				{
					ds.union_(i, j);
				}
			}
		}
		return ds._count;
	}
};


//方法二：广度优先遍历
class Solution2 {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int count = 0;
		vector<int> visited(M.size());
		queue<int> Q;
		for (size_t i = 0; i < M.size(); i++)
		{
			if (visited[i] == 0)
			{
				Q.push(i);
				visited[i] = 1;
				while (!Q.empty())
				{
					int tmp = Q.front();
					Q.pop();
					for (int j = 0; j < M[tmp].size(); j++)
					{
						if (visited[j]==0&&M[tmp][j]==1)
						{
							Q.push(j);
							visited[j] = 1;
						}
					}
				}
				count++;
			}
		}

		return count;
	}
};

//方法一、深度优先遍历
class Solution1 {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int count = 0;
		vector<int> visited(M.size());
		for (size_t i = 0; i < M.size(); i++)
		{
			if (visited[i]==0)
			{
				dfs(i, M, visited);
				count++;
			}		
		}
		
		return count;
	}
	void dfs(int index, vector<vector<int>>& M, vector<int>& visited)
	{
		visited[index] = 1;
		for (size_t i = 0; i < M[index].size(); i++)
		{
			if (visited[i] == 0&&M[index][i]==1)
			{
				dfs(i, M, visited);
			}
		}
	}
};

int main()
{
	vector<vector<int>> M = { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };
	Solution s;
	cout << s.findCircleNum(M) << endl;

	return 0;
}
