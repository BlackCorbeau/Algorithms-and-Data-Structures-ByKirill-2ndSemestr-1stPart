// Copyright 2025 Kirill Remizov
#pragma once
#ifndef LIB_UTABLEDM_LIB_STABLE_HEADER_H_
#define LIB_UTABLEDM_LIB_STABLE_HEADER_H_

#include "../lib_Table/lib_table.h"
#include "../lib_DMassiv/DMassiv.h"
#include "../lib_pair/lib_pair_heder.h"

template <class Tkey, class Tval>
class OrderedTable : ITable<Tkey, Tval> {
private:
    DMassiv<TPair<Tkey, Tval>> table;

public:
    OrderedTable() = default;

    Tkey insert(Tval val) override;

    void insert(Tkey key, Tval val) override;

    void erase(Tkey key) override;

    Tval find(Tkey key) override;

    void print() const;

    size_t size() const;
};

template <class Tkey, class Tval>
Tkey OrderedTable<Tkey, Tval>::insert(Tval val) {
    Tkey key = static_cast<Tkey>(table.size() + 1);
    insert(key, val);
    return key;
}

template <class Tkey, class Tval>
void OrderedTable<Tkey, Tval>::insert(Tkey key, Tval val) {
    TPair<Tkey, Tval> newPair(key, val);
    size_t pos = 0;
    while (pos < table.size() && table[pos].first() < key) {
        ++pos;
    }
    table.insert(newPair, pos);
}

template <class Tkey, class Tval>
void OrderedTable<Tkey, Tval>::erase(Tkey key) {
    for (size_t i = 0; i < table.size(); ++i) {
        if (table[i].first() == key) {
            table.remove_by_index(i);
            return;
        }
    }
    throw std::out_of_range("Key not found in the table.");
}

template <class Tkey, class Tval>
Tval OrderedTable<Tkey, Tval>::find(Tkey key) {
    size_t left = 0;
    size_t right = table.size();

    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (table[mid].first() == key) {
            return table[mid].second();
        }
        if (table[mid].first() < key) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    throw std::out_of_range("Key not found in the table.");
}

template <class Tkey, class Tval>
void OrderedTable<Tkey, Tval>::print() const {
    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << "Key: " << table[i].first()
        << ", Value: " << table[i].second() << std::endl;
    }
}

template <class Tkey, class Tval>
size_t OrderedTable<Tkey, Tval>::size() const {
    return table.size();
}

#endif  // LIB_UTABLEDM_LIB_STABLE_HEADER_H_
