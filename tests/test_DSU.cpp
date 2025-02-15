// Copyright 2024 Kirill Remizov

#include <gtest.h>
#include "../lib_DSU/DSU.h"

TEST(DSUTest, MakeSet) {
    DSU dsu(5);

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(dsu.find(i), i);
    }
}

// Тест на объединение множеств
TEST(DSUTest, UnionSets) {
    DSU dsu(5);

    dsu.union_sets(0, 1);
    EXPECT_EQ(dsu.find(0), dsu.find(1));

    dsu.union_sets(1, 2);
    EXPECT_EQ(dsu.find(0), dsu.find(2));

    dsu.union_sets(3, 4);
    EXPECT_EQ(dsu.find(3), dsu.find(4));
    EXPECT_NE(dsu.find(0), dsu.find(3));
}

// Тест на сжатие путей
TEST(DSUTest, PathCompression) {
    DSU dsu(5);

    dsu.union_sets(0, 1);
    dsu.union_sets(1, 2);
    dsu.union_sets(2, 3);

    EXPECT_EQ(dsu.find(0), dsu.find(3));
    EXPECT_EQ(dsu.find(1), dsu.find(3));
    EXPECT_EQ(dsu.find(2), dsu.find(3));
}

// Тест на поддержку рангов
TEST(DSUTest, UnionByRank) {
    DSU dsu(5);

    dsu.union_sets(0, 1);
    dsu.union_sets(2, 3);
    dsu.union_sets(0, 3);

    EXPECT_EQ(dsu.find(0), dsu.find(3));
    EXPECT_EQ(dsu.find(1), dsu.find(2));
}