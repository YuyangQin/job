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

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> v;
		if (head != NULL)
		{
			int size;
			int i = 0;
			ListNode* tmp = head;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
				i++;
			}
			i++;
			size = i;
			v.resize(size);
			v[0] = tmp->val;
			for (i = 0; i < size - 1; i++)
			{
				v[size - 1 - i] = head->val;
				head = head->next;	
			}
		}
		return v;
	}
};

void main()
{
	Solution s;
	ListNode l1 = ListNode(1);
	ListNode l2 = ListNode(2);
	ListNode l3 = ListNode(3);
	ListNode l4 = ListNode(4);
	ListNode l5 = ListNode(5);

	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;

	ListNode* head = &l1;

	vector<int> v= s.reversePrint(&l1);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i]<<" ";
	}
	cout << endl;
}