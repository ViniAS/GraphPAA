//
// Created by vini on 03/11/23.
//

#ifndef GRAPHPAA_GRAPH_H
#define GRAPHPAA_GRAPH_H

#include <list>
#include <vector>


namespace graph {
    class Graph {
    protected:
        int numVertices;
        int numEdges;
    public:
        explicit Graph(int numVertices);

        [[nodiscard]] virtual bool hasEdge(int v1, int v2) const = 0;

        virtual void addEdge(int v1, int v2) = 0;

        virtual bool removeEdge(int v1, int v2) = 0;

        virtual void printGraph() const = 0;

        [[nodiscard]] virtual std::list<int> getNeighbors(int v) const = 0;

        [[nodiscard]] int getNumVertices() const;

        [[nodiscard]] int getNumEdges() const;

        [[nodiscard]] unsigned long getDegree(int v) const;

        [[nodiscard]] unsigned long getMaxDegree() const;

        [[nodiscard]] unsigned long getMinDegree() const;

        [[nodiscard]] bool isPath(const int path[], int n) const;

        [[nodiscard]] bool isPath(const int path[], int n, bool & hasCycle) const;

        void dfs(int * preOrder, int* postOrder,int * parents) const;

        void dfsVisit(int v1, int * preOrder, int * postOrder,
                      int & preCounter, int & postCounter,int * parents) const;
    };




} // graph

#endif //GRAPHPAA_GRAPH_H
