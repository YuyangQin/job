#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int mystrCmp(string& s1, string& s2)
	{
		int ret = 0;
		for (size_t i = 0; i < s1.size(); i++)
		{
			if (s1[i]!=s2[i])
			{
				ret++;
			}
		}
		return ret;
	}
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (wordList.empty())
			return 0;
		unordered_map<string, vector<string>> umap;
		unordered_map<string, bool> visited;		
		queue<pair<string,int>> Q;
		int res = 0;
		wordList.push_back(beginWord);
		int n = wordList.size();	
		
		for (size_t i = 0; i < n; i++)
		{
			visited[wordList[i]] = false;
			for (int j = i + 1; j < n; j++)
			{
				if (mystrCmp(wordList[i],wordList[j])==1)
				{
					umap[wordList[i]].push_back(wordList[j]);
					umap[wordList[j]].push_back(wordList[i]);
				}
			}
		}
		Q.push(make_pair(beginWord, 1));
		visited[beginWord] = true;
		while (!Q.empty())
		{
			string tmp = Q.front().first;
			int step = Q.front().second;
			Q.pop();
			for (size_t i = 0; i < umap[tmp].size(); i++)
			{
				if (!visited[umap[tmp][i]])
				{
					if (umap[tmp][i]==endWord)
					{
						return step + 1;
					}
					Q.push(make_pair(umap[tmp][i], step + 1));
					visited[umap[tmp][i]] = true;
				}
			}
		}
		return 0;
	}
};

int main()
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
	Solution s;
	cout<<s.ladderLength(beginWord,endWord,wordList)<<endl;

	return 0;
}
