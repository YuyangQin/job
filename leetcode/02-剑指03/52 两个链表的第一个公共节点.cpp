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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lenA = 0;
		int lenB = 0;
		ListNode *tmpA = headA;
		ListNode *tmpB = headB;
		while (tmpA)
		{
			tmpA = tmpA->next;
			lenA++;
		}
		while (tmpB)
		{
			tmpB = tmpB->next;
			lenB++;
		}
		if (lenA>lenB)
		{
			headA = longerNode(lenA, lenB, headA);
		}
		else
		{
			headB = longerNode(lenB, lenA, headB);
		}
		while (headA&&headB)
		{
			if (headA == headB)
				return headA;
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}
	ListNode *longerNode(int longer, int shorter, ListNode *head)
	{
		int step = longer - shorter;
		while (step)
		{
			head = head->next;
			step--;
		}
		return head;
	}
};

int main()
{

	return 0;
}
