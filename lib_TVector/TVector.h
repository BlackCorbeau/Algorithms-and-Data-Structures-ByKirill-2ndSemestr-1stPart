// Copyright 2024 Kirill Remizov
#pragma once
#ifndef LIB_TVECTOR_LIB_TVECTOR_HEDER_H_
#define LIB_TVECTOR_LIB_TVECTOR_HEDER_H_

#include<iostream>
#include "../lib_DMassiv/DMassiv.h"

template <typename T>
class TVector {
 private:
    DMassiv<T> _data;

 public:
    TVector();
    TVector(const TVector& other);
    TVector(const T* arr, size_t n);
    TVector(size_t n, T value);
    ~TVector();

    bool empty() const noexcept;
    size_t size() const;
    size_t capacity() const;
    void clear();
    void reserve(size_t n);
    void resize(size_t n, T value);
    void push_back(T value);
    void pop_back();
    void push_front(T value);
    void pop_front();
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    void insert(size_t pos, T value);
    void erase(size_t pos, size_t n);
    void remove_all(T value);
    void remove_first(T value);
    void remove_last(T value);
    size_t find_first(T value);
    size_t find_last(T value);
    void print() const noexcept;
};

// Реализация методов TVector

template <typename T>
TVector<T>::TVector() : _data() {}

template <typename T>
TVector<T>::TVector(const TVector& other) : _data(other._data) {}

template <typename T>
TVector<T>::TVector(const T* arr, size_t n) : _data(arr, n) {}

template <typename T>
TVector<T>::TVector(size_t n, T value) : _data(n, value) {}

template <typename T>
TVector<T>::~TVector() {}

template <typename T>
bool TVector<T>::empty() const noexcept {
    return _data.empty();
}

template <typename T>
size_t TVector<T>::size() const {
    return _data.size();
}

template <typename T>
size_t TVector<T>::capacity() const {
    return _data.capacity();
}

template <typename T>
void TVector<T>::clear() {
    _data.clear();
}

template <typename T>
void TVector<T>::reserve(size_t n) {
    _data.reserve(n);
}

template <typename T>
void TVector<T>::resize(size_t n, T value) {
    _data.resize(n, value);
}

template <typename T>
void TVector<T>::push_back(T value) {
    _data.push_back(value);
}

template <typename T>
void TVector<T>::pop_back() {
    _data.pop_back();
    _data.repack();
}

template <typename T>
void TVector<T>::push_front(T value) {
    _data.push_front(value);
}

template <typename T>
void TVector<T>::pop_front() {
    _data.pop_front();
    _data.repack();
}

template <typename T>
T& TVector<T>::operator[](size_t index) {
    if (index >= _data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return const_cast<T&>(_data.data()[index]);
}

template <typename T>
const T& TVector<T>::operator[](size_t index) const {
    if (index >= _data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return _data.data()[index];
}

template <typename T>
void TVector<T>::insert(size_t pos, T value) {
    _data.insert(value, pos);
}

template <typename T>
void TVector<T>::erase(size_t pos, size_t n) {
    _data.erase(pos, n);
}

template <typename T>
void TVector<T>::remove_all(T value) {
    _data.remove_all(value);
    _data.repack();
}

template <typename T>
void TVector<T>::remove_first(T value) {
    _data.remove_first(value);
}

template <typename T>
void TVector<T>::remove_last(T value) {
    _data.remove_last(value);
}

template <typename T>
size_t TVector<T>::find_first(T value) {
    return _data.find_first(value);
}

template <typename T>
size_t TVector<T>::find_last(T value) {
    return _data.find_last(value);
}

template <typename T>
void TVector<T>::print() const noexcept {
    _data.print();
}

#endif  // LIB_TVECTOR_LIB_TVECTOR_HEDER_H_
