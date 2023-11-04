#include <iostream>
#include <gtest/gtest.h>
#include "graphs.h"
#include <list>
using namespace graph;

TEST(GraphListHasEdgeTest, HasEdge) {
    graph::GraphList g(5);
    EXPECT_FALSE(g.hasEdge(0, 1));
}

TEST(GraphListAddEdgeTest, AddEdge) {
    graph::GraphList g(5);
    g.addEdge(0, 1);
    EXPECT_TRUE(g.hasEdge(0, 1));
}

TEST(GraphListRemoveEdgeTest, RemoveEdge) {
    graph::GraphList g(5);
    g.addEdge(0, 1);
    g.removeEdge(0, 1);
    EXPECT_FALSE(g.hasEdge(0, 1));
}

TEST(GraphListIsSubGraphTest, IsSubGraph) {
    graph::GraphList g1(2);
    g1.addEdge(0, 1);

    graph::GraphList g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);

    EXPECT_TRUE(g2.isSubGraph(g1));
}

TEST(GraphListgetMaxdegreeTest, GetMaxDegree) {
    graph::GraphList g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);

    EXPECT_EQ(g.getMaxDegree(), 2);
}

TEST(GraphListGetMinDegreeTest, GetMinDegree) {
    graph::GraphList g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);

    EXPECT_EQ(g.getMinDegree(), 0);
}

TEST(GraphListIsPathTest, isPath) {
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

TEST(GraphListDFS, dfs){
    graph::GraphList g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(4,2);
    int v[g.getNumVertices()];
    g.dfs(v);

    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 5);
    EXPECT_EQ(v[3], 2);
    EXPECT_EQ(v[4], 3);
    EXPECT_EQ(v[5], 4);
    EXPECT_EQ(v[5], 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}