// Copyright 2024 Kirill Remizov
#pragma once
#ifndef LIB_LIST_LIB_LIST_HEDER_H_
#define LIB_LIST_LIB_LIST_HEDER_H_

template <class T>
class TNode {
    T _value;
    TNode<T>* _pnext;
 public:
    TNode();
    TNode(const TNode<T>* node);
    TNode(T val, TNode<T>* _next);

    ~TNode() { }

    void set_val(T val);
    void set_pnext(TNode<T>* _pnext);

    T get_val() const;
    TNode<T>* get_pnext() const;

    void next();
    TNode<T>& operator=(const TNode<T>& other);
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
TNode<T>* TNode<T>::get_pnext() const {
    return _pnext;
}

template <class T>
void TNode<T>::next() {
    this = _pnext;
}

template <class T>
TNode<T>& TNode<T>::operator=(const TNode<T>& other) {
    if (this == &other) {
        return *this;
    }

    delete _pnext;

    _value = other._value;
    if (other._pnext) {
        _pnext = new TNode<T>(*other._pnext);
    } else {
        _pnext = nullptr;
    }

    return *this;
}

template <class T>
class TList {
    TNode<T>* _head;
    TNode<T>* _tail;
 public:
    TList();
    TList(const TList<T>* l);
    TList(TNode<T>* head, TNode<T>* tail);

    ~TList() { }

    void set_head(TNode<T>* head);
    void set_tail(TNode<T>* tail);

    TNode<T>* get_head() const;
    TNode<T>* get_tail() const;

    bool empty() const;

    void push_front(TNode<T>* val);
    void push_back(TNode<T>* val);
    void push_pos(TNode<T>* val, int pos);

    void pop_back();
    void pop_front();
    void pop_pos(int pos);

    TNode<T>* find(T val);

    void change_first(TNode<T>* val);
    void change_last(TNode<T>* val);
    void change_pos(TNode<T>* val, int pos);
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
void TList<T>::push_front(TNode<T>* val) {
    if (_head == nullptr) {
        _head = val;
        _tail = val;
    } else {
        val->set_pnext(_head);
        _head = val;
    }
}

template <class T>
void TList<T>::push_back(TNode<T>* val) {
    if (_tail == nullptr) {
        _head = val;
        _tail = val;
    } else {
        _tail->set_pnext(val);
        _tail = val;
    }
}

template <class T>
void TList<T>::push_pos(TNode<T>* val, int pos) {
    int counter = 0;
    TNode<T>* ex = this->_head;
    while (ex != nullptr) {
        if (counter == pos) {
            val->set_pnext(ex->get_pnext());
            ex->set_pnext(val);
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
void TList<T>::change_first(TNode<T>* val) {
    if (_head != nullptr) {
        _head->set_val(val->get_val());
    }
}

template <class T>
void TList<T>::change_last(TNode<T>* val) {
    if (_tail != nullptr) {
        _tail->set_val(val->get_val());
    }
}

template <class T>
void TList<T>::change_pos(TNode<T>* val, int pos) {
    int counter = 0;
    TNode<T>* ex = _head;
    while (ex != nullptr) {
        if (counter == pos) {
            ex->set_val(val->get_val());
            break;
        } else {
            counter += 1;
            ex = ex->get_pnext();
        }
    }
}

#endif  // LIB_LIST_LIB_LIST_HEDER_H_
