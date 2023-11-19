// Bryan Kim   
// CPSC 2600
// HW4.cpp
// This code will take command line inputs for txt files containing information on graphs.
// It will then find the adjacency matrix, BFS, and DFS of each graph.

#include <iostream>
#include "Graph.h"

int main (int argc, char* argv[]) {
    Graph graph;
    graph.load(argv[1]);

    cout << endl << "Welcome to Bryan Kim's HW4 assignment."
         << endl << "Input file: " << argv[1] << endl;
    
    graph.display();
    graph.displayingDFS(0);
    graph.displayingBFS(0);
    
    return 0;
}
