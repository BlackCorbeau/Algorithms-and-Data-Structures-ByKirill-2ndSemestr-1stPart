// Copyright 2024 Kirill Remizov
#pragma once
#include <iostream>
#include <stdexcept>
#ifndef LIB_QUEUE_LIB_QUEUE_HEDER_H_
#define LIB_QUEUE_LIB_QUEUE_HEDER_H_

#include "../lib_list/List.h"

#include <iostream>
#include <stdexcept>

template <class T>
class TQueue {
    TList<T> _list;

public:
    TQueue();
    ~TQueue();

    void push_back(T val);
    void pop_front();
    T front() const;
    bool empty() const;
    void print_queue() const;
};

template <class T>
TQueue<T>::TQueue() {
    // Конструктор по умолчанию
}

template <class T>
TQueue<T>::~TQueue() {
    // Деструктор
}

template <class T>
void TQueue<T>::push_back(T val) {
    _list.push_back(val);
}

template <class T>
void TQueue<T>::pop_front() {
    if (!_list.empty()) {
        _list.pop_front();
    }
}

template <class T>
T TQueue<T>::front() const {
    if (!_list.empty()) {
        return _list.get_head()->get_val();
    }
    throw std::out_of_range("Queue is empty");
}

template <class T>
bool TQueue<T>::empty() const {
    return _list.empty();
}

template <class T>
void TQueue<T>::print_queue() const {
    _list.print_list();
}

#endif  // LIB_QUEUE_LIB_QUEUE_HEDER_H_
