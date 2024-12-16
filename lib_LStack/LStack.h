// Copyright 2024 Kirill Remizov
#pragma once
#ifndef LIB_STACK_LIB_LSTACK_HEDER_H_
#define LIB_STACK_LIB_LSTACK_HEDER_H_

#include "../lib_list/List.h"

template <class T>
class LStack {
private:
    TList<T> _list;

public:
    LStack() {}

    ~LStack() {}

    void push(T value) {
        _list.push_front(value);
    }

    void pop() {
        if (!_list.empty()) {
            _list.pop_front();
        }
    }

    T top() const {
        if (!_list.empty()) {
            return _list.get_head()->get_val();
        }
        throw std::out_of_range("Stack is empty");
    }

    bool empty() const {
        return _list.empty();
    }

    void print() const {
        _list.print_list();
    }
};

#endif  // LIB_STACK_LIB_STACK_HEDER_H_
