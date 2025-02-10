// Copyright 2024 Kirill Remizov

#ifndef LIB_DSU_LIB_DSU_HEDER_H_
#define LIB_DSU_LIB_DSU_HEDER_H_

class DSU {
    int _size;
    int *_parent;
    int *_rank;
 public:
    DSU(int size = 0);
    ~DSU();
    void make_set(int elem);
    int find(int elem);
    void Union(int first, int second);
    void clear();
};

#endif  // LIB_DMASSIVE_LIB_DMASSIVE_HEDER_H_