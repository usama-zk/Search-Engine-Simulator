#include"Trie.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include<algorithm>

class mypairs {
    std::string name;
    int count;

public:
    mypairs() : count(0) {}

    mypairs(const std::string& s, int c) : name(s), count(c) {}

    mypairs(const mypairs& a) : name(a.name), count(a.count) {}

    mypairs(const std::pair<std::string, int>& a) : name(a.first), count(a.second) {}

    mypairs& operator=(const mypairs& a) {
        if (this != &a) {
            name = a.name;
            count = a.count;
        }
        return *this;
    }

    mypairs& operator=(const std::pair<std::string, int>& a) {
        name = a.first;
        count = a.second;
        return *this;
    }

    bool operator==(const mypairs& a) const {
        return (name == a.name && count == a.count);
    }

    bool operator>(const mypairs& a) const {
        return count > a.count;
    }

    bool operator<(const mypairs& a) const {
        return count < a.count;
    }

    bool operator<=(const mypairs& a) const {
        return count <= a.count;
    }

    bool operator!=(const mypairs& a) const {
        return !(*this == a);
    }

    const std::string& getName() const {
        return name;
    }

    int getCount() const {
        return count;
    }
};

class mysort {
    template<class t>
    static std::vector<t> merge(std::vector<t> Right, std::vector<t> Left) {
        int R_size = Right.size();
        int L_size = Left.size();
        int count_R = 0;
        int count_L = 0;

        std::vector<t> ans;

        while (count_R < R_size && count_L < L_size) {
            if (Right[count_R] <= Left[count_L]) {
                ans.push_back(Right[count_R]);
                count_R++;
                continue;
            }
            if (Right[count_R] > Left[count_L]) {
                ans.push_back(Left[count_L]);
                count_L++;
                continue;
            }
        }

        while (count_R < R_size) {
            ans.push_back(Right[count_R]);
            count_R++;
        }
        while (count_L < L_size) {
            ans.push_back(Left[count_L]);
            count_L++;
        }
        return ans;
    }

public:

    template<class t>
    static std::vector<t> merge_sort(std::vector<t>& s) {
        if (s.size() < 2) return s;

        int mid = floor(s.size()) / 2;

        std::vector<t> left;
        for (int i = mid; i < s.size(); i++) {
            left.push_back(s[i]);
        }
        std::vector<t> right;
        for (int i = 0; i < mid; i++) {
            right.push_back(s[i]);
        }

        std::vector<t> left_ = merge_sort(left);
        std::vector<t> right_ = merge_sort(right);

        return s = merge(left_, right_);
    }
};

class myutility {
    static std::string trim(std::string& str) {
        size_t i = 0;
        while (i < str.size() && isspace(str[i])) {
            i++;
        }
        str = str.substr(i);

        i = str.size() - 1;
        while (i >= 0 && isspace(str[i])) {
            i--;
        }
        str = str.substr(0, i + 1);

        return str;
    }
public:
    static void read_directory(const std::string& name, Trie& v)
    {
        std::string pattern(name);
        pattern.append("\\*");
        WIN32_FIND_DATAA data;
        HANDLE hFind;
        if ((hFind = FindFirstFileA(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
            do {
                if (!(data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) { // Check if it's not a directory
                    std::string file_path = name + "\\" + data.cFileName;
                    std::ifstream file(file_path, std::ios::binary);
                    if (file.is_open()) {
                        std::string file_content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                        v.insert(file_content, data.cFileName);
                        file.close();
                    }
                    else {
                        std::cerr << "Error opening file: " << file_path << std::endl;
                    }
                }
            } while (FindNextFileA(hFind, &data) != 0);
            FindClose(hFind);
        }
    }

    static std::vector<mypairs> ParseQuery(std::string query, Trie filecontents) {

        std::hash_map<std::string, int> combined;
        bool combined_not_used = false;

        std::size_t And_pos = query.find("AND");
        std::size_t Or_pos = query.find("OR");

        if (And_pos == std::string::npos && Or_pos == std::string::npos) {
            auto vals = filecontents.search(query);
            bool first_time = true;
            for (auto maps : vals) {
                for (auto pairs : maps) {
                    if (first_time) {
                        if (combined.find(pairs.first) != combined.end()) {
                            combined[pairs.first] = pairs.second;
                        }
                        else {
                            combined[pairs.first] += pairs.second;
                        }
                    }
                    else {
                        std::hash_map<std::string, int> new_combined;
                        if (combined.find(pairs.first) != combined.end()) {
                            new_combined[pairs.first] = pairs.second + combined[pairs.first];
                        }
                    }
                }
                first_time = false;
            }
        }
        else {
            while (query.size() != 0) {

                if (And_pos == Or_pos) break;

                std::size_t index = Or_pos < And_pos ? Or_pos : And_pos;
                std::string key = Or_pos < And_pos ? "OR" : "AND";

                if (!combined_not_used) {
                    combined_not_used = true;
                    std::string key1 = query.substr(0, index);
                    query = query.substr(index + key.size() + 1, query.size());

                    std::size_t space_pos = query.find(' ');
                    std::string key2 = query.substr(0, space_pos);

                    query = query.substr(space_pos + 1, query.size());

                    trim(key1);
                    trim(key2);

                    std::hash_map<std::string, int> filenames_key1 = *filecontents.search(key1).begin();
                    std::hash_map<std::string, int> filenames_key2 = *filecontents.search(key2).begin();

                    if (key == "OR") {
                        for (auto pairs : filenames_key1) {
                            if (combined.find(pairs.first) == combined.end()) {
                                combined.insert(pairs);
                            }
                            else {
                                combined[pairs.first] += pairs.second;
                            }
                        }
                        for (auto pairs : filenames_key2) {
                            if (combined.find(pairs.first) == combined.end()) {
                                combined.insert(pairs);
                            }
                            else {
                                combined[pairs.first] += pairs.second;
                            }
                        }
                    }
                    if (key == "AND") {
                        for (auto pairs : filenames_key1) {
                            if (filenames_key2.find(pairs.first) != filenames_key2.end()) {
                                if (combined.find(pairs.first) == combined.end()) {
                                    combined.insert(pairs);
                                }
                                else {
                                    combined[pairs.first] += pairs.second;
                                }
                            }
                        }
                    }
                }
                else {
                    query = query.substr(index + key.size() + 1, query.size());
                    std::size_t space_pos = query.find(' ');
                    std::string key2 = query.substr(0, space_pos);

                    query = query.substr(space_pos + 1, query.size());

                    trim(key2);
                    std::hash_map<std::string, int> filenames_key2 = *filecontents.search(key2).begin();

                    if (key == "OR") {
                        for (auto pairs : filenames_key2) {
                            if (combined.find(pairs.first) == combined.end()) {
                                combined.insert(pairs);
                            }
                            else {
                                combined[pairs.first] += pairs.second;
                            }
                        }
                    }
                    if (key == "AND") {
                        std::hash_map<std::string, int> new_combined;
                        for (auto pairs : filenames_key2) {
                            if (combined.find(pairs.first) != combined.end()) {
                                new_combined[pairs.first] = combined[pairs.first] + pairs.second;
                            }
                        }
                        combined = new_combined;
                    }
                }
                And_pos = query.find("AND");
                Or_pos = query.find("OR");
            }
        }
        std::vector<mypairs> sorted(combined.begin(), combined.end());
        mysort::merge_sort(sorted);
        return sorted;
    }
};