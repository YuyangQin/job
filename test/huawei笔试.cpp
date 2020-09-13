#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector< string> split(const  string& s, char delimiter)
{
	vector< string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

struct Candies
{
	int index;
	int num;
	int color;
	Candies() {};
	Candies(int i,int n,int c) :index(i), num(n), color(c) {};
};
struct MyCompare
{
	bool operator()(Candies&c1, Candies&c2)
	{
		return c1.num < c2.num;
	}
};

void test1()
{
	int n;
	vector<Candies> color1;
	vector<Candies> color2;
	int num;
	int color;
	while (cin>>n)
	{		
		for (int i = 1; i <= n; i++)
		{
			cin >> num >> color;
			if (color==1)
			{
				color1.push_back(Candies(i, num, color));
			}
			else
			{
				color2.push_back(Candies(i, num, color));
			}
		}
		if (color1.size()<3&&color2.size()<3)
		{
			cout << "null" << endl;
			continue;
		}
		int sum1 = 0;
		int sum2 = 0;
		vector<int> index1;
		vector<int> index2;
		sort(color1.begin(), color1.end(), MyCompare());
		sort(color2.begin(), color2.end(), MyCompare());

		if (color1.size()>=3)
		{
			for (size_t i = 0; i < 3; i++)
			{
				sum1 += color1.top().num;
				index1.push_back(color1.top().index);
				color1.pop();
			}
		}
		if (color2.size()>=3)
		{
			for (size_t i = 0; i < 3; i++)
			{
				sum2 += color2.top().num;
				index2.push_back(color2.top().index);
				color2.pop();
			}
		}
		if (index1.size()==0&&index2.size()!=0)
		{
			sort(index2.begin(), index2.end());
			for (size_t i = 0; i < 3; i++)
			{
				cout << index2[i] << " ";
			}
			cout << endl;
			cout << 2 << endl;
			cout << sum2 << endl;
		}
		else if(index1.size() != 0 && index2.size() == 0)
		{
			sort(index1.begin(), index1.end());
			for (size_t i = 0; i < 3; i++)
			{
				cout << index1[i] << " ";
			}
			cout << endl;
			cout << 1 << endl;
			cout << sum1 << endl;
		}
		else
		{
			sort(index2.begin(), index2.end());
			sort(index1.begin(), index1.end());
			if (index1[0]<index2[0])
			{
				for (size_t i = 0; i < 3; i++)
				{
					cout << index1[i] << " ";
				}
				cout << endl;
				cout << 1 << endl;
				cout << sum1 << endl;
			}
			else
			{
				for (size_t i = 0; i < 3; i++)
				{
					cout << index2[i] << " ";
				}
				cout << endl;
				cout << 2 << endl;
				cout << sum2 << endl;
			}
		}
		
	}
}

void dfs(int x, int y, vector<vector<char>>& matrix, vector<vector<int>>& visited)
{
	static int dx[] = { 1,-1,0,0 };
	static int dy[] = { 0,0,1,-1 };

	visited[x][y] = 1;
	for (size_t i = 0; i < 4; i++)
	{
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (newx>=0&&newx<matrix.size()&& newy >= 0 && newy<matrix[0].size() && visited[newx][newy]==0&&matrix[newx][newy]=='S')
		{
			dfs(newx, newy, matrix, visited);
		}		
	}
}
void test2()
{
	int m, n;
	string str;
	while (cin>>str)
	{
		int pos = str.find(',');
		m = stoi(str.substr(0, pos));
		n = stoi(str.substr(pos+1));
		vector<vector<char>> matrix(m, vector<char>(n));
		vector<vector<int>> visited(m, vector<int>(n));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> matrix[i][j];
				visited[i][j] = 0;
			}
		}
		int count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j]=='S'&&visited[i][j]==0)
				{
					dfs(i, j, matrix, visited);
					count++;
				}
			}
		}
		cout << count << endl;
	}
}
void test3()
{
	int k;
	int n;
	while (cin>>k>>n)
	{
		vector<int> size(n+1);
		vector<int> value(n+1);
		for (size_t i = 1; i <= n; i++)
		{
			cin >> size[i];
		}
		for (size_t i = 1; i <= n; i++)
		{
			cin >> value[i];
		}
		vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
		for (int i = 1; i <= n; i++)
		{
			for (size_t j = 0; j <= k; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (j>=size[i])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - size[i]] + value[i]);
				}
			}
		}
		int totalvalue = 0;
		for (size_t i = 0; i <= k; i++)
			totalvalue = max(totalvalue, dp[n][i]);
		cout << totalvalue << endl;
	}
}


int main()
{
	test1();


	return 0;
}