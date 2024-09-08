// Copyright 2024 Kirill Remizov

#include <gtest.h>
#include"../lib_pair/lib_pair_heder.h"

#define EPSILON 0.000001

TEST(libPair, CanCreatedWithDifferentBaseTypes) {
    TPair<int, int> ex(1, 12);
    TPair<int, char> ex1(1, 'a');
    TPair<int, double> ex2(1, 12.12);
    TPair<int, bool> ex3(5, true);
    TPair<char, char> ex4('a', 'b');
    TPair<char, double> ex5('a', 3.14);
    TPair<char, bool> ex6('a', true);
    TPair<double, double> ex7(1.12, 3.14);
    TPair<double, bool> ex8(1.12, false);
    TPair<bool, bool> ex9(true, false);

    ASSERT_NO_THROW(ex, ex1, ex2, ex3, ex4, ex5, ex6, ex7, ex8, ex9);
}

TEST(libPair, CheckingConstructorsFunc) {
    TPair<int, int> ex;
    TPair<int, int> ex1(1, 2);
    TPair<int, int> ex2(ex1);

    ASSERT_NO_THROW(ex, ex1, ex2);
}

TEST(libPair, CheckingCopyConstructorsFunc) {
    TPair<int, int> ex(1, 2);
    TPair<int, int> ex1(ex);

    int actual_results[2] = { ex1.first(), ex1.second() };

    EXPECT_EQ(actual_results[0], 1, actual_results[1], 2);
}

TEST(libPair, CheckingGetters) {
    TPair<int, int> ex(3, 5);

    int _first = ex.first();
    int _second = ex.second();

    EXPECT_EQ(_first, 3, _second, 5);
}

TEST(libPair, CheckingSetters) {
    TPair<int, int> ex;

    ex.set_first(5);
    ex.set_second(7);

    EXPECT_EQ(ex.first(), 5, ex.second(), 7);
}

TEST(libPair, CheckingOperatorEqually) {
    TPair<char, char> t;
    TPair<char, char> ans('a', 'b');

    t = ans;

    EXPECT_EQ(t.first(), 'a', t.second(), 'b');
}

TEST(libPair, CheckingOperatorMinusIsEqualto) {
    TPair<char, char> t('y', 'z');
    TPair<char, char> t1('a', 'b');

    t -= t1;

    EXPECT_EQ(t.first(), '\x18', t.second(), '\x18');
}
TEST(libPair, CheckingOperatorPlus) {
    TPair<double, double> f(1.5, 3.14);
    TPair<double, double> _f(1.6, 4.86);
    TPair<double, double> ans;

    ans = f + _f;

    EXPECT_EQ(ans.first(), 3.1, ans.second(), 8.0);
}

TEST(libPair, CheckingOperatorComparison) {
    TPair<bool, bool> f;
    TPair<bool, bool> _f(true, true);

    EXPECT_EQ(f == _f, false);
}

TEST(libPair, CheckingOperatorMinus) {
    TPair<int, int> f(2, 4);
    TPair<int, int> _f(1, 3);
    TPair<int, int> ans;

    ans = f - _f;

    EXPECT_EQ(ans.first(), 1, ans.second(), 1);
}

TEST(libPair, CheckingFunctionTo_string) {
    TPair<int, int> t(12, 24);
    std::string str = "(12, 24)";

    EXPECT_EQ(t.to_string(), str);
}

TEST(libPair, CheckingOperatorPlusRavno) {
    TPair<int, int> t(12, 4);
    TPair<int, int> t1(1, 1);

    t1 += t;

    EXPECT_EQ(t1.first(), 13, t1.second(), 5);
}

TEST(libPair, CheckingOperatorMultRavno) {
    TPair<int, int> t(12, 4);
    TPair<int, int> t1(2, 2);

    t1 *= t;

    EXPECT_EQ(t1.first(), 24, t1.second(), 8);
}

TEST(libPair, CheckingOperatorDelRavno) {
    TPair<int, int> t(12, 4);
    TPair<int, int> t1(2, 2);

    t /= t1;

    EXPECT_EQ(t.first(), 6, t.second(), 2);
}

TEST(libPair, CheckingOperatorMult) {
    TPair<int, int> t(12, 4);
    TPair<int, int> t1(2, 2);
    TPair<int, int> ans;

    ans = t1 * t;

    EXPECT_EQ(ans.first(), 24, ans.second(), 8);
}
