// Copyright 2024 Kirill Remizov

#include <gtest.h>
#include <string>
#include"../lib_Stack/Stack.h"

#define EPSILON 0.000001

TEST(StackTest, Push) {
    Stack<int> stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(stack.size(), 3);
}

TEST(StackTest, PushBeyondLimit) {
    Stack<int> stack(2);
    stack.push(1);
    stack.push(2);
    EXPECT_THROW(stack.push(3), std::overflow_error);
}

TEST(StackTest, Pop) {
    Stack<int> stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    EXPECT_EQ(stack.size(), 2);
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(StackTest, PopEmptyStack) {
    Stack<int> stack(5);
    EXPECT_THROW(stack.pop(), std::logic_error);
}

TEST(StackTest, Top) {
    Stack<int> stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(stack.top(), 3);
    stack.pop();
    EXPECT_EQ(stack.top(), 2);
}

TEST(StackTest, TopEmptyStack) {
    Stack<int> stack(5);
    EXPECT_THROW(stack.top(), std::logic_error);
}

TEST(StackTest, Empty) {
    Stack<int> stack(5);
    EXPECT_TRUE(stack.empty());
    stack.push(1);
    EXPECT_FALSE(stack.empty());
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(StackTest, Size) {
    Stack<int> stack(5);
    EXPECT_EQ(stack.size(), 0);
    stack.push(1);
    EXPECT_EQ(stack.size(), 1);
    stack.push(2);
    EXPECT_EQ(stack.size(), 2);
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
    stack.pop();
    EXPECT_EQ(stack.size(), 0);
}
