#pragma once

#include <vector>

/**
 * @brief Class representing a vector with mathematical operations.
 */
class Vector
{
private:
    std::vector<double> values;

    /**
     * @brief Calculates the square root of a number using Newton's method.
     * @param x The number to calculate the square root for.
     * @return The square root of the input number.
     */
    double mySqrt(double x) const;

    /**
     * @brief Calculates the arccosine of a number while ensuring the result is within the valid range.
     * @param x The input value for which arccosine is to be calculated.
     * @return The arccosine value within the valid range.
     */
    double safeAcos(double x) const;

    /**
     * @brief Calculates the arccosine of a number using a Taylor series.
     * @param x The input value for which arccosine is to be calculated.
     * @return The arccosine value.
     */
    double myAcos(double x) const;

public:
    /**
     * @brief Constructor for the Vector class.
     * @param initValues Initial values for the vector.
     */
    Vector(std::vector<double> initValues);

    /**
     * @brief Increment all values in the vector.
     */
    void increment();

    /**
     * @brief Decrement all values in the vector.
     */
    void decrement();

    /**
     * @brief Overloaded [] operator to access elements of the vector by index.
     * @param index The index of the element to access.
     * @return Reference to the element at the specified index.
     */
    double &operator[](int index);

    /**
     * @brief Calculates the scalar product of this vector with another vector.
     * @param other The other vector for scalar product calculation.
     * @return The scalar product of the two vectors.
     */
    double scalarProduct(const Vector &other) const;

    /**
     * @brief Calculates the length (magnitude) of the vector.
     * @return The length of the vector.
     */
    double length() const;

    /**
     * @brief Calculates the angle between this vector and another vector.
     * @param other The other vector to calculate the angle with.
     * @return The angle between the two vectors.
     */
    double angle(const Vector &other) const;

    /**
     * @brief Get the values of the vector.
     * @return The values of the vector.
     */
    std::vector<double> getValues();
};