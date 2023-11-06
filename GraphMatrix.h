//
// Created by vini on 05/11/23.
//

#ifndef GRAPHPAA_GRAPHMATRIX_H
#define GRAPHPAA_GRAPHMATRIX_H
#include "Graph.h"

namespace graph {

    class GraphMatrix: public Graph{
    private:
        bool **adjMatrix;
    public:
        explicit GraphMatrix(int numVertices);

        ~GraphMatrix() override;

        [[nodiscard]] bool hasEdge(int v1, int v2) const override;

        bool addEdge(int v1, int v2) override;

        bool removeEdge(int v1, int v2) override;

        void printGraph() const override;

        [[nodiscard]] std::list<int> getNeighbors(int v) const override;

        [[nodiscard]] unsigned long getDegree(int v) const override;

        [[nodiscard]] bool** getAdjMatrix() const;

    };

} // graph

#endif //GRAPHPAA_GRAPHMATRIX_H
