#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	static bool mysort(vector<int>& p1, vector<int>& p2)
	{
		return p1[0] < p2[0];
	}
	int findMinArrowShots(vector<vector<int>>& points) {
		int n = points.size();
		if (n<2)
			return n;
		sort(points.begin(), points.end(), mysort);
		int ret = 1;
		int shoot_begin = points[0][0];
		int shoot_end = points[0][1];
		for (size_t i = 1; i < n; i++)
		{
			if (shoot_end>=points[i][0])
			{
				shoot_begin = points[i][0];
				if (shoot_end>points[i][1])
				{
					shoot_end = points[i][1];
				}
			}
			else
			{
				shoot_begin = points[i][0];
				shoot_end = points[i][1];
				ret++;
			}
		}
		return ret;
	}
};

int main()
{

	return 0;
}
