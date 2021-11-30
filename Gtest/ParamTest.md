#### 参数化  
被测函数需要传入不同的值，为了最大化地复用代码，我们采用参数化的方案。

1. 告诉gtest你的参数类型是什么  
    你必须添加一个类，继承testing::TestWithParam<T>，其中T就是你需要参数化的参数类型
    class IsPrimeParamTest : public::testing::TestWithParam<int>
    {

  };

2. 告诉gtest你拿到参数后的值，具体做些什么样的参数  
    这里，需要使用到一个新的宏TEST_P，关于这个“P”，可以理解为parameterized或者pattern  
    TEST_P(IsPrimeParamTest, HandleTrueReturn)
    {

  ​	int n = GetParam(); //在TETS_P宏中，使用GetParam()获取当前参数的具体值
  ​	EXPECT_TRUE(IsPrime(n));
  }

3. 告诉gtest你想要的参数范围

   INSTANTIATE_TEST_CASE_P(TrueReturn, IsPrimeParamTest, testing::Values(3,5,11,23,17));

   第一个参数是测试案例的前缀，可以任意取

   第二个参数是测试案例的名称，需要和之前定义的参数化的类的名称相同

   第三个参数可以理解为参数生成器，......



更多gtest的宏需要在实际测试中去学习。
