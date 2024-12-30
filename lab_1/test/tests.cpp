#include <gtest/gtest.h>
#include <string>
#include "../include/solution.h"

TEST(SolutionTest, BasicCases) {
    EXPECT_EQ(solution("Vader said: No, I am your father!", 2, 'a', 'o'), "Vader soid: No, I am your fother!");
    EXPECT_EQ(solution("aaaaaaaaa", 1, 'a', 'o'), "ooooooooo");
}

TEST(SolutionTest, NoOccurrencesOfOldValue) {
    EXPECT_EQ(solution("Hello, world!", 2, 'z', 'o'), "Hello, world!");
}

TEST(SolutionTest, ZeroOrNegativeN) {
    EXPECT_EQ(solution("Hello, world!", 0, 'a', 'o'), "Hello, world!");
    EXPECT_EQ(solution("Hello, world!", -1, 'a', 'o'), "Hello, world!");
}

TEST(SolutionTest, NGreaterThanOccurrences) {
    EXPECT_EQ(solution("Hello, world!", 3, 'l', 'i'), "Hello, worid!");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
