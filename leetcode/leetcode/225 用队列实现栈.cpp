#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
	queue<int> data_queue;
	queue<int> tmp_queue;
	int topnum;
	MyStack() {

	}
	void push(int x) {
		data_queue.push(x);
		topnum = x;
	}
	int pop() {
		while (data_queue.size()>1)
		{
			tmp_queue.push(data_queue.front());
			topnum = data_queue.front();
			data_queue.pop();
		}
		int ret = data_queue.front();
		data_queue.pop();
		swap(data_queue, tmp_queue);
		return ret;
	}
	int top() {
		return topnum;
	}
	bool empty() {
		return data_queue.empty();
	}
};

int main()
{

	return 0;
}
