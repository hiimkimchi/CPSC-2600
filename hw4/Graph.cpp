#include "Graph.h"

//desc: constructor
// pre: none
//post: initialized values
Graph::Graph() {
    size = 0;
    matrix = nullptr;
}

//desc: destructor
// pre: none
//post: dynamic memory is deallocated
Graph::~Graph() {
    for (int i = 0; i < size; i++) {
        delete matrix[i];
    }
    delete[] matrix;
}

//desc: getter for size
// pre: none
//post: returns size
int Graph::get_size() {
    return size;
}

//desc: load a graph from a txt file
// pre: the txt file exists, and is ASSUMED to be well formed
//post: the adjacency matrix is initialized
void Graph::load(char* filename) {
    int input_size;
    ifstream in_file(filename);

    if (in_file.fail()) {
        cout << endl << "WARNING: File error.\n";
        exit(0);
    }

    //initialize the size of the matrix
    in_file >> input_size;
    size = input_size;

    //allocate memory (see helper function)
    allocate();

    //mark appropriate edges as existing
    int i, j;
    while (in_file >> i >> j) {
        matrix[i][j] = true;
        matrix[j][i] = true;
    }
}

//desc: helper function to allocate memory
// pre: size is known from load function
//post: matrix is successfully allocated with sufficient size
void Graph::allocate() {
    //allocate a 2D dynamic array
    matrix = new bool *[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new bool[size];
        for (int j = 0; j < size; j++) {
            matrix[i][j] = false;
        }
    }
}

//desc: prints the adjacency matrix
// pre: adjacency matrix must first be allocated and inputed
//post: prints
void Graph::display() {
    cout << endl << "Adjacency Matrix" << endl;
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j]) {
                cout << '1';
            } else {
                cout << '0';
            }
        }
        cout << endl;
    }
    cout << endl;
}

//desc: performs breadth first search
// pre: matrix is allocated and initialized
//post: result is stored resulting queue inside of displayingBFS
queue<int> Graph::BFS(int vertex) {
    //initialize containers
    queue<int> q;
    queue<int> result;
    bool visited[size];
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }

    //starting from first vertex
    q.push(vertex);
    result.push(vertex);
    visited[vertex] = true;

    //pop front, check neighbors and enqueue them
    while (!q.empty()) {
        int w = q.front();
        q.pop();
        for (int i = 0; i < size; i++) {
            if (matrix[w][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
                result.push(i);
            }
        }
    }
    return result;
}

//desc: displays result of BFS
// pre: none
//post: prints values in order of vertex travelled
void Graph::displayingBFS(int vertex) {
    //initialize a queue and perform breadth first search
    queue<int> result = BFS(vertex);

    //print
    cout << "BFS at vertex " << vertex << ": ";
    for (int i = 0; i < size; i++) {
        cout << result.front() << ' ';
        result.pop();
    }
    cout << endl;
}

//desc: recursively performs depth first search
// pre: matrix is allocated and initialized
//post: result is stored in is_Visited
void Graph::DFS(int vertex, bool visited[]) {
    visited[vertex] = true;
    cout << vertex << ' ';
    for (int i = 0; i < size; i++) {
        if (matrix[vertex][i] && !visited[i]) {
            DFS(i, visited);
        }
    }
}

//desc: displays result of DFS
// pre: none
//post: prints values in order of vertex travelled
void Graph::displayingDFS(int vertex) {
    //initialize visited array
    bool visited_array[size];
    for (int i = 0; i < size; i++) {
        visited_array[i] = false;
    }
    
    //perform and print depth first search
    cout << "DFS at vertex " << vertex << ": ";
    DFS(vertex, visited_array);
    cout << endl;
}