#include "include/CustomList.h"
#include "include/FixedMemoryResource.h"
#include <gtest/gtest.h>

TEST(CustomListTest, PushBackAndIterate) {
    FixedMemoryResource memoryResource(1024);
    CustomList<int> list(&memoryResource);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    int expected[] = {1, 2, 3};
    int i = 0;
    for (const auto& value : list) {
        EXPECT_EQ(value, expected[i++]);
    }
}
