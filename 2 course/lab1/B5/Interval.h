#pragma once

/**
 * @brief Class representing an interval with start and end points.
 */
class Interval
{
private:
    double start;      /**< The start point of the interval. */
    double end;        /**< The end point of the interval. */
    bool includeStart; /**< Flag indicating if the start point is included in the interval. */
    bool includeEnd;   /**< Flag indicating if the end point is included in the interval. */

public:
    /**
     * @brief Constructor for the Interval class.
     * @param start The start point of the interval.
     * @param end The end point of the interval.
     * @param includeStart Flag indicating if the start point is included.
     * @param includeEnd Flag indicating if the end point is included.
     */
    Interval(double start, double end, bool includeStart, bool includeEnd);

    /**
     * @brief Get the start point of the interval.
     * @return The start point of the interval.
     */
    double getStart() const;

    /**
     * @brief Get the end point of the interval.
     * @return The end point of the interval.
     */
    double getEnd() const;

    /**
     * @brief Check if the interval includes the start point.
     * @return True if the start point is included, false otherwise.
     */
    bool getIncludesStart() const;

    /**
     * @brief Check if the interval includes the end point.
     * @return True if the end point is included, false otherwise.
     */
    bool getIncludesEnd() const;
};