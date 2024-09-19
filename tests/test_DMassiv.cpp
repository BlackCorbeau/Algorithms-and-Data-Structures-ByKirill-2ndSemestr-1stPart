// Copyright 2024 Kirill Remizov

#include <gtest.h>
#include"../lib_DMassiv/DMassiv.h"

#define EPSILON 0.000001

TEST(libDMassiv, CheckingConstructorZero) {
    DMassiv<int> t;

    ASSERT_NO_THROW(t);
}


TEST(libDMassiv, CheckingConstructorInitial) {
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    DMassiv<int> t(arr, size);

    ASSERT_NO_THROW(t);
    const int* a = t.data();
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(a[i], arr[i]);
    }
}

TEST(libDMassiv, CheckingConstructorCopy) {
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    DMassiv<int> t(arr, size);
    DMassiv<int> t1(t);

    ASSERT_NO_THROW(t1);
    const int* a = t.data();
    const int* b = t1.data();
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(b[i], a[i]);
    }
}

TEST(libDMassiv, CheckingConstructorInitializationWithSameElements) {
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = 1;
    }

    DMassiv t(5, 1);

    ASSERT_NO_THROW(t);
    const int* a = t.data();
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(a[i], arr[i]);
    }
}

TEST(libDMassiv, CheckingConstructorInitializationWithNotAllElements) {
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    DMassiv<int> t(arr, size);
    DMassiv<int> t1(t, 1, 2);

    ASSERT_NO_THROW(t1);
    const int* a = t.data();
    const int* b = t1.data();
    for (int i = 1; i < 3; i++) {
        EXPECT_EQ(b[i - 1], a[i]);
    }
}

TEST(libDMassiv, CheckingGetterSize) {
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    DMassiv<int> t(arr, size);

    ASSERT_NO_THROW(t);
    EXPECT_EQ(t.size(), 5);
}

TEST(libDMassiv, CheckingGetterCapacity) {
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    DMassiv<int> t(arr, size);

    ASSERT_NO_THROW(t);
    EXPECT_EQ(t.capacity(), 15);
}

TEST(libDMassiv, CheckingGetterData) {
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    DMassiv<int> t(arr, size);

    ASSERT_NO_THROW(t);
    const int* a = t.data();
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(a[i], arr[i]);
    }
}

TEST(libDMassiv, CheckingSwapF) {
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    DMassiv<int> t(arr, size);
    DMassiv<int> t1(5, 7);

    ASSERT_NO_THROW(t);
    ASSERT_NO_THROW(t1);

    t.swap(t1);

    const int* a = t.data();
    const int* b = t1.data();
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(a[i], 7);
        EXPECT_EQ(b[i], arr[i]);
    }
}

TEST(libDMassiv, CheckingClearF) {
    DMassiv<int> t(5, 1);

    ASSERT_NO_THROW(t.clear());

    EXPECT_EQ(t.size(), 0);
    EXPECT_EQ(t.capacity(), 15);
    EXPECT_EQ(t.data(), nullptr);
}

TEST(libDMassiv, CheckingMethodResolve) {
    DMassiv<int> t(15, 1);

    t.reserve(5);

    EXPECT_EQ(t.capacity(), 30);
}

TEST(libDMassiv, CheckingMethodResize) {
    DMassiv<int> t(10, 5);

    t.resize(2, 3);

    int ans[11] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3};

    const int* a = t.data();

    for (int i = 0; i < 11; i++) {
        EXPECT_EQ(a[i], ans[i]);
    }
}

TEST(libDMassiv, CheckingAssignMethod) {
    DMassiv<int> t(15, 1);
    DMassiv<int> t1(5, 4);

    int ans[5] = {4, 4, 4, 4, 4};

    ASSERT_NO_THROW(t.assign(t1));
    const int* a = t.data();
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(a[i], ans[i]);
    }
}

TEST(libDMassiv, CheckingMethodPushBack) {
    DMassiv<int> t(5, 4);

    ASSERT_NO_THROW(t.push_back(5));
    const int* a = t.data();
    EXPECT_EQ(a[5], 5);
}

TEST(libDMassiv, CheckingMethodPopBack) {
    DMassiv<int> t(5, 4);

    ASSERT_NO_THROW(t.pop_back());
    int a = t.size();
    EXPECT_EQ(a, 4);
}

TEST(libDMassiv, CheckingMethodPushFront) {
    DMassiv<int> t(5, 4);

    ASSERT_NO_THROW(t.push_front(3));
    const int* a = t.data();
    EXPECT_EQ(a[0], 3);
}

TEST(libDMassiv, CheckingMethodPopFront) {
    DMassiv<int> t(5, 4);

    ASSERT_NO_THROW(t.pop_front());
    int a = t.size();
    const int* _a = t.data();
    EXPECT_EQ(a, 4);
    EXPECT_EQ(_a[0], 4);
}

TEST(libDMassiv, CheckingMethodRemoveByIndex) {
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    DMassiv<int> t(arr, size);

    ASSERT_NO_THROW(t.remove_by_index(2));
    int a = t.size();
    const int* _a = t.data();
    EXPECT_EQ(a, 4);
}

TEST(libDMassiv, CheckingMethodInsert1) {
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    DMassiv<int> t(arr, size);

    ASSERT_NO_THROW(t.insert(9, 2));
    int a = t.size();
    const int* _a = t.data();
    EXPECT_EQ(a, 6);
    EXPECT_EQ(_a[2], 9);
}

TEST(libDMassiv, checkingMethodInsert2) {
    DMassiv<int> t(15, 1);
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = 4;
    }

    ASSERT_NO_THROW(t.insert(arr, 2, 2));
    const int* b = t.data();
    int c = t.size();
    EXPECT_EQ(c, 17);
    for (int i = 2; i < 4; i++) {
        EXPECT_EQ(b[i], 4);
    }
}

TEST(libDMassiv, checkingMethodReplace) {
    DMassiv<int> t(15, 1);

    ASSERT_NO_THROW(t.replace(2, 2));
    const int* a = t.data();
    EXPECT_EQ(a[2], 2);
}

TEST(libDMassiv, checkingMethodErase) {
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    DMassiv<int> t(arr, size);

    ASSERT_NO_THROW(t.erase(2, 2));

    EXPECT_EQ(t.size(), 3);
}

TEST(libDMassiv, checkingRemooveAllMethod) {
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    DMassiv<int> t(arr, size);
    t.push_back(4);

    ASSERT_NO_THROW(t.remove_all(4));
    EXPECT_EQ(t.size(), 6-2);
}

TEST(libDMassiv, checkingRemoveFirstMethod) {
    size_t size = 5;
    int* arr;
    arr = new int[size];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    DMassiv<int> t(arr, size);
    t.push_back(2);

    ASSERT_NO_THROW(t.remove_first(2));
    const int* a = t.data();
    EXPECT_EQ(t.size(), 6-1);
    EXPECT_EQ(a[5], 2);
}
// TEST(libDMassiv, CheckingReserveF)
