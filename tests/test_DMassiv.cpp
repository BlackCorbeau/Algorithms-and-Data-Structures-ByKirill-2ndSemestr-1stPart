// Copyright 2024 Kirill Remizov

#include <gtest.h>
#include"../lib_DMassiv/DMassiv.h"

#define EPSILON 0.000001

TEST(libDMassiv, CheckingConstructorZero) {
    DMassiv<int> t;

    ASSERT_NO_THROW(t);
}

//TEST(libDMassiv, )
