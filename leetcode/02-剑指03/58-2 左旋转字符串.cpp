#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Solution {
public:
	string reverseLeftWords(string s, int n) {
		int length = s.size();
		int n = n%length;
		s.append(s.substr(0, n));
		s.erase(0, n);
		return s;
	}
};

int main()
{

	return 0;
}
