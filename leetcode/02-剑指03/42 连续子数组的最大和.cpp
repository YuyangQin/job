#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		int num = 0;
		for (int i = 1; i <= n; i++)
		{
			int temp = i;
			while (temp>0)
			{
				if ((temp&(-temp)) != 0)
					num++;
				temp = temp/10;
			}
		}
		return num;
	}
};

void main()
{
	Solution s;
	cout << (2 & (-2)) << endl;
	cout << s.countDigitOne(3) << endl;
}
