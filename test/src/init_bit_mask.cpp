#include <gtest/gtest.h>
#include "large_bit_mask.h"

class InitBitMaskTest: public ::testing::TestWithParam<int>
{
protected:
    InitBitMaskTest()
    {

    }

    ~InitBitMaskTest() override
    {
        cleanBitMask(m_bitmask);
        m_bitmask = NULL;
    }

    void SetUp() override
    {

    }

    void TearDown() override
    {
        cleanBitMask(m_bitmask);
        m_bitmask = NULL;
    }

    bitmask_t* m_bitmask;
};

TEST_P(InitBitMaskTest, TestInitWithSize)
{
    GTEST_FLAG_SET(death_test_style, "threadsafe");
    int size = GetParam();
    size_t totalBytes = 0x0;
    m_bitmask = initBitMask(size, &totalBytes);
    if(m_bitmask == NULL)
    {
        GTEST_SKIP() << "Failed to initTest";
    }

    for(bitmask_t* current = m_bitmask; current < m_bitmask + totalBytes; ++current)
        EXPECT_EQ((*current), (bitmask_t)0x0);
}

INSTANTIATE_TEST_SUITE_P(InitBitMask_Test, InitBitMaskTest, ::testing::Range(0, 1000000000, 100000000));
