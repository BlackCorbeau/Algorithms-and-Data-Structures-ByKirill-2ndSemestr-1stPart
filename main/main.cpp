// Copyright 2024 Marina Usova

#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE

#include <iostream>
#include <chrono>
#include "../lib_Heap/Heap.h"

template <class T>
void heapSort(T* array, size_t size, heapType type) {

    Heap<T> heap(array, size, type);

    for (int i = size - 1; i >= 0; i--) {
        array[i] = heap.top();
        heap.eraise(heap.top());
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n, MAX);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    heapSort(arr, n, MIN);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
return 0;
}

#endif  // EASY_EXAMPLE
