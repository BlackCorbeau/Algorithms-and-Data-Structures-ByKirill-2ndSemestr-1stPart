// Copyright 2024 Kirill Remizov

#include <gtest.h>
#include"../lib_DMassiv/DMassiv.h"

TEST(DMassivTest, ConstructorTest) {
    DMassiv<int> massiv;
    EXPECT_TRUE(massiv.empty());
    EXPECT_EQ(massiv.size(), 0);
    EXPECT_EQ(massiv.capacity(), STEP_CAPACITY);
}

TEST(DMassivTest, CopyConstructorTest) {
    DMassiv<int> massiv1(5, 10);
    DMassiv<int> massiv2(massiv1);
    EXPECT_EQ(massiv2.size(), 5);
    EXPECT_EQ(massiv2.capacity(), massiv1.capacity());
    for (size_t i = 0; i < massiv2.size(); ++i) {
        EXPECT_EQ(massiv2.data()[i], 10);
    }
}

TEST(DMassivTest, ArrayConstructorTest) {
    int arr[] = {1, 2, 3, 4, 5};
    DMassiv<int> massiv(arr, 5);
    EXPECT_EQ(massiv.size(), 5);
    for (size_t i = 0; i < massiv.size(); ++i) {
        EXPECT_EQ(massiv.data()[i], arr[i]);
    }
}

TEST(DMassivTest, ValueConstructorTest) {
    DMassiv<int> massiv(5, 10);
    EXPECT_EQ(massiv.size(), 5);
    for (size_t i = 0; i < massiv.size(); ++i) {
        EXPECT_EQ(massiv.data()[i], 10);
    }
}

TEST(DMassivTest, SubarrayConstructorTest) {
    DMassiv<int> massiv1(10, 10);
    DMassiv<int> massiv2(massiv1, 2, 5);
    EXPECT_EQ(massiv2.size(), 5);
    for (size_t i = 0; i < massiv2.size(); ++i) {
        EXPECT_EQ(massiv2.data()[i], 10);
    }
}

TEST(DMassivTest, PushBackTest) {
    DMassiv<int> massiv;
    massiv.push_back(10);
    EXPECT_EQ(massiv.size(), 1);
    EXPECT_EQ(massiv.data()[0], 10);
}

TEST(DMassivTest, PopBackTest) {
    DMassiv<int> massiv(5, 10);
    massiv.pop_back();
    EXPECT_EQ(massiv.size(), 4);
    EXPECT_EQ(massiv.data()[3], 10);
}

TEST(DMassivTest, PopBackEmptyTest) {
    DMassiv<int> massiv;
    EXPECT_THROW(massiv.pop_back(), std::logic_error);
}

TEST(DMassivTest, PushFrontTest) {
    DMassiv<int> massiv;
    massiv.push_front(10);
    EXPECT_EQ(massiv.size(), 1);
    EXPECT_EQ(massiv.data()[0], 10);
}

TEST(DMassivTest, PopFrontTest) {
    DMassiv<int> massiv(5, 10);
    massiv.pop_front();
    EXPECT_EQ(massiv.size(), 4);
    EXPECT_EQ(massiv.data()[0], 10);
}

TEST(DMassivTest, PopFrontEmptyTest) {
    DMassiv<int> massiv;
    EXPECT_THROW(massiv.pop_front(), std::logic_error);
}

TEST(DMassivTest, InsertTest) {
    DMassiv<int> massiv(5, 10);
    massiv.insert(20, 2);
    EXPECT_EQ(massiv.size(), 6);
    EXPECT_EQ(massiv.data()[2], 20);
}

TEST(DMassivTest, InsertOutOfRangeTest) {
    DMassiv<int> massiv(5, 10);
    EXPECT_THROW(massiv.insert(20, 10), std::out_of_range);
}

TEST(DMassivTest, RemoveByIndexTest) {
    DMassiv<int> massiv(5, 10);
    massiv.remove_by_index(2);
    EXPECT_EQ(massiv.size(), 4);
    EXPECT_EQ(massiv.data()[2], 10);
}

TEST(DMassivTest, RemoveByIndexOutOfRangeTest) {
    DMassiv<int> massiv(5, 10);
    EXPECT_THROW(massiv.remove_by_index(10), std::out_of_range);
}

TEST(DMassivTest, EraseTest) {
    DMassiv<int> massiv(5, 10);
    massiv.erase(1, 2);
    EXPECT_EQ(massiv.size(), 3);
    EXPECT_EQ(massiv.data()[1], 10);
}

TEST(DMassivTest, EraseOutOfRangeTest) {
    DMassiv<int> massiv(5, 10);
    EXPECT_THROW(massiv.erase(1, 10), std::out_of_range);
}

TEST(DMassivTest, RemoveAllTest) {
    DMassiv<int> massiv(5, 10);
    massiv.remove_all(10);
    EXPECT_EQ(massiv.size(), 0);
}

TEST(DMassivTest, RemoveFirstTest) {
    DMassiv<int> massiv(5, 10);
    massiv.remove_first(10);
    EXPECT_EQ(massiv.size(), 4);
    EXPECT_EQ(massiv.data()[0], 10);
}

TEST(DMassivTest, RemoveLastTest) {
    DMassiv<int> massiv(5, 10);
    massiv.remove_last(10);
    EXPECT_EQ(massiv.size(), 4);
    EXPECT_EQ(massiv.data()[3], 10);
}

TEST(DMassivTest, FindAllTest) {
    DMassiv<int> massiv(5, 10);
    size_t count = 0;
    size_t* indices = massiv.find_all(10, count);
    EXPECT_EQ(count, 5);
    for (size_t i = 0; i < count; ++i) {
        EXPECT_EQ(indices[i], i);
    }
    delete[] indices;
}

TEST(DMassivTest, FindFirstTest) {
    DMassiv<int> massiv(5, 10);
    EXPECT_EQ(massiv.find_first(10), 0);
}

TEST(DMassivTest, FindLastTest) {
    DMassiv<int> massiv(5, 10);
    EXPECT_EQ(massiv.find_last(10), 4);
}

TEST(DMassivTest, CleanDeletedTest) {
    DMassiv<int> massiv(5, 10);
    massiv.remove_by_index(2);
    massiv.cleanDeleted();
    EXPECT_EQ(massiv.size(), 3);
    EXPECT_EQ(massiv.data()[2], 10);
}
