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
	ListNode* reverseList(ListNode* head) {
		if (head == NULL||head->next==NULL)
			return head;
		
		return recur(head);
	}
	ListNode* recur(ListNode* head)
	{
		if (head->next == NULL)
			return head;
		ListNode* tmp = get(head);	
		
		tmp->next = recur(head);
		
		return tmp;
	}
	ListNode* get(ListNode* head)
	{
		ListNode* pre = head;
		ListNode* temp = head;
		temp = temp->next;
		while (temp->next!=NULL)
		{
			pre = pre->next;
			temp = temp->next;
		}
		pre->next = NULL;
		return temp;
	}
	ListNode* reverseList1(ListNode* head) {
		if (head==NULL)
			return head;
		vector<ListNode*> v;
		while (head!=NULL)
		{
			v.push_back(head);
			head = head->next;
		}
		head = v[v.size() - 1];
		for (int i = 1; i <v.size(); i++)
		{
			v[v.size() - i]->next = v[v.size() - i - 1];
		}
		v[0]->next = NULL;
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
	cout << s.reverseList(head)->val << endl;
}