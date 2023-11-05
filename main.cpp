#include <iostream>
#include <gtest/gtest.h>
#include "GraphList.h"
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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}