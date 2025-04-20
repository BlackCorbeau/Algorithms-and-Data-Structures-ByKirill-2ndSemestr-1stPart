#include <gtest.h>
#include "../lib_HashTable/OpenAdressHashTable.h"

TEST(OpenAdressHashTableTest, DefaultConstructor) {
    OAHashT<int, std::string> hashTable;
    EXPECT_EQ(hashTable.get_size(), 0);
}

TEST(OpenAdressHashTableTest, InsertElements) {
    OAHashT<int, std::string> hashTable;
    HashNode<int, std::string> node1(1, "one");
    HashNode<int, std::string> node2(2, "two");
    HashNode<int, std::string> node3(3, "three");

    size_t index1 = hashTable.insert(node1);
    EXPECT_NE(index1, static_cast<size_t>(-1));
    EXPECT_EQ(hashTable.get_size(), 1);

    size_t index2 = hashTable.insert(node2);
    EXPECT_NE(index2, static_cast<size_t>(-1));
    EXPECT_EQ(hashTable.get_size(), 2);

    size_t index3 = hashTable.insert(node3);
    EXPECT_NE(index3, static_cast<size_t>(-1));
    EXPECT_EQ(hashTable.get_size(), 3);
}

TEST(OpenAdressHashTableTest, FindElements) {
    OAHashT<int, std::string> hashTable;
    HashNode<int, std::string> node1(1, "one");
    HashNode<int, std::string> node2(2, "two");

    hashTable.insert(node1);
    hashTable.insert(node2);

    auto found1 = hashTable.find(1);
    ASSERT_NE(found1, nullptr);
    EXPECT_EQ(found1->get_val().second(), "one");

    auto found2 = hashTable.find(2);
    ASSERT_NE(found2, nullptr);
    EXPECT_EQ(found2->get_val().second(), "two");

    auto notFound = hashTable.find(3);
    EXPECT_EQ(notFound, nullptr);
}

TEST(OpenAdressHashTableTest, HandleCollisions) {
    OAHashT<int, std::string> smallTable;
    HashNode<int, std::string> node1(1, "one");
    HashNode<int, std::string> node2(16, "sixteen");

    size_t index1 = smallTable.insert(node1);
    size_t index2 = smallTable.insert(node2);

    EXPECT_NE(index1, index2);
    EXPECT_EQ(smallTable.get_size(), 2);

    auto found1 = smallTable.find(1);
    ASSERT_NE(found1, nullptr);
    EXPECT_EQ(found1->get_val().second(), "one");

    auto found2 = smallTable.find(16);
    ASSERT_NE(found2, nullptr);
    EXPECT_EQ(found2->get_val().second(), "sixteen");
}

TEST(OpenAdressHashTableTest, OverflowTest) {
    OAHashT<int, std::string> hashTable;

    for (int i = 0; i < CAPACITY; ++i) {
        HashNode<int, std::string> node(i, "value" + std::to_string(i));
        size_t index = hashTable.insert(node);
        EXPECT_NE(index, static_cast<size_t>(-1));
    }

    EXPECT_EQ(hashTable.get_size(), CAPACITY);

    HashNode<int, std::string> overflowNode(CAPACITY, "overflow");
    size_t overflowIndex = hashTable.insert(overflowNode);
    EXPECT_EQ(overflowIndex, static_cast<size_t>(-1));
    EXPECT_EQ(hashTable.get_size(), CAPACITY);
}

TEST(OpenAdressHashTableTest, NodeStates) {
    OAHashT<int, std::string> hashTable;
    HashNode<int, std::string> node1(1, "one");
    size_t index = hashTable.insert(node1);

    EXPECT_EQ(hashTable.get_node_state(index), BUISY);
    EXPECT_EQ(hashTable.find(2), nullptr);
}

TEST(OpenAdressHashTableTest, DifferentTypes) {
    OAHashT<std::string, double> stringKeyTable;
    HashNode<std::string, double> node1("pi", 3.14);
    HashNode<std::string, double> node2("e", 2.71);

    stringKeyTable.insert(node1);
    stringKeyTable.insert(node2);

    auto foundPi = stringKeyTable.find("pi");
    ASSERT_NE(foundPi, nullptr);
    EXPECT_DOUBLE_EQ(foundPi->get_val().second(), 3.14);

    auto foundE = stringKeyTable.find("e");
    ASSERT_NE(foundE, nullptr);
    EXPECT_DOUBLE_EQ(foundE->get_val().second(), 2.71);
}

TEST(OpenAdressHashTableTest, EraseElement) {
    OAHashT<int, std::string> hashTable;
    HashNode<int, std::string> node1(1, "one");
    hashTable.insert(node1);

    auto foundBefore = hashTable.find(1);
    ASSERT_NE(foundBefore, nullptr);

    hashTable.eraise(1);

    auto foundAfter = hashTable.find(1);
    EXPECT_EQ(foundAfter, nullptr);
    EXPECT_EQ(hashTable.get_size(), 0);
}

TEST(OpenAdressHashTableTest, EraseNonExistentElement) {
    OAHashT<int, std::string> hashTable;
    hashTable.eraise(1);
    EXPECT_EQ(hashTable.get_size(), 0);
}

TEST(OpenAdressHashTableTest, InsertAfterErase) {
    OAHashT<int, std::string> hashTable;
    HashNode<int, std::string> node1(1, "one");
    hashTable.insert(node1);

    hashTable.eraise(1);

    HashNode<int, std::string> node2(1, "new_one");
    size_t index = hashTable.insert(node2);
    EXPECT_NE(index, static_cast<size_t>(-1));
    EXPECT_EQ(hashTable.get_size(), 1);

    auto found = hashTable.find(1);
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->get_val().second(), "new_one");
}

TEST(OpenAdressHashTableTest, FindDeletedElement) {
    OAHashT<int, std::string> hashTable;
    HashNode<int, std::string> node1(1, "one");
    hashTable.insert(node1);

    hashTable.eraise(1);

    auto found = hashTable.find(1);
    EXPECT_EQ(found, nullptr);
}
