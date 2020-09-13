#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> kmpNext(string& substr)
{
	vector<int> next(substr.size(),0);
	int i = 1;
	int j = 0;
	int n = substr.size();
	for (; i < n; i++)
	{
		while (j>0&&substr[i]!=substr[j])
		{
			j = next[j - 1];
		}
		if (substr[i]==substr[j])
		{
			j++;
		}
		next[i] = j;
	}
	return next;
}

int kmpSearch(string& str, string& substr, vector<int>& next)
{
	int j,i;
	for (i = 0,j=0; i < str.size(); i++)
	{
		while (j>0&&str[i]!=substr[j])
		{
			j = next[j - 1];
		}
		if (str[i] == substr[j])
			j++;
		if (j == substr.size())
			return i - j + 1;
	}
	return -1;
}

int main3()
{
	vector<int> next;
	string substr("abcabd");
	string str("abcabcabd");
	next = kmpNext(substr);
	
	int n = kmpSearch(str, substr, next);
	cout << n << endl;
	return 0;
}
