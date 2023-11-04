//
// Created by vini on 03/11/23.
//

#ifndef GRAPHPAA_GRAPHS_H
#define GRAPHPAA_GRAPHS_H

#include <list>

namespace graph {


    class GraphList {
    private:
        int numVertices;
        std::list<int> *adjLists;
        int numEdges;
    public:
        explicit GraphList(int numVertices);

        ~GraphList();

        [[nodiscard]] bool hasEdge(int v1, int v2) const;

        void addEdge(int v1, int v2);

        bool removeEdge(int v1, int v2);

        void printGraph() const;

        [[nodiscard]] bool isSubGraph(GraphList &g) const;

        [[nodiscard]] int getNumVertices() const;

        [[nodiscard]] int getNumEdges() const;

        [[nodiscard]] std::list<int> *getAdjLists() const;

        [[nodiscard]] unsigned long getDegree(int v) const;

        [[nodiscard]] unsigned long getMinDegree() const;

        [[nodiscard]] unsigned long getMaxDegree() const;

        [[nodiscard]] bool isPath(const int path[], int n, bool & hasCycle) const;

        [[nodiscard]] bool isPath(const int path[], int n) const;

        void dfs(int * preOrder, int* postOrder,
                 int * parents) const;

        void dfsVisit(int v1, int * preOrder, int * postOrder,
                      int & preCounter, int & postCounter,int * parents) const;
    };


} // graph

#endif //GRAPHPAA_GRAPHS_H
