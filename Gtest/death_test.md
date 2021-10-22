#### 死亡测试  
死亡测试，这里指的是程序的崩溃。需要考虑各种各样的输入，有的输入可能导致程序崩溃，这时我们就需要检查程序是否按照预期挂掉，这就是所谓的死亡测试。  

##### 需要使用的宏
ASSERT_DEATH(statement, regex)  
ASSERT_EXIT(statement, predicate, regex)  
其中的statement是被测试的代码语句，regex是一个正则表达式，用来匹配异常时在stderr中输出的内容  
predicate这里必须是一个委托，接收int型参数，并返回bool，只有当返回值是true时，才算通过死亡测试  
幸运是的gtest自己提供一些常见的predicate  
testing::ExitedWithCode(exit_code)


##### 死亡测试运行方式
```c++
TEST(MyDeathTest, TestOne){
    testing::FLAGGS_gtest_death_test_style = "threadsafe";
    //给到参数：线程安全
    ASSERT_DEATH(ThisShouleDie(), "");
}

TEST(MyDeathTest, TestTwo){
    //默认运行在fast模式下
    ASSERT_DEATH(ThisShouldDie(), "");
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGGS_gtest_death_test_style = "fast";
    return RUN_ALL_TESTS();
}
```