#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<string, char> umap;
		int visited[128] = { 0 };
		str.push_back(' ');
		string tmp_str = "";
		int pos = 0;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i]==' ')
			{
				if (umap.find(tmp_str) == umap.end())
				{
					if (visited[pattern[pos]] == 1)
					{
						return false;
					}
					visited[pattern[pos]] = 1;
					umap[tmp_str] = pattern[pos];
				}
				else
				{
					if (umap[tmp_str] != pattern[pos])
					{
						return false;
					}
				}
				tmp_str = "";
				pos++;
			}
			else
			{
				tmp_str += str[i];
			}
		}
		if (pos!=pattern.size())
		{
			return false;
		}
		return true;
	}
};

int main()
{
	string pattern = "abba";
	string str = "dog cat cat dog";
	Solution s;
	cout << s.wordPattern(pattern, str) << endl;

	return 0;
}
