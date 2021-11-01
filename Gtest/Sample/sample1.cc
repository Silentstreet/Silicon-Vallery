// 例子来源于　googletest官方文档　https://google.github.io/googletest/primer.html

//需要测试的类,并且我们只需要它的声明，具体定义commiter必须知道
template <typename E>
class Queue {
public:
    Queue();
    void Enqueue(const E& element);
    E* Dequeue(); // Returns NULL if the queue is empty.
    size_t size() const;
    ...
}

class QueueTest : public ::testing::Test{
protected:
    void SetUp() override {
        q1_.Enqueue(1);
        q2_.Enqueue(2);
        q2_.Enqueue(3);
    }

    // void TearDown() override {}

    Queue<int> q0_;
    Queue<int> q1_;
    Queue<int> q2_;
};


//单元测试
TEST_F(QueueTest, IsEmptyInitialy) {
    EXPECT_EQ(q0_.size(), 0);
}

TEST_F(QueueTest, DequeueWorks) {
    int* n = q0_.Dequeue();
    EXPECT_EQ(n, nullptr);

    n = q1_.Dequeue();
    EXPECT_NE(n, nullptr); //常规套路就是先检测这个指针是否空悬，再去查看它所指的值
    EXPECT_EQ(*n, 1);
    EXPECT_EQ(q1_.size(), 0);
    delete n;

    n = q2_.Dequeue();
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(*n, 2);
    EXPECT_EQ(q2_.size(), 1);
    delete n;
}

