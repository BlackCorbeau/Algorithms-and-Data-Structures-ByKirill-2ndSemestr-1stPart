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

    TEST(BinTreeTest, RemoveFromEmptyTreeThrows) {
        BinTree<int> tree;
        EXPECT_THROW(tree.Remove(5), std::logic_error);
    }

    TEST(BinTreeTest, RemoveNonExistentValueLeftSubtreeThrows) {
        BinTree<int> tree;
        tree.Insert(5);
        tree.Insert(3);

        EXPECT_THROW(tree.Remove(1), std::logic_error);
        EXPECT_NE(tree.Search(5), nullptr);
        EXPECT_NE(tree.Search(3), nullptr);
    }

    TEST(BinTreeTest, RemoveNonExistentValueRightSubtreeThrows) {
        BinTree<int> tree;
        tree.Insert(5);
        tree.Insert(7);

        EXPECT_THROW(tree.Remove(9), std::logic_error);
        EXPECT_NE(tree.Search(5), nullptr);
        EXPECT_NE(tree.Search(7), nullptr);
    }

    TEST(BinTreeTest, RemoveNodeWithNoLeftChild) {
        BinTree<int> tree;
        tree.Insert(5);
        tree.Insert(3);
        tree.Insert(7);
        tree.Insert(6);

        EXPECT_NO_THROW(tree.Remove(7));
        EXPECT_EQ(tree.Search(7), nullptr);
        EXPECT_NE(tree.Search(6), nullptr);
        EXPECT_NE(tree.Search(5), nullptr);
        EXPECT_NE(tree.Search(3), nullptr);
    }

    TEST(BinTreeTest, RemoveNodeWithNoRightChild) {
        BinTree<int> tree;
        tree.Insert(5);
        tree.Insert(3);
        tree.Insert(2);

        EXPECT_NO_THROW(tree.Remove(3));
        EXPECT_EQ(tree.Search(3), nullptr);
        EXPECT_NE(tree.Search(2), nullptr);
        EXPECT_NE(tree.Search(5), nullptr);
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

        EXPECT_NO_THROW(tree.Remove(5));
        EXPECT_EQ(tree.Search(5), nullptr);

        TrNode<int>* newRoot = tree.Search(6);
        ASSERT_NE(newRoot, nullptr);

        EXPECT_NE(tree.Search(3), nullptr);
        EXPECT_NE(tree.Search(2), nullptr);
        EXPECT_NE(tree.Search(4), nullptr);
        EXPECT_NE(tree.Search(7), nullptr);
        EXPECT_NE(tree.Search(8), nullptr);

        EXPECT_EQ(newRoot->getLeft()->getValue(), 3);
        EXPECT_EQ(newRoot->getRight()->getValue(), 7);
    }

    TEST(BinTreeTest, RemoveRootWithOnlyLeftChild) {
        BinTree<int> tree;
        tree.Insert(5);
        tree.Insert(3);

        EXPECT_NO_THROW(tree.Remove(5));
        EXPECT_EQ(tree.Search(5), nullptr);
        EXPECT_NE(tree.Search(3), nullptr);
    }

    TEST(BinTreeTest, RemoveRootWithOnlyRightChild) {
        BinTree<int> tree;
        tree.Insert(5);
        tree.Insert(7);

        EXPECT_NO_THROW(tree.Remove(5));
        EXPECT_EQ(tree.Search(5), nullptr);
        EXPECT_NE(tree.Search(7), nullptr);
    }

    TEST(BinTreeTest, RemoveLeafNode) {
        BinTree<int> tree;
        tree.Insert(5);
        tree.Insert(3);
        tree.Insert(7);

        EXPECT_NO_THROW(tree.Remove(3));
        EXPECT_NO_THROW(tree.Remove(7));
        EXPECT_EQ(tree.Search(3), nullptr);
        EXPECT_EQ(tree.Search(7), nullptr);
        EXPECT_NE(tree.Search(5), nullptr);
    }

    TEST(BinTreeTest, RemoveNodeWithTwoChildrenSuccessorHasRightChild) {
        BinTree<int> tree;
        tree.Insert(5);
        tree.Insert(3);
        tree.Insert(7);
        tree.Insert(6);
        tree.Insert(8);
        tree.Insert(9);

        EXPECT_NO_THROW(tree.Remove(5));
        EXPECT_EQ(tree.Search(5), nullptr);

        TrNode<int>* newRoot = tree.Search(6);
        ASSERT_NE(newRoot, nullptr);

        EXPECT_EQ(newRoot->getLeft()->getValue(), 3);
        EXPECT_EQ(newRoot->getRight()->getValue(), 7);
        EXPECT_EQ(tree.Search(7)->getRight()->getValue(), 8);
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
