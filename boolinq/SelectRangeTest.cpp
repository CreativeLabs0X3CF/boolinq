#include <vector>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "IterRange.h"
#include "SelectRange.h"

#include "ToVector.h"

using namespace boolinq;

TEST(SelectRange, Mul2)
{
    std::vector<int> src;
    src.push_back(1);
    src.push_back(2);
    src.push_back(3);
    src.push_back(4);
    
    auto rng = range(src);
    auto dst = select(rng, [](int a){return a * 2;});

    EXPECT_EQ(2, dst.popFront());
    EXPECT_EQ(4, dst.popFront());
    EXPECT_EQ(6, dst.popFront());
    EXPECT_EQ(8, dst.popFront());
    EXPECT_TRUE(dst.empty());
}

TEST(SelectRange, MakeChar)
{
    std::vector<int> src;
    src.push_back(1);
    src.push_back(2);
    src.push_back(3);
    src.push_back(4);

    static const char * table[] =
    {
        "hello",
        "world",
        "apple",
        "intel",
    };

    auto rng = range(src);
    auto dst = select(rng, [](int a){return table[a-1];});

    EXPECT_STREQ("hello", dst.popFront());
    EXPECT_STREQ("world", dst.popFront());
    EXPECT_STREQ("apple", dst.popFront());
    EXPECT_STREQ("intel", dst.popFront());
    EXPECT_TRUE(dst.empty());
}