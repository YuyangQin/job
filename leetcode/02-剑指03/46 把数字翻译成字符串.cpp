#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	//使用pqr优化
	int translateNum1(int num) {
		string str = to_string(num);

		int p = 0, q = 0, r = 1;
		for (size_t i = 0; i < str.size(); i++)
		{
			p = q;
			q = r;
			if (i == 0)
				continue;
			auto pre = str.substr(i - 1, 2);
			if (pre >= "10"&&pre <= "25")
			{
				r += p;
			}
		}
		return r;
	}

	//动态规划
	int translateNum1(int num) {
		string str = to_string(num);
		vector<int> count(str.size());
		count[0] = 1;
		for (size_t i = 1; i < str.size(); i++)
		{
			count[i] = count[i - 1];
			auto pre = str.substr(i - 1, 2);
			if (pre>="10"&&pre<="25")
			{
				if (i == 1)
					count[i] += 1;
				else
					count[i] += count[i - 2];
			}
		}
		return count[str.size() - 1];
	}
};

int main()
{

	return 0;
}
