#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int ret = 0;
		for (int n : nums)
			ret ^= n;
		int div = ret&(-ret);
		int a = 0, b = 0;
		for (int n : nums)
			if (div & n)
				a ^= n;

		return vector<int>{a, ret^a};
	}
};

int main()
{

	return 0;
}
