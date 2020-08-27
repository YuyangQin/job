#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1==NULL||l2==NULL)
		{
			if (l1 == NULL)
				return l2;
			return l1;
		}
		ListNode* res,*tmp;
		if (l1->val <= l2->val)
		{
			res = tmp = l1;
			l1 = l1->next;
		}	
		else
		{
			res = tmp = l2;
			l2 = l2->next;
		}
		while (l1 != NULL&&l2 != NULL)
		{	
			if (l1->val <= l2->val)
			{
				res->next  = l1;
				l1 = l1->next;
			}
			else
			{
				res->next = l2;
				l2 = l2->next;
			}
			res = res->next;
		}
		if (l1 == NULL)
			res->next = l2;
		else
			res->next = l1;

		return tmp;
	}
};

void main()
{
	Solution s;
	ListNode* head = &ListNode(1);
	head->next = &ListNode(2);
	head->next->next = &ListNode(3);
	head->next->next->next = &ListNode(4);
	cout << s.mergeTwoLists(head,NULL)->val<< endl;
}