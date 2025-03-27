#include <gtest.h>
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

