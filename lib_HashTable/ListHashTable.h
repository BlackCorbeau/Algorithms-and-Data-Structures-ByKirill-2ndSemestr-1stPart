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
size_t ListHashT<Tkey,Tval>::insert(TList<TPair<Tkey, Tval>> val) {
    if (val.empty()) {
        throw std::invalid_argument("Cannot insert empty list into hash table");
    }

    size_t index = hashFunc(val[0].first());

    if (_data[index].empty()) {
        _data[index] = val;
    } else {
        for (const auto& pair : val) {
            bool key_exists = false;
            for (auto it = _data[index].begin(); it != _data[index].end(); ++it) {
                if (it->first() == pair.first()) {
                    it->second() = pair.second();
                    key_exists = true;
                    break;
                }
            }
            if (!key_exists) {
                _data[index].push_back(pair);
            }
        }
    }

    _size += val.size();
    return index;
}

template<class Tkey, class Tval>
size_t ListHashT<Tkey,Tval>::insert(TPair<Tkey, Tval> val) {
    size_t index = hashFunc(val.first());

    if (_data[index].empty()) {
        _data[index].push_back(val);
    } else {
        bool key_exists = false;
        for (auto it = _data[index].begin(); it != _data[index].end(); ++it) {
            if (it->first() == val.first()) {
                it->second() = val.second();
                key_exists = true;
                break;
            }
        }
        if (!key_exists) {
            _data[index].push_back(val);
        }
    }

    _size++;
    return index;
}

#endif  // LIB_HEAP_LIB_HASHTABLE_HEDER_H_
