// Copyright 2024 Kirill Remizov

#ifndef LIB_HEAP_LIB_HASHTABLE_HEDER_H_
#define LIB_HEAP_LIB_HASHTABLE_HEDER_H_

#include <cstddef>
#include <functional>
#include <icecream.hpp>
#include <../lib_pair/lib_pair_heder.h>
#include <stdexcept>
#define CAPACITY 15

enum States {EMPTY, DELETED, BUISY};

template <class Tkey, class Tval>
struct HashNode {
private:
    TPair<Tkey, Tval> _val;
    States _state;
public:
    HashNode() : _val(), _state(EMPTY) {}
    HashNode(Tkey key, Tval val) : _val(key, val), _state(BUISY) {}

    TPair<Tkey, Tval> get_val(){
        return _val;
    }
    void set_val(TPair<Tkey, Tval> val){
        _val = val;
    }

    States get_state(){
        return _state;
    }
    void set_state(States state){
        _state = state;
    }
};

template<class Tkey, class Tval>
class OAHashT {
private:
    HashNode<Tkey, Tval> *_data;
    size_t _capacity;
    size_t _size;
public:
    OAHashT();
    OAHashT(HashNode<Tkey, Tval> *data, size_t size, size_t capacity): _data(data), _capacity(capacity), _size(size) {};
    OAHashT(HashNode<Tkey, Tval> data, size_t size);

    size_t hashFunc(const Tkey& key) {
        return (std::hash<Tkey>{}(key) % _capacity);
    }

    size_t probe(size_t hash, size_t iter) {
        return (hash + iter * iter) % _capacity;
    }

    size_t get_size() const { return _size; }
    States get_node_state(size_t index) const { return _data[index].get_state(); }
    size_t insert(HashNode<Tkey, Tval> val);
    HashNode<Tkey,Tval>* find(Tkey key);
    void eraise(Tkey key);
    void print() const;
};

template<class Tkey, class Tval>
OAHashT<Tkey, Tval>::OAHashT(){
    _capacity = CAPACITY;
    _data = new HashNode<Tkey, Tval>[_capacity];
    _size = 0;
}

template<class Tkey, class Tval>
OAHashT<Tkey, Tval>::OAHashT(HashNode<Tkey, Tval> data, size_t size) {
    _size = size;
    _capacity = (_size / CAPACITY) * CAPACITY + CAPACITY;
    _data = new HashNode<Tkey, Tval>[_capacity];
}

template<class Tkey, class Tval>
size_t OAHashT<Tkey, Tval>::insert(HashNode<Tkey, Tval> val) {
    if (_size >= _capacity) {
        return static_cast<size_t>(-1);
    }
    size_t hash = hashFunc(val.get_val().first());
    size_t iter = 0;
    size_t index;

    do {
        index = probe(hash, iter);
        if (_data[index].get_state() != BUISY) {
            _data[index].set_val(val.get_val());
            _data[index].set_state(BUISY);
            _size++;
            return index;
        }
        iter++;
    } while (iter < _capacity);
    return static_cast<size_t>(-1);
}

template <class Tkey, class Tval>
HashNode<Tkey,Tval>* OAHashT<Tkey, Tval>::find(Tkey key) {
    size_t hash = hashFunc(key);
    size_t iter = 0;
    size_t index;

    do {
        index = probe(hash, iter);
        if (_data[index].get_state() == EMPTY && _data[index].get_state() == DELETED) {
            return nullptr;
        }
        if (_data[index].get_state() == BUISY &&
            _data[index].get_val().first() == key) {
            return &_data[index];
        }
        iter++;
    } while (iter < _capacity);

    return nullptr;
}
template <class Tkey, class Tval>
void OAHashT<Tkey, Tval>::print() const {
    std::cout << "Hash Table (size: " << _size << ", capacity: " << _capacity << "):\n";
    std::cout << "| Index | Key  | Value | State  |\n";
    std::cout << "|-------|------|-------|--------|\n";

    for (size_t i = 0; i < _capacity; ++i) {
        std::cout << "| " << i << "\t| ";
        if (_data[i].get_state() == BUISY) {
            std::cout << _data[i].get_val().first() << " | "
                      << _data[i].get_val().second() << " | ";
        } else {
            std::cout << " -  |   -   | ";
        }

        switch (_data[i].get_state()) {
            case EMPTY: std::cout << "EMPTY  |\n"; break;
            case DELETED: std::cout << "DELETED|\n"; break;
            case BUISY: std::cout << "BUISY  |\n"; break;
        }
    }
    std::cout << std::endl;
}

#endif  // LIB_HEAP_LIB_HASHTABLE_HEDER_H_
