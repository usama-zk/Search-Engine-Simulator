#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include<Windows.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include "Graph_list.h" 


using namespace std;

void read_directory(const string& name, Graph_list& graph) {
    string pattern = name + "\\*";
    WIN32_FIND_DATAA data;
    HANDLE hFind = FindFirstFileA(pattern.c_str(), &data);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                string file_path = name + "\\" + data.cFileName;
                ifstream file(file_path);
                if (file.is_open()) {
                    string line;
                    while (getline(file, line)) {
                        size_t pos = 0;
                        graph.insert_vertix(data.cFileName);
                        while ((pos = line.find(".txt", pos)) != string::npos) {
                            size_t start = line.find_last_of(" \t", pos);
                            string referenced_file = line.substr(start + 1, pos - start + 3);
                            graph.insert_vertix(referenced_file);
                            graph.insert_edge(data.cFileName, referenced_file);
                            pos += 4; // Move past the current reference
                        }
                    }
                    file.close();
                }
                else {
                    cerr << "Error opening file: " << file_path << endl;
                }
            }
        } while (FindNextFileA(hFind, &data) != 0);
        FindClose(hFind);
    }
}




int main() {
    string directoryname = "D:\\Semester 4\\DSA\\data";
    Graph_list file_graph;

    // Step 1: Read directory and construct the graph
    read_directory(directoryname, file_graph);

    // Step 2: Choose a starting vertex (file) for BFS
    string start_vertex = "file1.txt";
    string end_vertex = "file16.txt";

    // Step 3: Perform BFS traversal

    file_graph.display_graph();

    string bfs_result = file_graph.shortest_path(start_vertex, end_vertex);
    cout << "BFS" << endl;
    cout << bfs_result << endl;
    return 0;
}