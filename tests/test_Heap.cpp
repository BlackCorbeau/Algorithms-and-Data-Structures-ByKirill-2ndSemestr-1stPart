#include <gtest.h>
#include "../lib_Heap/Heap.h"

TEST(HeapTest, DefaultConstructor) {
    Heap<int> heap;
    EXPECT_TRUE(heap.isEmpty());
    EXPECT_EQ(heap.find(5), static_cast<size_t>(-1));
}

TEST(HeapTest, TypeConstructor) {
    Heap<int> maxHeap(MAX);
    Heap<int> minHeap(MIN);

    maxHeap.insert(5);
    maxHeap.insert(3);
    maxHeap.insert(7);

    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(7);

    EXPECT_EQ(maxHeap.find(7), 0);
    EXPECT_EQ(minHeap.find(3), 0);
}

TEST(HeapTest, ArrayConstructor) {
    int arr[] = {4, 10, 3, 5, 1};
    Heap<int> maxHeap(arr, 5, MAX);
    Heap<int> minHeap(arr, 5, MIN);

    EXPECT_EQ(maxHeap.find(10), 0);
    EXPECT_EQ(minHeap.find(1), 0);
}

TEST(HeapTest, InsertAndShiftUp) {
    Heap<int> minHeap(MIN);
    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(7);
    minHeap.insert(1);

    EXPECT_EQ(minHeap.find(1), 0);
    EXPECT_EQ(minHeap.find(3), 1);
    EXPECT_EQ(minHeap.find(5), 3);
}

TEST(HeapTest, EraseAndShiftDown) {
    Heap<int> minHeap(MIN);
    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(7);
    minHeap.insert(1);
    minHeap.insert(2);

    minHeap.eraise(1); // Erase root

    EXPECT_EQ(minHeap.find(1), static_cast<size_t>(-1));
    EXPECT_EQ(minHeap.find(2), 0);
}

TEST(HeapTest, HeapPropertiesMax) {
    Heap<int> maxHeap(MAX);
    maxHeap.insert(5);
    maxHeap.insert(3);
    maxHeap.insert(7);
    maxHeap.insert(1);
    maxHeap.insert(9);

    EXPECT_EQ(maxHeap.find(9), 0);
    EXPECT_GT(maxHeap.find(7), 0);
    EXPECT_GT(maxHeap.find(5), 0);
}

TEST(HeapTest, HeapPropertiesMin) {
    Heap<int> minHeap(MIN);
    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(7);
    minHeap.insert(1);
    minHeap.insert(9);

    EXPECT_EQ(minHeap.find(1), 0);
    EXPECT_GT(minHeap.find(3), 0);
    EXPECT_GT(minHeap.find(5), 0);
}

TEST(HeapTest, FindNonExistent) {
    Heap<int> heap(MIN);
    heap.insert(5);
    heap.insert(3);

    EXPECT_EQ(heap.find(10), static_cast<size_t>(-1));
}

TEST(HeapTest, EmptyHeapOperations) {
    Heap<int> heap(MIN);
    EXPECT_TRUE(heap.isEmpty());
    EXPECT_THROW(heap.eraise(5), std::logic_error);
}

TEST(HeapTest, LargeInput) {
    Heap<int> minHeap(MIN);
    for (int i = 1000; i >= 0; --i) {
        minHeap.insert(i);
    }
    EXPECT_EQ(minHeap.find(0), 0);
    EXPECT_EQ(minHeap.find(1000), 511);
}
