// Copyright 2025 Kirill Remizov
#pragma once
#ifndef LIB_UTABLEDM_LIB_UTABLEDM_HEADER_H_
#define LIB_UTABLEDM_LIB_UTABLEDM_HEADER_H_
#include "../lib_DMassiv/DMassiv.h"
#include "../lib_pair/lib_pair_heder.h"
#include "../lib_Table/lib_table.h"
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
class UTableDM : public ITable<Tkey, Tval> {
    DMassiv<TPair<Tkey, Tval>> _data;
    size_t _size;
  public:
    UTableDM(): _size(_data.size()) {}
    UTableDM(const DMassiv<TPair<Tkey, Tval>>& data) : _data(data) {
        _size = _data.size();
    }
    UTableDM(const UTableDM& tab) : _data(tab._data), _size(tab._size){};

    Tkey insert(Tval val) override;
    void insert(Tkey key, Tval val) override;
    void erase(Tkey key) override;
    Tval find(Tkey key) override;
};

template <class Tkey, class Tval>
Tkey UTableDM<Tkey, Tval>::insert(Tval val) {
    Tkey key = generateKey<Tkey>();
    TPair<Tkey, Tval> row(key, val);
    _data.push_back(row);
    return key;
}

template <class Tkey, class Tval>
void UTableDM<Tkey, Tval>::insert(Tkey key, Tval val) {
    TPair<Tkey, Tval> row(key, val);
    _data.push_back(row);
}

template <class Tkey, class Tval>
Tval UTableDM<Tkey, Tval>::find(Tkey key){
    int size = _data.size();
    const TPair<Tkey, Tval>* dat = _data.data();
    int i = 0;
    while (i < size && key != dat[i].first()) {
        i++;
    }
    if (i == size) {
        throw std::logic_error("Not enough elements with this key");
    }
    return dat[i].second();
}

template <class Tkey, class Tval>
void UTableDM<Tkey, Tval>::erase(Tkey key) {
    int size = _data.size();
    const TPair<Tkey, Tval>* dat = _data.data();
    int i = 0;
    while (i < size && key != dat[i].first()) {
        i++;
    }
    if (i == size) {
        throw std::logic_error("Not enough elements with this key");
    }
    _data.remove_by_index(i);
}

#endif  // LIB_UTABLEDM_LIB_UTABLEDM_HEADER_H_
