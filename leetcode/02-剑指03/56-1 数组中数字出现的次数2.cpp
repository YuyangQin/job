#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		int count[32] = { 0 };
		for (size_t i = 0; i < 32; i++)
		{
			for (auto it : nums)
			{
				if ((it&(1 << i)) != 0)
					count[i]++;
			}
		}
		for (size_t i = 0; i < 32; i++)
		{
			if (count[i] % 3 == 1)
			{
				res += (1 << i);
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> v({ 3,4,3,3 });
	cout << s.singleNumber(v) << endl;

	return 0;
}
