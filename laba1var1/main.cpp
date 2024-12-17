#include "extract_numbers.h"
#include <iostream>
#include <vector>

int main() {
    std::string input;
    std::cin >> input;

    std::vector<std::string> numbers = extractNumbers(input);
    for (const auto& num : numbers) {
        std::cout << num << std::endl;
    }

    return 0;
}
