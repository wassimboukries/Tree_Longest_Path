#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    graph_t myGraph;

    readGraph("inputFile.txt", myGraph);
    cout << BFS(myGraph, 0) << endl;
    
    return 0;
}