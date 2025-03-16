// Copyright 2025 Kirill Remizov

#include <gtest.h>
#include <string>
#include "../lib_UTableDM/UTableDM.h"
#include "../lib_CString/CString.h"


TEST(UTableDMTest, InsertValue) {
    UTableDM<int, std::string> table;
    int key = table.insert("Kirill");
    EXPECT_EQ("Kirill", table.find(key));
}

TEST(UTableDMTest, InsertKeyValue) {
    UTableDM<int, std::string> table;
    table.insert(1, "kirill");
    EXPECT_EQ("kirill", table.find(1));
}

TEST(UTableDMTest, FindNonExistentKey) {
    UTableDM<int, std::string> table;
    EXPECT_THROW(table.find(999), std::logic_error);
}

TEST(UTableDMTest, EraseKey) {
    UTableDM<int, std::string> table;
    table.insert(1, "Kikita");
    table.erase(1);
    EXPECT_THROW(table.find(1), std::logic_error);
}

