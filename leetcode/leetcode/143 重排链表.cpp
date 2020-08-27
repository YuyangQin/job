#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head==NULL||head->next==NULL)
			return;
		int isEven = 0;
		ListNode* cur = head;
		stack<ListNode*> even;
		while (cur !=NULL)
		{
			isEven++;
			if (isEven%2==0)
			{
				even.push(cur);
			}
			cur = cur->next;
		}
		ListNode* tmp = head;
		ListNode* tmpNext;
		while (even.size()>=2)
		{
			tmpNext = tmp->next->next;
			tmp->next = even.top();
			tmp->next->next = tmpNext;
			tmp = tmpNext;
			even.pop();
		}
		tmp->next = even.top();
		tmp->next->next = NULL;
	}
};

int main()
{
	ListNode l6(6);
	ListNode l5(5, &l6);
	ListNode l4(4, &l5);
	ListNode l3(3, &l4);
	ListNode l2(2, &l3);
	ListNode l1(1, &l2);

	Solution s;
	s.reorderList(&l1);

	return 0;
}
