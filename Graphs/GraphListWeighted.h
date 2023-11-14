//
// Created by vinicius on 11/9/23.
//

#ifndef GRAPHPAA_GRAPHLISTWEIGHTED_H
#define GRAPHPAA_GRAPHLISTWEIGHTED_H

#include "GraphList.h"

namespace graph {

    class GraphListWeighted: public GraphList{
    private:
        std::list<float> *weights;
    public:
        explicit GraphListWeighted(int numVertices);

        ~GraphListWeighted() override;

        bool addEdge(int v1, int v2) override;

        bool addEdge(int v1, int v2, float weight);

        bool removeEdge(int v1, int v2) override;

        [[nodiscard]] std::list<float> *getWeights() const;

        bool BellmanFord(int s, float *dist, int *parents) const;

        void Dijkstra(int s, float *dist, int *parents) const;

        void MSTHeap(int s, int *parents) const;
    };

} // graph

#endif //GRAPHPAA_GRAPHLISTWEIGHTED_H
