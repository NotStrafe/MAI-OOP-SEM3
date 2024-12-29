#include <gtest/gtest.h>
#include "ListMemoryResource.hpp"
#include "DynamicArray.hpp"
#include <memory>

TEST(DynamicArrayIteratorTest, BasicIteration) {
    ListMemoryResource memoryResource;
    DynamicArray<int> array(&memoryResource); 

    array.push_back(10);
    array.push_back(20);
    array.push_back(30);

    auto it = array.begin();
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(*it, 30);

    ++it;
    EXPECT_TRUE(it == array.end());
}

TEST(DynamicArrayIteratorTest, EmptyArrayIteration) {
    ListMemoryResource memoryResource;
    DynamicArray<int> array(&memoryResource);

    auto it = array.begin();
    EXPECT_TRUE(it == array.end()); 
}

TEST(DynamicArrayTest, PushComplexTypeTest) {
    struct ComplexType {
        int id;
        std::string name;
    };

    ListMemoryResource memoryResource;
    DynamicArray<ComplexType> complexArray(&memoryResource);

    complexArray.push_back({1, "Alice"});
    complexArray.push_back({2, "Bob"});
    complexArray.push_back({3, "Charlie"});

    auto it = complexArray.begin();
    EXPECT_EQ(it->id, 1);
    EXPECT_EQ(it->name, "Alice");
    ++it;
    EXPECT_EQ(it->id, 2);
    EXPECT_EQ(it->name, "Bob");
    ++it;
    EXPECT_EQ(it->id, 3);
    EXPECT_EQ(it->name, "Charlie");
}

TEST(ListMemoryResourceTest, AllocationTest) {
    ListMemoryResource memoryResource;

    DynamicArray<int> array(&memoryResource);

    array.push_back(1);
    array.push_back(2);
    array.push_back(3);

    EXPECT_EQ(array.get_size(), 3);
    EXPECT_EQ(array.get_capacity(), 4);
}

TEST(DynamicArrayTest, ClearTest) {
    ListMemoryResource memoryResource;
    DynamicArray<int> array(&memoryResource);

    array.push_back(42);
    array.push_back(17);
    array.push_back(33);

    array.clear();
    EXPECT_EQ(array.get_size(), 0);
    EXPECT_TRUE(array.begin() == array.end()); 
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}