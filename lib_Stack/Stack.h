// Copyright 2024 Kirill Remizov
#pragma once
#ifndef LIB_STACK_LIB_STACK_HEDER_H_
#define LIB_STACK_LIB_STACK_HEDER_H_

#include<iostream>
#include "../lib_DMassiv/DMassiv.h"

template <typename T>
class Stack {
private:
    DMassiv<T> _data;

public:
    Stack() {}

    ~Stack() {}

    void push(const T& value) {
        _data.push_back(value);
    }

    void pop() {
        if (!_data.empty()) {
            _data.pop_back();
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    T top() const {
        if (!_data.empty()) {
            const T* a = this->_data.data();
            return a[this->_data.size() - 1];
        } else {
            std::cout << "Stack is empty. Cannot get top." << std::endl;
            return T();
        }
    }

    bool empty() const {
        return _data.empty();
    }

    size_t size() const {
        return _data.size();
    }

    void print() const {
        _data.print();
    }
};

#endif  // LIB_STACK_LIB_STACK_HEDER_H_
