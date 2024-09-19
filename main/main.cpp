// Copyright 2024 Marina Usova

#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include "../lib_easy_example/easy_example.h"
#include "../lib_pair/lib_pair_heder.h"
#include "../lib_DMassiv/DMassiv.h"

int main() {
  int a, b;
  float result;

  a = 1; b = 4;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }

  a = 1; b = 0;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }

  DMassiv<int> t(15, 1);
  size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = 4;
    }
  t.insert(arr, 2, 2);
  t.print();
}

#endif  // EASY_EXAMPLE
