//
// Created by vinicius on 11/9/23.
//

#ifndef GRAPHPAA_GRAPHLISTWEIGHTED_H
#define GRAPHPAA_GRAPHLISTWEIGHTED_H

#include "GraphList.h"

namespace graph {

    class GraphListWeighted: public GraphList{
    private:
        std::list<int> *weights;
    public:
        explicit GraphListWeighted(int numVertices);

        ~GraphListWeighted() override;

        bool addEdge(int v1, int v2) override;

        bool addEdge(int v1, int v2, int weight);

        bool removeEdge(int v1, int v2) override;

        [[nodiscard]] std::list<int> *getWeights() const;
    };

} // graph

#endif //GRAPHPAA_GRAPHLISTWEIGHTED_H
