#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

/**
 * @class Interval
 * @brief Represents an interval with a start and end point.
 */
class Interval
{
private:
    int start;         /**< Start point of the interval */
    int end;           /**< End point of the interval */
    bool includeStart; /**< Flag indicating if the start point is included in the interval */
    bool includeEnd;   /**< Flag indicating if the end point is included in the interval */

public:
    /**
     * @brief Constructor for the Interval class.
     * @param s Start point of the interval.
     * @param e End point of the interval.
     * @param incStart Flag indicating if the start point is included.
     * @param incEnd Flag indicating if the end point is included.
     */
    Interval(int s, int e, bool incStart, bool incEnd) : start(s), end(e), includeStart(incStart), includeEnd(incEnd) {}

    /**
     * @brief Checks if this interval has an intersection with another interval.
     * @param other The other Interval to check for intersection.
     * @return True if there is an intersection, false otherwise.
     */
    bool hasIntersection(Interval other)
    {
        if (end < other.start || other.end < start)
        {
            return false;
        }
        if (end == other.start && !(includeEnd && other.includeStart))
        {
            return false;
        }
        if (start == other.end && !(includeStart && other.includeEnd))
        {
            return false;
        }
        return true;
    }

    /**
     * @brief Returns the intersection of this interval with another interval.
     * @param other The other Interval for intersection.
     * @return The intersecting Interval.
     */
    Interval getIntersection(Interval other)
    {
        int newStart = std::max(start, other.start);
        int newEnd = std::min(end, other.end);
        bool newIncludeStart = (start < other.start) ? other.includeStart : includeStart;
        bool newIncludeEnd = (end > other.end) ? includeEnd : other.includeEnd;
        return Interval(newStart, newEnd, newIncludeStart, newIncludeEnd);
    }

    /**
     * @brief Returns the union of this interval with another interval.
     * @param other The other Interval for union.
     * @return The union Interval.
     */
    Interval getUnion(Interval other)
    {
        int newStart = std::min(start, other.start);
        int newEnd = std::max(end, other.end);
        bool newIncludeStart = (start < other.start) ? includeStart : other.includeStart;
        bool newIncludeEnd = (end > other.end) ? includeEnd : other.includeEnd;
        return Interval(newStart, newEnd, newIncludeStart, newIncludeEnd);
    }

    /**
     * @brief Calculates the distance covered by the interval.
     * @return The distance covered by the interval.
     */
    int distance()
    {
        return end - start;
    }
};

// Test functions

/**
 * @brief Tests the intersection of two intervals.
 */
void testIntersection()
{
    Interval interval1(1, 5, true, false);
    Interval interval2(3, 8, true, true);
    assert(interval1.hasIntersection(interval2) == true);
}

/**
 * @brief Tests the union of two intervals.
 */
void testUnion()
{
    Interval interval1(1, 5, true, false);
    Interval interval2(3, 8, true, true);
    assert(interval1.getUnion(interval2).distance() == 7);
}

/**
 * @brief Tests the distance calculation of an interval.
 */
void testDistance()
{
    Interval interval(1, 5, true, false);
    assert(interval.distance() == 4);
}

/**
 * @brief Tests the case where two intervals have no intersection.
 */
void testNoIntersection()
{
    Interval interval1(1, 5, true, false);
    Interval interval2(6, 8, true, true);
    assert(interval1.hasIntersection(interval2) == false);
}

/**
 * @brief Tests an invalid intersection scenario.
 */
void testInvalidIntersection()
{
    Interval interval1(1, 5, true, false);
    Interval interval2(5, 8, true, true);
    assert(interval1.hasIntersection(interval2) == false);
}

/**
 * @brief Tests an incorrect distance calculation.
 */
void testIncorrectDistance()
{
    Interval interval(1, 5, true, false);
    assert(interval.distance() != 5);
}

int main()
{
    testIntersection();
    testUnion();
    testDistance();
    testNoIntersection();
    testInvalidIntersection();
    testIncorrectDistance();

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}