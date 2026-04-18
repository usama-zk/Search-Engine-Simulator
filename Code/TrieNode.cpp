#include"Trie.h"

TrieNode::TrieNode() : val(char())
{
	for (int i = 0; i < 62; i++) {
		next[i] = nullptr;
	}
}

TrieNode::TrieNode(char v) : val(v)
{
	for (int i = 0; i < 62; i++) {
		next[i] = nullptr;
	}
}
