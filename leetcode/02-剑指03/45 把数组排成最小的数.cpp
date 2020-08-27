#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


struct MyCompare
{
	bool operator()(string s1, string s2)
	{
		return (s1 + s2) < (s2 + s1);
	}
};


//方法使用错误，因为字符串比较时就是按每个位置顺序比较的
struct MyCompare02
{
	bool operator()(int c1, int c2)
	{
		string s1 = to_string(c1);
		string s2 = to_string(c2);
		if (s1.size() == s2.size())
		{
			return c1 < c2;
		}
		else
		{
			int i = 0, j = 0;
			while (s1[i] == s2[j] && i < s1.size() && j < s2.size())
			{
				if (i < s1.size() - 1)
					i++;
				j++;
			}
			if (s1[i] <= s2[j])
				return false;
			else
				return true;
		}
		return false;
	}
};

class Solution {
public:
	string minNumber(vector<int>& nums) {
		vector<string> s;
		string res;
		for (int i = 0; i < nums.size(); i++)
			s.push_back(to_string(nums[i]));
		sort(s.begin(), s.end(), [](string&s1, string&s2) {return s1 + s2 < s2 +s1; });

		for (auto it : s)
			res += it;
		return res;
	}
};

void main()
{
	Solution s;
	vector<int> nums = { 3,30,34,9,35 };
	string res = s.minNumber(nums);
	cout << res << endl;
}