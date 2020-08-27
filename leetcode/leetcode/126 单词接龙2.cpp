#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int INF = 1 << 20;

class Solution {
private:
	unordered_map<string, int> wordId;
	vector<string> idWord;
	vector<vector<int>> edges;
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		int id = 0;
		for (const string& word : wordList) {
			if (!wordId.count(word)) {
				wordId[word] = id++;
				idWord.push_back(word);
			}
		}
		if (!wordId.count(endWord)) {
			return{};
		}
		if (!wordId.count(beginWord)) {
			wordId[beginWord] = id++;
			idWord.push_back(beginWord);
		}
		edges.resize(idWord.size());
		for (int i = 0; i < idWord.size(); i++) {
			for (int j = i + 1; j < idWord.size(); j++) {
				if (transformCheck(idWord[i], idWord[j])) {
					edges[i].push_back(j);
					edges[j].push_back(i);
				}
			}
		}
		const int dest = wordId[endWord];
		vector<vector<string>> res;
		queue<vector<int>> q;
		vector<int> cost(id, INF);
		q.push(vector<int>{wordId[beginWord]});
		cost[wordId[beginWord]] = 0;
		while (!q.empty()) {
			vector<int> now = q.front();
			q.pop();
			int last = now.back();
			if (last == dest) {
				vector<string> tmp;
				for (int index : now) {
					tmp.push_back(idWord[index]);
				}
				res.push_back(tmp);
			}
			else {
				for (int i = 0; i < edges[last].size(); i++) {
					int to = edges[last][i];
					if (cost[last] + 1 <= cost[to]) {
						cost[to] = cost[last] + 1;
						vector<int> tmp(now);
						tmp.push_back(to);
						q.push(tmp);
					}
				}
			}
		}
		return res;
	}

	bool transformCheck(const string& str1, const string& str2) {
		int differences = 0;
		for (int i = 0; i < str1.size() && differences < 2; i++) {
			if (str1[i] != str2[i]) {
				++differences;
			}
		}
		return differences == 1;
	}
};

class Solution1 {
public:
	struct Qitem
	{
		string word;
		int pre;
		int step;
		Qitem(string x,int y,int z):word(x),pre(y),step(z){}
	};
	int mystrCmp(string& s1, string& s2)
	{
		int ret = 0;
		for (size_t i = 0; i < s1.size(); i++)
		{
			if (s1[i] != s2[i])
			{
				ret++;
			}
		}
		return ret;
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		if (wordList.empty())
			return{};
		unordered_map<string, vector<string>> umap;
		vector<vector<string>> res;
		unordered_map<string, int> visited;
		vector<Qitem> Q;
		int hasBegin = 0;
		for (size_t i = 0; i < wordList.size(); i++)
		{
			if (wordList[i]==beginWord)
			{
				hasBegin = 1;
			}
		}
		if (hasBegin==0)
		{
			wordList.push_back(beginWord);
		}		
		int n = wordList.size();
		for (size_t i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (mystrCmp(wordList[i], wordList[j]) == 1)
				{
					umap[wordList[i]].push_back(wordList[j]);
					umap[wordList[j]].push_back(wordList[i]);
				}
			}
		}
		Q.push_back(Qitem(beginWord, -1,1));
		visited[beginWord] = 1;
		int front = 0;
		int minStep = 0;
		vector<int> intpos;
		while (front!=Q.size())
		{
			string tmp = Q[front].word;
			int step =Q[front].step;
			if (minStep!=0&&step>minStep)
			{
				break;
			}
			if (tmp==endWord)
			{
				minStep = step;
				intpos.push_back(front);
			}
			for (size_t i = 0; i < umap[tmp].size(); i++)
			{
				if (visited.find(umap[tmp][i])==visited.end()||visited[umap[tmp][i]]==step+1)
				{
					Q.push_back(Qitem(umap[tmp][i], front,step + 1));
					visited[umap[tmp][i]]=step+1;
				}
			}
			front++;
		}
		for (size_t i = 0; i < intpos.size(); i++)
		{
			int nth = minStep-1;
			vector<string> path(minStep);
			int pos = intpos[i];			
			while (pos!=-1)
			{
				path[nth] = Q[pos].word;
				pos = Q[pos].pre;
				nth--;
			}
			res.push_back(path);
		}
		return res;
	}
};

int main()
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
	Solution s;
	s.findLadders(beginWord, endWord, wordList);
	return 0;
}
