#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//方法二：建立表格分区，类两个dp
	vector<int> constructArr(vector<int>& a) {
		int n = a.size();
		if (n==0)
		{
			return{};
		}
		vector<int> res(n);
		int tmp = 1;;
		res[0] = 1;
		for (size_t i = 1; i < n; i++)
		{
			res[i] = res[i - 1] * a[i - 1];
		}
		for (int i = n-2; i >= 0; i--)
		{
			tmp *= a[i+1];
			res[i] *= tmp;
		}
		return res;
	}

	//方法一：暴力，超时
	vector<int> constructArr1(vector<int>& a) {
		int n = a.size();
		vector<int> res(n);
		int num;
		for (size_t i = 0; i < n; i++)
		{
			num = 1;
			for (size_t j = 1; j < n; j++)
			{
				if (j!=i)
				{
					num *= a[j];
				}
			}
			res[i] = num;
		}
		return res;
	}
};

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	Solution s;
	s.constructArr(v);

	return 0;
}
