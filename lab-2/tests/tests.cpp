#include <gtest/gtest.h>
#include "../include/bitstring.hpp"

TEST(BitStringTest, DefaultConstructor)
{
    BitString b;

    size_t size = b.getSize();
    unsigned char *data = b.getData();

    EXPECT_EQ(size, 0);
    EXPECT_EQ(data, nullptr);
}

TEST(BitStringTest, SizeAndDefaultConstructor)
{
    size_t n = 5;
    unsigned char t = '0';
    BitString b(n, t);

    size_t size = b.getSize();
    unsigned char *data = b.getData();

    EXPECT_EQ(size, n);
    for (size_t i = 0; i < size; ++i)
    {
        EXPECT_EQ(data[i], t);
    }
}

TEST(BitStringTest, InitializerListConstructor)
{
    std::initializer_list<unsigned char> t = {'1', '0', '1', '1'};
    BitString b(t);

    size_t size = b.getSize();
    unsigned char *data = b.getData();

    EXPECT_EQ(size, t.size());
    size_t i = 0;
    for (unsigned char digit : t)
    {
        EXPECT_EQ(data[i++], digit);
    }
}

TEST(BitStringTest, StringConstructor)
{
    std::string t = "1011";
    BitString b(t);

    size_t size = b.getSize();
    unsigned char *data = b.getData();

    EXPECT_EQ(size, t.size());
    for (size_t i = 0; i < size; ++i)
    {
        EXPECT_EQ(data[i], t[i]);
    }
}

TEST(BitStringTest, AssignmentOperator)
{
    BitString b1("1011");
    BitString b2;

    b2 = b1;

    EXPECT_EQ(b2.getSize(), b1.getSize());
    for (int i = 0; i < b2.getSize(); ++i)
    {
        EXPECT_EQ(b1.getData()[i], b2.getData()[i]);
    }
}

TEST(BitStringTest, AndOperator)
{
    BitString b1("1010");
    BitString b2("1101");

    b1 &= b2;

    std::string ans = "1000";
    EXPECT_EQ(b1.getSize(), ans.size());
    for (int i = 0; i < b1.getSize(); ++i)
    {
        EXPECT_EQ(b1.getData()[i], ans[i]);
    }
}

TEST(BitStringTest, OrOperator)
{
    BitString b1("1010");
    BitString b2("1101");

    b1 |= b2;

    std::string ans = "1111";
    EXPECT_EQ(b1.getSize(), ans.size());
    for (int i = 0; i < b1.getSize(); ++i)
    {
        EXPECT_EQ(b1.getData()[i], ans[i]);
    }
}

TEST(BitStringTest, XorOperator)
{
    BitString b1("1010");
    BitString b2("1101");

    b1 ^= b2;

    std::string ans = "0111";
    EXPECT_EQ(b1.getSize(), ans.size());
    for (int i = 0; i < b1.getSize(); ++i)
    {
        EXPECT_EQ(b1.getData()[i], ans[i] - '0');
    }
}

TEST(BitStringTest, EqualityOperator)
{
    BitString b1("1010");
    BitString b2("1010");
    BitString b3("1101");

    EXPECT_TRUE(b1 == b2);
    EXPECT_FALSE(b1 == b3);
}

TEST(BitStringTest, LessThanOperator)
{
    BitString b1("1010");
    BitString b2("1101");

    EXPECT_TRUE(b1 < b2);
    EXPECT_FALSE(b2 < b1);
}

TEST(BitStringTest, GreaterThanOperator)
{
    BitString b1("1101");
    BitString b2("1010");

    EXPECT_TRUE(b1 > b2);
    EXPECT_FALSE(b2 > b1);
}