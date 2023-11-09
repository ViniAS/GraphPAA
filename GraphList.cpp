//
// Created by vini on 05/11/23.
//

#include "GraphList.h"
#include <list>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include "Graph.h"
namespace graph {
    GraphList::GraphList(int numVertices) : Graph(numVertices){
        adjLists = new std::list<int>[numVertices];
    }

    GraphList::~GraphList() {
        delete[] adjLists;
    }

    bool GraphList::addEdge(int v1, int v2) {
        for (auto x: adjLists[v1])
            if (x == v2) return false;

        adjLists[v1].push_back(v2);
        numEdges++;
        return true;
    }

    bool GraphList::hasEdge(int v1, int v2) const {
        return std::any_of(adjLists[v1].begin(), adjLists[v1].end(),
                           [v2](int x) { return x == v2; });
    }

    bool GraphList::removeEdge(int v1, int v2) {
        unsigned long initSize = adjLists[v1].size();
        adjLists[v1].remove(v2);

        if(initSize != adjLists[v1].size()){
            numEdges--;
            return true;
        } else {
            return false;
        }
    }
    void GraphList::printGraph() const {
        for (int v = 0; v < numVertices; ++v){
            std::cout << "Adjacency list of vertex "
                      << v << "\n head";
            for (auto x: adjLists[v]){
                std::cout << "->" << x;
            }
            std::cout << std::endl;
        }
    }

    std::list<int> GraphList::getNeighbors(int v)  const {
        return adjLists[v];
    }

    unsigned long GraphList::getDegree(int v) const {
        return getNeighbors(v).size();
    }

    std::list<int> *GraphList::getAdjLists() const {
        return adjLists;
    }
} // graph