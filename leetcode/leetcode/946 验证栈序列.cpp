#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int N = pushed.size();
		stack<int> stack;

		int j = 0;
		for (int x : pushed) {
			stack.push(x);
			while (!stack.empty() && j < N && stack.top() == popped[j]) {
				stack.pop();
				j++;
			}
		}
		return j == N;
	}
}

int main()
{

	return 0;
}
