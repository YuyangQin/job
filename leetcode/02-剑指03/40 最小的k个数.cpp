#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//快速选择
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int>  res(k, 0);
		if (k == 0)
			return res;
		quickSelect(arr, 0, arr.size() - 1, k);
		for (int i = 0; i < k; i++)
		{
			res[i] = arr[i];
		}
		return res;
	}

	void quickSelect(vector<int>& arr, int l, int r, int k)
	{
		int pos = partition(arr, l, r);
		if (pos == k-1)
			return;
		else if (pos > k-1)
			quickSelect(arr, l, pos - 1, k);
		else
			quickSelect(arr, pos + 1, r, k);
	}
	int partition(vector<int>& arr, int l, int r)
	{
		int v = arr[l];
		int i = l;
		int j = r + 1;
		while (true)
		{
			while (++i <= r&&arr[i] < v);
			while (--j >= l&&arr[j] > v);

			if (i >= j)
				break;
			swap(arr[i], arr[j]);
		}
		swap(arr[l], arr[j]);
		return j;
	}

	//堆实现：priority_queue
	vector<int> getLeastNumbers2(vector<int>& arr, int k) {
		vector<int>  res(k, 0);
		if (k == 0)
			return res;
		priority_queue<int> pq;
		for (int i = 0; i < k; i++)
			pq.push(arr[i]);
		for (int i = k; i < arr.size(); i++)
		{
			if (arr[i]<pq.top())
			{
				pq.pop();
				pq.push(arr[i]);
			}
		}
		for (int i = 0; i < k; i++)
		{
			res[i]=pq.top();
			pq.pop();
		}
		return res;
	}

	//multiset实现
	vector<int> getLeastNumbers1(vector<int>& arr, int k) {
		if (k==0)
			return{};
		vector<int> res;
		multiset<int> s1;
		int i = 0;
		for (auto x : arr)
		{
			s1.insert(x);
		}
		for (auto y : s1)
		{
			if (i == k)
				break;
			res.push_back(y);
			i++;
		}
		return res;
	}
};

void main()
{
	vector<int> arr = { 1,4,3,2,1,0,5};
	Solution s;
	vector<int> res = s.getLeastNumbers(arr, 4);
	for (auto x:res)
	{
		cout << x << " ";
	}
}