#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution1 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* tmp = head;
		while (tmp != NULL&&tmp->next != NULL)
		{
			if (tmp->val == tmp->next->val)
				tmp->next = tmp->next->next;
			else
				tmp = tmp->next;
		}
		return head;
	}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		head->next = deleteDuplicates(head->next);
		if (head->val == head->next->val) {
			return head->next;
		}
		return head;
	}
};

int main()
{

	return 0;
}
