// Copyright 2025 Kirill Remizov

#ifndef LIB_ITABLE_LIB_ITABLE_HEDER_H_
#define LIB_ITABLE_LIB_ITABLE_HEDER_H_

template <class Tkey, class Tval>
class ITable{
  public:
    virtual Tkey insert(Tval val) = 0;
    virtual void insert(Tkey key, Tval val) = 0;
    virtual void erase(Tkey key) = 0;
    virtual Tval find(Tkey key) = 0;
};

#endif  // LIB_ITABLE_LIB_ITABLE_HEDER_H_