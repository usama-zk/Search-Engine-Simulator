#pragma once

#include<string>
#include<queue>
#include<stack>
#include<list>
#include<algorithm>

struct Node {
	std::string val;
	std::list<std::string> s;
public:
	Node();

	Node(std::string c);

	char operator==(Node a);
};

inline Node::Node()
{
	val = std::string();
}

inline Node::Node(std::string c) : val(c) {}

inline char Node::operator==(Node a)
{
	if (a.val == val)
		return true;

	return false;
}




class Graph_list {
	std::list<Node> start;

public:

	//void operator==(char a);

	void insert_vertix(std::string s);

	void insert_edge(std::string source, std::string destination);

	void del_vertix(std::string s);

	void del_egde(std::string source, std::string destination);

	bool Graphisempty();

	int vertex_num();

	int edge_num();

	bool edge_exist(std::string a, std::string b);

	bool vertex_exist(std::string a);

	std::string shortest_path(std::string source, std::string destination);
	void display_graph() const;
};