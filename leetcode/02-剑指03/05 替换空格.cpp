#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		if (!s.empty())
		{
			for (int i = 0 ; i < s.size(); i++)
			{
				if (s[i] == ' ')
				{
					s.replace(i, 1, "%20");
					i += 2;
				}
			}
		}
		return s;
	}
};

void main()
{
	Solution s;
	string str = "We are happy.";
	string str1 = s.replaceSpace(str);

	cout << str1;
}