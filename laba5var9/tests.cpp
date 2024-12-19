#include "include/CustomList.h"
#include "include/FixedMemoryResource.h"
#include <gtest/gtest.h>
#include <string>

// Тесты для CustomList
TEST(CustomListTest, PushBackAndIterate) {
    FixedMemoryResource memoryResource(1024);
    CustomList<int> intList(&memoryResource);

    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);

    std::vector<int> values;
    for (const auto& value : intList) {
        values.push_back(value);
    }

    EXPECT_EQ(values.size(), 3);
    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 2);
    EXPECT_EQ(values[2], 3);
}

TEST(CustomListTest, ComplexTypeSupport) {
    FixedMemoryResource memoryResource(1024);
    CustomList<std::string> stringList(&memoryResource);

    stringList.push_back("Alice");
    stringList.push_back("Bob");

    std::vector<std::string> values;
    for (const auto& value : stringList) {
        values.push_back(value);
    }

    EXPECT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], "Alice");
    EXPECT_EQ(values[1], "Bob");
}

// Тесты для FixedMemoryResource
TEST(FixedMemoryResourceTest, AllocateAndDeallocate) {
    FixedMemoryResource memoryResource(1024);
    void* ptr1 = memoryResource.allocate(128);
    ASSERT_NE(ptr1, nullptr);

    void* ptr2 = memoryResource.allocate(64);
    ASSERT_NE(ptr2, nullptr);

    memoryResource.deallocate(ptr1, 128);
    memoryResource.deallocate(ptr2, 64);
}

TEST(FixedMemoryResourceTest, AllocationExceedsBlockSize) {
    FixedMemoryResource memoryResource(1024);
    EXPECT_THROW([&]() {
        [[maybe_unused]] void* ptr = memoryResource.allocate(2048);
    }(), std::bad_alloc);
}

TEST(FixedMemoryResourceTest, ReuseDeallocatedMemory) {
    FixedMemoryResource memoryResource(1024);
    void* ptr1 = memoryResource.allocate(512);
    memoryResource.deallocate(ptr1, 512);

    void* ptr2 = memoryResource.allocate(512);
    EXPECT_NE(ptr2, nullptr);
}

// Дополнительные тесты для итераторов
TEST(CustomListIteratorTest, EmptyList) {
    FixedMemoryResource memoryResource(1024);
    CustomList<int> emptyList(&memoryResource);

    auto it = emptyList.begin();
    EXPECT_EQ(it, emptyList.end());
}

TEST(CustomListIteratorTest, SingleElement) {
    FixedMemoryResource memoryResource(1024);
    CustomList<int> intList(&memoryResource);

    intList.push_back(42);

    auto it = intList.begin();
    EXPECT_NE(it, intList.end());
    EXPECT_EQ(*it, 42);

    ++it;
    EXPECT_EQ(it, intList.end());
}

TEST(CustomListIteratorTest, MultipleElements) {
    FixedMemoryResource memoryResource(1024);
    CustomList<int> intList(&memoryResource);

    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);

    auto it = intList.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(it, intList.end());
}
