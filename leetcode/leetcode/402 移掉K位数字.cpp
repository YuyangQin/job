#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
		string s;
		int n = num.length();
		for (size_t i = 0; i < n; i++)
		{
			while (!s.empty()&&s[s.size()-1]>num[i]&&k>0)
			{
				s.pop_back();
				k--;
			}
			if (!s.empty()||num[i]!='0')
			{
				s.push_back(num[i]);
			}
		}
		while (k>0&&!s.empty())
		{
			s.pop_back();
			k--;
		}
		if (s.empty())
		{
			s = "0";
		}
		return s;
    }
};

int main()
{
	Solution sol;
	string s = "10";
	cout << sol.removeKdigits(s, 2)<<endl;

	return 0;
}
