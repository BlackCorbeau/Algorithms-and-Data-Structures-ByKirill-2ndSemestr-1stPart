// Copyright 2024 Kirill Remizov

#ifndef LIB_HEAP_LIB_HASHTABLE_HEDER_H_
#define LIB_HEAP_LIB_HASHTABLE_HEDER_H_

#include <cstddef>
#include <functional>
#include <icecream.hpp>
#include "../lib_pair/lib_pair_heder.h"
#include "../lib_list/List.h"
#include <stdexcept>
#define CAPACITY 15

template<class Tkey, class Tval>
class ListHashT {
private:
    HashList<Tkey, Tval>* _data;
    size_t _capacity;
    size_t _size;
public:
    ListHashT(): _data(), _capacity(CAPACITY), _size(0){};
    ListHashT(HashList<Tkey, Tval> *data, size_t size, size_t capacity): _data(data), _capacity(capacity), _size(size) {};
    ListHashT(HashList<Tkey, Tval> data, size_t size) {
        _size = size;
        _capacity = (_size / CAPACITY) * CAPACITY + CAPACITY;
        _data = new HashList<Tkey,Tval>[_capacity];
    };

    size_t hashFunc(const Tkey& key) {
        return (std::hash<Tkey>{}(key) % _capacity);
    }

    size_t insert(HashList<Tkey, Tval> val);
    HashList<Tkey,Tval>* find(Tkey key);
    void eraise(Tkey key);
};

#endif  // LIB_HEAP_LIB_HASHTABLE_HEDER_H_
