// Copyright 2025 Kirill Remizov
#include <string>
#include <gtest.h>
#include "../lib_UTable/UTable.h"


TEST(UnsortedTableTest, InsertWithoutKey) {
    UTable<int, std::string> table;
    int key_one = table.insert("one");
    int key_two = table.insert("two");
    int key_three = table.insert("three");

    EXPECT_EQ(table.find(key_three), "three");
    EXPECT_EQ(table.find(key_one), "one");
    EXPECT_EQ(table.find(key_two), "two");
}
/*
TEST(UnsortedTableTest, InsertWithKey) {
    UTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");
    table.insert(3, "three");

    EXPECT_EQ(table.find(3), "three");
    ASSERT_ANY_THROW(table.insert(1, "r"));
    EXPECT_EQ(table.find(1), "one");
}

TEST(UnsortedTableTest, FindMethod) {
    UTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");
    table.insert(3, "three");

    EXPECT_EQ(table.find(1), "one");
    EXPECT_EQ(table.find(2), "two");
    EXPECT_EQ(table.find(3), "three");
}

TEST(UnsortedTableTest, EraseMethod) {
    UTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");
    table.insert(3, "three");

    EXPECT_EQ(table.find(1), "one");
    EXPECT_EQ(table.find(2), "two");
    EXPECT_EQ(table.find(3), "three");

    table.erase(2);

    EXPECT_EQ(table.find(1), "one");
    EXPECT_EQ(table.find(3), "three");

    EXPECT_THROW(table.erase(4), std::out_of_range);
    EXPECT_THROW(table.erase(2), std::out_of_range);
}*/
