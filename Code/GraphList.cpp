#include "Graph_list.h"
#include<iostream>
#include <unordered_map>
using namespace std;
void Graph_list::insert_vertix(std::string s)
{
	auto it = find(start.begin(), start.end(), s);
	if (it != start.end()) return;
	start.push_back(s);
}

void Graph_list::insert_edge(std::string source, std::string destination)
{
	auto it_s = find(start.begin(), start.end(), source);
	auto it_d = find(start.begin(), start.end(), destination);

	if (it_s == start.end() || it_d == start.end()) return;        // 3

	it_s->s.push_back(destination);                  // 1                  
}

void Graph_list::del_vertix(std::string s)
{
	auto it = find(start.begin(), start.end(), s);

	if (it == start.end()) return;

	start.erase(it, next(it));

	auto it_s = start.begin();

	while (it_s != start.end()) {
		if (find(it_s->s.begin(), it_s->s.end(), s) != it_s->s.end()) {
			it_s->s.remove(s);
		}
		it_s++;
	}
}

void Graph_list::del_egde(std::string source, std::string destination)
{
	auto it_s = find(start.begin(), start.end(), source);
	auto it_d = find(start.begin(), start.end(), destination);

	if (it_s == start.end() || it_d == start.end()) return;

	it_s->s.remove(destination);
}

bool Graph_list::Graphisempty()
{
	return start.size() == 0 ? true : false;
}

int Graph_list::vertex_num()
{
	return start.size();
}

int Graph_list::edge_num()
{
	int count = 0;
	for (auto val : start) {
		count += val.s.size();
	}
	return count;
}

bool Graph_list::edge_exist(std::string source, std::string destination)
{
	auto it_s = find(start.begin(), start.end(), source);
	auto it_d = find(start.begin(), start.end(), destination);

	if (it_s == start.end() || it_d == start.end()) return false;

	auto it_s_nei = find((*it_s).s.begin(), (*it_s).s.end(), destination);

	if (it_s_nei != (*it_s).s.end()) return true;

	return false;
}

bool Graph_list::vertex_exist(std::string a)
{
	auto it = find(start.begin(), start.end(), a);

	return it != start.end() ? true : false;
}

// should be an an BFS 
std::string Graph_list::shortest_path(std::string source, std::string destination) {
	std::unordered_map<std::string, std::string> predecessor;  // To store the path
	std::queue<std::string> myq;
	std::vector<std::string> seen;

	myq.push(source);
	seen.push_back(source);
	predecessor[source] = "";

	while (!myq.empty()) {
		std::string current_vertix = myq.front();
		myq.pop();

		if (current_vertix == destination) {
			std::string path = "";
			for (std::string at = destination; at != ""; at = predecessor[at]) {
				path = at +" -> " + path;
			}
			return path;
		}

		auto it = std::find(start.begin(), start.end(), current_vertix);
		if (it == start.end()) continue;

		for (const auto& neighbor : it->s) {
			if (std::find(seen.begin(), seen.end(), neighbor) == seen.end()) {
				seen.push_back(neighbor);
				myq.push(neighbor);
				predecessor[neighbor] = current_vertix;
			}
		}
	}
	return ""; // Return an empty string if no path is found
}


void Graph_list::display_graph() const {
	std::cout << "Vertices:\n";
	for (const auto& node : start) {
		std::cout << node.val << std::endl;
	}

	std::cout << "Edges:\n";
	for (const auto& node : start) {
		for (const auto& neighbor : node.s) {
			std::cout << node.val << " -> " << neighbor << std::endl;
		}
		cout << endl;
	}
}