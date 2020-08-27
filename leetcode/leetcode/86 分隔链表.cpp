#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode lessHead(0);
		ListNode moreHead(0);
		ListNode* lessend = &lessHead;
		ListNode* moreend = &moreHead;
		while (head)
		{
			if (head->val < x)
			{
				lessend->next = head;
				lessend = head;
			}
			else
			{
				moreend->next = head;
				moreend = head;
			}
			head = head->next;
		}
		lessend->next = moreHead.next;
		moreend->next = NULL;
		return lessHead.next;
	}
};

int main()
{

	return 0;
}
