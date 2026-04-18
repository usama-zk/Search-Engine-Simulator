#pragma once
#include"TrieNode.h"
#include<list>

class Trie {
	TrieNode* Root;
public:
	Trie();

	void insert(std::string r, std::string file);

	std::list<std::hash_map<std::string, int>> search(std::string r);

	void del(std::string r);
};
