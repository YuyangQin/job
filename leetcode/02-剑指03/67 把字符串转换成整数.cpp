#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int strToInt(string str) {
		int res = 0;
		int is_negative = 1;
		const int BeginState = 0;
		const int CharState = 1;
		const int NumState = 2;
		const int EndState = 3;
		int state = BeginState;
		for (size_t i = 0; i < str.size(); i++)
		{
			switch (state)
			{
			case BeginState:
				if (str[i] == ' ')
				{
					continue;
				}
				if ('0' <= str[i] && str[i] <= '9')
				{
					state = NumState;
					i--;
				}
				else if (str[i] == '+' || str[i] == '-')
				{
					state = CharState;
					if (str[i] == '-')
					{
						is_negative = -1;
					}
				}
				else
				{
					state = EndState;
				}
				break;
			case CharState:
				if ('0' <= str[i] && str[i] <= '9')
				{
					state = NumState;
					i--;
				}
				else
				{
					state = EndState;
				}
				break;
			case NumState:
				if ('0' <= str[i] && str[i] <= '9')
				{
					if (abs(res) > 214748364)
					{
						if (is_negative == 1)
							res = INT_MAX;
						else
							res = INT_MIN;
						state = EndState;
						break;
					}
					else if(abs(res) == 214748364)
					{
						if (is_negative == 1 && (INT_MAX - res * 10 <= str[i] - '0'))
						{
							res = INT_MAX;
							state = EndState;
							break;
						}
						else if (is_negative == -1 && (res * 10 - INT_MIN < (str[i] - '0')))
						{
							res = INT_MIN;
							state = EndState;
							break;
						}
					}
					
					res = res * 10 + is_negative*(str[i] - '0');
				}
				else
				{
					state = EndState;
				}
				break;
			case EndState:
				break;
			}
		}
		if (res == INT_MAX || res == INT_MIN)
			return res;
		return res;
	}
};

int main()
{
	string str = "-2147483647";
	Solution s;
	cout << s.strToInt(str) << endl;

	return 0;
}
