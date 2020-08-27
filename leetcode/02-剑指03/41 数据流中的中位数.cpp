#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {
		
	}

	void addNum(int num) {
		if (lessPart.empty())
			lessPart.push(num);
		//Èç¹ûgPÎª¿Õ
		else if (greaterPart.empty())
		{
			if (num < lessPart.top())
			{
				greaterPart.push(lessPart.top());
				lessPart.pop();
				lessPart.push(num);
			}
			else
				greaterPart.push(num);
		}

		else if(lessPart.size()==greaterPart.size())
		{
			if (num>greaterPart.top())
			{
				lessPart.push(greaterPart.top());
				greaterPart.pop();
				greaterPart.push(num);
			}
			else
			{
				lessPart.push(num);
			}
		}
		else
		{
			if (num>=lessPart.top())
			{			
				greaterPart.push(num);
			}
			else
			{
				greaterPart.push(lessPart.top());
				lessPart.pop();
				lessPart.push(num);
			}
		}
	}

	double findMedian() {
		double res = 0;
		if (lessPart.empty())
		{
			return 0;
		}
		if (lessPart.size() == greaterPart.size())
		{
			res = (lessPart.top() + greaterPart.top()) / 2.0;
		}
		else
		{
			res = lessPart.top();
		}
		return res;
	}
	priority_queue<int> lessPart;
	priority_queue<int, vector<int>, greater<int> >greaterPart;
};

int main()
{
	MedianFinder m;

	m.addNum(1);
	m.addNum(2);
	cout << m.findMedian() << endl;
	m.addNum(3);
	cout << m.findMedian() << endl;


	return 0;
}
