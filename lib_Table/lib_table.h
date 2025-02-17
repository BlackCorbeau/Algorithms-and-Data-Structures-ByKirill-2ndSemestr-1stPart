// Copyright 2025 Kirill Remizov

#ifndef LIB_ITABLE_LIB_ITABLE_HEDER_H_
#define LIB_ITABLE_LIB_ITABLE_HEDER_H_

template <class Tkey, class Tval>
class ITable{
  public:
    virtual Tkey insert(Tval val);
    virtual void insert(Tkey key, Tval val);
    virtual void erase(Tkey key);
    virtual Tval find(Tkey key);
};

#endif  // LIB_ITABLE_LIB_ITABLE_HEDER_H_