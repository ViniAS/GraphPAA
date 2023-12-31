#include <iostream>
#include <gtest/gtest.h>
#include "Graphs/GraphList.h"
#include "Graphs/GraphMatrix.h"
#include "Graphs/GraphListWeighted.h"
#include <list>
using namespace graph;

TEST(GraphListTest, HasEdge) {
    graph::GraphList g(5);
    EXPECT_FALSE(g.hasEdge(0, 1));
}

TEST(GraphListTest, AddEdge) {
    graph::GraphList g(5);
    g.addEdge(0, 1);
    EXPECT_TRUE(g.hasEdge(0, 1));
}

TEST(GraphListTest, RemoveEdge) {
    graph::GraphList g(5);
    g.addEdge(0, 1);
    g.removeEdge(0, 1);
    EXPECT_FALSE(g.hasEdge(0, 1));
}

TEST(GraphListTest, IsSubGraph) {
    graph::GraphList g1(2);
    g1.addEdge(0, 1);

    graph::GraphList g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);

    EXPECT_TRUE(g2.isSubGraph(g1));

    graph::GraphMatrix g3(3);
    g3.addEdge(0,2);

    EXPECT_FALSE(g1.isSubGraph(g3));
}

TEST(GraphListTest, GetMaxDegree) {
    graph::GraphList g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);

    EXPECT_EQ(g.getMaxDegree(), 2);
}

TEST(GraphListTest, GetMinDegree) {
    graph::GraphList g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);

    EXPECT_EQ(g.getMinDegree(), 0);
}

TEST(GraphListTest, isPath) {
    graph::GraphList g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    int Vs[2] = {1};
    EXPECT_FALSE(g.isPath(Vs, 2));
    int Vs2[3] = {0, 1, 2};
    EXPECT_FALSE(g.isPath(Vs2, 3));
    g.addEdge(1, 2);
    EXPECT_TRUE(g.isPath(Vs2, 3));
}
TEST(GraphListCycle, isPath){
    graph::GraphList g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    int Vs[3] = {0, 1, 2};
    bool hasCycle;
    EXPECT_TRUE(g.isPath(Vs, 3, hasCycle));
    EXPECT_FALSE(hasCycle);
    int Vs2[2] = {0, 3};
    EXPECT_FALSE(g.isPath(Vs2, 2, hasCycle));
    EXPECT_FALSE(hasCycle);
    int Vs3[3] = {0, 1, 0};
    g.addEdge(1,0);
    EXPECT_TRUE(g.isPath(Vs3, 3, hasCycle));
    EXPECT_TRUE(hasCycle);
    g.addEdge(3,1);
    g.addEdge(2,3);
    int Vs4[5] = {0, 1, 2, 3,1};
    EXPECT_TRUE(g.isPath(Vs4, 5, hasCycle));
    EXPECT_TRUE(hasCycle);
}

TEST(GraphListTest, DFS) {
    graph::GraphList g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    int preOrder[5];
    int postOrder[5];
    int parents[5];
    g.dfs(preOrder, postOrder, parents);

    // Check that all vertices are visited
    for (int i: preOrder) EXPECT_NE(i, -1);
    for (int i: postOrder) EXPECT_NE(i, -1);
    // Check parent-child relationships
    for (int i = 0; i < 5; i++) {
        if (parents[i] != i) {
            EXPECT_TRUE(g.hasEdge(parents[i], i));
        }
    }

    // Check that preOrder is a permutation of vertices
    bool visited[5] = {false};
    for (int i : preOrder){
        EXPECT_FALSE(visited[i]);
        visited[i] = true;
    }

    // Check that postOrder is a permutation of vertices
    bool visited2[5] = {false};
    for (int i : postOrder){
        EXPECT_FALSE(visited2[i]);
        visited2[i] = true;
    }
}

TEST(GraphMatrixTest, HasEdge) {
    graph::GraphMatrix g(5);
    EXPECT_FALSE(g.hasEdge(0, 1));
}

