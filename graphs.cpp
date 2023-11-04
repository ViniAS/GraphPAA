//
// Created by vini on 03/11/23.
//
#include <list>
#include <iostream>
#include "graphs.h"

namespace graph {
    GraphList::GraphList(int numVertices): numVertices(numVertices),
    numEdges(0){
        adjLists = new std::list<int>[numVertices];
    }

    GraphList::~GraphList() {
        delete[] adjLists;
    }

    void GraphList::addEdge(int v1, int v2) {
        adjLists[v1].push_back(v2);
        numEdges++;
    }

    bool GraphList::hasEdge(int v1, int v2) {
        for (auto x: adjLists[v1]){
            if (x == v2){
                return true;
            }
        }
        return false;
    }

    bool GraphList::removeEdge(int v1, int v2) {
        int initSize = adjLists[v1].size();
        adjLists[v1].remove(v2);

        if(initSize != adjLists[v1].size()){
            numEdges--;
            return true;
        } else {
            return false;
        }
    }
    void GraphList::printGraph() {
        for (int v = 0; v < numVertices; ++v){
            std::cout << "Adjacency list of vertex "
            << v << "\n head";
            for (auto x: adjLists[v]){
                std::cout << "->" << x;
            }
            std::cout << std::endl;
        }
    }

    bool GraphList::isSubGraph(GraphList &g) {
        if (g.numVertices > numVertices){
            return false;
        }
        for (int v = 0; v < g.numVertices; ++v){
            for (auto x: g.adjLists[v]){
                if (!hasEdge(v, x)){
                    return false;
                }
            }
        }
        return true;
    }

    int GraphList::getNumVertices() const {
        return numVertices;
    }

    int GraphList::getNumEdges() const {
        return numEdges;
    }

    int GraphList::getDegree(int v) const {
        return adjLists[v].size();
    }

    int GraphList::getMaxDegree() const {
        int max = 0;
        for (int v = 0; v < numVertices; ++v){
            if (getDegree(v) > max){
                max = getDegree(v);
            }
        }
        return max;
    }

    int GraphList::getMinDegree() const {
        int min = numVertices;
        for (int v = 0; v < numVertices; ++v){
            if (getDegree(v) < min){
                min = getDegree(v);
            }
        }
        return min;
    }

    std::list<int> *GraphList::getAdjLists() const {
        return adjLists;
    }



} // graph