#include <gtest/gtest.h>
#include "../main.cpp"

TEST(DoublyLinkedListTest, DeleteList) {
DoublyLinkedList list;
list.append(1);
list.append(2);
list.append(3);

list.deleteList();
EXPECT_TRUE(list.isEmpty());
}