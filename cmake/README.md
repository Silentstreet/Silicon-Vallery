需要系统地学习下camke,并且做好笔记.供以后使用

主要参考和我一起写makefile:https://seisman.github.io/how-to-write-makefile/overview.html

主要还是参考:https://blog.csdn.net/zhanghm1995/article/details/80902807

### 文章目录

#### 基本语法规则

#### 常见CmakeLists.txt中指令剖析

#### 从VS项目配置过程中理解CMakeLists内容

#### CMake中常用变量汇总

#### 常见CMakeLists文件模板

##### 基础模板

##### 使用OpenCV库CMakeLists文件模板

##### 使用PCL库CMakeLists文件模板

##### 使用Eigen库CMakeLists文件模板






#### 基本语法规则

CMake要求工程主目录和所有存放源代码子目录下都要编写CMakeLists.txt文件。CMake变量使用${}方式取值，但是在IF控制语句中是直接使用变量名

环境变量使用$ENV{}的方式取值，使用SET(ENV{VAR} VALUE)赋值

参数使用括弧括起，参数之间使用空格或者分号分开。


#### 常见CMakeLists.txt中指令剖析

1. cmake_minimum_required(VERSION 2.6)命令
2. project(<projectname>)命令

语法：project(projectname [cxx] [c] [java])

可以指定工程采用的语言，选项分别表示:C++, C, java

意义:cmake中project命令正是定义了解决方案的名称，add_executable和add_library命令都会生成一个项目，cmake会自动为每个项目创建对应的文件夹，存储编译中间件。 [外部构建和内部构建的区别?]

3. ADD_SUBDIRECTORY命令

语法:ADD_SUBDIRECTORY(source_dir [binary_dir] [EXCLUDE_FROM_ALL])   该命令告诉CMake去子目录中查看可用的CMakeLists.txt文件

EXCLUDE_FROM_ALL参数的含义是将这个目录从编译过程中排除

4. ADD_LIBRARY命令

语法：ADD_LIBRARY(libname [SHARED|STATIC]) 告诉工程生成一个库文件

5. FIND_LIBRARY命令

查找库所在目录，语法如下:

```
FIND_LIBRARY(RUNTIME_LIB rt /usr/lib /usr/local/lib NO_DEFAULT_PATH)  
cmake会在目录中寻找，如果所在目录中都没有，值RUNTIME_LIB就会被赋予NO_DEFAULT_PATH
```


