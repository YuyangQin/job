#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};



class Solution {
public:
	Node* head, *pre;
	Solution()
	{
		head = new Node;
		pre = NULL;
	}
	Node* treeToDoublyList(Node* root) {
		if (root == NULL)
			return NULL;
		dfs(root);

		head->left = pre;
		pre->right = head;
		return head;
	}
	void dfs(Node* cur)
	{
		if (cur == NULL)
			return;
		dfs(cur->left);

		if (pre != NULL)
			pre->right = cur;
		else
			head = cur;
		cur->left = pre;
		pre = cur;

		dfs(cur->right);

	}

	Node* treeToDoublyList1(Node* root) {
		if (root == NULL||(root->left == NULL&&root->right == NULL))
			return root;
		Node tmp = *root;
		Node* ltmp = treeToDoublyList(root->left);
		if (ltmp != NULL)
		{
			root->right = ltmp;
			if (ltmp->left==NULL&&ltmp->right==NULL)
			{
				ltmp->right = root;
				root->left = ltmp;
			}
			else
			{
				ltmp->left->right = root;
				root->left = ltmp->left->right;
			}
			ltmp->left = root;
		}	

		Node* rtmp = treeToDoublyList(tmp.right);
		if (rtmp!=NULL)
		{
			
			if (ltmp == NULL)
			{
				tmp.right = rtmp;
				tmp.left = rtmp->left;
				rtmp->left->right = &tmp;
				rtmp->left = &tmp;
				return &tmp;
			}
			else
			{
				ltmp->left->right = rtmp;
				rtmp->left->right = ltmp;
				ltmp->left = rtmp->left;
				rtmp->left = root;
			}
		} 		
		return ltmp;
	}
};

void main()
{
	Node* node1 = &Node(1);
	Node* node3 = &Node(3);
	Node* node5 = &Node(5);
	Node* node2 = &Node(2, node1, node3);
	Node* root = &Node(4, node2, node5);

	Solution s;
	Node* tmp = s.treeToDoublyList(root);
	printf("%d\n", tmp->val);
}
