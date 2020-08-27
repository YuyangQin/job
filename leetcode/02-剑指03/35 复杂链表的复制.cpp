#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	//使用unordered_map 哈希表 实现
	Node* copyRandomList(Node* head) {
		if (head == NULL)
			return NULL;
		unordered_map<Node*, Node*> map1;
		Node* tmp = head;
		while (tmp != NULL)
		{
			map1[tmp] = new Node(tmp->val);
			tmp = tmp->next;
		}
		tmp = head;
		while (tmp != NULL)
		{
			if (tmp->next != NULL)		//没必要判断，因为默认是空指针
				map1[tmp]->next = map1[tmp->next];
			if (tmp->random != NULL)	//没必要判断，因为默认是空指针
				map1[tmp]->random = map1[tmp->random];
			tmp = tmp->next;
		}
		return map1[head];
	}
	Node* copyRandomList1(Node* head) {
		if (head==NULL)
			return NULL;
		int i = 1;
		map<int, Node*> map1;
		map<Node*, int> map2;
		Node* myHead = new Node(head->val);
		map1.insert(make_pair(0, myHead));
		map2.insert(make_pair(head, 0));
		Node* tmp = myHead;
		Node* tmpHead = head;
		while (head->next!=NULL)
		{
			head = head->next;		
			myHead->next = new Node(head->val);
			myHead = myHead->next;
			map2.insert(make_pair(head, i));
			map1.insert(make_pair(i, myHead));
			i++;
		}
		Node* res= tmp;
		while (tmp!=NULL)
		{
			if (tmpHead->random != NULL)
			{
				tmp->random = map1.find(map2.find(tmpHead->random)->second)->second;
			}
			tmp = tmp->next;
			tmpHead = tmpHead->next;
		}
		return res;
	}	
};

void main()
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(2);
	head->next->next->random = head->next->next;
	Solution s;
	s.copyRandomList(head);
}