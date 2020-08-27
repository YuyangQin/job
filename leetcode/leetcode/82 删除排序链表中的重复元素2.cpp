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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* cur = head;
		if (head->val == head->next->val)
		{
			while (cur->next != NULL&&cur->val == cur->next->val)
			{
				cur = cur->next;
			}
			return deleteDuplicates(cur->next);
		}
		else
			head->next = deleteDuplicates(head->next);
		
		return head;
	}
};

int main82()
{

	return 0;
}
