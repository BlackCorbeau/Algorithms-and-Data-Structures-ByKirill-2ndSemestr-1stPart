#include <gtest.h>
#include "../lib_STable/STable.h"

TEST(OrderedTableTest, InsertAutoKey) {
    OrderedTable<int, std::string> table;
    int key1 = table.insert("Apple");
    int key2 = table.insert("Banana");

    EXPECT_EQ(key1, 1);
    EXPECT_EQ(key2, 2);
}

TEST(OrderedTableTest, InsertWithKey) {
    OrderedTable<int, std::string> table;
    table.insert(10, "Apple");
    table.insert(5, "Banana");

    EXPECT_EQ(table.find(10), "Apple");
    EXPECT_EQ(table.find(5), "Banana");
}

TEST(OrderedTableTest, FindElement) {
    OrderedTable<int, std::string> table;
    table.insert(1, "Apple");
    table.insert(2, "Banana");

    EXPECT_EQ(table.find(1), "Apple");
    EXPECT_EQ(table.find(2), "Banana");
    EXPECT_THROW(table.find(3), std::out_of_range);
}

TEST(OrderedTableTest, EraseElement) {
    OrderedTable<int, std::string> table;
    table.insert(1, "Apple");
    table.insert(2, "Banana");

    table.erase(1);

    ASSERT_ANY_THROW(table.find(1));
}

TEST(OrderedTableTest, TableSize) {
    OrderedTable<int, std::string> table;
    EXPECT_EQ(table.size(), 0);

    table.insert(1, "Apple");
    table.insert(2, "Banana");
    EXPECT_EQ(table.size(), 2);

    table.erase(1);
    EXPECT_EQ(table.size(), 1);
}


TEST(OrderedTableTest, PrintElements) {
    OrderedTable<int, std::string> table;
    table.insert(1, "Apple");
    table.insert(2, "Banana");

    testing::internal::CaptureStdout();
    table.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Key: 1, Value: Apple") != std::string::npos);
    EXPECT_TRUE(output.find("Key: 2, Value: Banana") != std::string::npos);
}
