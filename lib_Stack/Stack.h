// Copyright 2024 Kirill Remizov
#pragma once
#ifndef LIB_STACK_LIB_STACK_HEDER_H_
#define LIB_STACK_LIB_STACK_HEDER_H_

#include<iostream>
#include "../lib_DMassiv/DMassiv.h"
#include <stdexcept>
#define MIN_MAX_SIZE 1000000

template <typename T>
class Stack {
 private:
    DMassiv<T> _data;
    size_t _max_size;

 public:

    Stack() {
        _max_size = MIN_MAX_SIZE;
    }
    Stack(size_t max_size) : _max_size(max_size) {}

    ~Stack() {}

    void push(const T& value) {
        if (_data.size() < _max_size) {
            _data.push_back(value);
        } else {
            throw std::overflow_error("Stack is full. Cannot push.");
        }
    }

    void pop() {
        if (!_data.empty()) {
            _data.pop_back();
        } else {
            throw std::logic_error("Stack is empty. Cannot pop.");
        }
    }

    T top() const {
        if (!_data.empty()) {
            const T* a = this->_data.data();
            return a[this->_data.size() - 1];
        } else {
            throw std::logic_error("Stack is empty. Cannot get top.");
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
