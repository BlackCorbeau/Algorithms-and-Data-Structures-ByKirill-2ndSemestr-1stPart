#include <gtest.h>
#include "../lib_list/List.h"

#define EPSILON 0.000001

// Тесты для класса TNode
TEST(TNodeTest, DefaultConstructor) {
    TNode<int> node;
    EXPECT_EQ(node.get_pnext(), nullptr);
}

TEST(TNodeTest, CopyConstructor) {
    TNode<int> node1(10, nullptr);
    TNode<int> node2(&node1);
    EXPECT_EQ(node2.get_val(), 10);
    EXPECT_EQ(node2.get_pnext(), nullptr);
}

TEST(TNodeTest, ValueConstructor) {
    TNode<int> node(10, nullptr);
    EXPECT_EQ(node.get_val(), 10);
    EXPECT_EQ(node.get_pnext(), nullptr);
}

TEST(TNodeTest, SetValue) {
    TNode<int> node;
    node.set_val(20);
    EXPECT_EQ(node.get_val(), 20);
}

TEST(TNodeTest, SetNext) {
    TNode<int> node1;
    TNode<int> node2;
    node1.set_pnext(&node2);
    EXPECT_EQ(node1.get_pnext(), &node2);
}

TEST(TNodeTest, AssignmentOperator) {
    TNode<int> node1(10, nullptr);
    TNode<int> node2;
    node2 = node1;
    EXPECT_EQ(node2.get_val(), 10);
    EXPECT_EQ(node2.get_pnext(), nullptr);
}

// Тесты для класса TList
TEST(TListTest, DefaultConstructor) {
    TList<int> list;
    EXPECT_EQ(list.get_head(), nullptr);
    EXPECT_EQ(list.get_tail(), nullptr);
}

TEST(TListTest, CopyConstructor) {
    TNode<int> node1(10, nullptr);
    TNode<int> node2(20, nullptr);
    TList<int> list1(&node1, &node2);
    TList<int> list2(&list1);
    EXPECT_EQ(list2.get_head(), list1.get_head());
    EXPECT_EQ(list2.get_tail(), list1.get_tail());
}

TEST(TListTest, SetHead) {
    TNode<int> node(10, nullptr);
    TList<int> list;
    list.set_head(&node);
    EXPECT_EQ(list.get_head(), &node);
}

TEST(TListTest, SetTail) {
    TNode<int> node(10, nullptr);
    TList<int> list;
    list.set_tail(&node);
    EXPECT_EQ(list.get_tail(), &node);
}

TEST(TListTest, Empty) {
    TList<int> list;
    EXPECT_TRUE(list.empty());
}

TEST(TListTest, PushFront) {
    TNode<int> node(10, nullptr);
    TList<int> list;
    list.push_front(&node);
    EXPECT_EQ(list.get_head()->get_val(), 10);
}

TEST(TListTest, PushBack) {
    TNode<int> node(10, nullptr);
    TList<int> list;
    list.push_back(&node);
    EXPECT_EQ(list.get_tail()->get_val(), 10);
}

TEST(TListTest, PopFront) {
    TNode<int> node1(10, nullptr);
    TNode<int> node2(20, nullptr);
    TList<int> list;
    list.push_front(&node1);
    list.push_front(&node2);
    list.pop_front();
    EXPECT_EQ(list.get_head()->get_val(), 10);
}

TEST(TListTest, PopBack) {
    TNode<int> node1(10, nullptr);
    TNode<int> node2(20, nullptr);
    TList<int> list;
    list.push_back(&node1);
    list.push_back(&node2);
    list.pop_back();
    EXPECT_EQ(list.get_tail()->get_val(), 10);
}

TEST(TListTest, Find) {
    TNode<int> node1(10, nullptr);
    TNode<int> node2(20, nullptr);
    TList<int> list;
    list.push_back(&node1);
    list.push_back(&node2);
    TNode<int>* found = list.find(20);
    EXPECT_EQ(found->get_val(), 20);
}

TEST(TListTest, ChangeFirst) {
    TNode<int> node1(10, nullptr);
    TNode<int> node2(20, nullptr);
    TList<int> list;
    list.push_front(&node1);
    list.change_first(&node2);
    EXPECT_EQ(list.get_head()->get_val(), 20);
}

TEST(TListTest, ChangeLast) {
    TNode<int> node1(10, nullptr);
    TNode<int> node2(20, nullptr);
    TList<int> list;
    list.push_back(&node1);
    list.change_last(&node2);
    EXPECT_EQ(list.get_tail()->get_val(), 20);
}
