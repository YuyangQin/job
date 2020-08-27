#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int val;
	vector<Node*> adjcent;
	Node(int x) :val(x) {}
};

//广度优先遍历
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if (prerequisites.size()<2)
		{
			return true;
		}
		vector<Node*> node_list;
		vector<int> in_degree(numCourses,0);
		for (size_t i = 0; i < numCourses; i++)
		{
			node_list.push_back(new Node(i));
		}
		for (size_t i = 0; i < prerequisites.size(); i++)
		{
			Node* begin = node_list[prerequisites[i][1]];
			Node* end = node_list[prerequisites[i][0]];
			begin->adjcent.push_back(end);
			in_degree[end->val]++;
		}
		queue<Node*> Q;
		for (size_t i = 0; i < numCourses; i++)
		{
			if (in_degree[i] == 0)
			{
				Q.push(node_list[i]);
			}
		}
		while (!Q.empty())
		{
			Node* tmp = Q.front();
			Q.pop();
			for (size_t i = 0; i < tmp->adjcent.size(); i++)
			{
				in_degree[tmp->adjcent[i]->val]--;
				if (in_degree[tmp->adjcent[i]->val] == 0)
					Q.push(tmp->adjcent[i]);
			}
		}

		for (int i = 0; i<numCourses; i++)
		{
			delete node_list[i];
		}

		for (size_t i = 0; i < numCourses; i++)
		{
			if (in_degree[i])
				return false;
		}

		return true;
	}
};

//深度优先遍历
class Solution1 {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if (prerequisites.size()<2)
		{
			return true;
		}
		vector<Node*> node_list;
		vector<int> visited;
		for (size_t i = 0; i < numCourses; i++)
		{
			node_list.push_back(new Node(i));
			visited.push_back(-1);
		}
		for (size_t i = 0; i < prerequisites.size(); i++)
		{
			Node* begin = node_list[prerequisites[i][1]];
			Node* end = node_list[prerequisites[i][0]];
			begin->adjcent.push_back(end);
		}
		for (size_t i = 0; i < numCourses; i++)
		{
			if (visited[i] == -1 && !DFS(node_list[i], visited))
			{
				return false;
			}
		}
		for (int i = 0; i<numCourses; i++)
		{
			delete node_list[i];
		}

		return true;
	}
	bool DFS(Node* node, vector<int>& visited)
	{
		visited[node->val] = 0;
		for (size_t i = 0; i < node->adjcent.size(); i++)
		{
			if (visited[node->adjcent[i]->val] == -1)
			{
				if (DFS(node->adjcent[i], visited) == 0)
					return false;
			}
			else if (visited[node->adjcent[i]->val] == 0)
			{
				return false;
			}
		}
		visited[node->val] = 1;
		return true;
	}
};

int main()
{
	vector<vector<int>> prerequisites = { {1,0},{2,1} };
	Solution s;
	cout << s.canFinish(3, prerequisites) << endl;

	return 0;
}
