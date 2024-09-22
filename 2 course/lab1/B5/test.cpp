#include "pch.h"

// Tests for a sum method
TEST(IntervalServiceTest, Sum_ZeroIntervals)
{
    Interval first(0, 0, true, true);
    Interval second(0, 0, true, true);

    IntervalService intervalService;
    Interval result = intervalService.sum(first, second);

    EXPECT_EQ(result.getStart(), 0);
    EXPECT_EQ(result.getEnd(), 0);
}

TEST(IntervalServiceTest, Sum_NegativeWithPositiveIntervals)
{
    Interval first(-100, 100, true, true);
    Interval second(200, 300, true, true);

    IntervalService intervalService;
    Interval result = intervalService.sum(first, second);

    EXPECT_EQ(result.getStart(), -100 + 200);
    EXPECT_EQ(result.getEnd(), 100 + 300);
}

TEST(IntervalServiceTest, Sum_MaxAndMinValues)
{
    Interval first(std::numeric_limits<double>::max(), std::numeric_limits<double>::max(), true, true);
    Interval second(std::numeric_limits<double>::min(), std::numeric_limits<double>::min(), true, true);

    IntervalService intervalService;
    Interval result = intervalService.sum(first, second);

    EXPECT_EQ(result.getStart(), std::numeric_limits<double>::max() + std::numeric_limits<double>::min());
    EXPECT_EQ(result.getEnd(), std::numeric_limits<double>::max() + std::numeric_limits<double>::min());
}

// Tests for subtaction method
TEST(IntervalServiceTest, Subtraction_ZeroIntervals)
{
    Interval first(0, 0, true, true);
    Interval second(0, 0, true, true);

    IntervalService intervalService;
    Interval result = intervalService.subtraction(first, second);

    EXPECT_EQ(result.getStart(), 0);
    EXPECT_EQ(result.getEnd(), 0);
}

TEST(IntervalServiceTest, Subtraction_NegativeWithPositiveIntervals)
{
    Interval first(-100, 100, true, true);
    Interval second(200, 300, true, true);

    IntervalService intervalService;
    Interval result = intervalService.subtraction(first, second);

    EXPECT_EQ(result.getStart(), -100 - 200);
    EXPECT_EQ(result.getEnd(), 100 - 300);
}

TEST(IntervalServiceTest, Subtraction_MaxAndMinValues)
{
    Interval first(std::numeric_limits<double>::max(), std::numeric_limits<double>::max(), true, true);
    Interval second(std::numeric_limits<double>::min(), std::numeric_limits<double>::min(), true, true);

    IntervalService intervalService;
    Interval result = intervalService.subtraction(first, second);

    EXPECT_EQ(result.getStart(), std::numeric_limits<double>::max() - std::numeric_limits<double>::min());
    EXPECT_EQ(result.getEnd(), std::numeric_limits<double>::max() - std::numeric_limits<double>::min());
}

// Tests for multiplyByScalar method
TEST(IntervalServiceTest, MultiplyByScalar_ZeroIntervals)
{
    Interval interval(0, 0, true, true);
    double scalar = 0;

    IntervalService intervalService;
    Interval result = intervalService.multiplyByScalar(interval, scalar);

    EXPECT_EQ(result.getStart(), 0);
    EXPECT_EQ(result.getEnd(), 0);
}

TEST(IntervalServiceTest, MultiplyByScalar_NegativePosition)
{
    Interval interval(-100, 100, true, true);
    double scalar = 0.5;

    IntervalService intervalService;
    Interval result = intervalService.multiplyByScalar(interval, scalar);

    EXPECT_EQ(result.getStart(), -100 * 0.5);
    EXPECT_EQ(result.getEnd(), 100 * 0.5);
}

TEST(IntervalServiceTest, MultiplyByScalar_MaxAndMinValues)
{
    Interval interval(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max(), true, true);
    double scalar = 2;

    IntervalService intervalService;
    Interval result = intervalService.multiplyByScalar(interval, scalar);

    EXPECT_EQ(result.getStart(), std::numeric_limits<double>::lowest() * 2);
    EXPECT_EQ(result.getEnd(), std::numeric_limits<double>::max() * 2);
}

// Tests for intersect method
TEST(IntervalServiceTest, Intersect_AvgValues)
{
    Interval a(0, 10, true, true);
    Interval b(5, 15, true, true);

    IntervalService intervalService;
    Interval result = intervalService.intersect(a, b);

    EXPECT_EQ(result.getStart(), 5);
    EXPECT_EQ(result.getEnd(), 10);
}

TEST(IntervalServiceTest, Intersect_NegativeValues)
{
    Interval a(-10, 10, true, true);
    Interval b(-20, 0, true, true);

    IntervalService intervalService;
    Interval result = intervalService.intersect(a, b);

    EXPECT_EQ(result.getStart(), -10);
    EXPECT_EQ(result.getEnd(), 0);
}

TEST(IntervalServiceTest, Intersect_NoIntersect)
{
    Interval a(5, 10, true, true);
    Interval b(0, 3, true, true);

    IntervalService intervalService;
    Interval result = intervalService.intersect(a, b);

    EXPECT_EQ(result.getStart(), 0);
    EXPECT_EQ(result.getEnd(), 0);
}

// Tests for merge method
TEST(IntervalServiceTest, Merge_AvgValues)
{
    Interval a(0, 10, true, true);
    Interval b(5, 15, true, true);

    IntervalService intervalService;
    Interval result = intervalService.merge(a, b);

    EXPECT_EQ(result.getStart(), 0);
    EXPECT_EQ(result.getEnd(), 15);
}

TEST(IntervalServiceTest, Merge_NegativeValues)
{
    Interval a(-10, 10, true, true);
    Interval b(-20, 0, true, true);

    IntervalService intervalService;
    Interval result = intervalService.merge(a, b);

    EXPECT_EQ(result.getStart(), -20);
    EXPECT_EQ(result.getEnd(), 10);
}

TEST(IntervalServiceTest, Merge_Test)
{
    Interval a(5, 10, true, true);
    Interval b(0, 3, true, true);

    IntervalService intervalService;
    Interval result = intervalService.merge(a, b);

    EXPECT_EQ(result.getStart(), 0);
    EXPECT_EQ(result.getEnd(), 10);
}

// Tests for distanse method
TEST(IntervalServiceTest, Distance_AvgValues)
{
    Interval a(0, 10, true, true);
    Interval b(5, 15, true, true);

    IntervalService intervalService;
    double result = intervalService.distance(a, b);

    EXPECT_EQ(result, 5.0);
}

TEST(IntervalServiceTest, Distance_Test)
{
    Interval a(10, 20, true, true);
    Interval b(30, 40, true, true);

    IntervalService intervalService;
    double result = intervalService.distance(a, b);

    EXPECT_EQ(result, 20.0);
}

TEST(IntervalServiceTest, Distance_NegativeValues)
{
    Interval a(-10, 10, true, true);
    Interval b(-20, 0, true, true);

    IntervalService intervalService;
    double result = intervalService.distance(a, b);

    EXPECT_EQ(result, 10.0);
}