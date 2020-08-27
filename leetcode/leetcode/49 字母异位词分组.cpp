#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//先对字符串进行排序
class Solution2 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		map<string, vector<string>> umap;
		string tmp;
		for (size_t i = 0; i < strs.size(); i++)
		{
			tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			umap[tmp].push_back(strs[i]);
		}
		for (auto& it : umap)
			res.push_back(it.second);
		return res;
	}
};
//用数组记录每个元素出现次数
class Solution1 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		vector<int> count(26,0);
		map<vector<int>, vector<string>> umap;
		for (size_t i = 0; i < strs.size(); i++)
		{
			for (size_t j = 0; j < strs[i].size(); j++)
			{
				count[strs[i][j] - 'a']++;
			}
			umap[count].push_back(strs[i]);
			count.assign(26, 0);
		}
		for (auto it : umap)
			res.push_back(it.second);
		return res;
	}
};

int main()
{
	Solution s;
	vector<string> strs({ "eat", "tea", "tan", "ate", "nat", "bat" });
	vector<vector<string>> res = s.groupAnagrams(strs);

	return 0;
}
