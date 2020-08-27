#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
bool mycom(ListNode*l1, ListNode*l2)
{
	return l1->val < l2->val;
}
//∑Ω∑®“ª°¢≈≈–Ú
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
			return NULL;
		if (lists.size() == 1)
			return lists[0];
		if (lists.size() == 2)
		{
			return mergeTwoLists(lists[0], lists[1]);
		}

		int mid = (lists.size() - 1) / 2;
		vector<ListNode*> left;
		vector<ListNode*> right;

		for (size_t i = 0; i < mid; i++)
		{
			left.push_back(lists[i]);
		}
		for (size_t i = mid; i < lists.size(); i++)
		{
			right.push_back(lists[i]);
		}

		ListNode* l1 = mergeKLists(left);
		ListNode* l2 = mergeKLists(right);

		return mergeTwoLists(l1, l2);
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode tmp_head(0);
		ListNode* cur = &tmp_head;
		while (l1&&l2)
		{
			if (l1->val<l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		if (l1)
		{
			cur->next = l1;
		}
		if (l2)
		{
			cur->next = l2;
		}
		return tmp_head.next;
	}
};

int main()
{

	return 0;
}
