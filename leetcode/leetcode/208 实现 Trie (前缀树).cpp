#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define MAX 26

struct TrieNode
{
	TrieNode* child[MAX];
	bool is_end;
	TrieNode()
	{
		is_end = false;
		for (size_t i = 0; i < MAX; i++)
		{
			child[i] = 0;
		}
	}
};

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* tmp = root;
		for (size_t i = 0; i < word.size(); i++)
		{
			int pos = word[i] - 'a';
			if (!tmp->child[pos])
			{
				tmp->child[pos] = new TrieNode;
			}
			tmp = tmp->child[pos];
		}
		tmp->is_end = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* tmp = root;
		for (size_t i = 0; i < word.size(); i++)
		{
			int pos = word[i] - 'a';
			if (!tmp->child[pos])
			{
				return false;
			}
			tmp = tmp->child[pos];
		}
		return tmp->is_end;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* tmp = root;
		for (size_t i = 0; i < prefix.size(); i++)
		{
			int pos = prefix[i] - 'a';
			if (!tmp->child[pos])
			{
				return false;
			}
			tmp = tmp->child[pos];
		}
		return true;
	}
	TrieNode* root;
};

int main()
{

	return 0;
}
