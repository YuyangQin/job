#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

																//FALSE ANSWER
																//FALSE ANSWER
																//FALSE ANSWER

class Solution {
public:
	bool isNumber(string s) {
		if (s.empty())
			return false;
		//int symbols[4] = { 0 };
		vector<int> symbols(4, 0);
		for (int i = 0; i < s.size(); i++)
		{
			if (((s[i] >= '0') && (s[i] <= '9'))||s[i]==' ')
				;
			else if (s[i] == 'e') 
				symbols[0]++;
			else if (s[i] == '.') 
				symbols[1]++;
			else if (s[i] == '+' || s[i] == '-') 
				symbols[2]++;
			else
				symbols[3]++;
		}
		for (int i = 0; i < 3; i++)
		{
			if (symbols[i] >= 2)
				return false;
		}
		if (symbols[3]>=1)
			return false;
		if (symbols[0] == 1)
		{
			int epos = s.find('e');
			if (epos == 0 || epos == s.size()-1)
				return false;
			if (s[epos-1]<0||s[epos-1]>9)
				return false;
			if (symbols[1] == 1)
			{
				if(epos<s.find('.'))
					return false;
			}
		}
		if (symbols[1] == 1)
		{
			int dotpos = s.find('.');
			if (s.size() == 1)
				return false;
			if ((s[dotpos + 1] >= '0' && s[dotpos + 1] <= '9') || (s[dotpos - 1] >= '0' && s[dotpos - 1] <= '9'))
				return true;
			else
				return false;
		}
		if (symbols[2] == 1)
		{
			int aspos;
			if (s.find('+') >= s.size() || s.find('+') < 0)
				aspos = s.find('-');
			else
				aspos = s.find('+');
			if (aspos != 0)
			{
				if (symbols[0] == 1)
				{
					if (aspos != s.find('e') + 1)
						return false;
				}
			}
		}

		return true;
	}
};

void main()
{
	Solution s;
	cout << s.isNumber(".") << endl;
}