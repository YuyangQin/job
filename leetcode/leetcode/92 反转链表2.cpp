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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head->next == NULL)
			return head;
		int length = n - m+1;//需要逆置节点个数
		ListNode* pre_head = NULL;//初始化开始逆置节点的前驱
		ListNode* new_nail = head;//最终转换后
		for (int i = 1; i < m; i++)
		{
			pre_head = new_nail;
			new_nail = new_nail->next;
		}
		ListNode* new_head = new_nail;
		ListNode* pre = new_nail;
		ListNode* next_nail=new_head->next;
		for (size_t i = 1; i < length; i++)
		{
			new_head = next_nail;
			next_nail = new_head->next;
			new_head->next = pre;
			pre = new_head;
		}
		new_nail->next = next_nail;
		if (m>1)
		{
			pre_head->next = new_head;
			return head;
		}
		else {
			return new_head;
		}
	}
};

int main()
{
	ListNode l1(1);
	ListNode l2(1);
	ListNode l3(1);
	ListNode l4(1);
	ListNode l5(1);

	ListNode* head = &l1;
	head->next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;

	return 0;
}
