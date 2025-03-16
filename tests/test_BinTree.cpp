// Copyright 2025 Kirill Remizov

#include <gtest.h>
#include"../lib_BinTree/BinTree.h"

    TEST(BinTreeTest, InsertAndSearch) {
        BinTree<int> tree;

        tree.Insert(5);
        tree.Insert(3);
        tree.Insert(7);
        tree.Insert(2);
        tree.Insert(4);
        tree.Insert(6);
        tree.Insert(8);

        EXPECT_NE(tree.Search(5), nullptr);
        EXPECT_EQ(tree.Search(5)->getValue(), 5);
        EXPECT_NE(tree.Search(3), nullptr);
        EXPECT_NE(tree.Search(7), nullptr);
        EXPECT_NE(tree.Search(2), nullptr);
        EXPECT_NE(tree.Search(4), nullptr);
        EXPECT_NE(tree.Search(6), nullptr);
        EXPECT_NE(tree.Search(8), nullptr);

        EXPECT_EQ(tree.Search(1), nullptr);
        EXPECT_EQ(tree.Search(9), nullptr);
        EXPECT_EQ(tree.Search(0), nullptr);
    }

    TEST(BinTreeTest, RemoveLeafNodes) {
        BinTree<int> tree;
        tree.Insert(5);
        tree.Insert(3);
        tree.Insert(7);

        tree.Remove(3);
        EXPECT_EQ(tree.Search(3), nullptr);
        EXPECT_NE(tree.Search(5), nullptr);
        EXPECT_NE(tree.Search(7), nullptr);

        tree.Remove(7);
        EXPECT_EQ(tree.Search(7), nullptr);
        EXPECT_NE(tree.Search(5), nullptr);
    }

    TEST(BinTreeTest, RemoveNodeWithOneChild) {
        BinTree<int> tree;
        tree.Insert(5);
        tree.Insert(3);
        tree.Insert(2);
        tree.Insert(7);
        tree.Insert(6);

        tree.Remove(3);
        EXPECT_EQ(tree.Search(3), nullptr);
        EXPECT_NE(tree.Search(2), nullptr);
        EXPECT_NE(tree.Search(5), nullptr);


        tree.Remove(7);
        EXPECT_EQ(tree.Search(7), nullptr);
        EXPECT_NE(tree.Search(6), nullptr);
    }

    TEST(BinTreeTest, RemoveNodeWithTwoChildren) {
        BinTree<int> tree;
        tree.Insert(5);
        tree.Insert(3);
        tree.Insert(2);
        tree.Insert(4);
        tree.Insert(7);
        tree.Insert(6);
        tree.Insert(8);

        tree.Remove(5);
        EXPECT_EQ(tree.Search(5), nullptr);

        EXPECT_NE(tree.Search(3), nullptr);
        EXPECT_NE(tree.Search(2), nullptr);
        EXPECT_NE(tree.Search(4), nullptr);
        EXPECT_NE(tree.Search(7), nullptr);
        EXPECT_NE(tree.Search(6), nullptr);
        EXPECT_NE(tree.Search(8), nullptr);

        EXPECT_NE(tree.Search(6)->getLeft(), nullptr);
        EXPECT_NE(tree.Search(6)->getRight(), nullptr);
    }

    TEST(BinTreeTest, CopyConstructor) {
        BinTree<int> original;
        original.Insert(5);
        original.Insert(3);
        original.Insert(7);
        original.Insert(2);
        original.Insert(6);

        BinTree<int> copy(original);

        EXPECT_NE(copy.Search(5), nullptr);
        EXPECT_NE(copy.Search(3), nullptr);
        EXPECT_NE(copy.Search(7), nullptr);
        EXPECT_NE(copy.Search(2), nullptr);
        EXPECT_NE(copy.Search(6), nullptr);

        original.Remove(3);
        EXPECT_NE(copy.Search(3), nullptr);
        EXPECT_EQ(original.Search(3), nullptr);
    }

    TEST(BinTreeTest, Destructor) {
        BinTree<int>* tree = new BinTree<int>();
        tree->Insert(5);
        tree->Insert(3);
        tree->Insert(7);
        delete tree;
        SUCCEED();
    }

    /*TEST(BinTreeTest, PrintTest) {
        BinTree<int> tree;
        tree.Insert(5);
        tree.Insert(3);
        tree.Insert(7);
        tree.Insert(2);
        tree.Insert(6);
        EXPECT_NO_THROW(tree.Print());
    }*/
