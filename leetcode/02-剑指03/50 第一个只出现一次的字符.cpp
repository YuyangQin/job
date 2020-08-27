#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	//3.用数组替换哈希表
	char firstUniqChar(string s) {
		int n = s.size();
		vector<int> v(26, 0);
		for (size_t i = 0; i < n; i++)
		{
			v[s[i] = 'a']++;
		}
		for (size_t i = 0; i < 26; i++)
		{
			if (v[i] == 1)
				return i + 'a';
		}		
		return ' ';
	}
	//2.直接对字符串查找
	char firstUniqChar2(string s) {
		int n = s.size();
		unordered_map<char, bool> umap;
		for (size_t i = 0; i < n; i++)
		{
			if (umap.find(s[i]) != umap.end())
			{
				if (umap[s[i]] != false)
					umap[s[i]] = false;
			}
			else
			{
				umap.insert(make_pair(s[i], true));
			}
		}
		for (size_t i = 0; i < n; i++)
		{
			if (umap[s[i]] == true)
				return s[i];
		}
		return ' ';
	}
	//1.对哈希表查找
	char firstUniqChar1(string s) {
		int n = s.size();
		unordered_map<char,int> umap;
		for (size_t i = 0; i < n; i++)
		{
			if (umap.find(s[i])!=umap.end())
			{
				if (umap[s[i]] != n)
					umap[s[i]] = n;
			}
			else
			{
				umap.insert(make_pair(s[i], i));
			}
		}
		int min = n;
		for (auto it:umap)
		{
			if (it.second<min)
			{
				min = it.second;
			}
		}
		if (min==n)
		{
			return ' ';
		}
		return s[min];
	}
};

int main()
{
	string s = "hello world";
	int n = s.size();
	unordered_map<char, int> umap;
	for (size_t i = 0; i < n; i++)
	{
			umap.insert(make_pair(s[i], i));
	}
	for (auto it : umap)
	{
		cout << it.first;
	}
	

	return 0;
}
