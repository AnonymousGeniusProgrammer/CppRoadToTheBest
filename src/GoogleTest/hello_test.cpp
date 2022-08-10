#include <gtest/gtest.h>

TEST(test_suit_1, test_1) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7*6, 42);
}

TEST(test_suit_1, test_2) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7*6, 42);
}

TEST(test_suit_2, test_1)
{
    EXPECT_STREQ("hello", "world");
    EXPECT_NE(7*6, 42);
}

TEST(test_suit_2, test_2)
{
    EXPECT_STRNE("hello", "world");
    EXPECT_NE(7*6, 42);
}
