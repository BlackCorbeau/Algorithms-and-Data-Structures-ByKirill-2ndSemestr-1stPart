// Copyright 2024 Kirill Remizov

#ifndef LIB_HEAP_LIB_HASHTABLE_HEDER_H_
#define LIB_HEAP_LIB_HASHTABLE_HEDER_H_

#include <cstddef>
#include <functional>
#include "icecream.hpp"
#include "../lib_pair/lib_pair_heder.h"
#include "../lib_list/List.h"
#include <iostream>
#include <stdexcept>
#define CAPACITY 15

template<class Tkey, class Tval>
class ListHashT {
private:
    TList<TPair<Tkey, Tval>>* _data;
    size_t _capacity;
    size_t _size;
public:
    ListHashT() : _capacity(CAPACITY), _size(0) { _data = new TList<TPair<Tkey, Tval>>[_capacity]; };
    ListHashT(TList<TPair<Tkey, Tval>>* data, size_t size, size_t capacity): _data(data), _capacity(capacity), _size(size) {};
    ListHashT(TList<TPair<Tkey, Tval>>* data, size_t size) {
        _size = size;
        _capacity = (_size / CAPACITY) * CAPACITY + CAPACITY;
        _data = new TList<TPair<Tkey, Tval>>[_capacity];
    };

    ~ListHashT() {
        delete[] _data;
    }

    size_t hashFunc(const Tkey& key) {
        return (std::hash<Tkey>{}(key) % _capacity);
    }

    size_t size() { return _size; }
    size_t capacity() { return _capacity; }
    void insert(Tkey key, Tval val);
    Tval find(Tkey key);
    void eraise(Tkey key);
};


template<class Tkey, class Tval>
void ListHashT<Tkey,Tval>::insert(Tkey key, Tval val) {
    TPair<Tkey, Tval> _val(key, val);
    size_t index = hashFunc(key);
    if (_size >= _capacity) {
        return;
    }
    if(_data[index].find(_val) == nullptr){
        _data[index].push_back(_val);
        _size++;
        return;
    }
}

template <class Tkey, class Tval>
Tval ListHashT<Tkey, Tval>::find(Tkey key){
    size_t index = hashFunc(key);

    for (auto& pair : _data[index]) {
        if (pair.first() == key) {
            return pair.second();
        }
    }
    return Tval();
}

template <class Tkey, class Tval>
void ListHashT<Tkey, Tval>::eraise(Tkey key){
    size_t index = hashFunc(key);

    for (int i = _data[index].size() - 1; i >= 0 ; i--) {
        if (_data[index][i].first() == key) {
            _data[index].pop_pos(i);
            _size --;
        } else if (_data[index].empty() == true) {
            return;
        }
    }
}

#endif  // LIB_HEAP_LIB_HASHTABLE_HEDER_H_
