2021-10-14 开始重新学习gtest框架

 gtest官方教程：https://google.github.io/googletest/primer.html
 其中完整的assert断言宏：https://google.github.io/googletest/reference/assertions.html

#### 配置  
1.ubuntu下配置gtest参考: https://blog.csdn.net/l1216766050/article/details/111094078  

通过g++ main.cpp -std=c++11 lgtest -lpthread 编译得到一个a.out可执行文件,执行这个a.out能够进行google test
-l参数就是用来指定程序要链接的库

编写一个简单的测试样例多么的简单.我们使用了TEST这个宏,它有两个参数,官方对这两个参数的解释为:[TestCaseName, TestName],而我对这两个参数的定义是[TestSuiteName, TestCaseName]
Google还包装了一系列的EXPECT_*和ASSERT_*的宏,而EXPECT_*和ASSERT_*系列的的区别是:  
1. EXPECT_*失败时,案例继续往下执行  
2. ASSERT_*失败时,直接在当前函数中返回,当前函数中ASSERT_*后面的语句将不会执行

写单元测试的时候尽量用EXPECT_*,因为ASSERT_*是直接crash退出的,可能会导致一些内存、文件资源没有释放，因此可能引入一些bug  

gtest和gmock的区别？  
    gmock仅提供一个方便mock的工具，通过gmock可以方便地创建一个真实类的子类。