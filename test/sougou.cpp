#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct House
{
	int left;
	int right;
	House(){}
	House(int l,int r):left(l),right(r){}
};
bool compare(House& h1, House& h2)
{
	return h1.left < h2.left;
}
void test2()
{
	int neww,pos,width;
	vector<House> houses;
	while (cin>>neww)
	{
		//这里先不处理字符串
		while (cin >> pos >> width)
		{
			houses.push_back(House(pos - width / 2, pos + width / 2));
		}		
		if (houses.empty())
		{
			cout << 0 << endl;
			continue;
		}
		sort(houses.begin(), houses.end(), compare);
		int tmpleft = houses[0].left;
		int tmpright = houses[0].right;
		int count = 2;
		for (size_t i = 1; i < houses.size(); i++)
		{
			if (houses[i].left > tmpright)
			{
				if (houses[i].left-tmpright>neww)
				{
					count += 2;
				}
				else if(houses[i].left - tmpright==neww)
				{
					count += 1;
				}
				tmpleft = houses[i].left;
				tmpright = houses[i].right;
			}
		}
		cout << count << endl;
	}
	
}

int main()
{
	test2();

	return 0;
}
