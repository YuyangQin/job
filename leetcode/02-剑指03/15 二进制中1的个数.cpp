#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int num = 0;
		while (n)
		{
			n = n&(n - 1);
			num++;
		}
		return num;
	}
};

void main()
{
	Solution s;
	cout<<s.hammingWeight(00000000000000000000000000001011);
}