#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> s1;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				s1.push(s[i]);
			else if (s[i]==')')
			{
				if (s1.empty()||s1.top()!='(')
					return false;
				s1.pop();
			}
			else if (s[i] == '[')
				s1.push(s[i]);
			else if (s[i] == ']')
			{
				if (s1.empty() || s1.top() != '[')
					return false;
				s1.pop();
			}
			else if (s[i] == '{')
				s1.push(s[i]);
			else if (s[i] == '}')
			{
				if (s1.empty() || s1.top() != '{')
					return false;
				s1.pop();
			}
		}
		return s1.empty();
	}
};

int main()
{

	return 0;
}
