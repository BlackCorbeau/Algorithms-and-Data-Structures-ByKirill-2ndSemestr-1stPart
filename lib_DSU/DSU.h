// Copyright 2024 Kirill Remizov

#ifndef LIB_DSU_LIB_DSU_HEDER_H_
#define LIB_DSU_LIB_DSU_HEDER_H_
#define SIZE_STEP 5 //просто затравочка на доработку

#include "../lib_DMassiv/DMassiv.h"

class DSU {
    int _size;
    int *_parent;
    int *_rank;

public:
    DSU(int size = 0);
    ~DSU();

    void make_set(int elem);
    int find(int elem);
    void union_sets(int first, int second);
    void clear();
};

DSU::DSU(int size) {
    _size = size;
    _parent = new int[_size];
    _rank = new int[_size];
    for (int i = 0; i < _size; ++i) {
        make_set(i);
    }
}

DSU::~DSU() {
    delete[] _parent;
    delete[] _rank;
    _parent = nullptr;
    _rank = nullptr;
    _size = 0;
}

void DSU::make_set(int elem) {
    _parent[elem] = elem;
    _rank[elem] = 0;
}

int DSU::find(int elem) {
    if (_parent[elem] != elem) {
        _parent[elem] = find(_parent[elem]);
    }
    return _parent[elem];
}

void DSU::union_sets(int first, int second) {
    int root1 = find(first);
    int root2 = find(second);

    if (root1 != root2) {
        if (_rank[root1] > _rank[root2]) {
            _parent[root2] = root1;
        } else if (_rank[root1] < _rank[root2]) {
            _parent[root1] = root2;
        } else {
            _parent[root2] = root1;
            _rank[root1]++;
        }
    }
}

void DSU::clear() {
    this->~DSU();
}
#endif  // LIB_DSU_LIB_DSU_HEDER_H_
