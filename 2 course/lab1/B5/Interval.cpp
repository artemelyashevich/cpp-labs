#include "Interval.h"

#pragma once

Interval::Interval(double start, double end, bool includeStart, bool includeEnd)
    : start(start), end(end), includeStart(includeStart), includeEnd(includeEnd) {}

double Interval::getStart() const
{
    return start;
}

double Interval::getEnd() const
{
    return end;
}

bool Interval::getIncludesStart() const
{
    return includeStart;
}

bool Interval::getIncludesEnd() const
{
    return includeEnd;
}
