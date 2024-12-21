#include <gtest/gtest.h>
#include <iomanip>
#include "large_bit_mask.h"


class SetBitMaskTest: public ::testing::TestWithParam<std::tuple<int, int, int>>
{
protected:
    SetBitMaskTest()
    {

    }

    ~SetBitMaskTest() override
    {
        cleanBitMask(m_bitmask);
        m_bitmask = NULL;
    }

    void SetUp() override
    {
        m_totalSize = 0x00;
        m_bitmask = initBitMask(32, &m_totalSize);
        if(m_bitmask == NULL)
        {
            GTEST_SKIP() << "Failed to initTest";
        }
    }

    void TearDown() override
    {          
        cleanBitMask(m_bitmask);
        m_bitmask = NULL;
    }

    bitmask_t* m_bitmask;
    size_t m_totalSize;
};


class ScopeOfValueTest: public ::testing::TestWithParam<std::tuple<bit_t, int>>
{
protected:
    ScopeOfValueTest()
    {

    }

    ~ScopeOfValueTest() override
    {
        cleanBitMask(m_bitmask);
        m_bitmask = NULL;
    }

    void SetUp() override
    {
        m_totalSize = 0x00;
        m_bitmask = initBitMask(1, &m_totalSize);
        if(m_bitmask == NULL)
        {
            GTEST_SKIP() << "Failed to initTest";
        }
    }

    void TearDown() override
    {
        cleanBitMask(m_bitmask);
        m_bitmask = NULL;
    }

    bitmask_t* m_bitmask;
    size_t m_totalSize;
};

TEST_P(SetBitMaskTest, TestSetFirstSlotBit)
{
    auto param = GetParam();
    setBit(m_bitmask, m_totalSize, std::get<0>(param), 0x01);
    
    std::stringstream bitMaskValue;
    bitMaskValue << "\\x";
    for(bit_t* current = m_bitmask; current < m_bitmask + m_totalSize; ++current)
        bitMaskValue << std::setfill ('0') << std::setw(sizeof(bit_t)*2) << std::hex << (short)(*current);
        
    SCOPED_TRACE(bitMaskValue.str());
    RecordProperty("bitmask", bitMaskValue.str());
    EXPECT_TRUE(*(m_bitmask + std::get<1>(param)) & (0x01 << std::get<2>(param)));
}

TEST_P(ScopeOfValueTest, TestScopeOfValue)
{
    auto param = GetParam();
    EXPECT_TRUE(setBit(m_bitmask, m_totalSize, 0, std::get<0>(param)) == std::get<1>(param));  
}

INSTANTIATE_TEST_SUITE_P(SetBitMask_Test, SetBitMaskTest, ::testing::Values(
    std::make_tuple(0x00, 0x00, 0x00),
    std::make_tuple(0x01, 0x00, 0x01),
    std::make_tuple(0x02, 0x00, 0x02),
    std::make_tuple(0x03, 0x00, 0x03),
    std::make_tuple(0x04, 0x00, 0x04),
    std::make_tuple(0x05, 0x00, 0x05),
    std::make_tuple(0x06, 0x00, 0x06),
    std::make_tuple(0x07, 0x00, 0x07),
    std::make_tuple(0x08, 0x01, 0x00),
    std::make_tuple(0x09, 0x01, 0x01),
    std::make_tuple(0x0a, 0x01, 0x02),
    std::make_tuple(0x0b, 0x01, 0x03),
    std::make_tuple(0x0c, 0x01, 0x04),
    std::make_tuple(0x0d, 0x01, 0x05),
    std::make_tuple(0x0e, 0x01, 0x06),
    std::make_tuple(0x0f, 0x01, 0x07),
    std::make_tuple(0x10, 0x02, 0x00),
    std::make_tuple(0x11, 0x02, 0x01),
    std::make_tuple(0x12, 0x02, 0x02),
    std::make_tuple(0x13, 0x02, 0x03),
    std::make_tuple(0x14, 0x02, 0x04),
    std::make_tuple(0x15, 0x02, 0x05),
    std::make_tuple(0x16, 0x02, 0x06),
    std::make_tuple(0x17, 0x02, 0x07),
    std::make_tuple(0x18, 0x03, 0x00),
    std::make_tuple(0x19, 0x03, 0x01),
    std::make_tuple(0x1a, 0x03, 0x02),
    std::make_tuple(0x1b, 0x03, 0x03),
    std::make_tuple(0x1c, 0x03, 0x04),
    std::make_tuple(0x1d, 0x03, 0x05),
    std::make_tuple(0x1e, 0x03, 0x06),
    std::make_tuple(0x1f, 0x03, 0x07)
));


INSTANTIATE_TEST_SUITE_P(SetBitMask_Test, ScopeOfValueTest, ::testing::Values(
    std::make_tuple(0x0, 0x1),
    std::make_tuple(0x1, 0x1),
    std::make_tuple(0x2, 0x0),
    std::make_tuple(0x3, 0x0),
    std::make_tuple(0x4, 0x0),
    std::make_tuple(0x5, 0x0),
    std::make_tuple(0x6, 0x0),
    std::make_tuple(0x7, 0x0)
));