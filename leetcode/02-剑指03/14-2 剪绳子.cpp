#include <iostream>

using namespace std;

class Solution {
public:
	int cuttingRope(int n) {
		if (n <= 3) 
			return n - 1;
		int b = n % 3, p = 1000000007;
		long rem = 1, x = 3;
		for (int a = n / 3 - 1; a > 0; a /= 2)
		{
			if (a % 2 == 1)
				rem = (rem * x) % p;
			x = (x * x) % p;
		}
		if (b == 0) 
			return (int)(rem * 3 % p);
		if (b == 1) 
			return (int)(rem * 4 % p);
		return (int)(rem * 6 % p);
		/*if (n <= 3)
		{
			return n - 1;
		}
		int a = n / 3;
		int b = n % 3;
		int res = 1;
		for (int i = 0; i < a-1; i++)
		{
			res *= 3 % 1000000007;
		}
		if (b == 0)
			return res*3% 1000000007;
		else if (b == 2)
			return res*6% 1000000007;
		else
			return res*4% 1000000007;*/
	}
};

void main()
{
	Solution s;
	cout << s.cuttingRope(100) << endl;
}
