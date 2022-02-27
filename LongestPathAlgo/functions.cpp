#include "functions.h"
#include <queue>
#include <iostream>
#include <fstream>

void readGraph(string fileName, graph_t& graph) {

    std::ifstream fichier(fileName);
    int neighbour, nbNeighbours;

    fichier >> graph.nEdges >> graph.nVertex;

    for (int i = 0; i < graph.nVertex; ++i) {
        vector<int> neigbours;
        graph.vertexNeighbours.push_back(neigbours);
    }

    for (int i = 0; i < graph.nVertex; i++) {
        fichier >> nbNeighbours;
        for (int j = 0; j < nbNeighbours; ++j) {
            fichier >> neighbour;
            graph.vertexNeighbours[i].push_back(neighbour);
            graph.vertexNeighbours[neighbour].push_back(i);
        }
        
    }
}


int BFS(graph_t& graph, int source) {
    vector<bool> isVertexExplored;
    queue<int> myQueue;
    int vertex;

    for (int i = 0; i < graph.nVertex; ++i) {
        // None of the vertices is yet explored
        isVertexExplored.push_back(0);
    }

    isVertexExplored[source] = true;
    myQueue.push(source);

    while (!myQueue.empty()) {
        vertex = myQueue.front();
        cout << vertex << " ";
        myQueue.pop();

        for (auto& neighbour : graph.vertexNeighbours[vertex]) {
            if (!isVertexExplored[neighbour]) {
                myQueue.push(neighbour);
                isVertexExplored[neighbour] = true;
            }
        }
    }

    return vertex;
}