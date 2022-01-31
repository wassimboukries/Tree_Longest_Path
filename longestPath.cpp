#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    graph_t myGraph;

    readGraph("inputFile.txt", myGraph);
    BFS(graph, 0);
    
    return 0;
}