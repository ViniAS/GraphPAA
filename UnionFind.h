//
// Created by vinicius on 11/14/23.
//

#ifndef UNIONFIND_H
#define UNIONFIND_H



class UnionFind {
private:
    int numElements;
    int * group;
    int * groupSize;
public:
    explicit UnionFind(int numElements);
    ~UnionFind();
    [[nodiscard]] int find(int e) const;
    void unite(int e1, int e2);
    [[nodiscard]] int getNumElements() const;
    [[nodiscard]] int *getGroup() const;
    [[nodiscard]] int *getGroupSize() const;
};



#endif //UNIONFIND_H
