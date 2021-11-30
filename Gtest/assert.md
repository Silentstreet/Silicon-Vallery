#### 断言相关的宏
主要总结断言相关的宏

##### 布尔值检查
```
ASSERT_TRUE(condition);          Verifies condition is true;
ASSERT_FALSE(condition);         Verifies condition is false;
```

##### 数值型数据检查
ASSERT_EQ(expected, actual);     检查是否相等
ASSERT_NE(val1, val2);           val1 != val2
ASSERT_LT(val1, val2);           val1 < val2
ASSERT_LE(val1, val2);           val1 <= val2
ASSERT_GT(val1, val2);           val1 > val2
ASSERT_GE(val1, val2);           val1 >= val2

##### 字符串检查
ASSERT_STREQ(expected_str, actual_str);
ASSERT_STRNE(str1, str2);
ASSERT_STRCASEEQ(expected_str, actual_str);     //the two string have the same content, ignoring case
ASSERT_STRCASENE(str1, str2);                   //the two string have different content, ignoring case

##### 异常检查
ASSERT_THROW(statement, exception_type);
ASSERT_ANY_THROW(statement);
ASSERT_NO_THROW(statement);