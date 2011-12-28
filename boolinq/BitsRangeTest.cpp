#include <vector>
#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "CommonTests.h"

#include "IterRange.h"
#include "BitsRange.h"

using namespace boolinq;

//////////////////////////////////////////////////////////////////////////

TEST(BitsRange, OneByteDefault)
{
    unsigned char src[] = {0xAA};
    int ans[] = {1,0,1,0,1,0,1,0};

    auto rng = range(src);
    auto dst = bits(rng);

    CheckRangeEqArray(dst, ans);
}

TEST(BitsRange, OneByteHL)
{
    unsigned char src[] = {0xAA};
    int ans[] = {1,0,1,0,1,0,1,0};

    auto rng = range(src);
    auto dst = bits<HighToLow>(rng);

    CheckRangeEqArray(dst, ans);
}

TEST(BitsRange, OneByteLH)
{
    unsigned char src[] = {0xAA};
    int ans[] = {0,1,0,1,0,1,0,1};

    auto rng = range(src);
    auto dst = bits<LowToHigh>(rng);

    CheckRangeEqArray(dst, ans);
}

//////////////////////////////////////////////////////////////////////////

TEST(BitsRange, OneIntDefault)
{
    unsigned int src[] = {0x12345678};
    int ans[] = 
    {
        0,1,1,1,1,0,0,0,
        0,1,0,1,0,1,1,0,
        0,0,1,1,0,1,0,0,
        0,0,0,1,0,0,1,0,
    };

    auto rng = range(src);
    auto dst = bits(rng);

    CheckRangeEqArray(dst, ans);
}

TEST(BitsRange, OneIntHL)
{
    unsigned int src[] = {0x12345678};
    int ans[] = 
    {
        0,1,1,1,1,0,0,0,
        0,1,0,1,0,1,1,0,
        0,0,1,1,0,1,0,0,
        0,0,0,1,0,0,1,0,
    };

    auto rng = range(src);
    auto dst = bits<HighToLow>(rng);

    CheckRangeEqArray(dst, ans);
}

TEST(BitsRange, OneIntLH)
{
    unsigned int src[] = {0x12345678};
    int ans[] = 
    {
        0,0,0,1,1,1,1,0,
        0,1,1,0,1,0,1,0,
        0,0,1,0,1,1,0,0,
        0,1,0,0,1,0,0,0,
    };

    auto rng = range(src);
    auto dst = bits<LowToHigh,FirstToLast>(rng);

    CheckRangeEqArray(dst, ans);
}

//////////////////////////////////////////////////////////////////////////

TEST(BitsRange, IntsDefault)
{
    unsigned int src[] = {0x12345678,0xAABBCCDD};
    int ans[] = 
    {
        0,1,1,1,1,0,0,0, // 78
        0,1,0,1,0,1,1,0, // 56
        0,0,1,1,0,1,0,0, // 34
        0,0,0,1,0,0,1,0, // 12

        1,1,0,1,1,1,0,1, // DD
        1,1,0,0,1,1,0,0, // CC
        1,0,1,1,1,0,1,1, // BB
        1,0,1,0,1,0,1,0, // AA
    };

    auto rng = range(src);
    auto dst = bits(rng);

    CheckRangeEqArray(dst, ans);
}

TEST(BitsRange, IntsHL)
{
    unsigned int src[] = {0x12345678,0xAABBCCDD};
    int ans[] = 
    {
        0,1,1,1,1,0,0,0, // 78
        0,1,0,1,0,1,1,0, // 56
        0,0,1,1,0,1,0,0, // 34
        0,0,0,1,0,0,1,0, // 12

        1,1,0,1,1,1,0,1, // DD
        1,1,0,0,1,1,0,0, // CC
        1,0,1,1,1,0,1,1, // BB
        1,0,1,0,1,0,1,0, // AA
    };

    auto rng = range(src);
    auto dst = bits<HighToLow>(rng);

    CheckRangeEqArray(dst, ans);
}

TEST(BitsRange, IntsLH)
{
    unsigned int src[] = {0x12345678,0xAABBCCDD};
    int ans[] = 
    {
        0,0,0,1,1,1,1,0, // -87
        0,1,1,0,1,0,1,0, // -65
        0,0,1,0,1,1,0,0, // -43
        0,1,0,0,1,0,0,0, // -21

        1,0,1,1,1,0,1,1, // -DD
        0,0,1,1,0,0,1,1, // -CC
        1,1,0,1,1,1,0,1, // -BB
        0,1,0,1,0,1,0,1, // -AA
    };

    auto rng = range(src);
    auto dst = bits<LowToHigh>(rng);

    CheckRangeEqArray(dst, ans);
}
