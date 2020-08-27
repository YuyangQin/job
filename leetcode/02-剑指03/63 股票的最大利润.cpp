#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	//方法二：动态规划
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n <= 1)
		{
			return 0;
		}
		int minum = prices[0];
		int price = 0;
		for (size_t i = 1; i < n; i++)
		{
			if (prices[i]<minum)
			{
				minum = prices[i];
			}
			price = max(price, prices[i] - min(prices[i], minum));
		}
		return 
	}
	//方法一
	int maxProfit1(vector<int>& prices) {
		int n = prices.size();
		if (n <= 1)
		{
			return 0;
		}
		int min = prices[0];
		int max = prices[0];
		int price = 0;
		for (size_t i = 1; i < n; i++)
		{
			if (prices[i]<min)
			{
				if (max - min>price)
					price = max - min;
				min = prices[i];
				max = min;
			}
			else if (prices[i]>max)
			{
				max = prices[i];
			}
		}
		return price>max - min ? price : max - min;
	}
};

int main()
{

	return 0;
}
