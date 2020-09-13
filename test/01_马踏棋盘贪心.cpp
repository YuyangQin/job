#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define X 8
#define Y 8

static int visited[X][Y];
static int flag;

using namespace std;

void static print()
{
	for (int i = 0; i < X; i++)
	{
		for (size_t j = 0; j < Y; j++)
		{
			printf("%-3d", visited[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

vector<pair<int, int>> getNext(int x, int y)
{
	vector<pair<int, int>> next;

	if (x + 2 < X&& y + 1 < Y)
		next.push_back(make_pair(x + 2, y + 1));
	if (x + 2 < X&& y - 1 >= 0)
		next.push_back(make_pair(x + 2, y - 1));
	if (x + 1 < X&& y - 2 >= 0)
		next.push_back(make_pair(x + 1, y - 2));
	if (x - 1 >= 0 && y - 2 >= 0)
		next.push_back(make_pair(x - 1, y - 2));
	if (x - 2 >= 0 && y - 1 >= 0)
		next.push_back(make_pair(x - 2, y - 1));
	if (x - 2 >= 0 && y + 1 < Y)
		next.push_back(make_pair(x - 2, y + 1));
	if (x - 1 >= 0 && y + 2 < Y)
		next.push_back(make_pair(x - 1, y + 2));
	if (x + 1 < X&& y + 2 < Y)
		next.push_back(make_pair(x + 1, y + 2));
	return next;
}



int getNum(pair<int, int> p)
{
	int count = 0;
	int x = p.first;
	int y = p.second;
	if (x + 2 < X&& y + 1 < Y)
		count++;
	if (x + 2 < X&& y - 1 >= 0)
		count++;
	if (x + 1 < X&& y - 2 >= 0)
		count++;
	if (x - 1 >= 0 && y - 2 >= 0)
		count++;
	if (x - 2 >= 0 && y - 1 >= 0)
		count++;
	if (x - 2 >= 0 && y + 1 < Y)
		count++;
	if (x - 1 >= 0 && y + 2 < Y)
		count++;
	if (x + 1 < X&& y + 2 < Y)
		count++;
	return count;
}

void mySort(vector<pair<int, int>>& nextStep)
{
	int length = nextStep.size();
	for (size_t i = 0; i < length-1; i++)
	{
		for (size_t j = 0; j < length-i-1; j++)
		{
			if (getNum(nextStep[j]) < getNum(nextStep[j + 1]))
			{
				pair<int, int> tmp = nextStep[j];
				nextStep[j] = nextStep[j + 1];
				nextStep[j + 1] = tmp;
			}
		}
	}
}
static int mycount=0;

void static dfs(int x, int y, int& flag)
{
	mycount++;
	if (/*x >= X || y >= Y || x < 0 || y < 0 || */visited[x][y] != 0)
		return;
	flag += 1;
	
	visited[x][y] = flag;
	if (flag == 64)
		print();
	vector<pair<int, int>> nextStep = getNext(x, y);
	mySort(nextStep);
	while (!nextStep.empty())
	{
		dfs(nextStep.back().first, nextStep.back().second, flag);
		nextStep.pop_back();
	}
	return;
}

int main0102()
{
	flag = 0;
	dfs(5, 6, flag);
	if (flag < 64)
		cout << "find err" << endl;
	cout << mycount<<endl;
	return 0;
}
