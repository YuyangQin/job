#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		int chars[128] = { 0 };
		int flag = 0;
		int res=0;
		int n = s.size();
		for (size_t i = 0; i < n; i++)
		{
			chars[s[i]]++;
		}
		for (size_t i = 0; i < 128; i++)
		{
			if (chars[i] > 0)
			{
				if (chars[i]%2==0)
				{
					res += chars[i];
				}
				else
				{
					res += chars[i] - 1;
					flag = 1;
				}
			}
		}
		return res + flag;
	}
};

int main()
{

	return 0;
}
