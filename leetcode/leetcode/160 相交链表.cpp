#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lenA = getLen(headA);
		int lenB = getLen(headB);
		if (lenA> lenB)
			headA = moveForward(lenA, lenB, headA);
		else
			headB = moveForward(lenB, lenA, headB);
		while (headA&&headB)
		{
			if (headA == headB)
				return headA;
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}
	int getLen(ListNode *List)
	{
		int length = 0;
		while (List)
		{
			length++;
			List = List->next;
		}
		return length;
	}
	ListNode *moveForward(int longer, int shorter, ListNode *Listlonger)
	{
		int step = longer - shorter;
		while (Listlonger&&step)
		{
			Listlonger = Listlonger->next;
			step--;
		}
		return Listlonger;
	}
};

int main()
{

	return 0;
}
