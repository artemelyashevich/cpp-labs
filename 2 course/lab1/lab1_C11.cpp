#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

// Define a Vector class
class Vector
{
private:
    std::vector<double> components;

public:
    Vector(std::vector<double> vec) : components(vec) {}

    void increment()
    {
        for (double &component : this->components)
        {
            component++;
        }
    }

    void decrement()
    {
        for (double &component : this->components)
        {
            component--;
        }
    }

    // Overloaded indexing operator
    double &operator[](int index)
    {
        return this->components[index];
    }

    // Method to calculate the scalar product of two vectors
    static double scalarProduct(const Vector v1, const Vector v2)
    {
        double product = 0;
        for (int i = 0; i < v1.components.size(); ++i)
        {
            product += v1.components[i] * v2.components[i];
        }
        return product;
    }

    // Method to calculate the length of the vector
    double length() const
    {
        double sum = 0;
        for (double component : this->components)
        {
            sum += component * component;
        }
        return std::sqrt(sum);
    }

    // Method to calculate the angle between two vectors in radians
    static double angleBetween(const Vector v1, const Vector v2)
    {
        double dotProduct = scalarProduct(v1, v2);
        double len1 = v1.length();
        double len2 = v2.length();

        return std::acos(dotProduct / (len1 * len2));
    }

    void setComponents(std::vector<double> components)
    {
        this->components = components;
    }

    std::vector<double> getComponents()
    {
        return this->components;
    }
};

void testVectorIncrementDecrement()
{
    Vector v(std::vector<double>{1, 2, 3});

    v.increment();
    assert(v[0] == 2 && v[1] == 3 && v[2] == 4);

    v.decrement();
    assert(v[0] == 1 && v[1] == 2 && v[2] == 3);
}

void testScalarProductCalculation()
{
    Vector v1(std::vector<double>{1, 2, 3});
    Vector v2(std::vector<double>{4, 5, 6});

    double expectedScalarProduct = 1 * 4 + 2 * 5 + 3 * 6;
    assert(Vector::scalarProduct(v1, v2) == expectedScalarProduct);
}

void testVectorLengthCalculation()
{
    Vector v(std::vector<double>{3, 4});
    assert(v.length() == 5); // Length of vector (3, 4) should be 5
}

void testScalarProductWithDifferentSizes()
{
    Vector v1(std::vector<double>{1, 2, 3});
    Vector v2(std::vector<double>{4, 5});

    // Assert that calculating scalar product with vectors of different sizes fails
    assert(std::isnan(Vector::scalarProduct(v1, v2)));
}

void testZeroVectorLength()
{
    Vector zeroVector(std::vector<double>{0, 0, 0});

    // Assert that the length of a zero vector is indeed 0
    assert(zeroVector.length() == 0);
}

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