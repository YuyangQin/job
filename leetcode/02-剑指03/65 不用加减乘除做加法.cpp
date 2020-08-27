#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Solution {
public:
	int add(int a, int b) {
		int carry = 0;
		int res = 0;
		for (size_t i = 0; i < 32; i++)
		{
			if (a&(1<<i)&& b&(1 << i))
			{
				res |= (carry << i);
				carry = 1;
			}
			else if(a&(1 << i) || b&(1 << i))
			{
				if (!carry)
				{
					res |= (1 << i);
				}
			}
			else
			{
				if (carry)
				{
					res |= (carry << i);
					carry = 0;
				}
			}
		}
		return res;
	}
};

int main()
{

	return 0;
}
