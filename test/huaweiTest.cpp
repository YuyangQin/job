#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <sstream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

using namespace std;

void test171()
{
	int n;
	vector<int> nums;
	while (cin >> n&&n != 0)
	{
		nums.push_back(n);
	}
	for (size_t i = 0; i < nums.size(); i++)
	{
		int count = 0;
		int bottles = nums[i];
		int new_bottle = 0;
		while (bottles / 3>0)
		{
			new_bottle = bottles / 3;
			count += new_bottle;
			bottles = bottles % 3 + new_bottle;
		}
		if (bottles == 2)
			count++;
		cout << count << endl;
	}
}
void test172()
{
	int n;
	int tmp;
	
	while (cin>>n)
	{
		set<int> myset;
		for (size_t i = 0; i < n; i++)
		{
			cin >> tmp;
			myset.insert(tmp);
		}
		for (auto& it : myset)
			cout << it << endl;
	}
	/*while (cin >> n)
	{
		int nums[1001] = { 0 };
		for (size_t i = 0; i < n; i++)
		{
			cin >> tmp;
			nums[tmp] = 1;
		}
		for (size_t i = 0; i <= 1000; i++)
		{
			if (nums[i])
				cout << i << endl;
		}
	}*/
}
void test173()
{
	static int nummap[128] = { 0 };
	for (int i = '0'; i <= '9'; i++)
	{
		nummap[i] = i-'0';
	}
	for (size_t i = 'A'; i <= 'F'; i++)
	{
		nummap[i] = 10 + i - 'A';
	}
	string str;
	while (cin >> str)
	{
		int res = 0;
		int bit = 0;
		for (size_t i = str.size() - 1; i >= 2; i--)
		{
			res += (nummap[str[i]] * pow(16, bit));
			bit++;
		}
		cout << res << endl;
	}	
}

void test161(int n)
{
	if (n>1000)
	{
		n = 1000;
	}
	vector<int> arr(n);
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = i;
	}
	int step=0;
	int i = 0;
	int count = n;
	while (count>0)
	{
		if (arr[i] != -1)
		{
			if (count == 1)
			{
				cout << arr[i] << endl;
				break;
			}
			step++;		
			if (step==3)
			{
				count--;
				step = 0;
				arr[i] = -1;
			}
			
		}
		i++;
		if (i >= n)
			i %= n;
	}
}
void test162()
{
	string str;
	cin >> str;
	int lettersMap[128] = { 0 };
	for (size_t i = 0; i < str.size(); i++)
	{
		if (lettersMap[str[i]]==0)
		{
			cout << str[i];
		}
		lettersMap[str[i]]=1;
	}
}

void test1611()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> grades(n);
		for (size_t i = 0; i < n; i++)
		{
			cin >> grades[i];
		}
		char command;
		int a, b;
		for (size_t i = 0; i < m; i++)
		{
			cin >> command;
			cin >> a >> b;
			if (command == 'U')
			{

				grades[a - 1] = b;
			}
			else if (command == 'Q')
			{
				int max = 0;
				if (a > b)
					swap(a, b);
				for (size_t i = a - 1; i < b; i++)
				{
					if (grades[i]>max)
					{
						max = grades[i];
					}
				}
				cout << max << endl;
			}
		}
	}	
}
void test1612()
{
	string str;
	while (getline(cin,str))
	{
		int blank = str.find(' ');
		string filenameP = str.substr(0, blank);
		string lineNum = str.substr(blank + 1, str.size() - blank-1);
		int pos=filenameP.rfind('\\');
		string filename = filenameP.substr(pos + 1, filenameP.size() - pos - 1);
		cout << filename << endl;
	}
}
void test1613()
{
	string str;
	unordered_map<string, int> pockermap;
	for (size_t i = 3; i <= 10; i++)
	{
		pockermap[to_string(i)] = i;
	}
	pockermap["J"] = 11;
	pockermap["Q"] = 12;
	pockermap["K"] = 13;
	pockermap["A"] = 14;
	pockermap["2"] = 15;
	pockermap["joker"] = 16;
	pockermap["JOKER"] = 16;
	while (getline(cin, str))
	{
		int blank = str.find('-');
		string pocker1 = str.substr(0, blank);
		string pocker2 = str.substr(blank + 1, str.size() - blank - 1);

		int bnum1 = count(pocker1.begin(), pocker1.end(), ' ');
		int bnum2 = count(pocker2.begin(), pocker2.end(),' ');

		int pos1 = pocker1.find(' ');
		int pos2 = pocker2.find(' ');

		string str1 = pocker1.substr(0, pos1);
		string str2 = pocker2.substr(0, pos2);
		if (bnum1 == bnum2)
		{
			if (pockermap[str1] > pockermap[str2])
				cout << pocker1 << endl;
			else
				cout << pocker2<<endl;
		}
		else
		{
			if (bnum1 == 1 && str1 == "joker")
				cout << pocker1 << endl;
			else if (bnum2 == 1 && str2 == "joker")
				cout << pocker2 << endl;
			else if (bnum1 == 3)
				cout << pocker1 << endl;
			else if (bnum2 == 3)
				cout << pocker2 << endl;
			else
				cout << "ERROR" << endl;
		}		
	}
}

void simulate1()
{
	int n;
	while (cin>>n)
	{
		char tmp = cin.get();
		cout << tmp;
	}
}

int main1()
{
	simulate1();
	

	return 0;
}


