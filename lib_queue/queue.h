// Copyright 2024 Kirill Remizov
#pragma once
#include <iostream>
#include <stdexcept>
#ifndef LIB_QUEUE_LIB_QUEUE_HEDER_H_
#define LIB_QUEUE_LIB_QUEUE_HEDER_H_

#include "../lib_list/List.h"

template <class T>
class TQueue {
    TList<T> _list;

 public:
    TQueue();
    ~TQueue();

    void enqueue(T value);
    void dequeue();
    T front() const;
    bool isEmpty() const;
};

template <class T>
TQueue<T>::TQueue() { }

template <class T>
TQueue<T>::~TQueue() { }

template <class T>
void TQueue<T>::enqueue(T value) {
    TNode<T>* newNode = new TNode<T>(value, nullptr);
    _list.push_back(newNode);
}

template <class T>
void TQueue<T>::dequeue() {
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
bool TQueue<T>::isEmpty() const {
    return _list.empty();
}

#endif  // LIB_QUEUE_LIB_QUEUE_HEDER_H_
