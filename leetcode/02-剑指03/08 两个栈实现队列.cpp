#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class CQueue {
public:
	CQueue() {

	}

	void appendTail(int value) {
		while (!rs.empty())
		{
			s.push(rs.top());
			rs.pop();
		}
		rs.push(value);
		while (!s.empty())
		{
			rs.push(s.top());
			s.pop();
		}
	}

	int deleteHead() {
		if (rs.empty())
		{
			return -1;
		}
		//·µ»ØÖµ
		int temp = rs.top();
		rs.pop();

		return temp;
	}
	stack<int> s;
	stack<int> rs;
};

/**
* Your CQueue object will be instantiated and called as such:
* CQueue* obj = new CQueue();
* obj->appendTail(value);
* int param_2 = obj->deleteHead();
*/


void main()
{
	CQueue q;
	/*q.appendTail(3);
	cout << q.deleteHead() << endl;*/
	//cout << q.deleteHead() << endl;
	//q.appendTail(5);
	q.appendTail(6);
	cout << q.deleteHead() << endl;
	cout << q.deleteHead() << endl;
	
}