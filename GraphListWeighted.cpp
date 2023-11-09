//
// Created by vinicius on 11/9/23.
//

#include "GraphListWeighted.h"

namespace graph {
    GraphListWeighted::GraphListWeighted(int numVertices) : GraphList(numVertices){
        weights = new std::list<int>[numVertices];
    }

    GraphListWeighted::~GraphListWeighted() {
        delete[] weights;
    }

    bool GraphListWeighted::addEdge(int v1, int v2, int weight) {
        for (auto x: adjLists[v1])
            if (x == v2) return false;

        adjLists[v1].push_back(v2);
        weights[v1].push_back(weight);
        numEdges++;
        return true;
    }

    bool GraphListWeighted::


    bool GraphListWeighted::removeEdge(int v1, int v2) {
        unsigned long initSize = adjLists[v1].size();
        auto itAdj = adjLists[v1].begin();
        auto itWeight = weights[v1].begin();

        while (itAdj != adjLists[v1].end()) {
            if (*itAdj == v2) {
                adjLists[v1].erase(itAdj);
                weights[v1].erase(itWeight);
                numEdges--;
                return true;
            }
            itAdj++;
            itWeight++;
        }
        return false;
    }


} // graph