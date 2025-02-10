// Copyright 2024 Kirill Remizov

#ifndef LIB_DSU_LIB_DSU_HEDER_H_
#define LIB_DSU_LIB_DSU_HEDER_H_
#define SIZE_STEP 5 //просто затравочка на доработку

#include "../lib_DMassiv/DMassiv.h"

class DSU {
    int _size;
    int *_parent;

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
    for (int i = 0; i < _size; i++){
        make_set(_parent[i]);
    }
}

DSU::~DSU() {
    _size = 0;
    delete[] _parent;
    _parent = nullptr;
}

void DSU::make_set(int elem) {
    _parent[elem] = elem;
}

int DSU::find(int elem) {
    while (_parent[elem] != elem){
        elem = _parent[elem];
    }
    return elem;
}

void DSU::union_sets(int first, int second) {
    int root1 = find(first);
    int root2 = find(second);

    if (root1 != root2) {
        _parent[root2] = root1;
    }
}

void DSU::clear() {
    this->~DSU();
}
#endif  // LIB_DSU_LIB_DSU_HEDER_H_
