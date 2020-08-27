#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> printNumbers(int n) {
		vector<int> v;
		int num = pow(10, n);
		v.resize(num);
		n = n - 1;
		int num2 = pow(10, n);
		for (int i = 1; i < 10; i++)
		{
			v[i-1] = i;
			v[10 * i-1] = 10 * i;
			for (int j = 1; j < num2; j++)
				v[i + j * 10-1] = i + j * 10;
		}
		return v;
	}
};

void myPrint(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
		if (i%10==9)
		{
			cout << endl;
		}
	}
}

void main()
{
	Solution s;
	vector<int> v = s.printNumbers(2);
	myPrint(v);
}