TEST(GraphMatrixTest, AddEdge) {
    graph::GraphMatrix g(5);
    g.addEdge(0, 1);
    EXPECT_TRUE(g.hasEdge(0, 1));
}

TEST(GraphMatrixTest, RemoveEdge) {
    graph::GraphMatrix g(5);
    g.addEdge(0, 1);
    g.removeEdge(0, 1);
    EXPECT_FALSE(g.hasEdge(0, 1));
}

TEST(GraphMatrixTest, IsSubGraph) {
    graph::GraphMatrix g1(2);
    g1.addEdge(0, 1);

    graph::GraphMatrix g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);

    EXPECT_TRUE(g2.isSubGraph(g1));

    graph::GraphMatrix g3(3);
    g3.addEdge(0,2);

    EXPECT_FALSE(g1.isSubGraph(g3));
}

TEST(GraphMatrixTest, GetMaxDegree) {
    graph::GraphMatrix g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);

    EXPECT_EQ(g.getMaxDegree(), 2);
}

TEST(GraphMatrixTest, GetMinDegree) {
    graph::GraphList g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);

    EXPECT_EQ(g.getMinDegree(), 0);
}

TEST(GraphMatrixTest, isPath) {
    graph::GraphList g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    int Vs[2] = {1};
    EXPECT_FALSE(g.isPath(Vs, 2));
    int Vs2[3] = {0, 1, 2};
    EXPECT_FALSE(g.isPath(Vs2, 3));
    g.addEdge(1, 2);
    EXPECT_TRUE(g.isPath(Vs2, 3));
}
TEST(GraphMatrixCycle, isPath){
    graph::GraphList g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    int Vs[3] = {0, 1, 2};
    bool hasCycle;
    EXPECT_TRUE(g.isPath(Vs, 3, hasCycle));
    EXPECT_FALSE(hasCycle);
    int Vs2[2] = {0, 3};
    EXPECT_FALSE(g.isPath(Vs2, 2, hasCycle));
    EXPECT_FALSE(hasCycle);
    int Vs3[3] = {0, 1, 0};
    g.addEdge(1,0);
    EXPECT_TRUE(g.isPath(Vs3, 3, hasCycle));
    EXPECT_TRUE(hasCycle);
    g.addEdge(3,1);
    g.addEdge(2,3);
    int Vs4[5] = {0, 1, 2, 3,1};
    EXPECT_TRUE(g.isPath(Vs4, 5, hasCycle));
    EXPECT_TRUE(hasCycle);
}

TEST(GraphMatrixTest, DFS) {
    graph::GraphList g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    int preOrder[5];
    int postOrder[5];
    int parents[5];
    g.dfs(preOrder, postOrder, parents);

    // Check that all vertices are visited
    for (int i: preOrder) EXPECT_NE(i, -1);
    for (int i: postOrder) EXPECT_NE(i, -1);
    // Check parent-child relationships
    for (int i = 0; i < 5; i++) {
        if (parents[i] != i) {
            EXPECT_TRUE(g.hasEdge(parents[i], i));
        }
    }

    // Check that preOrder is a permutation of vertices
    bool visited[5] = {false};
    for (int i : preOrder){
        EXPECT_FALSE(visited[i]);
        visited[i] = true;
    }

    // Check that postOrder is a permutation of vertices
    bool visited2[5] = {false};
    for (int i : postOrder){
        EXPECT_FALSE(visited2[i]);
        visited2[i] = true;
    }

    //Check that preOrder and postOrder are different
    for (int i = 0; i < 5; i++) EXPECT_NE(preOrder[i], postOrder[i]);
}

TEST(GraphMatrixTest, GetNeighbors) {
    graph::GraphMatrix g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    std::list<int> neighbors = g.getNeighbors(0);

    EXPECT_EQ(neighbors.size(), 2);
    EXPECT_TRUE(std::find(neighbors.begin(), neighbors.end(), 1) != neighbors.end());
    EXPECT_TRUE(std::find(neighbors.begin(), neighbors.end(), 2) != neighbors.end());
}

