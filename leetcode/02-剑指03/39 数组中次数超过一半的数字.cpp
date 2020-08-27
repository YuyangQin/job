#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//Ä¦¶ûÍ¶Æ±·¨
	int majorityElement(vector<int>& nums) {
		int res = 0;
		int votes = 0;
		for (auto x:nums)
		{
			if (votes == 0)
				res = x;
			if (x == res)
				votes++;
			else
				votes--;
		}
		return res;
	}
	//ÅÅÐò
	int majorityElement2(vector<int>& nums) {
		if (nums.size() <= 2)
			return nums[0];
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2 + 1];
	}
//¹þÏ£±í
	int majorityElement1(vector<int>& nums) {
		if (nums.size() <= 2)
			return nums[0];
		int pos = 0;
		unordered_map<int, int> map1;
		vector<int> v;
		for (int i = 0; i < nums.size(); i++)
		{
			if (map1.find(nums[i]) == map1.end())
			{
				map1.insert(make_pair(nums[i], pos));
				pos++;
				v.push_back(1);
			}
			else
				v[map1[nums[i]]]++;
		}
		int more = 0;
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i] > v.size()/2)
			{
				more = i;
				break;
			}		
		}
		for (unordered_map<int, int>::iterator it = map1.begin(); it != map1.end(); it++)
		{
			if (it->second == more)
				return it->first;
		}
		return -1;
	}
};

void main()
{
	Solution s;
	vector<int> nums = { 6,5,5 };
	cout << s.majorityElement(nums) << endl;
}