#include <gtest/gtest.h>
#include "extract_numbers.h"

TEST(test_01, basic_test_set) {
    std::string input = "a123b45c6";
    auto result = extractNumbers(input);
    ASSERT_EQ(result.size(), 3); // Проверка количества чисел
    ASSERT_EQ(result[0], "123");
    ASSERT_EQ(result[1], "45");
    ASSERT_EQ(result[2], "6");
}

TEST(test_02, empty_input) {
    std::string input = "";
    auto result = extractNumbers(input);
    ASSERT_TRUE(result.empty()); // Проверка на пустой результат
}

TEST(test_03, no_numbers) {
    std::string input = "abcdXYZ";
    auto result = extractNumbers(input);
    ASSERT_TRUE(result.empty()); // Проверка, если чисел нет
}

TEST(test_04, consecutive_numbers) {
    std::string input = "123456";
    auto result = extractNumbers(input);
    ASSERT_EQ(result.size(), 1); // Только одно число
    ASSERT_EQ(result[0], "123456");
}

TEST(test_05, mixed_numbers) {
    std::string input = "12a34b567";
    auto result = extractNumbers(input);
    ASSERT_EQ(result.size(), 3); // Три отдельных числа
    ASSERT_EQ(result[0], "12");
    ASSERT_EQ(result[1], "34");
    ASSERT_EQ(result[2], "567");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
