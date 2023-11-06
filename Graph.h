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

        void dfsVisit(int v1, int * preOrder, int * postOrder,
                      int & preCounter, int & postCounter,int * parents) const;

        void reachRecursive(int v1, bool * visited) const;
    public:
        explicit Graph(int numVertices);

        virtual ~Graph() = default; 

        [[nodiscard]] virtual bool hasEdge(int v1, int v2) const = 0;

        virtual void addEdge(int v1, int v2) = 0;

        virtual bool removeEdge(int v1, int v2) = 0;

        virtual void printGraph() const = 0;

        [[nodiscard]] virtual unsigned long getDegree(int v) const = 0;

        [[nodiscard]] virtual std::list<int> getNeighbors(int v) const = 0;

        [[nodiscard]] int getNumVertices() const;

        [[nodiscard]] int getNumEdges() const;

        [[nodiscard]] unsigned long getMaxDegree() const;

        [[nodiscard]] unsigned long getMinDegree() const;

        [[nodiscard]] bool isPath(const int path[], int n) const;

        [[nodiscard]] bool isPath(const int path[], int n, bool & hasCycle) const;

        [[nodiscard]] bool isSubGraph(Graph &g) const;

        void dfs(int * preOrder, int* postOrder,int * parents) const;

        [[nodiscard]] bool canReach(int v1, int v2) const;
    };




} // graph

#endif //GRAPHPAA_GRAPH_H
