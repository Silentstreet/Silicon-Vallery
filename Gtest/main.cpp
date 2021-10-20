#include <gtest/gtest.h>
#include <Eigen/Dense>
#include <iostream>

int Foo(int a, int b) {
    if(a == 0 || b == 0) {
        throw "don't do that";
    }
    int c = a % b;
    if(c == 0) {
        return b;
    }
    return Foo(b, c);
}

TEST(FooTest, HandleNoneZeroInput) {
    EXPECT_EQ(2, Foo(4, 10));
    EXPECT_EQ(6, Foo(30,18));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv); // gtest的测试案例允许接收一系列的命令行参数,因此,我们将命令行参数传递给gtest,进行一些初始化操作.
    return RUN_ALL_TESTS(); // 运行所有测试案例.
}

