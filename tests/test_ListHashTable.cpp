#include <gtest.h>
#include "../lib_HashTable/ListHashTable.h"
#include "../lib_list/List.h"
#include "../lib_pair/lib_pair_heder.h"
#include <icecream.hpp>
#include <iostream>

TEST(ListHashTTest, DefaultConstructor) {
    ListHashT<int, std::string> table;
    EXPECT_EQ(table.size(), 0);
    EXPECT_EQ(table.capacity(), CAPACITY);
}

TEST(ListHashTTest, InsertAndFind) {
    ListHashT<int, std::string> table;

    table.insert(1, "one");
    table.insert(2, "two");

    EXPECT_EQ(table.size(), 2);
    EXPECT_EQ(table.find(1), "one");
    EXPECT_EQ(table.find(2), "two");
}

TEST(ListHashTTest, InsertDuplicate) {
    ListHashT<int, std::string> table;

    table.insert(1, "one");
    table.insert(1, "another one");

    EXPECT_EQ(table.size(), 1);
    EXPECT_EQ(table.find(1), "one");
}

TEST(ListHashTTest, FindNonExistent) {
    ListHashT<int, std::string> table;
    table.insert(1, "one");

    EXPECT_EQ(table.find(2), "");
}

TEST(ListHashTTest, Erase) {
    ListHashT<int, std::string> table;

    table.insert(1, "one");
    table.insert(2, "two");

    table.eraise(1);
    EXPECT_EQ(table.size(), 1);
    EXPECT_EQ(table.find(1), "");
    EXPECT_EQ(table.find(2), "two");

    table.eraise(2);
    EXPECT_EQ(table.size(), 0);
    EXPECT_EQ(table.find(2), "");
}

TEST(ListHashTTest, HashCollision) {
    ListHashT<int, std::string> table;

    table.insert(1, "one");
    table.insert(1 + CAPACITY, "one plus capacity");

    EXPECT_EQ(table.size(), 2);
    EXPECT_EQ(table.find(1), "one");
    EXPECT_EQ(table.find(1 + CAPACITY), "one plus capacity");
}

TEST(ListHashTTest, CapacityLimit) {
    ListHashT<int, std::string> table;

    for (int i = 0; i < CAPACITY; ++i) {
        table.insert(i, "value" + std::to_string(i));
    }

    table.insert(CAPACITY, "extra");

    EXPECT_EQ(table.size(), CAPACITY);
    EXPECT_EQ(table.find(CAPACITY), "");
}

TEST(ListHashTTest, StringKeys) {
    ListHashT<std::string, int> table;

    table.insert("one", 1);
    table.insert("two", 2);

    EXPECT_EQ(table.size(), 2);
    EXPECT_EQ(table.find("one"), 1);
    EXPECT_EQ(table.find("two"), 2);
}

TEST(ListHashTTest, Destructor) {
    ListHashT<int, std::string>* table = new ListHashT<int, std::string>();
    table->insert(1, "one");

    delete table;
}
