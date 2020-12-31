#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int begin = 1;
		int end = n;
		int mid = begin - (begin - end) / 2;
		while (true)
		{
			if (isBadVersion(mid) && !isBadVersion(mid - 1))
			{
				return mid;
			}
			else if (isBadVersion(mid))
			{
				end = mid;
			}
			else
			{
				begin = mid+1;
			}
		}
	}
};

int main()
{

	return 0;
}
