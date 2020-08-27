#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
	bool isSub(int umaps[], int umapt[], vector<int>& vec_t)
	{
		for (size_t i = 0; i < vec_t.size(); i++)
		{
			if (umaps[vec_t[i]] < umapt[vec_t[i]])
				return false;
		}
		return true;
	}
public:
	string minWindow(string s, string t) {
		int umaps[128] = { 0 };
		int umapt[128] = { 0 };
		vector<int> vec_t;
		for (size_t i = 0; i < t.length(); i++)
		{
			umapt[t[i]]++;
		}
		for (size_t i = 0; i < 128; i++)
		{
			if (umapt[i] > 0)
				vec_t.push_back(i);
		}
		int begin = 0;
		string res;
		for (size_t i = 0; i < s.size(); i++)
		{
			umaps[s[i]]++;
			while (begin<i)
			{
				if (umapt[s[begin]] == 0)
				{
					begin++;
				}
				else if (umaps[s[begin]]>umapt[s[begin]])
				{
					umaps[s[begin]]--;
					begin++;
				}
				else
				{
					break;
				}
			}
			
			if (isSub(umaps, umapt,vec_t))
			{
				int len = i - begin + 1;
				if (res.empty() || res.size()>len)
				{
					res = s.substr(begin,len);
				}
			}
		}
		return res;
	}
};

class Solution1 {
public:
	bool isSub(unordered_map<char, int> umaps, unordered_map<char, int> umapt)
	{
		for (auto& it : umapt)
		{
			if (umaps[it.first] < it.second)
				return false;
		}
		return true;
	}
	string minWindow(string s, string t) {
		unordered_map<char, int> umaps;
		unordered_map<char, int> umapt;
		string res;
		for (auto& it : t)
		{
			umapt[it]++;
		}
		int begin = 0;
		int n = s.size();
		string word;
		for (size_t i = 0; i < n; i++)
		{
			umaps[s[i]]++;
			while (begin<i)
			{
				if (umapt.find(s[begin]) == umapt.end())
				{
					umaps[s[begin]]--;
					begin++;
				}
				else if(umapt.find(s[begin])!=umapt.end()&&umaps[s[begin]]>umapt[s[begin]])
				{
					umaps[s[begin]]--;
					begin++;
				}
				else
				{
					break;
				}
			}
			word = s.substr(begin, i-begin+1);
			if (isSub(umaps, umapt))
			{
				if (res.empty()||res.size()>word.size())
				{
					res = word;
				}
			}
		}
		return res;
	}
};

int main()
{
	string s = "ADOBECODEBANC";
	string t = "ABC";
	Solution sol;
	cout << sol.minWindow(s, t) << endl;

	return 0;
}
