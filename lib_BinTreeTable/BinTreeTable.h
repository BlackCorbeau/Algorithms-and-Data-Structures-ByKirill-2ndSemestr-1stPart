// Copyright 2024 Kirill Remizov

#ifndef LIB_BINTREETABLE_LIB_BINTREETABLE_HEDER_H_
#define LIB_BINTREETABLE_LIB_BINTREETABLE_HEDER_H_

#pragma once
#include "../lib_BinTree/BinTree.h"
#include "../lib_pair/lib_pair_heder.h"
#include "../lib_Table/lib_table.h"

template <class Tkey, class Tval>
class BTTable : ITable<Tkey, Tval> {
private:
    BinTree<TPair<Tkey, Tval>> table;
    size_t _size;

public:
    BTTable(): _size(0) {}

    int size() {return _size;}

    Tkey insert(Tval val) override;

    void insert(Tkey key, Tval val) override;

    void erase(Tkey key) override;

    Tval find(Tkey key) override;

    void print() const noexcept;
};

template <class Tkey, class Tval>
Tkey BTTable<Tkey, Tval>::insert(Tval val) {
    _size++;
    TPair<Tkey, Tval> par(_size, val);
    table.Insert(par);
    return _size;
}

template <class Tkey, class Tval>
void BTTable<Tkey, Tval>::insert(Tkey key, Tval val) {
    _size++;
    TPair<Tkey, Tval> par(key, val);
    table.Insert(par);
}

template <class Tkey, class Tval>
void BTTable<Tkey, Tval>::erase(Tkey key) {
    TPair<Tkey, Tval> tempPair(key, Tval());

    if (table.Search(tempPair) != nullptr) {
        table.Remove(tempPair);
        _size--;
    }
}

