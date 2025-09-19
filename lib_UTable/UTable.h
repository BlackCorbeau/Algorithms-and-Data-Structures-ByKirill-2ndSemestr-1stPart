// Copyright 2025 Kirill Remizov
#pragma once
#ifndef LIB_UTABLE_LIB_UTABLE_HEDER_H_
#define LIB_UTABLE_LIB_UTABLE_HEDER_H_
#include "../lib_list/List.h"
#include "../lib_pair/lib_pair_heder.h"
#include "../lib_Table/lib_table.h"
#include "../lib_pair/lib_pair_heder.h"
#include "../lib_Parser/Parser.h"
#include <iostream>
#include <unordered_set>
#include <random>
#include <limits>

template<class Tkey>
Tkey generateKey() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis
        (0, std::numeric_limits<Tkey>::max());
    return dis(gen);
}


template <class Tkey, class Tval>
class UTable : ITable<Tkey, Tval> {
    TList<TPair<Tkey, Tval>> _data;
    size_t _size;
  public:
    UTable(): _size(0) {}
    UTable(const TList<TPair<Tkey, Tval>>& data) : _data(data) {
        _size = _data.size();
    }
    UTable(const UTable& tab) : _data(tab._data), _size(tab._size){};

    Tkey insert(Tval val) override;
    void insert(Tkey key, Tval val) override;
    void erase(Tkey key) override;
    Tval find(Tkey key) override;
};

template <class Tkey, class Tval>
Tkey UTable<Tkey, Tval>::insert(Tval val) {
    _size ++;
    Tkey key = generateKey<Tkey>();
    TPair<Tkey, Tval> row(key, val);
    _data.push_back(row);
    return key;
}

template <class Tkey, class Tval>
void UTable<Tkey, Tval>::insert(Tkey key, Tval val) {
    if (this->find(key) != Tval()) {
        throw std::logic_error("Key is already exist");
    }
    _size ++;
    TPair<Tkey, Tval> row(key, val);
    _data.push_back(row);
}

template <class Tkey, class Tval>
Tval UTable<Tkey, Tval>::find(Tkey key){
    TNode<TPair<Tkey, Tval>> *contr = _data.get_head();
    int size = 0;
    while (key != contr->get_val().first()) {
        contr = contr->get_pnext();
        size ++; 
    }
    if(size == this->_size){
        std::logic_error("Not enoth element with this key");
    }
    return contr->get_val().second();
}

template <class Tkey, class Tval>
void UTable<Tkey, Tval>::erase(Tkey key) {
    TNode<TPair<Tkey, Tval>> *contr = _data.get_head();
    int size = 0;
    while (key != contr->get_val().first()) {
        contr = contr->get_pnext();
        size ++; 
    }
    if(size == this->_size){
        std::logic_error("Not enoth element with this key");
    }
    this->_data.pop_pos(size);
}

#endif  // LIB_UTABLE_LIB_UTABLE_HEDER_H_
