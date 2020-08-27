#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
	//方法二：单调队列
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.empty())
			return{};
		deque<int> dq;
		vector<int> res;
		for (size_t i = 0; i < k; i++)
		{
			while (!dq.empty() && dq.back() < nums[i])
				dq.pop_back();
			dq.push_back(nums[i]);
		}
		res.push_back(dq.front());
		int n = nums.size();
		for (size_t i = k; i < n; i++)
		{
			if (dq.front()==nums[i-k])
			{
				dq.pop_front();
			}
			while (!dq.empty() && dq.back() < nums[i])
				dq.pop_back();
			dq.push_back(nums[i]);
			res.push_back(dq.front());
		}
		return res;
	}
	//方法一:暴力
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.empty())
			return{};
		int n = nums.size() - k + 1;
		vector<int> res(n);

		for (size_t i = 0; i < n; i++)
		{
			int max = nums[i];
			for (int j = i+1; j < nums.size(); j++)
			{
				if (nums[j]>max)
				{
					max = nums[j];
				}
			}
			res[i] = max;
		}
		return res;
	}
};

int main()
{

	return 0;
}
