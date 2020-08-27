#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	//方法二、双指针
	string reverseWords(string s) {
		if (s.empty())
		{
			return "";
		}
		string res;
		int i, j;
		i =  s.size() - 1;
		while (i >= 0 && s[i] == ' ') i--;
		if (i==-1)
		{
			return "";
		}
		int begin = 0;
		while (begin < s.size() && s[begin] == ' ') begin++;
		j = i;
		while (i>=begin)
		{
			while (i >= begin && s[i] != ' ') i--;
			res += s.substr(i+1, j - i + 1);
			if (i!=begin)
				res += ' ';
			while (i >= begin && s[i] == ' ') i--;
			j = i;
		}
		return res;
	}
	string reverseWords1(string s) {
		vector<string> strvec;
		string res;
		string tmp;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i]==' ')
			{
				if (!tmp.empty())
				{
					strvec.push_back(tmp);
					tmp = "";
				}
				continue;
			}
			tmp += s[i];
		}
		if (!tmp.empty())
		{
			strvec.push_back(tmp);
		}
		for (int i = strvec.size()-1; i > 0; i--)
		{
			res += strvec[i] + ' ';
		}
		res += strvec[0];
		return res;
	}
};

int main()
{
	string s = " is  ";
	Solution sol;
	cout << sol.reverseWords(s) << endl;

	return 0;
}
