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

enum States {EMPTY, DELETED, BUISY};

template <class Tkey, class Tval>
struct HashList {
private:
    TList<TPair<Tkey, Tval>> _val;
    States _state;
public:
    HashList() : _val(), _state(EMPTY) {}
    HashList(Tkey key, Tval val) : _val(key, val), _state(BUISY) {}

    TList<TPair<Tkey, Tval>>* get_val(){
        return *_val;
    }
    void set_val(TList<TPair<Tkey, Tval>>* val){
        _val = &val;
    }

    States get_state(){
        return _state;
    }
    void set_state(States state){
        _state = state;
    }
};

template<class Tkey, class Tval>
class ListHashT {
private:
    HashList<Tkey, Tval>* _data;
    size_t _capacity;
    size_t _size;
public:

    size_t insert(HashList<Tkey, Tval> val);
    HashList<Tkey,Tval>* find(Tkey key);
    void eraise(Tkey key);
};

#endif  // LIB_HEAP_LIB_HASHTABLE_HEDER_H_
