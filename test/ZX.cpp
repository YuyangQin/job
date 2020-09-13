#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct MyStr
{
	string str;
	int l;
	int r;
	MyStr() {  }
	MyStr(string s,int left,int right):str(s),l(left),r(right){}
};

//4
//A A A
//A A A
//B B B
//C C C
bool isGroup(vector<char>& c1, vector<char>& c2, vector<char>& c3)
{
	int count1 = 0;
	int count2 = 0;
	for (size_t i = 0; i < 3; i++)
	{
		if (c1[i] != c2[i] && c1[i] != c3[i] && c2[i] != c3[i])
			count1++;
		else if (c1[i] == c2[i] && c1[i] == c3[i])
		{
			count2++;
		}
		else
		{
			return false;
		}
	}
	return count1==3||count2==3;
}

void test01()
{
	int n;
	cin >> n;
	if (n<3)
	{
		cout << 0;
		return;
	}
	vector<vector<char>> pockers(n,vector<char> (3));

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			cin >> pockers[i][j];
		}
	}
	int count = 0;
	for (size_t i = 0; i < n-2; i++)
	{
		for (int j = i+1; j < n - 1; j++)
		{
			for (size_t k = j+1; k < n; k++)
			{
				if (isGroup(pockers[i],pockers[j],pockers[k]))
				{
					count++;
				}
			}
		}
	}
	cout << count;
}

//3 3
//9 1 9
//1 1 1
//9 1 9
void test02()
{
	static const int dx[4] = {-1,1,0,0};
	static const int dy[4] = {0,0,-1,1};
	int m, n;
	cin >> m >> n;

	vector<vector<int>> nums(n,vector<int> (m));
	for (size_t i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> nums[i][j];
		}
	}
	int res = 0;
	int sum;
	for (size_t i = 1; i < n-1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			sum = nums[i][j];
			for (size_t k = 0; k < 4; k++)
			{
				sum += nums[i + dx[k]][j + dy[k]];
			}
		}
		if (sum>res)
		{
			res = sum;
		}
	}
	cout << res;
}

void test2()
{
	//字符哈希
	int numMap[128];
	//字符哈希初始化
	//数字部分
	for (int i = 0; i <= 9; i++)
	{
		numMap[i + '0'] = i;
	}
	//英文字母部分
	for (int i = 0; i < 26; i++)
	{
		numMap['A' + i] = 10 + i;
	}

	int N;
	cin >> N;

	//输入并保存数据数组
	vector<MyStr> strVec(N);
	string temp;
	int left;
	int right;
	for (int i = 0; i < N; i++)
	{
		cin >> temp >> left >> right;
		strVec[i]=MyStr(temp, left, right);

	}

	int tempNum;	//转化为10进制的数
	char strLast;	//最后一个字符
	int strLen;		//字符串长度
	for (size_t i = 0; i < N; i++)
	{
		tempNum = 0;
		temp = strVec[i].str;
		left = strVec[i].l;
		right = strVec[i].r;
		strLen = temp.size();
		for (int j = left; j <= right; j++)
		{
			//若为偶，只需计算最后一位
			if (j%2==0)
			{
				tempNum += numMap[temp.back()];
				continue;
			}
			//若为奇，则正常计算
			for (int k = 0; k < strLen; k++)
			{
				tempNum += numMap[temp[k]] * pow(j, k);
				tempNum %= 2;
			}
		}
		cout << tempNum % 2 << endl;
	}
}

int main()
{
	test01();

	return 0;
}
