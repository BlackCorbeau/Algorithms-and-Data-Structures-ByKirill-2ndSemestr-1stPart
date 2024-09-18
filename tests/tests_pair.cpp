// Copyright 2024 Kirill Remizov

#include <gtest.h>
#include"../lib_pair/lib_pair_heder.h"

#define EPSILON 0.000001

TEST(libPair, CanCreatedWithDifferentBaseTypes0) {
    TPair<int, int> ex(1, 12);

    ASSERT_NO_THROW(ex);
}

TEST(libPair, CanCreatedWithDifferentBaseTypes1) {
    TPair<int, char> ex1(1, 'a');

    ASSERT_NO_THROW(ex1);
}

TEST(libPair, CanCreatedWithDifferentBaseTypes2) {
    TPair<int, double> ex2(1, 12.12);

    ASSERT_NO_THROW(ex2);
}

TEST(libPair, CanCreatedWithDifferentBaseTypes3) {
    TPair<int, bool> ex3(5, true);

    ASSERT_NO_THROW(ex3);
}

TEST(libPair, CanCreatedWithDifferentBaseTypes4) {
    TPair<char, char> ex4('a', 'b');

    ASSERT_NO_THROW(ex4);
}

TEST(libPair, CanCreatedWithDifferentBaseTypes5) {
    TPair<char, double> ex5('a', 3.14);

    ASSERT_NO_THROW(ex5);
}

TEST(libPair, CanCreatedWithDifferentBaseTypes6) {
    TPair<char, bool> ex6('a', true);

    ASSERT_NO_THROW(ex6);
}

TEST(libPair, CanCreatedWithDifferentBaseTypes7) {
    TPair<double, double> ex7(1.12, 3.14);

    ASSERT_NO_THROW(ex7);
}

TEST(libPair, CanCreatedWithDifferentBaseTypes8) {
    TPair<double, bool> ex8(1.12, false);

    ASSERT_NO_THROW(ex8);
}

TEST(libPair, CanCreatedWithDifferentBaseTypes9) {
    TPair<bool, bool> ex9(true, false);

    ASSERT_NO_THROW(ex9);
}

TEST(libPair, CheckingConstructorsFunc0) {
    TPair<int, int> ex;

    ASSERT_NO_THROW(ex);
}

TEST(libPair, CheckingConstructorsFunc1) {
    TPair<int, int> ex1(1, 2);

    ASSERT_NO_THROW(ex1);
}

TEST(libPair, CheckingConstructorsFunc2) {
    TPair<int, int> ex1(1, 2);
    TPair<int, int> ex2(ex1);

    ASSERT_NO_THROW(ex2);
}

TEST(libPair, CheckingCopyConstructorsFunc) {
    TPair<int, int> ex(1, 2);
    TPair<int, int> ex1(ex);

    int actual_results[2] = { ex1.first(), ex1.second() };

    EXPECT_EQ(actual_results[0], 1);
    EXPECT_EQ(actual_results[1], 2);
}

TEST(libPair, CheckingGetters) {
    TPair<int, int> ex(3, 5);

    int _first = ex.first();
    int _second = ex.second();

    EXPECT_EQ(_first, 3);
    EXPECT_EQ(_second, 5);
}

TEST(libPair, CheckingSetters) {
    TPair<int, int> ex;

    ex.set_first(5);
    ex.set_second(7);

    EXPECT_EQ(ex.first(), 5);
    EXPECT_EQ(ex.second(), 7);
}

TEST(libPair, CheckingOperatorEqually) {
    TPair<char, char> t;
    TPair<char, char> ans('a', 'b');

    t = ans;

    EXPECT_EQ(t.first(), 'a');
    EXPECT_EQ(t.second(), 'b');
}
