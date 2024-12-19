#include "include/CustomList.h"
#include "include/FixedMemoryResource.h"
#include <iostream>
#include <string>

struct ComplexType {
    int id;
    std::string name;
};

int main() {
    FixedMemoryResource memoryResource(1024);
    CustomList<int> intList(&memoryResource);

    intList.push_back(42);
    intList.push_back(77);

    for (const auto& value : intList) {
        std::cout << value << "\n";
    }

    CustomList<ComplexType> complexList(&memoryResource);
    complexList.push_back({1, "Alice"});
    complexList.push_back({2, "Bob"});

    for (const auto& item : complexList) {
        std::cout << item.id << ": " << item.name << "\n";
    }

    return 0;
}
