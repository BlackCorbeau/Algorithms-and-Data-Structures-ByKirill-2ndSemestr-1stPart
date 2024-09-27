// Copyright 2024 Kirill Remizov

#ifndef LIB_ALGORITMS_LIB_ALGORITMS_HEDER_H_
#define LIB_ALGORITMS_LIB_ALGORITMS_HEDER_H_

namespace algorithms {
    template<typename T>
    void swap(T& val_1, T& val_2) {
        T tmp = val_1;
        val_1 = val_2;
        val_2 = tmp;
    }

    template<typename T>
    T max(T val_1, T val_2) {
        if (val_1 > val_2) return val_1;
        else return val_2;
    }

    template<typename T>
    T min(T val_1, T val_2) {
        if (val_1 < val_2) return val_1;
        else return val_2;
    }
}

#endif  // LIB_ALGORITMS_LIB_ALGORITMS_HEDER_H_