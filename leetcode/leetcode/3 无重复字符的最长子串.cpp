#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int begin = 0;
		int res = 0;
		int n = s.size();
		int cmap[128] = { 0 };
		for (int i = 0; i < n; i++)
		{
			cmap[s[i]]++;
			if (cmap[s[i]]==1)
			{
				if (res < (i - begin) + 1)
					res = i - begin + 1;
			}
			else
			{
				while (begin<i&&cmap[s[i]]>1)
				{
					cmap[s[begin]]--;
					begin++;
				}
			}
		}
		return res;
	}
};

class Solution1 {
public:
	int lengthOfLongestSubstring(string s) {
		int begin = 0;
		int res = 0;
		int n = s.size();
		unordered_map<char, int> umap;
		for (int i = 1; i < n; i++)
		{
			if (umap.find(s[i]) != umap.end())
			{
				res = max(res, i - umap[s[i]]);
				begin = max(begin, umap[s[i]]);				
			}
			umap[s[i]] = i;
		}
		res = max(res, (int)(s.size() - begin));
		return res;
	}
};

int main()
{
	Solution s;
	cout << s.lengthOfLongestSubstring("a") << endl;

	return 0;
}
