#include "MyString.cpp"
#include "gtest/gtest.h"
namespace 
{
    TEST(MyString, DefaultConstructor) 
    {
        const MyString s;

        EXPECT_STREQ(NULL, s.c_string());
        EXPECT_EQ(0u, s.length());
    }

    const char kHelloString[] = "Hello, world!";

    TEST(MyString, ConstructorFromCString) 
    {
        const MyString s(kHelloString);
        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));
        EXPECT_EQ(sizeof(kHelloString)/sizeof(kHelloString[0]) - 1, s.length());
    }

    TEST(MyString, CopyConstructor) 
    {
        const MyString s1(kHelloString);
        const MyString s2 = s1;
        EXPECT_EQ(0, strcmp(s2.c_string(), kHelloString));
    }

    TEST(MyString, Set) 
    {
        MyString s;

        s.setCString(kHelloString);
        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));

        s.setCString(s.c_string());
        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));

        // Can we set the MyString to NULL?
        s.setCString(NULL);
        EXPECT_STREQ(NULL, s.c_string());
    }
}  // namespace

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}