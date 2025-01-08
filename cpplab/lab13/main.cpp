#include <gtest/gtest.h>

// Your test cases
TEST(SampleTest, TrueIsTrue) {
    EXPECT_EQ(true, true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}