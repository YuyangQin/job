#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minArray(vector<int>& numbers) {
		int mid;
		int i = 0, j = numbers.size() - 1;
		while (i<j)
		{
			mid = (i + j) / 2;
			if (numbers[mid] < numbers[j])
			{
				j = mid;
			}
			else if(numbers[mid] > numbers[j])
			{
				i = mid + 1;
			}
			else
			{
				j--;
			}
		}
		return numbers[i];
	}
};

void main()
{
	Solution s;
	vector<int> numbers = { 2,2,2,0,1 };
	cout << s.minArray(numbers) << endl;
}