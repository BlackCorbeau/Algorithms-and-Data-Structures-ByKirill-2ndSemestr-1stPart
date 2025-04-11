#include <gtest.h>
#include <icecream.hpp>
#include "../lib_BinTreeTable/BinTreeTable.h"

TEST(BTTableTest, InsertAutoKey) {
    BTTable<int, std::string> table;
    int key1 = table.insert("value1");
    int key2 = table.insert("value2");

    EXPECT_EQ(key1, 1);
    EXPECT_EQ(key2, 2);
}

TEST(BTTableTest, InsertWithKey) {
    BTTable<int, std::string> table;
    table.insert(10, "value10");
    table.insert(20, "value20");

    EXPECT_EQ(table.find(10), "value10");
    EXPECT_EQ(table.find(20), "value20");
}

TEST(BTTableTest, EraseElement) {
    BTTable<int, std::string> table;
    table.insert(1, "value1");
    table.insert(2, "value2");

    table.erase(1);

    EXPECT_EQ(table.size(), 1);
    EXPECT_EQ(table.find(2), "value2");
}
TEST(BTTableTest, EraseNonExistentElement) {
    BTTable<int, std::string> table;
    table.insert(1, "value1");

    EXPECT_NO_THROW(table.erase(2));
    EXPECT_EQ(table.size(), 1);
}

TEST(BTTableTest, Find) {
    BTTable<int, std::string> table;
    table.insert(1, "value1");
    table.insert(2, "value2");

    EXPECT_EQ(table.find(1), "value1");
    EXPECT_EQ(table.find(2), "value2");
}

TEST(BTTableTest, Size) {
    BTTable<int, std::string> table;
    EXPECT_EQ(table.size(), 0);

    table.insert(1, "value1");
    table.insert(2, "value2");
    EXPECT_EQ(table.size(), 2);

    table.erase(1);
    EXPECT_EQ(table.size(), 1);
}

TEST(BTTableTest, Print) {
    BTTable<int, std::string> table;
    table.insert(1, "value1");
    table.insert(2, "value2");

    EXPECT_NO_THROW(table.print());
}
