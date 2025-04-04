// Copyright 2024 Kirill Remizov

#ifndef LIB_HEAP_LIB_HEAP_HEDER_H_
#define LIB_HEAP_LIB_HEAP_HEDER_H_

#include <icecream.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

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

template <class T>
size_t Heap<T>::parent(size_t pos) {
    return (pos - 1) / 2;
}

template <class T>
size_t Heap<T>::right(size_t pos){
    return (2 * pos) + 2;
}

template <class T>
size_t Heap<T>::left(size_t pos){
    return (2 * pos) + 1;
}

template <class T>
void Heap<T>::shift_down(size_t pos){
    size_t extremum = pos;
    switch (type) {
    case MIN:
        while (true) {
            size_t left_child = left(pos);
            size_t right_child = right(pos);

            if (left_child < _data.size() && min(_data[left_child], _data[extremum])) {
                extremum = left_child;
            }
            if (right_child < _data.size() && min(_data[right_child], _data[extremum])) {
                extremum = right_child;
            }
            if (extremum == pos) {
                break;
            }

            std::swap(_data[pos], _data[extremum]);
            pos = extremum;
        }
        break;
    case MAX:
        while (true) {
            size_t left_child = left(pos);
            size_t right_child = right(pos);

            if (left_child < _data.size() && max(_data[left_child], _data[extremum])) {
                extremum = left_child;
            }
            if (right_child < _data.size() && max(_data[right_child], _data[extremum])) {
                extremum = right_child;
            }
            if (extremum == pos) {
                break;
            }

            std::swap(_data[pos], _data[extremum]);
            pos = extremum;
        }
        break;
    default:
        std::logic_error("heapType is not initialized");
        break;
    }
}

template <class T>
void Heap<T>::shift_up(size_t pos){
    size_t _pos = pos;

    if (type == MIN) {
        while (parent(_pos) < _data.size() && min(_data[_pos], _data[parent(_pos)]) == true) {
            std::swap(_data[parent(_pos)], _data[_pos]);
            _pos = parent(_pos);
        }
    } else if (type == MAX) {
        while (parent(_pos) < _data.size() && max(_data[_pos], _data[parent(_pos)]) == true) {
            std::swap(_data[parent(_pos)], _data[_pos]);
            _pos = parent(_pos);
        }
    } else {
        throw std::logic_error("heapType is not initialized");
    }
}

template <class T>
}

template <class T>
size_t Heap<T>::find(T val){
    return _data.find_first(val);
}


template <class T>
void Heap<T>::heapify(){
    for(int i = _data.size()-1; i > 0; i--){
        shift_down(i);
    }
    shift_down(0);
}

template <class T>
void Heap<T>::printTree(size_t index, int indent) {
    if (index >= _data.size()) return;

    printTree(right(index), indent + 4);

    if (indent) {
        std::cout << std::setw(indent) << ' ';
    }
    std::cout << _data[index] << "\n";

    printTree(left(index), indent + 4);
}
#endif  // LIB_HEAP_LIB_HEAP_HEDER_H_
