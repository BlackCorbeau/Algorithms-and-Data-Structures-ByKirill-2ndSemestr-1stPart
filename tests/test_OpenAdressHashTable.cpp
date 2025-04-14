#include <gtest.h>
#include "../lib_HashTable/HashTable.h"

TEST(OpenAdressHashTableTest, DefaultConstructor) {
    OAHashT<int, std::string> hashTable;
    EXPECT_EQ(hashTable.get_size(), 0);
    HashNode<int, std::string> node(42, "answer");
    EXPECT_NO_THROW(hashTable.insert(node));
}

TEST(OpenAdressHashTableTest, InsertElement) {
    OAHashT<int, std::string> hashTable;
    HashNode<int, std::string> node(42, "answer");

    size_t index = hashTable.insert(node);
    EXPECT_NE(index, static_cast<size_t>(-1));
}

TEST(OpenAdressHashTableTest, HandleCollision) {
    OAHashT<int, std::string> hashTable;
    HashNode<int, std::string> node1(1, "first");
    HashNode<int, std::string> node2(1 + CAPACITY, "collision");

    size_t index1 = hashTable.insert(node1);
    size_t index2 = hashTable.insert(node2);

    EXPECT_NE(index1, index2);
}

TEST(OpenAdressHashTableTest, NodeStates) {
    OAHashT<int, std::string> hashTable;
    HashNode<int, std::string> node(10, "ten");

    size_t index = hashTable.insert(node);
    EXPECT_EQ(hashTable.get_node_state(index), BUISY);
}

TEST(OpenAdressHashTableTest, OverflowHandling) {
    OAHashT<int, std::string> hashTable;
    for (int i = 0; i < CAPACITY; ++i) {
        HashNode<int, std::string> node(i, "value_" + std::to_string(i));
        EXPECT_NE(hashTable.insert(node), static_cast<size_t>(-1));
    }
    HashNode<int, std::string> overflowNode(CAPACITY, "overflow");
    EXPECT_EQ(hashTable.insert(overflowNode), static_cast<size_t>(-1));
}


TEST(OpenAdressHashTableTest, HashFunctionConsistency) {
    OAHashT<int, std::string> hashTable;
    int key = 123;
    size_t hash1 = hashTable.hashFunc(key, 0);
    size_t hash2 = hashTable.hashFunc(key, 0);

    EXPECT_EQ(hash1, hash2);
}