TEST(GraphListTest, GetNeighbors){
    graph::GraphList g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    std::list<int> neighbors = g.getNeighbors(0);

    EXPECT_EQ(neighbors.size(), 2);
    EXPECT_TRUE(std::find(neighbors.begin(), neighbors.end(), 1) != neighbors.end());
    EXPECT_TRUE(std::find(neighbors.begin(), neighbors.end(), 2) != neighbors.end());
}

TEST(GraphListTest, canReach){
    graph::GraphList g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    EXPECT_TRUE(g.canReach(0,1));
    EXPECT_TRUE(g.canReach(0,4));
    EXPECT_FALSE(g.canReach(4,0));
}

TEST(GraphMatrixTest, canReach){
    graph::GraphMatrix g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    EXPECT_TRUE(g.canReach(0,1));
    EXPECT_TRUE(g.canReach(0,4));
    EXPECT_FALSE(g.canReach(4,0));
}

TEST(GraphListTest, isTopological){
    graph::GraphList g(7);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(0,6);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(4,6);
    g.addEdge(5,6);
    EXPECT_TRUE(g.isTopological());

    graph::GraphList g2(5);
    g2.addEdge(0,1);
    g2.addEdge(0,2);
    g2.addEdge(1,2);
    g2.addEdge(2,3);
    g2.addEdge(4,3);
    EXPECT_FALSE(g2.isTopological());
}

TEST(GraphMatrixTest, isTopological){
    graph::GraphMatrix g(7);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(0,6);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(4,6);
    g.addEdge(5,6);
    EXPECT_TRUE(g.isTopological());

    graph::GraphMatrix g2(5);
    g2.addEdge(0,1);
    g2.addEdge(0,2);
    g2.addEdge(1,2);
    g2.addEdge(2,3);
    g2.addEdge(4,3);
    EXPECT_FALSE(g2.isTopological());
}

TEST(GraphListTest, hasCycle){
    graph::GraphList g(7);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(0,6);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(4,6);
    g.addEdge(5,6);
    EXPECT_FALSE(g.hasCycle());

    graph::GraphList g2(5);
    g2.addEdge(0,1);
    g2.addEdge(0,2);
    g2.addEdge(1,2);
    g2.addEdge(2,3);
    g2.addEdge(3,0);
    EXPECT_TRUE(g2.hasCycle());
}

TEST(GraphMatrixTest, hasCycle){
    graph::GraphMatrix g(7);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(0,6);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(4,6);
    g.addEdge(5,6);
    EXPECT_FALSE(g.hasCycle());

    graph::GraphMatrix g2(5);
    g2.addEdge(0,1);
    g2.addEdge(0,2);
    g2.addEdge(1,2);
    g2.addEdge(2,3);
    g2.addEdge(3,0);
    EXPECT_TRUE(g2.hasCycle());
}

TEST(GraphListTest, BFS) {
    // Step 1: Create a graph with a known structure.
    graph::GraphList g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // Step 2: Call the bfs method on the graph.
    int order[5];
    int parent[5];
    g.bfs(0, order, parent);

    // Step 3: Check that the order and parent arrays are as expected.
    int expectedOrder[5] = {0, 1, 2, 3, 4};
    int expectedParent[5] = {0, 0, 0, 1, 2};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(order[i], expectedOrder[i]);
        EXPECT_EQ(parent[i], expectedParent[i]);
    }
}

TEST(GraphList, minDistanceBFS){
    graph::GraphList g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    int distance[5];
    g.minDistanceBFS(0, distance);
    int expectedDistance[5] = {0, 1, 1, 2, 2};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(distance[i], expectedDistance[i]);
    }
}

TEST(GraphMatrix, minDistanceBFS){
    graph::GraphMatrix g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    int distance[5];
    g.minDistanceBFS(0, distance);
    int expectedDistance[5] = {0, 1, 1, 2, 2};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(distance[i], expectedDistance[i]);
    }
}

TEST(GraphList, minDistanceDag){
    graph::GraphList g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    int distance[5];
    int parent[5];
    g.minDistanceDag(distance, parent);
    int expectedDistance[5] = {0, 1, 1, 2, 2};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(distance[i], expectedDistance[i]);
    }
}

