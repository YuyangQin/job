#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> tmp;
		int j = 0;
		for (auto x:pushed)
		{
			tmp.push(x);
			while (tmp.size()&&tmp.top()==popped[j])
			{
				tmp.pop();
				j++;
			}
		}
		return tmp.empty();
	}
	bool validateStackSequences1(vector<int>& pushed, vector<int>& popped) {
		if (pushed.empty())
			return true;
		stack<int> order;
		for (int i = 0; i < popped.size(); i++)
		{
			if (!order.empty()&&popped[i]==order.top())
				order.pop();
			else
			{
				int flag = 0;
				for (vector<int>::iterator it = pushed.begin(); it!=pushed.end(); it++)
				{
					if (*it==popped[i])
					{
						flag = 1;
						for (vector<int>::iterator mit = pushed.begin(); mit != it; mit++)
						{
							order.push(*mit);
						}
						pushed.erase(pushed.begin(), it + 1);
						break;
					}					
				}
				if (flag == 0)
					return false;
			}
		}
		return true;
	}
};

void main()
{
	Solution s;
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 4,5,3,2,1 };
	cout << s.validateStackSequences(v1, v2) << endl;
}