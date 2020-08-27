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

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode;
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
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

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return trieSearch(word, 0, root);
	}
	bool trieSearch(string& word, int index, TrieNode* node)
	{
		if (index == word.size())
		{
			return node->is_end;
		}
		if (word[index] == '.')
		{
			for (size_t i = 0; i < MAX; i++)
			{
				if (node->child[i])
				{
					if (trieSearch(word, index + 1, node->child[i]))
					{
						return true;
					}
				}
			}
		}
		else
		{
			int pos = word[index] - 'a';
			if (!node->child[pos])
			{
				return false;
			}
			else
			{
				return trieSearch(word, index + 1, node->child[pos]);
			}
		}
		return false;
	}
	TrieNode* root;
};

int main()
{
	string word = "bad";
	WordDictionary* obj = new WordDictionary();
	obj->addWord("bad");
	obj->addWord("dad");
	obj->addWord("mad");
	cout << obj->search("pad") << endl;
	cout << obj->search("bad") << endl;
	cout << obj->search(".ad") << endl;
	cout << obj->search("b..") << endl;

	return 0;
}
