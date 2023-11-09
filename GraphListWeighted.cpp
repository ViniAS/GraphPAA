//
// Created by vinicius on 11/9/23.
//

#include "GraphListWeighted.h"
#include <limits>

namespace graph {
    GraphListWeighted::GraphListWeighted(int numVertices) : GraphList(numVertices){
        weights = new std::list<float>[numVertices];
    }

    GraphListWeighted::~GraphListWeighted() {
        delete[] weights;
    }

    bool GraphListWeighted::addEdge(int v1, int v2, float weight) {
        for (auto x: adjLists[v1])
            if (x == v2) return false;

        adjLists[v1].push_back(v2);
        weights[v1].push_back(weight);
        numEdges++;
        return true;
    }

    bool GraphListWeighted::addEdge(int v1, int v2){
        return addEdge(v1, v2, 1);
    }


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

    std::list<float> *GraphListWeighted::getWeights() const {
        return weights;
    }

    bool GraphListWeighted::BellmanFord(int s, float *dist, int *parents) const {
        for (int i = 0; i < numVertices; ++i) {
            dist[i] = std::numeric_limits<float>::infinity();
            parents[i] = -1;
        }
        dist[s] = 0;
        parents[s] = s;
        for(int i = 1; i <= getNumVertices()-1; i++){
            for(int v = 0; v < getNumVertices(); v++) {
                auto itWeight = weights[v].begin();
                auto itAdj = adjLists[v].begin();
                for (; itAdj != adjLists[v].end() && itWeight != weights[v].end(); itWeight++, itAdj++) {
                    if (dist[v] + *itWeight < dist[*itAdj]) {
                        dist[*itAdj] = dist[v] + *itWeight;
                        parents[*itAdj] = v;
                    }
                }
            }
        }
        for(int v = 0; v < getNumVertices(); v++) {
            auto itWeight = weights[v].begin();
            auto itAdj = adjLists[v].begin();
            for (; itAdj != adjLists[v].end() && itWeight != weights[v].end(); itWeight++, itAdj++)
                if (dist[v] + *itWeight < dist[*itAdj]) return false;
        }
        return true;
    }
} // graph