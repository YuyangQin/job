#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	//¹þÏ£±í
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> index;
		int n = nums.size();
		int comlement;
		for (int i = 0; i < n; i++)
		{
			comlement = target - nums[i];
			if (index.find(comlement) != index.end())
			{
				auto it = index.find(comlement);
				return vector<int> {it->second, i};
			}
			index.insert(make_pair(nums[i], i));
		}
		return{};
	}
	
	//Ë«Ö¸Õë+¹þÏ£
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		vector<pair<int, int>> index;
		int n = nums.size();
		for (size_t i = 0; i < n; i++)
		{
			index.push_back(make_pair(nums[i], i));
		}
		sort(index.begin(), index.end(), mycompare);
		int i = 0;
		int j = n - 1;
		while (i<j)
		{
			if (index[i].first + index[j].first==target)
			{
				res.push_back(index[i].second);
				res.push_back(index[j].second);
				break;
			}
			else if (index[i].first + index[j].first<target)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
		return res;
	}
	bool mycompare(pair<int, int>&p1, pair<int, int>&p2)
	{
		return p1.first < p2.first;
	}
};

int main()
{
	vector<int> nums = { 3,2,3 };
	Solution s;
	s.twoSum(nums, 6);

	return 0;
}
