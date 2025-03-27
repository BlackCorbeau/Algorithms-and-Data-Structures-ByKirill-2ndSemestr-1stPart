#include <gtest.h>
#include "../lib_BinTreeTable/BinTreeTable.h"

TEST(BTTableTest, InsertAutoKey) {
    BTTable<int, std::string> table;
    int key1 = table.insert("value1");
    int key2 = table.insert("value2");

    EXPECT_EQ(key1, 1);
    EXPECT_EQ(key2, 2);
}

