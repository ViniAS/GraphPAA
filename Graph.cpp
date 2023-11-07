//
// Created by vini on 03/11/23.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include "Graph.h"
#include <limits>

namespace graph {
    Graph::Graph(int numVertices): numVertices(numVertices),
    numEdges(0){}

    int Graph::getNumVertices() const {
        return numVertices;
    }

    int Graph::getNumEdges() const {
        return numEdges;
    }

    unsigned long Graph::getMaxDegree() const {
        unsigned long max = 0;
        for (int v = 0; v < getNumVertices(); ++v){
            if (getDegree(v) > max){
                max = getDegree(v);
            }
        }
        return max;
    }

    unsigned long Graph::getMinDegree() const {
        unsigned long min = getNumVertices();
        for (int v = 0; v < getNumVertices(); ++v){
            if (getDegree(v) < min){
                min = getDegree(v);
            }
        }
        return min;
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
    
    bool Graph::isSubGraph(Graph &g) const {
        if (g.getNumVertices() > numVertices) {
            return false;
        }
        for (int v = 0; v < g.getNumVertices(); ++v) {
            for (int x: g.getNeighbors(v)) {
                if (!hasEdge(v, x)) {
                    return false;
                }
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

        for (int v = 0; v < getNumVertices(); v++){
            preOrder[v] = -1;
            parents[v] = -1;
            postOrder[v] = -1;
        }
        for (int v = 0; v < getNumVertices(); v++){
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
        int v;

        while (!stackVertex.empty()){
            v = stackVertex.top();

            if (preOrder[v] == -1) {
                preOrder[v] = preCounter++;
                for (auto x: getNeighbors(v)) {
                    if (preOrder[x] == -1) {
                        parents[x] = v;
                        stackVertex.push(x);
                    }
                }
            }
            else{
                stackVertex.pop();
                postOrder[v] = postCounter++;
            }

        }
    }

    bool Graph::canReach(int v1, int v2) const {
        bool visited[getNumVertices()];
        for (int v=0; v < getNumVertices(); v++) visited[v] = false;

        reachRecursive(v1, visited);
        return visited[v2];
    }

    void Graph::reachRecursive(int v1, bool *visited) const {
        std::stack<int> stackVertex;
        stackVertex.push(v1);
        int v;
        while (!stackVertex.empty()){
            v = stackVertex.top();
            stackVertex.pop();
            visited[v] = true;
            for (int v2 = 0; v2 < getNumVertices(); v2++)
                if(hasEdge(v,v2) && !visited[v2]) stackVertex.push(v2);
        }
    }

    bool Graph::isTopological() const {
        for (int i = 0; i < getNumVertices(); i++) {
            for (int x: getNeighbors(i))
                if (x < i) return false;
        }
        return true;
   }

   bool Graph::hasCycle() const {
        int preOrder[getNumVertices()];
        int postOrder[getNumVertices()];
        int parents[getNumVertices()];
        dfs(preOrder, postOrder, parents);
        
        for (int v1 = 0; v1 < getNumVertices(); v1++) {
            for (int v2: getNeighbors(v1))
                if (preOrder[v1] > preOrder[v2] && postOrder[v1] < postOrder[v2])
                    return true;
        }
        return false;
   }

    void Graph::bfs(int v, int *order, int *parent) const {
        std::queue<int> vertexQueue;
        int counter = 0;
        for (int i=0; i< getNumVertices(); i++){
            order[i] = -1;
            parent[i] = -1;
        }
        order[v] = counter++;
        parent[v] = v;
        vertexQueue.push(v);

        while (!vertexQueue.empty()){
            int v1 = vertexQueue.front();
            vertexQueue.pop();
            for (int v2: getNeighbors(v1)){
                if (order[v2] == -1){
                    order[v2] = counter++;
                    parent[v2] = v1;
                    vertexQueue.push(v2);
                }
            }
        }
    }

    void Graph::dfsRecursive(int v, int *preOrder, int *postOrder) const {
        for(int i=0; i< getNumVertices(); i++){
            preOrder[i] = -1;
            postOrder[i] = -1;
        }
        std::stack<int> stackVertex;
        stackVertex.push(v);
        int preCounter = 0;
        int postCounter = 0;
        while (!stackVertex.empty()){
            v = stackVertex.top();

            if (preOrder[v] == -1) {
                preOrder[v] = preCounter++;
                for (int x: getNeighbors(v)) {
                    if (preOrder[x] == -1) {
                        std::cout<<("(%d,%d) Tree branch",v,x)<<std::endl;
                        stackVertex.push(x);
                    } else {
                        if (postOrder[x] == -1)
                            std::cout<<("(%d,%d) Return",v,x)<<std::endl;
                        else{
                            if (preOrder[x] > preOrder[v])
                                std::cout<<("(%d,%d) Forward",v,x)<<std::endl;
                            else
                                std::cout<<("(%d,%d) Cross",v,x)<<std::endl;
                        }
                    }
                }
            }
            else{
                stackVertex.pop();
                postOrder[v] = postCounter++;
            }

        }
    }

    void Graph::minDistanceDag(int *distance, int * parent) const {
        for(int i = 0; i< getNumVertices(); i++) {
            distance[i] = std::numeric_limits<int>::max();
            parent[i] = -1;
        }
        std::stack<int> vertexStack;
        distance[0] = 0;

        for(int v1=0; v1<getNumVertices(); v1++){
            for( int v2: getNeighbors(v1)){
                if(distance[v1]+1<distance[v2]){
                    parent[v2] = v1;
                    distance[v2] = v1+1;
                }
            }
        }

    }

    void Graph::minDistanceBFS(int v,int * distance) const{
        std::queue<int> vertexQueue;
        int parent[getNumVertices()];
        for (int i=0; i< getNumVertices(); i++){
            distance[i] = -1;
            parent[i] = -1;
        }
        parent[v] = v;
        distance[v] = 0;
        vertexQueue.push(v);

        while (!vertexQueue.empty()){
            int v1 = vertexQueue.front();
            vertexQueue.pop();
            for (int v2: getNeighbors(v1)){
                if (distance[v2] == -1){
                    parent[v2] = v1;
                    distance[v2] = distance[v1] + 1;
                    vertexQueue.push(v2);
                }
            }
        }
    }
} // graph