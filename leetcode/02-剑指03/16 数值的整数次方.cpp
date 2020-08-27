#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (x==1||x==0)
			return x;
		long n2 = n;
		double val = 1;
		if (n2 < 0)
		{
			n2 = -n2 ;
			x = 1 / x;
		}
		while (n2)
		{
			if (n2 & 1)
				val *= x;
			x *= x;
			n2 >>= 1;
		}
		
		return val;
	}
};

void main()
{
	Solution s;
	cout << s.myPow(2.0000,3);
}