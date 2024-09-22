#include "IntervalService.h"

Interval IntervalService::sum(const Interval &first, const Interval &second)
{
    return Interval(first.getStart() + second.getStart(), first.getEnd() + second.getEnd(), true, true);
}

Interval IntervalService::subtraction(const Interval &first, const Interval &second)
{
    return Interval(first.getStart() - second.getStart(), first.getEnd() - second.getEnd(), true, true);
}

Interval IntervalService::multiplyByScalar(const Interval &interval, double scalar)
{
    double a = interval.getStart() * scalar;
    double b = interval.getEnd() * scalar;
    return Interval(a, b, true, true);
}

Interval IntervalService::intersect(const Interval &a, const Interval &b)
{
    double start = std::max(a.getStart(), b.getStart());
    double end = std::min(a.getEnd(), b.getEnd());
    bool includeStart = (start == a.getStart() && a.getIncludesStart()) || (start == b.getStart() && b.getIncludesStart());
    bool includeEnd = (end == a.getEnd() && a.getIncludesEnd()) || (end == b.getEnd() && b.getIncludesEnd());

    if (start > end)
    {
        std::cerr << "Intervals do not intersect" << std::endl;
        return Interval(0, 0, false, false);
    }

    return Interval(start, end, includeStart, includeEnd);
}

Interval IntervalService::merge(const Interval &a, const Interval &b)
{
    double start = std::min(a.getStart(), b.getStart());
    double end = std::max(a.getEnd(), b.getEnd());
    bool includeStart = (start == a.getStart() && a.getIncludesStart()) || (start == b.getStart() && b.getIncludesStart());
    bool includeEnd = (end == a.getEnd() && a.getIncludesEnd()) || (end == b.getEnd() && b.getIncludesEnd());

    return Interval(start, end, includeStart, includeEnd);
}

double IntervalService::distance(const Interval &a, const Interval &b)
{
    double startDistance = std::abs(a.getStart() - b.getStart());
    double endDistance = std::abs(a.getEnd() - b.getEnd());
    return startDistance > endDistance ? startDistance : endDistance;
}
