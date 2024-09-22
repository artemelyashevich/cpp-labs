#pragma once

#include "Interval.h"
#include <algorithm>
#include <iostream>

class IntervalService
{
public:
    Interval sum(const Interval &first, const Interval &second);

    Interval subtraction(const Interval &first, const Interval &second);

    Interval multiplyByScalar(const Interval &interval, double scalar);

    Interval intersect(const Interval &a, const Interval &b);

    Interval merge(const Interval &a, const Interval &b);

    double distance(const Interval &a, const Interval &b);
};