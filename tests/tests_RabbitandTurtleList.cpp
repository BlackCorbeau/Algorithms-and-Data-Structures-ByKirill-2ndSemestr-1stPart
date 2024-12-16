#include <gtest.h>

#include "../lib_Parser/Parser.h"
#include "../lib_list/List.h"

TEST(RabbitandTurtleCycleListTest, NoCycle) {
    TList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_FALSE(RabbitandTurtleCycleList(list));

    while (!list.empty()) {
        list.pop_front();
    }
}

TEST(RabbitandTurtleCycleListTest, Cycle) {
    TList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    TNode<int>* tail = list.get_tail();
    tail->set_pnext(list.get_head()->get_pnext());

    EXPECT_TRUE(RabbitandTurtleCycleList(list));

    delete list.get_head();
    delete tail;
}

TEST(RabbitandTurtleCycleListTest, SingleElementNoCycle) {
    TList<int> list;
    list.push_back(1);

    EXPECT_FALSE(RabbitandTurtleCycleList(list));

    list.pop_front();
}

TEST(RabbitandTurtleCycleListTest, SingleElementCycle) {
    TList<int> list;
    list.push_back(1);

    TNode<int>* head = list.get_head();
    head->set_pnext(head);

    EXPECT_TRUE(RabbitandTurtleCycleList(list));

    delete head;
}

TEST(RabbitandTurtleCycleListTest, EmptyList) {
    TList<int> list;

    EXPECT_FALSE(RabbitandTurtleCycleList(list));
}

