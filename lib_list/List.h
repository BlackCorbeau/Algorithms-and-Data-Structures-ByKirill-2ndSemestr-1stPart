// Copyright 2024 Kirill Remizov
#pragma once
#ifndef LIB_LIST_LIB_LIST_HEDER_H_
#define LIB_LIST_LIB_LIST_HEDER_H_

#include <iostream>
#include <stdexcept>

template <class T>
class TNode {
    T _value;
    TNode<T>* _pnext;
public:
    TNode();
    explicit TNode(const TNode<T>* node);
    TNode(T val, TNode<T>* _next);

    ~TNode() { }

    void set_val(T val);
    void set_pnext(TNode<T>* _pnext);

    T get_val() const;
    T& get_val_ref();
    TNode<T>* get_pnext() const;
};

template <class T>
TNode<T>::TNode() {
    _pnext = nullptr;
}

template <class T>
TNode<T>::TNode(const TNode<T>* node) {
    _value = node->_value;
    _pnext = node->_pnext;
}

template <class T>
TNode<T>::TNode(T val, TNode<T>* _next) {
    _value = val;
    _pnext = _next;
}

template <class T>
void TNode<T>::set_val(T val) {
    _value = val;
}

template <class T>
void TNode<T>::set_pnext(TNode<T>* _pnext) {
    this->_pnext = _pnext;
}

template <class T>
T TNode<T>::get_val() const {
    return this->_value;
}

template <class T>
T& TNode<T>::get_val_ref() {
    return _value;
}

template <class T>
TNode<T>* TNode<T>::get_pnext() const {
    return _pnext;
}

template <class T>
class TList {
private:
    class TIterator {
        TNode<T>* _node;
        
    public:
        TIterator(TNode<T>* node = nullptr) : _node(node) {}

        T& operator*() const {
            return _node->get_val_ref();
        }

        T* operator->() {
            return &(_node->get_val_ref());
        }

        TIterator& operator++() {
            if (_node) {
                _node = _node->get_pnext();
            }
            return *this;
        }

        TIterator operator++(int) {
            TIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const TIterator& other) const {
            return _node == other._node;
        }

        bool operator!=(const TIterator& other) const {
            return _node != other._node;
        }
    };

public:
    using iterator = TIterator;

    TList();
    explicit TList(const TList<T>* l);
    TList(TNode<T>* head, TNode<T>* tail);

    ~TList() { }

    void set_head(TNode<T>* head);
    void set_tail(TNode<T>* tail);

    TNode<T>* get_head() const;
    TNode<T>* get_tail() const;

    bool empty() const;

    void push_front(T _val);
    void push_back(T _val);
    void push_pos(T _val, int pos);

    void pop_back();
    void pop_front();
    void pop_pos(int pos);

    TNode<T>* find(T val);

    void change_first(T val);
    void change_last(T val);
    void change_pos(T val, int pos);

    T& operator[](int index);

    void print_list() const;

    iterator begin() {
        return iterator(_head);
    }

    iterator end() {
        return iterator(nullptr);
    }

private:
    TNode<T>* _head;
    TNode<T>* _tail;
};

template <class T>
TList<T>::TList() {
    _head = nullptr;
    _tail = nullptr;
}

template <class T>
TList<T>::TList(const TList<T>* l) {
    _head = l->_head;
    _tail = l->_tail;
}

template <class T>
TList<T>::TList(TNode<T>* head, TNode<T>* tail) {
    _head = head;
    _tail = tail;
}

template <class T>
void TList<T>::set_head(TNode<T>* head) {
    _head = head;
}

template <class T>
void TList<T>::set_tail(TNode<T>* tail) {
    _tail = tail;
}

template <class T>
TNode<T>* TList<T>::get_head() const {
    return _head;
}

template <class T>
TNode<T>* TList<T>::get_tail() const {
    return _tail;
}

