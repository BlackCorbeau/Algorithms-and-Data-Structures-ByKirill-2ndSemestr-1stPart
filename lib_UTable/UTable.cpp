// Copyright 2025 Kirill Remizov

#include "./UTable.h"
#include "../lib_Parser/Parser.h"

template <class Tkey, class Tval>
Tkey UTable<Tkey, Tval>::insert(Tval val) {
    int key = GenerateIntId();
    TPair<Tkey, Tval> row(key, val);
    _data.push_back(row);
    return key;
}

template <class Tkey, class Tval>
void UTable<Tkey, Tval>::insert(Tkey key, Tval val) {
    TPair<Tkey, Tval> row(key, val);
    _data.push_back(row);
}

// Copyright 2024 Kirill Remizov