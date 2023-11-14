//
// Created by vini on 05/11/23.
//

#include "GraphMatrix.h"
#include <iostream>
#include <list>

namespace graph {
    GraphMatrix::GraphMatrix(int const numVertices) :Graph(numVertices),
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

    bool GraphMatrix::hasEdge(int const v1, int const v2) const {
        return adjMatrix[v1][v2];
    }

    bool GraphMatrix::addEdge(int const v1, int const v2) {
        if (!hasEdge(v1,v2)) {
            adjMatrix[v1][v2]  = true;
            numEdges++;
            return true;
        }
        return false;
    }

    bool GraphMatrix::removeEdge(int const v1, int const v2) {
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

    std::list<int> GraphMatrix::getNeighbors(int const v) const{
        std::list<int> neighbors;
        for(int i=0; i < numVertices; i++){
            if(adjMatrix[v][i]) neighbors.push_back(i);
        }
        return neighbors;
    }

    unsigned long GraphMatrix::getDegree(int const v) const {
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