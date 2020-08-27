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
	ListNode* deleteNode(ListNode* head, int val) {
		ListNode* tmphead = head;
		ListNode* pre = NULL;
		while (tmphead)
		{
			if (tmphead->val == val)
			{
				if (pre == NULL)
					return head->next;
				else
				{
					pre->next = tmphead->next;
					return head;
				}
			}
			pre = tmphead;
			tmphead = tmphead->next;
		}
		return head;
	}
};

void main()
{
	Solution s;
	ListNode* head = &ListNode(4);
}