#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>

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
	Node* copyRandomList(Node* head) {
		unordered_map<Node*, int> nodeMap;
		vector<Node*> nodes;
		Node* ptr= head;
		int i = 0;
		while (ptr)
		{
			nodes.push_back(new Node(ptr->val));
			nodeMap.insert(make_pair(ptr, i));
			ptr = ptr->next;
			i++;
		}
		nodes.push_back(NULL);
		ptr = head;
		i = 0;
		while (ptr)
		{
			nodes[i]->next = nodes[i + 1];
			if (ptr->random)
			{
				int rdmid = nodeMap[ptr->random];
				nodes[i]->random = nodes[rdmid];
			}
			ptr = ptr->next;
			i++;
		}
		return nodes[0];
	}
};

int main()
{

	return 0;
}
