// Copyright 2024 Kirill Remizov

#include <gtest.h>
#include "../lib_TVector/TVector.h"

TEST(TVectorTest, DefaultConstructor) {
    TVector<int> vec;
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec.size(), 0);
}

TEST(TVectorTest, PushBack) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

TEST(TVectorTest, PopBack) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
}

TEST(TVectorTest, PushFront) {
    TVector<int> vec;
    vec.push_front(1);
    vec.push_front(2);
    vec.push_front(3);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 3);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 1);
}

TEST(TVectorTest, PopFront) {
    TVector<int> vec;
    vec.push_front(1);
    vec.push_front(2);
    vec.push_front(3);
    vec.pop_front();
    vec.cleanDeleted();
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 1);
}

TEST(TVectorTest, Insert) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.insert(1, 4);
    EXPECT_EQ(vec.size(), 4);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 4);
    EXPECT_EQ(vec[2], 2);
    EXPECT_EQ(vec[3], 3);
}

TEST(TVectorTest, Erase) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.erase(1, 1);
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
}

TEST(TVectorTest, RemoveAll) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);
    vec.remove_all(2);
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 3);
}

TEST(TVectorTest, RemoveFirst) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);
    vec.remove_first(2);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 2);
}

TEST(TVectorTest, RemoveLast) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);
    vec.remove_last(2);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 2);
}

TEST(TVectorTest, FindFirst) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec.find_first(2), 1);
}

TEST(TVectorTest, FindLast) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(2);
    EXPECT_EQ(vec.find_last(2), 3);
}
