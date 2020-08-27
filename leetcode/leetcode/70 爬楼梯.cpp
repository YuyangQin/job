#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 2)
			return n;
		int preTwo = 1;
		int preOne = 2;
		int res;
		for (size_t i = 2; i < n; i++)
		{
			res = preTwo + preOne;
			preTwo = preOne;
			preOne = res;
		}
		return res;
	}
};

int main()
{

	return 0;
}
