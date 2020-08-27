#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:	
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string tmp = "";
		dfs(n, n, tmp, res);
		return res;
	}
	void dfs(int left, int right, string tmp, vector<string>& res)
	{
		if (left==0&&right==0)
		{
			res.push_back(tmp);
			return;
		}
		if (left>0)
			dfs(left-1, right, tmp+'(', res);
		if (left<right)
		{
			dfs(left, right - 1, tmp + ')', res);
		}		
	}
};
int main()
{
	Solution s;
	vector<string> v;
	v =s.generateParenthesis(3);
	for (auto it:v)
		cout << it << endl;

	return 0;
}
