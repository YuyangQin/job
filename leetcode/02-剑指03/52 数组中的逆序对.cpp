#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class BIT {
private:
	vector<int> tree;
	int n;

public:
	BIT(int _n) : n(_n), tree(_n + 1) {}

	static int lowbit(int x) {
		return x & (-x);
	}

	int query(int x) {
		int ret = 0;
		while (x) {
			ret += tree[x];
			x -= lowbit(x);
		}
		return ret;
	}

	void update(int x) {
		while (x <= n) {
			++tree[x];
			x += lowbit(x);
		}
	}
};

class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		vector<int> tmp = nums;
		// 离散化
		sort(tmp.begin(), tmp.end());
		for (int& num : nums) {
			num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
		}
		// 树状数组统计逆序对
		BIT bit(n);
		int ans = 0;
		cout << endl;
		for (int i = n - 1; i >= 0; --i) {
			ans += bit.query(nums[i] - 1);
			bit.update(nums[i]);
		}
		return ans;
	}
};

//归并
class Solution1 {
public:
	int num = 0;

	void mergeArr(vector<int>& a, int begin, int mid, int end, vector<int>& temp)
	{
		int i = begin;
		int j = mid + 1;
		int length = 0;
		while (i <= mid&&j <= end)
		{
			if (a[i] <= a[j])
			{
				temp[length++] = a[i++];
				num = num + (j - mid - 1);
			}
			else
				temp[length++] = a[j++];
		}
		while (i <= mid)
		{
			temp[length++] = a[i++];
			num = num + (j - mid - 1);
		}
		while (j <= end)
			temp[length++] = a[j++];
		for (int i = 0; i < length; i++)
		{
			a[begin + i] = temp[i];
		}
	}

	void mergeSort(vector<int>& a, int begin, int end, vector<int>& temp)
	{
		if (begin >= end)
			return;
		int mid = (begin + end) / 2;

		mergeSort(a, begin, mid, temp);
		mergeSort(a, mid + 1, end, temp);

		mergeArr(a, begin, mid, end, temp);
	}
	int reversePairs(vector<int>& nums) {
		vector<int> temp;
		temp.resize(nums.size());
		mergeSort(nums, 0, nums.size() - 1, temp);
		return num;
	}
};

void main()
{
	Solution s;
	vector<int> nums = { 7,0,6,4 };
	cout << s.reversePairs(nums) << endl;
}
