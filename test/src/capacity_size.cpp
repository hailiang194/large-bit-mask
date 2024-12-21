#include <gtest/gtest.h>
#include "large_bit_mask.h"

TEST(CapcityTest, FullCapacity1Byte) {
  EXPECT_EQ(getCapacitySize(0x8), 1);
}

TEST(CapcityTest, CapacityRemain1For1Byte) {
  EXPECT_EQ(getCapacitySize(0x7), 1);
}

TEST(CapcityTest, CapacityRemain2For1Byte) {
  EXPECT_EQ(getCapacitySize(0x6), 1);
}

TEST(CapcityTest, CapacityRemain3For1Byte) {
  EXPECT_EQ(getCapacitySize(0x5), 1);
}

TEST(CapcityTest, CapacityRemain4For1Byte) {
  EXPECT_EQ(getCapacitySize(0x4), 1);
}

TEST(CapcityTest, CapacityRemain5For1Byte) {
  EXPECT_EQ(getCapacitySize(0x3), 1);
}

TEST(CapcityTest, CapacityRemain6For1Byte) {
  EXPECT_EQ(getCapacitySize(0x2), 1);
}

TEST(CapcityTest, CapacityRemain7For1Byte) {
  EXPECT_EQ(getCapacitySize(0x1), 1);
}

TEST(CapcityTest, FullCapacity2Bytes) {
  EXPECT_EQ(getCapacitySize(0x10), 2);
}


TEST(CapcityTest, CapacityRemain1For2Byte) {
  EXPECT_EQ(getCapacitySize(0xf), 2);
}

TEST(CapcityTest, CapacityRemain2For2Byte) {
  EXPECT_EQ(getCapacitySize(0xe), 2);
}

TEST(CapcityTest, CapacityRemain3For2Byte) {
  EXPECT_EQ(getCapacitySize(0xd), 2);
}

TEST(CapcityTest, CapacityRemain4For2Byte) {
  EXPECT_EQ(getCapacitySize(0xc), 2);
}

TEST(CapcityTest, CapacityRemain5For2Byte) {
  EXPECT_EQ(getCapacitySize(0xb), 2);
}

TEST(CapcityTest, CapacityRemain6For2Byte) {
  EXPECT_EQ(getCapacitySize(0xa), 2);
}

TEST(CapcityTest, CapacityRemain7For2Byte) {
  EXPECT_EQ(getCapacitySize(0x9), 2);
}

TEST(CapcityTest, FullCapacity3Bytes) {
  EXPECT_EQ(getCapacitySize(0x18), 3);
}

TEST(CapcityTest, FullCapacity4Bytes) {
  EXPECT_EQ(getCapacitySize(0x20), 4);
}