#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	vector<string> res1;
	vector<string> permutation(string s) {
		/*vector<string> res;
		res.push_back(s);
		recur(s, 0, res);
		return res;*/
		dfs(0, s);
		return res1;
	}
	void dfs(int x,string s)
	{
		if (x == s.size() - 1)
		{
			res1.push_back(s);
			return;
		}
		set<char> mset;
		for (int i = x; i < s.size(); i++)
		{
			if (mset.find(s[i])!=mset.end()) continue; 
			mset.insert(s[i]);
			swap(s[i],s[x]); 
			dfs(x + 1,s); 
		}
	}

	//³¬Ê±  babÀàÐÍ´íÎó
	void recur(string s,int pos, vector<string>& res)
	{
		if (pos >= s.size())
			return;
		for (int i = pos; i < s.size(); i++)
		{
			if (s[i]!=s[pos]||pos==i)
			{
				if(i!=pos)
				{
					swap(s[i], s[pos]);
					/*if(find(res.begin(), res.end(), s)==res.end())*/
						res.push_back(s);
				}			
				recur(s, pos + 1, res);
			}
		}
	}
};

void main()
{
	Solution s;
	string str = "bab";
	vector<string> v = s.permutation(str);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}