#include <gtest/gtest.h>
#include "class_BitString.h"

TEST(BitStringTest, DefaultConstructor) {
    BitString a;
    EXPECT_EQ(a.ToString(), "");
}

TEST(BitStringTest, FillConstructorWithZeros) {
    BitString a(5, 0);
    EXPECT_EQ(a.ToString(), "00000");
}

TEST(BitStringTest, FillConstructorWithOnes) {
    BitString a(4, 1);
    EXPECT_EQ(a.ToString(), "1111");
}

TEST(BitStringTest, FillConstructorThrowsOnInvalidBit) {
    EXPECT_THROW(BitString(3, 2), std::invalid_argument);
}

TEST(BitStringTest, InitializerListConstructor) {
    BitString a({1, 0, 1});
    EXPECT_EQ(a.ToString(), "101");
}

TEST(BitStringTest, StringConstructorValid) {
    BitString a("101010");
    EXPECT_EQ(a.ToString(), "101010");
}

TEST(BitStringTest, StringConstructorThrowsOnInvalidChar) {
    EXPECT_THROW(BitString("10a01"), std::invalid_argument);
}

TEST(BitStringTest, CopyConstructor) {
    BitString a("1010");
    BitString b(a);
    EXPECT_EQ(b.ToString(), "1010");
    EXPECT_EQ(a.ToString(), "1010");
}

TEST(BitStringTest, MoveConstructor) {
    BitString a("1111");
    BitString b(std::move(a));
    EXPECT_EQ(b.ToString(), "1111");
    EXPECT_EQ(a.ToString(), "");
}

TEST(BitStringTest, AndOperation) {
    BitString a("1100");
    BitString b("1010");
    BitString result = a.And(b);
    EXPECT_EQ(result.ToString(), "1000");
}

TEST(BitStringTest, OrOperation) {
    BitString a("1100");
    BitString b("1010");
    BitString result = a.Or(b);
    EXPECT_EQ(result.ToString(), "1110");
}

TEST(BitStringTest, XorOperation) {
    BitString a("1100");
    BitString b("1010");
    BitString result = a.Xor(b);
    EXPECT_EQ(result.ToString(), "0110");
}

TEST(BitStringTest, NotOperation) {
    BitString a("1010");
    BitString result = a.Not();
    EXPECT_EQ(result.ToString(), "0101");
}

TEST(BitStringTest, AndThrowsIfDifferentLength) {
    BitString a("101");
    BitString b("10");
    EXPECT_THROW(a.And(b), std::invalid_argument);
}

TEST(BitStringTest, OrThrowsIfDifferentLength) {
    BitString a("101");
    BitString b("10");
    EXPECT_THROW(a.Or(b), std::invalid_argument);
}

TEST(BitStringTest, XorThrowsIfDifferentLength) {
    BitString a("101");
    BitString b("10");
    EXPECT_THROW(a.Xor(b), std::invalid_argument);
}
