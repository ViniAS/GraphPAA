//
// Created by vini on 05/11/23.
//

#include "GraphMatrix.h"
#include <iostream>
#include <list>

namespace graph {
    GraphMatrix::GraphMatrix(int numVertices) :Graph(numVertices),
    adjMatrix(nullptr) {
        adjMatrix = new bool*[numVertices];
        for (int i=0; i<numVertices;i++){
            adjMatrix[i] = new bool [numVertices];
            for (int j = 0; j < numVertices; j++){
                adjMatrix[i][j] = false;
            }
        }
    }

    GraphMatrix::~GraphMatrix(){
        for (int i=0; i<numVertices; i++) delete[] adjMatrix[i];
        delete [] adjMatrix;
    }

    bool GraphMatrix::hasEdge(int v1, int v2) const {
        return adjMatrix[v1][v2];
    }

    void GraphMatrix::addEdge(int v1, int v2) {
        if (!hasEdge(v1,v2)) {
            adjMatrix[v1][v2]  = true;
            numEdges++;
        }
    }

    bool GraphMatrix::removeEdge(int v1, int v2) {
        if(hasEdge(v1,v2)) {
            adjMatrix[v1][v2] = false;
            numEdges--;
            return true;
        }
        return false;
    }

    void GraphMatrix::printGraph() const {
        for (int i=0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << ("%d ", hasEdge(i, j));
            }
            std::cout << std::endl;
        }
    }

    std::list<int> GraphMatrix::getNeighbors(int v) const{
        std::list<int> neighbors;
        for(int i=0; i < numVertices; i++){
            if(adjMatrix[v][i]) neighbors.push_back(i);
        }
        return neighbors;
    }

    unsigned long GraphMatrix::getDegree(int v) const {
        unsigned long degree = 0;
        for (int i=0; i < numVertices; i++){
            if (adjMatrix[v][i]) degree++;
        }
        return degree;
    }

    bool** GraphMatrix::getAdjMatrix() const {
        return adjMatrix;
    }
} // graph