// Copyright 2024 Kirill Remizov
#include <gtest.h>
#include "../lib_list/List.h"

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

// Тесты для класса TList
TEST(TListTest, DefaultConstructor) {
    TList<int> list;
    EXPECT_EQ(list.get_head(), nullptr);
    EXPECT_EQ(list.get_tail(), nullptr);
}

TEST(TListTest, CopyConstructor) {
    TNode<int> node1(10, nullptr);
    TList<int> list1(&node1, &node1);
    TList<int> list2(&list1);
    EXPECT_EQ(list2.get_head(), list1.get_head());
    EXPECT_EQ(list2.get_tail(), list1.get_tail());
}

TEST(TListTest, PushFront) {
    TList<int> list;
    list.push_front(10);
    EXPECT_NE(list.get_head(), nullptr);
    EXPECT_EQ(list.get_head()->get_val(), 10);
    EXPECT_EQ(list.get_tail(), list.get_head());
}

TEST(TListTest, PushBack) {
    TList<int> list;
    list.push_back(10);
    EXPECT_NE(list.get_tail(), nullptr);
    EXPECT_EQ(list.get_tail()->get_val(), 10);
    EXPECT_EQ(list.get_head(), list.get_tail());
}

TEST(TListTest, PushPos) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_pos(15, 1);
    EXPECT_EQ(list.get_head()->get_pnext()->get_val(), 15);
}

TEST(TListTest, PopBack) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_back();
    EXPECT_EQ(list.get_tail()->get_val(), 10);
}

TEST(TListTest, PopFront) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_front();
    EXPECT_EQ(list.get_head()->get_val(), 20);
}

TEST(TListTest, PopPos) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.pop_pos(1);
    EXPECT_EQ(list.get_head()->get_pnext()->get_val(), 30);
}

TEST(TListTest, Find) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);
    TNode<int>* found = list.find(20);
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->get_val(), 20);
}

TEST(TListTest, ChangeFirst) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.change_first(30);
    EXPECT_EQ(list.get_head()->get_val(), 30);
}

TEST(TListTest, ChangeLast) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.change_last(30);
    EXPECT_EQ(list.get_tail()->get_val(), 30);
}

TEST(TListTest, ChangePos) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.change_pos(40, 1);
    EXPECT_EQ(list.get_head()->get_pnext()->get_val(), 40);
}

TEST(TListTest, OperatorBracket) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list[0], 10);
    EXPECT_EQ(list[1], 20);
    EXPECT_EQ(list[2], 30);

    list[1] = 25;
    EXPECT_EQ(list[1], 25);
}