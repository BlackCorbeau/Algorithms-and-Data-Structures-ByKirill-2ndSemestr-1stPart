// Copyright 2024 Kirill Remizov
#include <gtest.h>
#include "../lib_queue/queue.h"

// Тест для проверки, что очередь пуста после создания
TEST(TQueueTest, IsEmptyOnCreation) {
    TQueue<int> queue;
    EXPECT_TRUE(queue.isEmpty());
}

// Тест для проверки добавления элемента в очередь
TEST(TQueueTest, Enqueue) {
    TQueue<int> queue;
    queue.enqueue(1);
    EXPECT_FALSE(queue.isEmpty());
    EXPECT_EQ(queue.front(), 1);
}

// Тест для проверки удаления элемента из очереди
TEST(TQueueTest, Dequeue) {
    TQueue<int> queue;
    queue.enqueue(1);
    queue.dequeue();
    EXPECT_TRUE(queue.isEmpty());
}

// Тест для проверки добавления и удаления нескольких элементов
TEST(TQueueTest, EnqueueDequeueMultiple) {
    TQueue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    EXPECT_EQ(queue.front(), 1);
    queue.dequeue();
    EXPECT_EQ(queue.front(), 2);
    queue.dequeue();
    EXPECT_EQ(queue.front(), 3);
    queue.dequeue();
    EXPECT_TRUE(queue.isEmpty());
}

// Тест для проверки попытки удаления из пустой очереди
TEST(TQueueTest, DequeueFromEmpty) {
    TQueue<int> queue;
    EXPECT_ANY_THROW(queue.dequeue());
}

// Тест для проверки попытки получения первого элемента из пустой очереди
TEST(TQueueTest, FrontFromEmpty) {
    TQueue<int> queue;
    EXPECT_THROW(queue.front(), std::out_of_range);
}