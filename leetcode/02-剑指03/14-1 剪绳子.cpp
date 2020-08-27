#include <iostream>

using namespace std;

class Solution {
public:
	int cuttingRope(int n) {
		if (n <= 3)
		{
			return n - 1;
		}
		int a = n / 3;
		int b = n % 3;
		if (b == 0)
			return pow(3, a);
		else if (b == 2)
			return pow(3, a) * 2;
		else
			return pow(3, a - 1) * 4;
	}
};

void main()
{
	Solution s;
	cout << s.cuttingRope(8) << endl;
}
