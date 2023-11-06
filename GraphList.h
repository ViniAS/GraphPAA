//
// Created by vini on 05/11/23.
//

#ifndef GRAPHPAA_GRAPHLIST_H
#define GRAPHPAA_GRAPHLIST_H
#include "Graph.h"
namespace graph {

    class GraphList: public Graph{
    private:
        std::list<int> *adjLists;
    public:
        explicit GraphList(int numVertices);

        ~GraphList() override;

        [[nodiscard]] bool hasEdge(int v1, int v2) const override;

        bool addEdge(int v1, int v2) override;

        bool removeEdge(int v1, int v2) override;

        void printGraph() const override;

        [[nodiscard]] std::list<int> getNeighbors(int v) const override;

        [[nodiscard]] unsigned long getDegree(int v) const override;

        [[nodiscard]] std::list<int> *getAdjLists() const;
    };

} // graph

#endif //GRAPHPAA_GRAPHLIST_H
