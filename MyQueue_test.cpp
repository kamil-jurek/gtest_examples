#include "MyQueue.hpp"
#include "gtest/gtest.h"
#include <iostream>

namespace 
{
    class MyQueueFixture : public testing::Test 
    {
      protected:
        virtual void SetUp() 
        {
            std::cout << "SetUp()" << std::endl;
            q1_.Enqueue(1);
            q2_.Enqueue(2);
            q2_.Enqueue(3);
        }

        virtual void TearDown() 
        {
             std::cout << "TearDown()" << std::endl;
        }

        static int Double(int n) 
        {
            return 2*n;
        }

        // A helper function for testing Queue::Map().
        void MapTester(const Queue<int>* q) 
        {
            // Creates a new queue, where each element is twice as big as the corresponding one in q.
            const Queue<int> * const new_q = q->Map(Double);

            // Verifies that the new queue has the same size as q.
            ASSERT_EQ(q->Size(), new_q->Size());

            // Verifies the relationship between the elements of the two queues.
            for ( const QueueNode<int> * n1 = q->Head(), * n2 = new_q->Head();
                  n1 != NULL; n1 = n1->next(), n2 = n2->next() ) 
            {
                EXPECT_EQ(2 * n1->element(), n2->element());
            }

            delete new_q;
        }

        // Declares the variables your tests want to use.
        Queue<int> q0_;
        Queue<int> q1_;
        Queue<int> q2_;
    };

    // Tests the default c'tor.
    TEST_F(MyQueueFixture, DefaultConstructor) 
    {
        // You can access data in the test fixture here.
        EXPECT_EQ(0u, q0_.Size());
    }

    // Tests Dequeue().
    TEST_F(MyQueueFixture, Dequeue) 
    {
        int* n = q0_.Dequeue();
        EXPECT_TRUE(n == nullptr);

        n = q1_.Dequeue();
        ASSERT_TRUE(n != nullptr);
        EXPECT_EQ(1, *n);
        EXPECT_EQ(0u, q1_.Size());
        delete n;

        n = q2_.Dequeue();
        ASSERT_TRUE(n != nullptr);
        EXPECT_EQ(2, *n);
        EXPECT_EQ(1u, q2_.Size());
        delete n;
    }

    // Tests the Queue::Map() function.
    TEST_F(MyQueueFixture, Map) 
    {
        MapTester(&q0_);
        MapTester(&q1_);
        MapTester(&q2_);
    }
}  // namespace

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}