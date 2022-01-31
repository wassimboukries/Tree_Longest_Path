#pragma once
#include <iostream>
#include <vector>

using namespace std;

typedef struct graph {
    int nEdges, nVertex;
    vector<vector<int>> vertexNeighbours;
} graph_t;

void readGraph(string fileName, graph_t & graph);
int BFS(graph_t & graph, int source);
