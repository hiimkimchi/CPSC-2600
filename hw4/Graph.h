// Bryan Kim
// Graph.h

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class Graph {
    private:
        bool **matrix;
        int  size;
        void DFS(int vertex, bool visited[]);
        queue<int> BFS(int vertex);
        void allocate();
    public:
        Graph();
        ~Graph();
        int get_size();
        void load(char *filename);
        void display();
        void displayingBFS(int vertex);
        void displayingDFS(int vertex);
};