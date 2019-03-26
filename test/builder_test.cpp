#include "gtest/gtest.h"
#include "../src/lib/base.h"

TEST(BuilderTest, ConstructorTest) {
    CBase b(0);
    EXPECT_EQ(b.car_type, 0);
}

TEST(TestTest, Fail) {
    EXPECT_EQ(1, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}