TEST(GraphMatrix, minDistanceDag){
    graph::GraphMatrix g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    int distance[5];
    int parent[5];
    g.minDistanceDag(distance, parent);
    int expectedDistance[5] = {0, 1, 1, 2, 2};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(distance[i], expectedDistance[i]);
    }
}

TEST(GraphListWeighted, BellmanFord){
    graph::GraphListWeighted g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, -5);
    g.addEdge(2, 4, 4);
    g.addEdge(3,2,3);
    float distance[5];
    int parent[5];
    g.BellmanFord(0, distance, parent);
    float expectedDistance[5] = {0, 1, -1, -4, 3};
    int expectedParent[5] = {0, 0, 3, 1, 2};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(distance[i], expectedDistance[i]);
        EXPECT_EQ(parent[i], expectedParent[i]);
    }
}

TEST(GraphListWeighted, Dijkstra){
    graph::GraphListWeighted g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 4, 4);
    float distance[5];
    int parent[5];
    g.Dijkstra(0, distance, parent);
    float expectedDistance[5] = {0, 1, 2, 4, 6};
    int expectedParent[5] = {0, 0, 0, 1, 2};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(distance[i], expectedDistance[i]);
        EXPECT_EQ(parent[i], expectedParent[i]);
    }
}

TEST(GraphListWeighted, AGP) {
    graph::GraphListWeighted g(6);
    g.addEdge(0, 1, 7);
    g.addEdge(1,0,7);
    g.addEdge(0,2,9);
    g.addEdge(2,0,9);
    g.addEdge(1,2,5);
    g.addEdge(2,1,5);
    g.addEdge(1,3,2);
    g.addEdge(3,1,2);
    g.addEdge(1,4,4);
    g.addEdge(4,1,4);
    g.addEdge(2,4,6);
    g.addEdge(4,2,6);
    g.addEdge(2,5,1);
    g.addEdge(5,2,1);
    g.addEdge(3,4,3);
    g.addEdge(4,3,3);
    g.addEdge(3,5,2);
    g.addEdge(5,3,2);
    g.addEdge(4,5,7);
    g.addEdge(5,4,7);
    int parent[6];
    g.MSTHeap(4,parent);
    int const expectedParent[6] = {1,3,5,4,4,3};
    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(parent[i], expectedParent[i]);
    }
}

TEST(GraphListWeighted, kruksal) {
    graph::GraphListWeighted g(6);
    g.addEdge(0,1,2);
    g.addEdge(1,0,2);
    g.addEdge(0,2,9);
    g.addEdge(2,0,9);
    g.addEdge(1,2,5);
    g.addEdge(2,1,5);
    g.addEdge(1,3,7);
    g.addEdge(3,1,7);
    g.addEdge(1,4,4);
    g.addEdge(4,1,4);
    g.addEdge(2,4,6);
    g.addEdge(4,2,6);
    g.addEdge(2,5,1);
    g.addEdge(5,2,1);
    g.addEdge(3,4,3);
    g.addEdge(4,3,3);
    g.addEdge(3,5,2);
    g.addEdge(5,3,2);
    g.addEdge(4,5,7);
    g.addEdge(5,4,7);

    auto const edges = g.Kruksal();
    std::vector<std::tuple<float,int,int>> expectedEdges;
    expectedEdges.emplace_back(1,2,5);
    expectedEdges.emplace_back(2,0,1);
    expectedEdges.emplace_back(2,3,5);
    expectedEdges.emplace_back(3,3,4);
    expectedEdges.emplace_back(4,1,4);


    for(int i=0; i<edges.size(); i++){
        EXPECT_EQ(std::get<0>(edges[i]), std::get<0>(expectedEdges[i]));
        EXPECT_EQ(std::get<1>(edges[i]), std::get<1>(expectedEdges[i]));
        EXPECT_EQ(std::get<2>(edges[i]), std::get<2>(expectedEdges[i]));
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}