//
// Created by vinicius on 11/14/23.
//

#include "UnionFind.h"

UnionFind::UnionFind(int const numElements) : numElements(numElements), group(nullptr), groupSize(nullptr) {
    group = new int[numElements];
    groupSize = new int[numElements];
    for (int i = 0; i < numElements; ++i) {
        group[i] = i;
        groupSize[i] = 1;
    }
}

UnionFind::~UnionFind() {
    delete[] group;
    delete[] groupSize;
}

int UnionFind::find(int e) const {
    while (e != group[e]) {
        e = group[e];
    }
    return e;
}

void UnionFind::unite(int const e1, int const e2) {
    int const root1 = find(e1);
    int const root2 = find(e2);
    if (root1 == root2) return;
    if (groupSize[root1] < groupSize[root2]) {
        group[root1] = root2;
        groupSize[root2] += groupSize[root1];
    } else {
        group[root2] = root1;
        groupSize[root1] += groupSize[root2];
    }
}

int UnionFind::getNumElements() const {
    return numElements;
}

int *UnionFind::getGroup() const {
    return group;
}

int *UnionFind::getGroupSize() const {
    return groupSize;
}