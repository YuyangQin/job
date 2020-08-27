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
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* former = head;
		ListNode* latter = head;
		for (int i = 0; i < k; i++)
		{
			former = former->next;
		}
		while (former!=NULL)
		{
			former = former->next;
			latter = latter->next;
		}
		return latter;
	}
	int mynum = -1;
	ListNode* getKthFromEnd2(ListNode* head, int k) {
		mynum = k;
		return recur(head);
	}	
	ListNode* recur(ListNode* head) {
		if (head == NULL)
			return NULL;
		ListNode* tmp=recur(head->next);
		mynum--;
		if (mynum == 0)
			return head;
		if (mynum < 0)
			return tmp;
	}
	ListNode* getKthFromEnd1(ListNode* head, int k) {
		ListNode* tmp = head;
		int i = 0;
		while (tmp!=NULL)
		{
			tmp = tmp->next;
			i++;
		}
		int num = i - k;
		for (int j = 0; j < num; j++)
		{
			head = head->next;
		}
		return head;
	}
};



void main()
{
	Solution s;
	ListNode* head = &ListNode(1);	
	head->next = &ListNode(2);
	head->next->next = &ListNode(3);
	head->next->next->next = &ListNode(4);
	
	cout << s.getKthFromEnd(head, 1)->val << endl;
}