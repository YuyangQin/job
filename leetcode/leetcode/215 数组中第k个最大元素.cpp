#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <functional>
#include <time.h>

using namespace std;

class Solution {
public:
	//快速选择
	int quickSelect(vector<int>& a, int l, int r, int index) {
		int q = randomPartition(a, l, r);
		if (q == index) {
			return a[q];
		}
		else {
			return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
		}
	}

	inline int randomPartition(vector<int>& a, int l, int r) {
		int i = rand() % (r - l + 1) + l;
		swap(a[i], a[r]);
		return partition(a, l, r);
	}

	inline int partition(vector<int>& a, int l, int r) {
		int x = a[r], i = l - 1;
		for (int j = l; j < r; ++j) {
			if (a[j] <= x) {
				swap(a[++i], a[j]);
			}
		}
		swap(a[i + 1], a[r]);
		return i + 1;
	}

	int findKthLargest(vector<int>& nums, int k) {
		srand(time(0));
		return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
	}

	//优先队列
	int findKthLargest1(vector<int>& nums, int k) {
		priority_queue<int,vector<int>, greater<int>> pq;
		for (size_t i = 0; i < k; i++)
		{
			pq.push(nums[i]);
		}
		for (size_t i = k; i < nums.size(); i++)
		{
			if (nums[i] > pq.top())
			{
				pq.pop();
				pq.push(nums[i]);
			}
		}
		return pq.top();
	}
};

int main1()
{

	return 0;
}