template <class T>
bool TList<T>::empty() const {
    if (_head == nullptr) {
        return true;
    } else {
        return false;
    }
}

template <class T>
void TList<T>::push_front(T _val) {
    TNode<T>* val = new TNode<T>(_val, _head);
    if (_head == nullptr) {
        _head = val;
        _tail = val;
    } else {
        _head = val;
    }
}

template <class T>
void TList<T>::push_back(T _val) {
    TNode<T>* val = new TNode<T>(_val, nullptr);
    if (_tail == nullptr) {
        _head = val;
        _tail = val;
    } else {
        _tail->set_pnext(val);
        _tail = val;
    }
}

template <class T>
void TList<T>::push_pos(T _val, int pos) {
    TNode<T>* val = new TNode<T>(_val, nullptr);
    if (pos == 0) {
        val->set_pnext(_head);
        _head = val;
        if (_tail == nullptr) {
            _tail = val;
        }
        return;
    }

    int counter = 0;
    TNode<T>* ex = _head;
    while (ex != nullptr) {
        if (counter == pos - 1) {
            val->set_pnext(ex->get_pnext());
            ex->set_pnext(val);
            if (val->get_pnext() == nullptr) {
                _tail = val;
            }
            break;
        } else {
            counter += 1;
            ex = ex->get_pnext();
        }
    }
}

template <class T>
void TList<T>::pop_back() {
    if (_head == nullptr) return;
    if (_head == _tail) {
        _head = nullptr;
        _tail = nullptr;
        return;
    }
    TNode<T>* ex = _head;
    while (ex->get_pnext() != _tail) {
        ex = ex->get_pnext();
    }
    _tail = ex;
    _tail->set_pnext(nullptr);
}

template <class T>
void TList<T>::pop_front() {
    if (_head == nullptr) return;
    _head = _head->get_pnext();
    if (_head == nullptr) {
        _tail = nullptr;
    }
}

template <class T>
void TList<T>::pop_pos(int pos) {
    if (_head == nullptr) return;
    int counter = 0;
    TNode<T>* ex = _head;
    TNode<T>* prev = nullptr;
    while (ex != nullptr) {
        if (counter == pos) {
            if (prev != nullptr) {
                prev->set_pnext(ex->get_pnext());
            } else {
                _head = ex->get_pnext();
            }
            if (ex == _tail) {
                _tail = prev;
            }
            delete ex;
            break;
        } else {
            counter += 1;
            prev = ex;
            ex = ex->get_pnext();
        }
    }
}

template <class T>
TNode<T>* TList<T>::find(T val) {
    TNode<T>* ex = _head;
    while (ex != nullptr) {
        if (ex->get_val() == val) {
            return ex;
        }
        ex = ex->get_pnext();
    }
    return nullptr;
}

template <class T>
void TList<T>::change_first(T val) {
    if (_head != nullptr) {
        _head->set_val(val);
    }
}

template <class T>
void TList<T>::change_last(T val) {
    if (_tail != nullptr) {
        _tail->set_val(val);
    }
}

template <class T>
void TList<T>::change_pos(T val, int pos) {
    int counter = 0;
    TNode<T>* ex = _head;
    while (ex != nullptr) {
        if (counter == pos) {
            ex->set_val(val);
            break;
        } else {
            counter += 1;
            ex = ex->get_pnext();
        }
    }
}

template <class T>
T& TList<T>::operator[](int index) {
    TNode<T>* current = _head;
    int counter = 0;
    while (current != nullptr) {
        if (counter == index) {
            return current->get_val_ref();
        }
        counter++;
        current = current->get_pnext();
    }
    throw std::out_of_range("Index out of range");
}

template <class T>
void TList<T>::print_list() const {
    TNode<T>* current = _head;
    while (current != nullptr) {
        std::cout << current->get_val() << " ";
        current = current->get_pnext();
    }
    std::cout << std::endl;
}


#endif  // LIB_LIST_LIB_LIST_HEDER_H_
