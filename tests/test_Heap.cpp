#include <gtest.h>
#include "../lib_Heap/Heap.h"

TEST(HeapTest, DefaultConstructorCreatesEmptyMinHeap) {
    Heap<int> heap;
    EXPECT_TRUE(heap.isEmpty());

    heap.insert(5);
    heap.insert(3);
    EXPECT_EQ(heap.find(3), 0);
}

TEST(HeapTest, TypeConstructorCreatesEmptyHeapOfSpecifiedType) {
    Heap<int> maxHeap(MAX);
    EXPECT_TRUE(maxHeap.isEmpty());

    maxHeap.insert(5);
    maxHeap.insert(7);
    EXPECT_EQ(maxHeap.find(7), 0);

    Heap<int> minHeap(MIN);
    EXPECT_TRUE(minHeap.isEmpty());

    minHeap.insert(5);
    minHeap.insert(3);
    EXPECT_EQ(minHeap.find(3), 0);
}

TEST(HeapTest, ArrayConstructorBuildsCorrectHeap) {
    int arr[] = {3, 1, 4, 1, 5, 9};
    size_t size = sizeof(arr)/sizeof(arr[0]);

    Heap<int> maxHeap(arr, size, MAX);
    EXPECT_FALSE(maxHeap.isEmpty());
    EXPECT_EQ(maxHeap.find(9), 0);

    Heap<int> minHeap(arr, size, MIN);
    EXPECT_FALSE(minHeap.isEmpty());
    EXPECT_EQ(minHeap.find(1), 0);
}

TEST(HeapTest, NavigationMethodsReturnCorrectIndices) {
    Heap<int> heap;

    EXPECT_EQ(heap.parent(1), 0);
    EXPECT_EQ(heap.parent(2), 0);
    EXPECT_EQ(heap.left(0), 1);
    EXPECT_EQ(heap.right(0), 2);

    EXPECT_EQ(heap.parent(0), static_cast<size_t>(-1));
}

TEST(HeapTest, IsEmptyReturnsCorrectState) {
    Heap<int> heap;
    EXPECT_TRUE(heap.isEmpty());

    heap.insert(10);
    EXPECT_FALSE(heap.isEmpty());

    // heap.eraise(10);
    // EXPECT_TRUE(heap.isEmpty());
}
/*
TEST(HeapTest, InsertAndFindWorkCorrectly) {
    Heap<int> minHeap(MIN);

    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(8);

    EXPECT_EQ(minHeap.find(3), 0);
    EXPECT_EQ(minHeap.find(5), 1);
    EXPECT_EQ(minHeap.find(8), 2);
    EXPECT_EQ(minHeap.find(10), static_cast<size_t>(-1));

    Heap<int> maxHeap(MAX);
    maxHeap.insert(5);
    maxHeap.insert(3);
    maxHeap.insert(8);

    EXPECT_EQ(maxHeap.find(8), 0);
    EXPECT_EQ(maxHeap.find(5), 1);
    EXPECT_EQ(maxHeap.find(3), 2);
}

TEST(HeapTest, EraseRemovesElementAndMaintainsHeapProperty) {
    int arr[] = {3, 1, 4, 1, 5, 9};
    size_t size = sizeof(arr)/sizeof(arr[0]);

    Heap<int> maxHeap(arr, size, MAX);
    maxHeap.eraise(9);
    EXPECT_EQ(maxHeap.find(9), static_cast<size_t>(-1));
    EXPECT_EQ(maxHeap.find(5), 0);

    Heap<int> minHeap(arr, size, MIN);
    minHeap.eraise(1);
    size_t pos = minHeap.find(1);
    EXPECT_TRUE(pos == static_cast<size_t>(-1) || minHeap.find(1) > 0);
}
*/
