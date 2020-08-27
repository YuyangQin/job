#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numWays(int n) {
		if (n ==0 )
		{
			return 0;
		}
		else if(n<=2)
		{
			return 1;
		}
		int pre1 = 1;
		int pre2 = 2;
		int sum;
		for (int i = 3;i<n+1;i++)
		{
			sum = (pre1 + pre2) % 1000000007;
			pre1 = pre2;
			pre2 = sum;
		}
		return sum;
	}
};

void main()
{
	Solution s;
	
	cout << s.numWays(7)<< endl;
}