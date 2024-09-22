#pragma once

#include "Interval.h"
#include <algorithm>
#include <iostream>

/**
 * @brief Class representing a service for interval operations.
 */
class IntervalService
{
public:
    /**
     * @brief Calculates the sum of two intervals.
     * @param first The first interval.
     * @param second The second interval.
     * @return The interval resulting from the sum.
     */
    Interval sum(const Interval &first, const Interval &second);

    /**
     * @brief Calculates the subtraction of one interval from another.
     * @param first The first interval.
     * @param second The interval to subtract.
     * @return The interval resulting from the subtraction.
     */
    Interval subtraction(const Interval &first, const Interval &second);

    /**
     * @brief Multiplies an interval by a scalar value.
     * @param interval The interval to multiply.
     * @param scalar The scalar value to multiply by.
     * @return The interval resulting from the multiplication.
     */
    Interval multiplyByScalar(const Interval &interval, double scalar);

    /**
     * @brief Calculates the intersection of two intervals.
     * @param a The first interval.
     * @param b The second interval.
     * @return The interval resulting from the intersection.
     */
    Interval intersect(const Interval &a, const Interval &b);

    /**
     * @brief Merges two intervals into a single interval.
     * @param a The first interval.
     * @param b The second interval.
     * @return The merged interval.
     */
    Interval merge(const Interval &a, const Interval &b);

    /**
     * @brief Calculates the distance between two intervals.
     * @param a The first interval.
     * @param b The second interval.
     * @return The distance between the two intervals.
     */
    double distance(const Interval &a, const Interval &b);
};