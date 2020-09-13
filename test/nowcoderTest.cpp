#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

void test1()
{
	vector<string> pockers(4);
	unordered_map<string, int> pockermap;
	for (int i = 2; i <= 10; i++)
	{
		pockermap[to_string(i)] = i;
	}
	pockermap["J"] = 11;
	pockermap["Q"] = 12;
	pockermap["K"] = 13;
	pockermap["A"] = 1;
	int flag = 0;
	for (size_t i = 0; i < 4; i++)
	{
		cin >> pockers[i];
		if (pockers[i].compare("jocker")==0|| pockers[i].compare("JOCKER") == 0)
		{
			flag = -1;
		}
	}
	if (flag==-1)
	{
		cout << "ERROR" << endl;
		return;
	}

}
//void dfs(vector<string>& pockers, int index, int res, string tmpstr,int &flag,char cacul)
//{
//	if (index>3||flag==1)
//	{
//		return;
//	}
//	if (index==3)
//	{
//		if (cacuStr(tmpstr) ==24)
//		{
//			flag = 1;
//			cout << tmpstr << endl;
//		}
//		return;
//	}
//	tmpstr +=pockers[index] +=cacul;
//	dfs(pockers, index + 1, res, tmpstr, flag, '+');
//	dfs(pockers, index + 1, res, tmpstr, flag, '-');
//	dfs(pockers, index + 1, res, tmpstr, flag, '*');
//	dfs(pockers, index + 1, res, tmpstr, flag, '/');
//}
//int cacuStr(string str)
//{
//	return 0;
//}

void test2(int n)
{	
	vector<int> buildings(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> buildings[i];
	}
	int max = 0;
	int left = 0;
	int right = 0;
	int j;
	for (int i = 0; i < n; i++)
	{
		left = 0;
		right = 0;
		j = i - 1;
		while (j >= 0 && buildings[j] < buildings[i])
		{
			left++;
			j--;
		}
			
		j = i + 1;
		while (j < n && buildings[j] < buildings[i])
		{
			right++;
			j++;
		}
		if ((left+right)>max)
		{
			max = left + right;
		}
	}
	cout << max << endl;
}

int main()
{
	int n;
	while (cin>>n)
	{
		test2(n);
	}
	

	return 0;
}


