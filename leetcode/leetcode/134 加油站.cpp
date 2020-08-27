#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
			return -1;
		int n = gas.size();
		int res = 0;
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (sum < 0)
			{
				sum = 0;
				res = i;
			}
			sum =sum+ gas[i]-cost[i];
			
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> gas({ 1,2,3,4,5 });
	vector<int> cost({ 3,4,5,1,2 });
	cout << s.canCompleteCircuit(gas, cost) << endl;

	return 0;
}
