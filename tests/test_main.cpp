#include <gtest.h> //_VARIADIC_MAX=10

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
