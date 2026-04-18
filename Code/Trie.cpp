#include "Trie.h"

Trie::Trie()
{
	Root = new TrieNode();
}

void Trie::insert(std::string r, std::string file)
{
	TrieNode* current = Root;

	for (int i = 0; i < r.size(); i++) {
		if (int(r[i]) < 0) continue;
		bool isdig = isdigit(r[i]);

		int s;
		if (!isdig) {
			s = isupper(r[i]) ? 'Z' - r[i] + 26 : r[i] - 'a';
		}
		else {
			s = '0' - r[i];
		}

		if (r[i] == ' ' || ispunct(r[i]) || r[i] < 65) {
			if (current->inverse_index.find(file) == current->inverse_index.end()) {
				current->inverse_index[file] = 1;
			}
			else {
				current->inverse_index[file] += 1;
			}
			current = Root;
			continue;
		}

		if (current->next[s] == nullptr) {
			current->next[s] = new TrieNode(r[i]);
			current = current->next[s];
		}
		else {
			current = current->next[s];
		}
	}
	if (current->inverse_index.find(file) == current->inverse_index.end()) {
		current->inverse_index[file] = 1;
	}
	else {
		current->inverse_index[file] += 1;
	}
}

std::list<std::hash_map<std::string, int>> Trie::search(std::string r)
{
	std::list<std::hash_map<std::string, int>> freq_map;
	TrieNode* current = Root;
	for (int i = 0; i < r.size(); i++) {

		if (r[i] == ' ') {
			freq_map.push_back(current->inverse_index);
			current = Root;
			continue;
		}

		bool isdig = isdigit(r[i]);
		int s;

		if (!isdig) {
			s = isupper(r[i]) ? 'Z' - r[i] + 26 : r[i] - 'a';
		}
		else {
			s = '0' - r[i] + 52;
		}
		if (current->next[s] == nullptr) {
			return freq_map;
		}
		else {
			current = current->next[s];
		}
	}
	freq_map.push_back(current->inverse_index);
	return freq_map;
}

void Trie::del(std::string r)
{

}
