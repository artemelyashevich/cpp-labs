#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

/**
 * @brief Represents a mathematical vector with various operations.
 */
class Vector
{
private:
    std::vector<double> components;

public:
    /**
     * @brief Constructs a vector with the given components.
     * @param vec The components of the vector
     */
    Vector(std::vector<double> vec) : components(vec) {}

    /**
     * @brief Increments each component of the vector by 1.
     */
    void increment()
    {
        for (double &component : this->components)
        {
            component++;
        }
    }

    /**
     * @brief Decrements each component of the vector by 1.
     */
    void decrement()
    {
        for (double &component : this->components)
        {
            component--;
        }
    }

    /**
     * @brief Overloaded indexing operator to access vector components.
     * @param index The index of the component
     * @return Reference to the component at the given index
     */
    double &operator[](int index)
    {
        return this->components[index];
    }

    /**
     * @brief Calculates the scalar product of two vectors.
     * @param v1 The first vector
     * @param v2 The second vector
     * @return The scalar product of the two vectors
     */
    static double scalarProduct(const Vector v1, const Vector v2)
    {
        double product = 0;
        for (int i = 0; i < v1.components.size(); ++i)
        {
            product += v1.components[i] * v2.components[i];
        }
        return product;
    }

    ***@brief Calculates the length of the vector.
            *@ return The length of the vector *
        /
        double length() const
    {
        double sum = 0;
        for (double component : this->components)
        {
            sum += component * component;
        }
        return std::sqrt(sum);
    }

    /**
     * @brief Calculates the angle between two vectors in radians.
     * @param v1 The first vector
     * @param v2 The second vector
     * @return The angle between the two vectors in radians
     */
    static double angleBetween(const Vector v1, const Vector v2)
    {
        double dotProduct = scalarProduct(v1, v2);
        double len1 = v1.length();
        double len2 = v2.length();

        return std::acos(dotProduct / (len1 * len2));
    }
};

/**
 * @brief Tests the increment and decrement functionality of the Vector class.
 */
void testVectorIncrementDecrement()
{
    Vector v(std::vector<double>{1, 2, 3});

    v.increment();
    assert(v[0] == 2 && v[1] == 3 && v[2] == 4);

    v.decrement();
    assert(v[0] == 1 && v[1] == 2 && v[2] == 3);
}

/**
 * @brief Tests the scalar product calculation of two vectors.
 */
void testScalarProductCalculation()
{
    Vector v1(std::vector<double>{1, 2, 3});
    Vector v2(std::vector<double>{4, 5, 6});

    double expectedScalarProduct = 1 * 4 + 2 * 5 + 3 * 6;
    assert(Vector::scalarProduct(v1, v2) == expectedScalarProduct);
}

/**
 * @brief Tests the calculation of vector length.
 */
void testVectorLengthCalculation()
{
    Vector v(std::vector<double>{3, 4});
    assert(v.length() == 5); // Length of vector (3, 4) should be 5
}

/**
 * @brief Tests the scalar product calculation with vectors of different sizes.
 */
void testScalarProductWithDifferentSizes()
{
    Vector v1(std::vector<double>{1, 2, 3});
    Vector v2(std::vector<double>{4, 5});

    // Assert that calculating scalar product with vectors of different sizes fails
    assert(std::isnan(Vector::scalarProduct(v1, v2)));
}

/**
 * @brief Tests the calculation of length for a zero vector.
 */
void testZeroVectorLength()
{
    Vector zeroVector(std::vector<double>{0, 0, 0});

    // Assert that the length of a zero vector is indeed 0
    assert(zeroVector.length() == 0);
}

/**
 * @brief Tests the calculation of the angle between two zero vectors.
 */
void testAngleCalculationWithZeroVectors()
{
    Vector zeroVector1(std::vector<double>{0, 0, 0});
    Vector zeroVector2(std::vector<double>{0, 0, 0});

    // Assert that calculating the angle between two zero vectors fails
    assert(std::isnan(Vector::angleBetween(zeroVector1, zeroVector2)));
}

int main()
{
    testVectorIncrementDecrement();
    testScalarProductCalculation();
    testVectorLengthCalculation();
    testZeroVectorLength();
    testAngleCalculationWithZeroVectors();

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}