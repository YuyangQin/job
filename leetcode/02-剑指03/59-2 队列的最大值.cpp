#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <deque>

using namespace std;

class MaxQueue {
public:
	queue<int> data_queue;
	deque<int> max_queue;
	MaxQueue() {

	}

	int max_value() {
		if (data_queue.empty())
		{
			return -1;
		}
		return max_queue.front();
	}

	void push_back(int value) {
		data_queue.push(value);
		while (!max_queue.empty()&&max_queue.back()<value)
		{
			max_queue.pop_back();
		}
		max_queue.push_back(value);
	}

	int pop_front() {
		if (data_queue.empty())
		{
			return -1;
		}
		int tmp = data_queue.front();
		data_queue.pop();
		if (tmp==max_queue.front())
		{
			max_queue.pop_front();
		}
		return tmp;
	}
};

int main()
{

	return 0;
}
