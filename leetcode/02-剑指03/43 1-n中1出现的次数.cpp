#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//计算每一位1出现的次数
	int countDigitOne(int n) {
		int res = 0;
		int high = n / 10;
		int cur = n % 10;
		int bit = 1;
		int low = 0;

		while (1)
		{
			if (cur == 0)
				res += high*bit;
			else if (cur == 1)
				res += (high*bit + low + 1);
			else
				res += (high + 1)*bit;
			
			low = cur*bit + low;
			cur = high % 10;
			high /= 10;
			if (high == 0 && cur == 0)
				break;
			bit *= 10;
		}

		return res;
	}
};

void main()
{
	Solution s;
	cout << s.countDigitOne(9999) << endl;
}
