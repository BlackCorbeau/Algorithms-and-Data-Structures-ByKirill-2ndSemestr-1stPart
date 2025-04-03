// Copyright 2024 Kirill Remizov

#ifndef LIB_HEAP_LIB_HEAP_HEDER_H_
#define LIB_HEAP_LIB_HEAP_HEDER_H_

#include "../lib_DMassiv/DMassiv.h"

enum heapType { MAX, MIN };

template <class T>
class Heap {
private:
    DMassiv<T> _data;
    heapType type;

    bool max(T val1, T val2) {
        return val1 > val2;
    }

    bool min(T val1, T val2) {
        return val1 < val2;
    }
public:
    Heap() {type = MIN;}
    Heap(heapType t): type(t), _data() {}
    Heap(T *mas, size_t size, heapType t): _data(mas, size), type(t){ heapify(); }

    size_t left(size_t pos);
    size_t right(size_t pos);
    size_t parent(size_t pos);
    T top() {
        if (_data.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return _data[0];
    }

    void print() { printTree(0, 0); }
    void printMass() {_data.print();}
    void printTree(size_t index, int indent);

    bool isEmpty();

    void insert(T val);
    size_t find(T val);
    //void eraise(T val);
private:
    void heapify();
    void shift_up(size_t pos);
    void shift_down(size_t pos);
};
