#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();
		int i, j;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (board[i][j] == word[0])
				{
					if (dfs(i, j, 0, word, board))
						return true;
				}
			}
		}
		return false;
	}
	bool dfs(int i, int j, int k, string& word, vector<vector<char>>& board)
	{
		if ((i < 0) || (i > board.size() - 1) || (j<0)
			|| (j>board[0].size() - 1) || (board[i][j] != word[k]))
			return false;
		if (k == word.size() - 1)
			return true;
		char tmp = board[i][j];

		board[i][j] = '/';
		bool res = dfs(i + 1, j, k + 1, word, board)
			|| dfs(i, j + 1, k + 1, word, board)
			|| dfs(i - 1, j, k + 1, word, board)
			|| dfs(i, j - 1, k + 1, word, board);
		board[i][j] = tmp;
		return res;
	}
};

void main()
{
	vector<char> c1 = { 'A','B','C','E' };
	vector<char> c2 = { 'D','E','C','E' };
	vector<char> c3 = { 'A','S','E','E' };
	vector<vector<char>> board;
	board.push_back(c1);
	board.push_back(c2);
	board.push_back(c3);

	Solution s;


	cout << s.exist(board, "ABCCED") << endl;
}