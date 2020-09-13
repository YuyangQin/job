#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

//哈希算法
int Hash(string str,int R,int K,int len,int j)
{
	int hash = 0;
	for (int i = 0; i < len; i++)
	{
		hash = R*hash + str[i+j] % K;
	}
	return hash;
}

//比较函数
bool match(string t,string p,int i)
{
	for (int j = 0; j < p.size(); j++)
	{
		if (t[i+j]!=p[j])
		{
			return false;
		}
	}
	return true;
}

int RK(string t, string p)
{
	int hashp = Hash(p, 26, 31, p.size(),0);
	for (int i = 0; i < t.size(); i++)
	{
		if (Hash(t,26,31,p.size(),i)==hashp&&match(t,p,i))
		{
			return i;
		}
	}
	return -1;
}

void main()
{
	cout << RK("abcde", "f") << endl;
}