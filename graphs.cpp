//
// Created by vini on 03/11/23.
//
#include <list>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include "graphs.h"

namespace graph {
    Graph::Graph(int numVertices): numVertices(numVertices),
    numEdges(0){}

    GraphList::GraphList(int numVertices) : Graph(numVertices){
        adjLists = new std::list<int>[numVertices];
    }

    GraphList::~GraphList() {
        delete[] adjLists;
    }

    void GraphList::addEdge(int v1, int v2) {
        adjLists[v1].push_back(v2);
        numEdges++;
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

    std::vector<int> GraphList::getNeighbors(int v)  const {
        return {adjLists[v].begin(), adjLists[v].end()};
    }

    bool GraphList::isSubGraph(GraphList &g) const {
        if (g.numVertices > numVertices){
            return false;
        }
        for (int v = 0; v < g.numVertices; ++v){
            for (int x: g.adjLists[v]){
                if (!hasEdge(v, x)){
                    return false;
                }
            }
        }
        return true;
    }

    int Graph::getNumVertices() const {
        return numVertices;
    }

    int Graph::getNumEdges() const {
        return numEdges;
    }

    unsigned long Graph::getDegree(int v) const {
        return getNeighbors(v).size();
    }

    unsigned long Graph::getMaxDegree() const {
        unsigned long max = 0;
        for (int v = 0; v < numVertices; ++v){
            if (getDegree(v) > max){
                max = getDegree(v);
            }
        }
        return max;
    }

    unsigned long Graph::getMinDegree() const {
        unsigned long min = numVertices;
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

    bool Graph::isPath(const int path[], int n) const {
        if (n < 2) return false;
        for (int i = 0; i < n-1; ++i){
            if (!hasEdge(path[i], path[i+1])){
                return false;
            }
        }
        return true;
    }

    bool Graph::isPath(const int *path, int n, bool & hasCycle) const {
        if (n < 2) return false;
        bool visited[getNumVertices()];
        bool noCycle = true;
        for (int i = 0; i < getNumVertices(); ++i) visited[i] = false;
        visited[path[0]] = true;
        for (int i = 0; i < n-1; ++i){
            if (!hasEdge(path[i], path[i+1])){
                return false;
            }
            if (visited[path[i+1]]){
                hasCycle = true;
                noCycle = false;
            }
            visited[path[i+1]] = true;
        }
        if (noCycle) hasCycle = false;
        return true;
    }

    void Graph::dfs(int *preOrder, int* postOrder,
                        int *parents) const {
        int preCounter = 0;
        int postCounter = 0;

        for (int v = 0; v < numVertices; v++){
            preOrder[v] = -1;
            parents[v] = -1;
            postOrder[v] = -1;
        }
        for (int v = 0; v < numVertices; v++){
            if (preOrder[v] == -1){
                parents[v] = v;
                dfsVisit(v, preOrder, postOrder,
                         preCounter, postCounter, parents);
            }
        }
    }

    void Graph::dfsVisit(int v1, int *preOrder, int * postOrder,
                             int & preCounter, int & postCounter, int * parents) const {
        std::stack<int> stackVertex;
        stackVertex.push(v1);
        while (!stackVertex.empty()){
            int v = stackVertex.top();
            stackVertex.pop();
            if (preOrder[v] == -1) {
                preOrder[v] = preCounter++;
                for (auto x: getNeighbors(v)){
                    parents[x] = v;
                    if (preOrder[x] == -1){
                        stackVertex.push(x);
                    }
                }
                postOrder[v] = postCounter++;
            }
        }
    }



} // graph