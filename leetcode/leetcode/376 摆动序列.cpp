#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size()<2)
		{
			return nums.size();
		}
		const int BeginState = 0;
		const int UpState = 1;
		const int DownState = 2;
		int State = BeginState;
		int count = 1;
		int n = nums.size();
		for (size_t i = 1; i < n; i++)
		{
			switch (State)
			{
			case BeginState:
				if (nums[i-1]<nums[i])
				{
					State = UpState;
					count++;
				}
				if (nums[i - 1]>nums[i])
				{
					State = DownState;
					count++;
				}
				break;
			case UpState:
				if (nums[i - 1]>nums[i])
				{
					State = DownState;
					count++;
				}
				break;
			case DownState:
				if (nums[i - 1]<nums[i])
				{
					State = UpState;
					count++;
				}
				break;
			}
		}	
		return count;
	}
};


int main()
{

	return 0;
}
