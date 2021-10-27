#include <gtest/gtest.h>
#include <gmock/gmock.h>

//在我们需要测试某个api的时候，需要将这个api封装为一个借口
class Turtle{
...
 virtual ~Turtle();
 virtual void PenUp() = 0;
 virtual void Pendown() = 0;
 virtual void Forward(int distance) = 0;
 virtual void Turn(int degrees) = 0;
 virtual void Goto(int x, int y) = 0;
 virtual int GETY() const = 0;
 virtual int GETX() const = 0;

}

1.继承Turtle类，得到MockTurtle类  
2.从Turtle类中选取一个虚函数，数一下它有几个参数  
3.在MockTurtle类中的public部分，写上MOCK_METHODn()，其中ｎ是参数的个数。如果mock的是一个const函数，就写上MOCK_CONST_METHODn  
4.将函数名作为宏的第一个参数，然后将函数定义中除函数名以外的部分作为宏的第二个参数  

class MockTurtle : public Turtle {
 public:
  ...
  MOCK_METHOD0(PenUp, void ());
  MOCK_METHOD0(Pendown, void ());
  MOCK_METHOD1(Forward, void (int distance));
  MOCK_METHOD1(Turn, void (int degrees));
  MOCK_METHOD1(Goto, void (int x, int y));
  MOCK_METHOD_CONST_METHOD0(GETY, int ());
  MOCK_METHOD_CONST_METHOD0(GETX, int ());
}


//TEST宏的例子
// 这个测试是检查PenUp()是否被调用了一次，如果Painter对象没有调用这个函数，你的测试就会失败
TEST(PainterTest, CanDrowSomething) {
  MockTurtle turtle;
  //Google Mock要求期望在Mock函数被调用之前就设置好，
  //这意味着EXPECT_CALL应该被理解为一个调用在未来的期望。
  EXPECT_CALL(turtle, PenUp()).Times();
  Painter painter(&turtule);

  EXPECT_TRUE(painter.DrawCircle(0,0, 10));
}

//设置尺度
EXPECT_ALL(turtle, GetX())
  .Times(5)
  .WillOnce(Return(100))
  .WillOnce(Return(150))
  .WillRepeatedly(Return(200))
// turtle对象的GetX()会被调用５次，它第一次返回１００，第二次返回１５０，然后每次返回２００

//为什么Google Mock会以逆序去匹配期望呢？
using ::testing::_; ...
EXPECT_CALL(turtle, Forward(_));  // #1
EXPECT_CALL(turtle, Forward(10)); // #2

//这里先调用#2, 再调用#1


//顺序执行
using :: testing::InSequence;
using :: testing::Return;

{
  InSequence s;

  for(int i = 1; i <= n; i++) {
    EXPECT_CALL(turtle, GetX())
      .WillOnce(Return(10*i))
      .RetiresOnSaturation(); //没有严格期望
  }
}