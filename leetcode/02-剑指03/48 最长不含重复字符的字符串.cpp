#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> dic;
		int i = -1, res = 0;
		for (int j = 0; j < s.size(); j++) {
			if (dic.find(s[j])!=dic.end())
				i = max(i, dic[s[j]]); // 更新左指针 i
			dic.insert(make_pair(s[j],j)); // 哈希表记录
			res = max(res, j - i); // 更新结果
		}
		return res;
	}
};

int main()
{
	string s = "bacabcbb";
	Solution sol;
	cout << sol.lengthOfLongestSubstring(s) << endl;

	return 0;
}
