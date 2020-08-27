#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> myStack;
	stack<int> minStack;
	MinStack() {

	}

	void push(int x) {
		myStack.push(x);
		if (minStack.empty() || minStack.top() >= x)
			minStack.push(x);
	}

	void pop() {
		if (myStack.top() == minStack.top())
			minStack.pop();
		myStack.pop();
	}

	int top() {
		return myStack.top();
	}

	int min() {
		if (minStack.empty())
			return{};
		return minStack.top();
	}
};

class MinStack1 {
public:
	/** initialize your data structure here. */
	typedef struct STACKNODE
	{
		struct STACKNODE* next;
		int data;		
	}StackNode;
	typedef struct MYSTACK
	{
		StackNode top;
		int size;
	} MyStack;

	MinStack() {
		stack = new MyStack;
		stack->top.next = NULL;
		stack->size = 0;
	}
	void push(int x) {
		if (stack->size==0)
			stack->top.data = x;
		else
		{
			StackNode* tmp = new StackNode;
			tmp->next = &stack->top;
			tmp->data = x;
			stack->top = *tmp;
		}
		stack->size++;
	}

	void pop() {
		if (stack->size == 0)
			return;
		stack->top = *stack->top.next;
		stack->size--;
	}

	int top() {
		if (stack->size == 0)
			return{};
		return stack->top.data;
	}

	int min() {
		if (stack->size == 0)
			return{};
		if (stack->size == 1)
			return stack->top.data;
		int min = stack->top.data;
		StackNode tmp = stack->top;
		for (int i = 0; i < stack->size-1; i++)
		{
			if (tmp.next->data < min)
				min = tmp.next->data;
			tmp = *tmp.next;
		}
		return min;
	}
	MyStack* stack;
};

void main()
{
	MinStack m;
}