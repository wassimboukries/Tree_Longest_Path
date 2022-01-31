#include "functions.h"
#include <queue>
#include <fstream>

void readGraph(string fileName, graph_t & graph) {

    std::ifstream fichier(fileName);
    int neighbour;

    fichier >> graph.nEdges;
    
    for (int i = 0; i < graph.nEdges; i++) {
        fichier >> neighbour;
        graph.vertexNeighbours[i].push_back(neighbour); 
        graph.vertexNeighbours[neighbour].push_back(i); 
    }

}


int BFS(graph_t & graph, int source) {
    vector<bool> isEdgeExplored;
    queue<int> myQueue;
    int vertex;

    for (int i = 0; i<graph.nEdges; ++i) {
        // None of the edges is yet explored
        isEdgeExplored.push_back(0);
    }

    isEdgeExplored[source] = true; 
    myQueue.push(source);

    while(!myQueue.empty()) {
        vertex = myQueue.front();
        myQueue.pop();
        
        for (auto & neighbour : graph.vertexNeighbours[vertex]) {
            if (!isEdgeExplored[neighbour]) {
                myQueue.push(vertex);
                isEdgeExplored[neighbour] = true;
            } 
        } 
    }

    return vertex;
} 