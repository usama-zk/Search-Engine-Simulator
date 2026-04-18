#pragma once

#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
#include<hash_map>
#include<vector>
#include<string>

struct TrieNode {
	char val;
	TrieNode* next[62];
	std::hash_map<std::string, int> inverse_index;

	TrieNode();
	TrieNode(char v);
};
