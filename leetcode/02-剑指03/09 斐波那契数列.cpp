#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int fib(int n) {
		int pre1 = 0;
		int pre2 = 1;
		int sum;
		if (n == 0)
			return 0;
		else if(n == 1)
		{
			return 1;
		}
		while (n>1)
		{
			sum = (pre1 + pre2) % 1000000007;
			pre1 = pre2;
			pre2 = sum;
			n--;
		}
		return sum;
	}
	
};

void main()
{
	Solution s;
	cout <<s.fib(5) <<endl;
}