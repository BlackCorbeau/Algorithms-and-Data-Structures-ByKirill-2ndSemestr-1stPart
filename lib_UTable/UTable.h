// Copyright 2025 Kirill Remizov
#pragma once
#ifndef LIB_DMASSIVE_LIB_DMASSIVE_HEDER_H_
#define LIB_DMASSIVE_LIB_DMASSIVE_HEDER_H_
#include "../lib_list/List.h"
#include "../lib_pair/lib_pair_heder.h"
#include "../lib_Table/lib_table.h"

template <class Tkey, class Tval>
class UTable : ITable<Tkey, Tval> {
    TList<TPair<Tkey, Tval>> _data;
    size_t _size;
  public:
    UTable() {}
    UTable(const TList<TPair<Tkey, Tval>>& data) : _data(data) {
        _size = _data.size();
    }
    UTable(const UTable& tab) : _data(tab._data), _size(tab._size){};

    Tkey insert(Tval val) override;
    void insert(Tkey key, Tval val) override;
    void erase(Tkey key) override;
    Tval find(Tkey key) override;
};

#endif  // LIB_DMASSIVE_LIB_DMASSIVE_HEDER_H_