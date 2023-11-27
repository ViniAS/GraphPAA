//
// Created by vinicius on 11/9/23.
//

#include "GraphListWeighted.h"
#include <limits>
#include <queue>
#include <tuple>
#include "../UnionFind.h"

namespace graph {
    GraphListWeighted::GraphListWeighted(int const numVertices) : GraphList(numVertices){
        weights = new std::list<float>[numVertices];
    }

    GraphListWeighted::~GraphListWeighted() {
        delete[] weights;
    }

    bool GraphListWeighted::addEdge(int const v1, int const v2, float const weight) {
        for (auto x: adjLists[v1])
            if (x == v2) return false;

        adjLists[v1].push_back(v2);
        weights[v1].push_back(weight);
        numEdges++;
        return true;
    }

    bool GraphListWeighted::addEdge(int const v1, int const v2){
        return addEdge(v1, v2, 1);
    }


    bool GraphListWeighted::removeEdge(int const v1, int const v2) {
        unsigned long initSize = adjLists[v1].size();
        auto itAdj = adjLists[v1].begin();
        auto itWeight = weights[v1].begin();

        while (itAdj != adjLists[v1].end()) {
            if (*itAdj == v2) {
                adjLists[v1].erase(itAdj);
                weights[v1].erase(itWeight);
                numEdges--;
                return true;
            }
            ++itAdj;
            ++itWeight;
        }
        return false;
    }

    std::list<float> *GraphListWeighted::getWeights() const {
        return weights;
    }

    bool GraphListWeighted::BellmanFord(int const s, float *dist, int *parents) const {
        for (int i = 0; i < numVertices; ++i) {
            dist[i] = std::numeric_limits<float>::infinity();
            parents[i] = -1;
        }
        dist[s] = 0;
        parents[s] = s;
        for(int i = 1; i <= getNumVertices()-1; i++){
            for(int v = 0; v < getNumVertices(); v++) {
                auto itWeight = weights[v].begin();
                auto itAdj = adjLists[v].begin();
                for (; itAdj != adjLists[v].end() && itWeight != weights[v].end(); ++itWeight, ++itAdj) {
                    if (dist[v] + *itWeight < dist[*itAdj]) {
                        dist[*itAdj] = dist[v] + *itWeight;
                        parents[*itAdj] = v;
                    }
                }
            }
        }
        for(int v = 0; v < getNumVertices(); v++) {
            auto itWeight = weights[v].begin();
            auto itAdj = adjLists[v].begin();
            for (; itAdj != adjLists[v].end() && itWeight != weights[v].end(); ++itWeight, ++itAdj)
                if (dist[v] + *itWeight < dist[*itAdj]) return false;
        }
        return true;
    }

    void GraphListWeighted::Dijkstra(int s, float *dist, int *parents) const {
        bool *checked = new bool[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            dist[i] = std::numeric_limits<float>::infinity();
            parents[i] = -1;
            checked[i] = false;
        }
        dist[s] = 0;
        parents[s] = s;
        std::priority_queue<std::pair<float, int>,
                std::vector<std::pair<float, int>>, std::greater<>> heap;
        heap.emplace(0, s);

        while(!heap.empty()) {
            int const v = heap.top().second;
            heap.pop();
            if (dist[v] == std::numeric_limits<float>::infinity()) break;
            auto itWeight = weights[v].begin();
            auto itAdj = adjLists[v].begin();
            for (; itAdj != adjLists[v].end() && itWeight != weights[v].end(); ++itWeight, ++itAdj){
                if (!checked[*itAdj]) {
                    if (dist[v] + *itWeight < dist[*itAdj]) {
                        dist[*itAdj] = dist[v] + *itWeight;
                        parents[*itAdj] = v;
                        heap.emplace(dist[*itAdj], *itAdj);
                    }
                }
            }
            checked[v] = true;
        }
        delete[] checked;
    }

    void GraphListWeighted::MSTHeap(int s, int* parents) const {
        bool *checked = new bool[numVertices];
        float *dist = new float[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            parents[i] = -1;
            checked[i] = false;
            dist[i] = std::numeric_limits<float>::infinity();
        }
        parents[s] = s;
        dist[s] = 0;
        std::priority_queue<std::pair<float, int>,
                std::vector<std::pair<float, int>>, std::greater<>> heap;
        heap.emplace(0, s);

        while(!heap.empty()) {
            int const v = heap.top().second;
            heap.pop();
            if (dist[v]==std::numeric_limits<float>::infinity()) break;
            if(checked[v]) continue;
            checked[v] = true;
            auto itWeight = weights[v].begin();
            auto itAdj = adjLists[v].begin();
            for (; itAdj != adjLists[v].end() && itWeight != weights[v].end(); ++itWeight, ++itAdj){
                if (!checked[*itAdj] && *itWeight < dist[*itAdj]) {
                    dist[*itAdj] = *itWeight;
                    parents[*itAdj] = v;
                    heap.emplace(*itWeight, *itAdj);
                }
            }
        }
        delete[] checked;
        delete[] dist;
    }

    std::vector<std::tuple<float,int,int>> GraphListWeighted::Kruksal() const {
        UnionFind uf(numVertices);
        std::priority_queue<std::tuple<float, int, int>,
                std::vector<std::tuple<float, int, int>>, std::greater<>> heap;
        std::vector<std::tuple<float,int,int>> edges;

        for (int v = 0; v < numVertices; ++v) {
            auto itWeight = weights[v].begin();
            auto itAdj = adjLists[v].begin();
            for (; itAdj != adjLists[v].end() && itWeight != weights[v].end(); ++itWeight, ++itAdj)
                if(v<*itAdj)
                    heap.emplace(*itWeight, v, *itAdj);
        }
        int i = 0;
        while(!heap.empty()) {
            auto const [weight, v1, v2] = heap.top();
            heap.pop();
            if (uf.find(v1) != uf.find(v2)) {
                uf.unite(v1, v2);
                edges.emplace_back(weight, v1, v2);
            }
        }
        return edges;
    }


} // graph
