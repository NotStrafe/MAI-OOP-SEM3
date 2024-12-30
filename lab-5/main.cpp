#include "ListMemoryResource.hpp"
#include "DynamicArray.hpp"
#include <iostream>
#include <string>

struct ComplexType {
    int id;
    std::string name;

    ComplexType(int id, const std::string& name) : id(id), name(name) {}
};

int main() {
    ListMemoryResource memory_resource;

    DynamicArray<int> int_array{&memory_resource};
    int_array.push_back(1);
    int_array.push_back(2);
    int_array.push_back(3);

    for (const auto& val : int_array) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    DynamicArray<ComplexType> complex_array{&memory_resource};
    complex_array.push_back({1, "Alice"});
    complex_array.push_back({2, "Bob"});

    for (const auto& obj : complex_array) {
        std::cout << obj.id << ": " << obj.name << std::endl;
    }

    return 0;
}