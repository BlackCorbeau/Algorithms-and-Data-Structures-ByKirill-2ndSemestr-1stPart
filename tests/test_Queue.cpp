// Copyright 2024 Kirill Remizov
#include <gtest.h>
#include "../lib_queue/queue.h"

TEST(TQueueTest, push_backPop_front) {
    TQueue<int> queue;
    queue.push_back(1);
    queue.push_back(2);
    queue.push_back(3);

    EXPECT_EQ(queue.front(), 1);
    queue.pop_front();
    EXPECT_EQ(queue.front(), 2);
    queue.pop_front();
    EXPECT_EQ(queue.front(), 3);
    queue.pop_front();
    EXPECT_TRUE(queue.empty());
}

TEST(TQueueTest, EmptyQueue) {
    TQueue<int> queue;
    EXPECT_TRUE(queue.empty());
    EXPECT_THROW(queue.front(), std::out_of_range);
}

TEST(TQueueTest, MultiplePush_backPop_front) {
    TQueue<int> queue;
    for (int i = 1; i <= 10; ++i) {
        queue.push_back(i);
    }

    for (int i = 1; i <= 10; ++i) {
        EXPECT_EQ(queue.front(), i);
        queue.pop_front();
    }

    EXPECT_TRUE(queue.empty());
}
