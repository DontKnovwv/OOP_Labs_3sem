#include "extract_numbers.h"
#include <cctype>
#include <string>
#include <vector>

std::vector<std::string> extractNumbers(const std::string& input) {
    std::vector<std::string> numbers;
    std::string currentNumber;

    for (char ch : input) {
        if (std::isdigit(ch)) {
            currentNumber += ch;
        } else if (!currentNumber.empty()) {
            numbers.push_back(currentNumber);
            currentNumber.clear();
        }
    }

    if (!currentNumber.empty()) {
        numbers.push_back(currentNumber);
    }

    return numbers;
}
