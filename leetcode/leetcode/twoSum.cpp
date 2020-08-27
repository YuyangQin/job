#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) 
	{
		string sum;
		//根据长度保存字符串
		string longer;
		string shorter;
		//保存进位数
		int up = 0;
		//暂存加法结果
		string temp;
		//保存较短的数的长度
		int length;
		if (a.size()>b.size())
		{
			length = b.size();
			longer = a;
			shorter = b;
		}
		else
		{
			length = a.size();
			longer = b;
			shorter = a;
		}
		for (int i = 0; i <longer.size(); i++)
		{
			if (i<length)
			{
				if (up == 0)
				{
					temp = myAdd((longer[longer.size() - 1 - i]), shorter[length - 1 - i], up);
					sum.insert(0, temp);
				}
				else
				{
					temp = myAdd((longer[longer.size() - 1 - i]), shorter[length - 1 - i], up);
					if (up == 1)
					{
						sum.insert(0, "1");
					}
					else
					{
						temp = myAdd(temp[0], '1', up);
						sum.insert(0, temp);
					}
				}
			}
			else
			{
				if (up == 0)
				{
					temp = myAdd((longer[longer.size() - 1 - i]), '0', up);
					sum.insert(0, temp);
				}
				else
				{
					temp = myAdd((longer[longer.size() - 1 - i]), '0', up);
					if (up == 1)
					{
						sum.insert(0, "1");
					}
					else
					{
						temp = myAdd(temp[0], '1', up);
						sum.insert(0, temp);
					}
				}
			}
		}
		if (up == 1)
		{
			sum.insert(0, "1");
		}
		return sum;
	}
	string myAdd(char c1, char c2,int &up)
	{
		up = 0;
		if ((c1=='1')&&(c2=='1'))
		{
			up = 1;
			return "0";
		}
		else if((c1 == '0') && (c2 == '0'))
		{
			return "0";
		}
		else
		{
			return "1";
		}
	}
};

void main()
{
	string s;
	string a1 = "101";
	string a2 = "111";

	Solution sol;
	s = sol.addBinary(a1, a2);
	cout << s << endl;
}