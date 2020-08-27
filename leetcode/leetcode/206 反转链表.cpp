#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

//迭代实现
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* newHead = NULL;
		while (head!=NULL)
		{
			ListNode* next= head->next;
			head->next = newHead;
			newHead = head;
			head = next;
		}
		return newHead;
	}
};

//递归实现
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* tmp = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return tmp;
	}
};

int main()
{

	return 0;
}
