#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int bf(string t, string p)
{
	int i = 0;
	int j = 0;

	while (i<t.size()&&j<p.size())
	{
		if (t[i]==p[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (i <= t.size()&&j==p.size())
		return i - p.size();
	else
		return -1;

}

void main2()
{
	cout << bf("abcde", "e") << endl;
}