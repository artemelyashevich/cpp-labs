#include "Vector.h"

Vector::Vector(std::vector<double> initValues) : values(initValues) {}

void Vector::increment()
{
    for (double &value : values)
    {
        value++;
    }
}

void Vector::decrement()
{
    for (double &value : values)
    {
        value--;
    }
}

double &Vector::operator[](int index)
{
    return values[index];
}

double Vector::scalarProduct(const Vector &other) const
{
    double result = 0;
    for (size_t i = 0; i < values.size(); i++)
    {
        result += values[i] * other.values[i];
    }
    return result;
}

double Vector::length() const
{
    double sum = 0;
    for (double value : values)
    {
        sum += value * value;
    }
    return mySqrt(sum);
}

double Vector::angle(const Vector &other) const
{
    double dotProduct = scalarProduct(other);
    double thisLength = length();
    double otherLength = other.length();

    return safeAcos(dotProduct / (thisLength * otherLength));
}

std::vector<double> Vector::getValues()
{
    return values;
}