#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int seenOnce = 0, seenTwice = 0;
		for (int num : nums) {
			seenOnce = ~seenTwice & (seenOnce ^ num);
			seenTwice = ~seenOnce & (seenTwice ^ num);
		}
		return seenOnce;
	}
};

class Solution1 {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		int count;
		for (int i = 0; i < 31; i++)
		{
			count = 0;
			for (auto it : nums)
				count += (it >> i) & 1;
			if (count%3==1)
				res += 1 << i;
		}
		return res;
	}
};

void main()
{
	Solution s;
	vector<int> nums = { 0,1,0,1,0,1,99 };
	cout << s.singleNumber(nums) << endl;
	cout << (~2 & 2) << endl;
}
