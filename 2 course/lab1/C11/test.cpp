#include "pch.h"
#include <cmath>

#define M_PI 3.14159265358979323846

// Tests for increment method
TEST(VectorTest, Increment_NegativeZeroPositive)
{
    Vector vec({-10, 0, 10});
    vec.increment();

    const auto &values = vec.getValues();
    EXPECT_EQ(values[0], -9.0);
    EXPECT_EQ(values[1], 1.0);
    EXPECT_EQ(values[2], 11.0);
}

TEST(VectorTest, Increment_ZeroValues)
{
    Vector vec({0, 0, 0});
    vec.increment();

    const auto &values = vec.getValues();
    EXPECT_EQ(values[0], 1.0);
    EXPECT_EQ(values[1], 1.0);
    EXPECT_EQ(values[2], 1.0);
}

TEST(VectorTest, Increment_OppositeValues)
{
    Vector vec({-1000, 1000});
    vec.increment();

    const auto &values = vec.getValues();
    EXPECT_EQ(values[0], -999.0);
    EXPECT_EQ(values[1], 1001.0);
}

// Tests for decrement method
TEST(VectorTest, Decrement_NegativeZeroPositive)
{
    Vector vec({-10, 0, 10});
    vec.decrement();

    const auto &values = vec.getValues();
    EXPECT_EQ(values[0], -11.0);
    EXPECT_EQ(values[1], -1.0);
    EXPECT_EQ(values[2], 9.0);
}

TEST(VectorTest, Decrement_ZeroValues)
{
    Vector vec({0, 0, 0});
    vec.decrement();

    const auto &values = vec.getValues();
    EXPECT_EQ(values[0], -1.0);
    EXPECT_EQ(values[1], -1.0);
    EXPECT_EQ(values[2], -1.0);
}

TEST(VectorTest, Decrement_OppositeValues)
{
    Vector vec({-1000, 1000});
    vec.decrement();

    const auto &values = vec.getValues();
    EXPECT_EQ(values[0], -1001.0);
    EXPECT_EQ(values[1], 999.0);
}

// Tests for scalarProduct method
TEST(VectorTest, ScalarProduct_NegativeZeroPositive)
{
    Vector vec1({-2, 0, 3});
    Vector vec2({4, -5, 6});

    double result = vec1.scalarProduct(vec2);
    EXPECT_EQ(result, 10.0);
}

TEST(VectorTest, ScalarProduct_ZeroValues)
{
    Vector vec1({0, 0, 0});
    Vector vec2({1, 2, 3});

    double result = vec1.scalarProduct(vec2);
    EXPECT_EQ(result, 0.0);
}

TEST(VectorTest, ScalarProduct_PositiveNegativeValues)
{
    Vector vec1({-100, 200});
    Vector vec2({300, -400});

    double result = vec1.scalarProduct(vec2);
    EXPECT_EQ(result, -110000.0);
}

// Tests for length method
TEST(VectorTest, Length_PositiveNegativeValues)
{
    Vector vec({-3, 4});

    double result = vec.length();
    EXPECT_NEAR(result, 5.0, 0.0001);
}

TEST(VectorTest, Length_ZeroValues)
{
    Vector vec({0, 0, 0});

    double result = vec.length();
    EXPECT_EQ(result, 0.0);
}

TEST(VectorTest, Angle_ParallelVectors)
{
    Vector vec1({1, 0});
    Vector vec2({1, 0});

    double result = vec1.angle(vec2);
    EXPECT_DOUBLE_EQ(result, 0.0);
}

TEST(VectorTest, Angle_PerpendicularVectors)
{
    Vector vec1({1, 0});
    Vector vec2({0, 1});

    double result = vec1.angle(vec2);
    EXPECT_DOUBLE_EQ(result, 0);
}

TEST(VectorTest, Angle_OppositeDirectionVectors)
{
    Vector vec1({1, 0});
    Vector vec2({-1, 0});

    double result = vec1.angle(vec2);
    EXPECT_DOUBLE_EQ(result, M_PI);
}