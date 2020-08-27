#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//双指针法
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> res;
		vector<int> tmp;

		for (int left = 1,right=2;left<right;)
		{
			int sum = (left + right) * (right - left + 1) / 2;
			if (sum == target)
			{
				for (size_t i = left; i <= right; i++)
				{
					tmp.push_back(i);
				}
				res.push_back(tmp);
				tmp.clear();
				left++;
			}
			else if(sum<target)
			{
				right++;
			}
			else
			{
				left++;
			}
		}
		
		return res;
	}
};

//枚举法
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> vec;
		vector<int> res;
		int sum = 0, limit = (target - 1) / 2; // (target - 1) / 2 等效于 target / 2 下取整
		for (int i = 1; i <= limit; ++i) {
			for (int j = i;; ++j) {
				sum += j;
				if (sum > target) {
					sum = 0;
					break;
				}
				else if (sum == target) {
					res.clear();
					for (int k = i; k <= j; ++k) res.emplace_back(k);
					vec.emplace_back(res);
					sum = 0;
					break;
				}
			}
		}
		return vec;
	}
};

int main()
{

	return 0;
}
