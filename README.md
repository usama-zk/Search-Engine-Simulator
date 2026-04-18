# Web Crawler and Search Engine Simulator

## Introduction

The **Web Crawler and Search Engine Simulator** project aims to replicate the core functionality of industry-standard web search engines like Google and Chrome. The objective of this project is to develop a time-efficient solution to crawl the web and retrieve relevant information based on user queries. The project uses optimal data structures, including a trie for efficient data retrieval, and implements a linking graph to manage relationships between web pages. The entire system is run on a local server with a backend database consisting of 50 files, allowing for controlled testing and simulation of real-world web crawling operations.

## Methodology

The project involves the following key steps:

1. **Data Structure Selection**:
   - A **Trie** data structure is used to store the content from multiple files, allowing for fast search operations.
2. **Query Handling**:
   - The search engine loads data from files into the trie structure upon initialization, and efficiently retrieves data based on user queries.
   - A **Hashmap** is used to track the frequency of words across files, which is useful for implementing logical operators like AND, OR in queries as well as displaying the resulta in order of relevancy.

3. **Graphical User Interface (GUI)**:
   - A user-friendly **GUI** was created to facilitate easy interaction with the search engine.
   - The GUI dynamically accommodates the display of any number of files and results, ensuring flexibility and scalability.

## Efficiency and Results

The primary goal of the project was to optimize search time. By leveraging the **Trie** data structure, the time complexity was reduced to **O(k)**, where `k` is the number of words in the query.

- For example, the query "Flow and Stream" has a time complexity of **O(3)**.
- The average search time recorded during testing was between **20-30 ms**.

### Time Complexity Analysis:

- The system handles most queries in constant or near-constant time, making it ideal for large datasets.

## Limitations

While the project successfully implements a functional web crawler and search engine simulator, some limitations were observed:

- The code is **sensitive to spaces**: If a query has extra spaces, it may not parse correctly.
- The GUI does not handle **single-character queries**: Queries consisting of single characters do not return results or display anything in the form.

## How to run

### Prerequisites

- A C++ compiler (GCC, Clang, or similar)
- A graphical interface library (Visual Studio's C++ Window Builder) for the GUI

### Installation

1. Clone the repository: Use git clone command to clone the repository.
2. Update the path of root folder from ("D:\\NUST\\4th Semester\\DSA\\Root") to wherever your files/database is placed.
3. Navigate to the directory where the files have been downloaded, change the properties of ".resx" files (Check the unblock option under the General tab, in front of Security heading).
4. Run the .sln file (or build the project yourself and run the executable).
