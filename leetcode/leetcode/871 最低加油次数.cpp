#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		priority_queue<int> pq;
		stations.push_back({ target, 0 });
		int n = stations.size();
		int ret = 0;
		for (size_t i = 0; i < n; i++)
		{
			while (startFuel<stations[i][0])
			{
				if (pq.empty())
					return -1;
				startFuel += pq.top();
				pq.pop();
				ret++;
			}
			pq.push(stations[i][1]);
		}
		return ret;
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> stations = { {10,60},{20,30},{30,30},{60,40} };
	cout << sol.minRefuelStops(100, 10, stations) << endl;

	return 0;
}
