#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

void ShellSort(vector<int>& nums)
{
	int k, j;
	int temp=-1;
	int gap = nums.size();
	do
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < gap; ++i)
		{
			for ( j = i+gap; j <nums.size() ; j+=gap)
			{
				temp = nums[j];
				for (k = j; (k >=gap) &&(nums[k-gap]>temp); k-=gap)
				{
					nums[k] = nums[k-gap];
				}
				nums[k] = temp;
			}
		}
	} while (gap>1);
}


void main2()
{
	vector<int> nums = { 4,5,3,6,2,1,0,9 };
	ShellSort(nums);
	for (auto it : nums)
		cout << it << " ";
	cout << endl;
}
