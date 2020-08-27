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
	bool hasCycle(ListNode *head) {
		ListNode* fast=head;
		ListNode* slow=head;
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
			if (!fast)
			{
				return false;
			}
			fast = fast->next;
			if (fast==slow)
			{
				return true;
			}
		}
		return false;
	}
	ListNode *detectCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* meet = NULL;
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
			if (!fast)
			{
				return NULL;
			}
			fast = fast->next;
			if (fast == slow)
			{
				meet = fast;
				break;
			}
		}
		if (meet == NULL)
			return NULL;
		while (1)
		{
			if (head == meet)
				return head;
			head = head->next;
			meet = meet->next;
		}
		return NULL;
	}
};

int main()
{

	return 0;
}
