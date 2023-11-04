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
        GraphList(int numVertices);

        ~GraphList();

        bool hasEdge(int v1, int v2);

        void addEdge(int v1, int v2);

        bool removeEdge(int v1, int v2);

        void printGraph();

        bool isSubGraph(GraphList &g);

        int getNumVertices() const;

        int getNumEdges() const;

        std::list<int> *getAdjLists() const;

        int getDegree(int v) const;

        int getMinDegree() const;

        int getMaxDegree() const;
    };

} // graph

#endif //GRAPHPAA_GRAPHS_H
