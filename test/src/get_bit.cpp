#include <gtest/gtest.h>
#include "large_bit_mask.h"

class GetBitMaskTest: public ::testing::TestWithParam<std::tuple<size_t, bit_t>>
{
protected:
    GetBitMaskTest()
    {

    }

    ~GetBitMaskTest() override
    {

    }

    static void SetUpTestSuite()
    {
        m_totalSize = 0x0;
        m_bitMask = initBitMask(16, &m_totalSize);
        m_bitMask[0] = 0xaa;
        m_bitMask[1] = 0xaa;
    }

    static void TearDownTestSuite()
    {
        cleanBitMask(m_bitMask);
        m_bitMask = NULL;
    }

    static size_t m_totalSize;
    static bitmask_t m_bitMask;
};

size_t GetBitMaskTest::m_totalSize = 0x0;
bitmask_t GetBitMaskTest::m_bitMask = NULL;

TEST_P(GetBitMaskTest, TestGetBitMask)
{
    auto param = GetParam();
    EXPECT_EQ(getBit(m_bitMask, m_totalSize, std::get<0>(param)), std::get<1>(param));
}

INSTANTIATE_TEST_SUITE_P(GetBitMask_Test, GetBitMaskTest, ::testing::Values(
    std::make_tuple(0x00, 0x00),
    std::make_tuple(0x01, 0x02),
    std::make_tuple(0x02, 0x00),
    std::make_tuple(0x03, 0x08),
    std::make_tuple(0x04, 0x00),
    std::make_tuple(0x05, 0x20),
    std::make_tuple(0x06, 0x00),
    std::make_tuple(0x07, 0x80),
    std::make_tuple(0x08, 0x00),
    std::make_tuple(0x09, 0x02),
    std::make_tuple(0x0a, 0x00),
    std::make_tuple(0x0b, 0x08),
    std::make_tuple(0x0c, 0x00),
    std::make_tuple(0x0d, 0x20),
    std::make_tuple(0x0e, 0x00),
    std::make_tuple(0x0f, 0x80),
    std::make_tuple(0x10, 0xff)
));