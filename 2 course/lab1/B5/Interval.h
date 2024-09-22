#pragma once

class Interval
{
private:
    double start;
    double end;
    bool includeStart;
    bool includeEnd;

public:
    Interval(double start, double end, bool includeStart, bool includeEnd) {}

    double getStart() const;

    double getEnd() const;

    bool getIncludesStart() const;

    bool getIncludesEnd() const;
};