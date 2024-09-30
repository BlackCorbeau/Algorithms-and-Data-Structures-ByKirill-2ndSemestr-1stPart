// Copyright 2024 Kirill Remizov

#include <gtest.h>
#include"../lib_Stack/Stack.h"

#define EPSILON 0.000001

TEST(StackTest, PushPop) {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    EXPECT_EQ(stack.top(), 30);
    stack.pop();
    EXPECT_EQ(stack.top(), 20);
    stack.pop();
    EXPECT_EQ(stack.top(), 10);
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

// Тест на проверку пустого стека
TEST(StackTest, Empty) {
    Stack<int> stack;
    EXPECT_TRUE(stack.empty());
    stack.push(10);
    EXPECT_FALSE(stack.empty());
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

// Тест на получение верхнего элемента
TEST(StackTest, Top) {
    Stack<int> stack;
    stack.push(10);
    EXPECT_EQ(stack.top(), 10);
    stack.push(20);
    EXPECT_EQ(stack.top(), 20);
    stack.push(30);
    EXPECT_EQ(stack.top(), 30);
}

// Тест на размер стека
TEST(StackTest, Size) {
    Stack<int> stack;
    EXPECT_EQ(stack.size(), 0);
    stack.push(10);
    EXPECT_EQ(stack.size(), 1);
    stack.push(20);
    EXPECT_EQ(stack.size(), 2);
    stack.push(30);
    EXPECT_EQ(stack.size(), 3);
    stack.pop();
    EXPECT_EQ(stack.size(), 2);
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
    stack.pop();
    EXPECT_EQ(stack.size(), 0);
}

// Тест на вывод элементов стека
TEST(StackTest, Print) {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    testing::internal::CaptureStdout();
    stack.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10, 20, 30, \n");
}
