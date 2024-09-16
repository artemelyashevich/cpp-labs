// 4,3 - 10

#include <iostream>
#include <cmath>

using namespace std;

class Vector
{
private:
    double x;
    double y;
    double z;

public:
    Vector() : x(0.0), y(0.0), z(0.0) {}

    Vector(double xValue, double yValue, double zValue) : x(xValue), y(yValue), z(zValue) {}

    void inputVector()
    {
        cout << "Введите координаты вектора (x, y, z): ";
        cin >> this->x >> this->y >> this->z;
    }

    double calculateLength() const
    {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    double calculateDotProduct(const Vector &other) const
    {
        return this->x * other.x + this->y * other.y + this->z * other.z;
    }

    Vector calculateCrossProduct(const Vector &other) const
    {
        double crossX = this->y * other.z - z * other.y;
        double crossY = this->z * other.x - x * other.z;
        double crossZ = this->x * other.y - y * other.x;

        return Vector(crossX, crossY, crossZ);
    }

    ~Vector()
    {
        cout << "Вызван деструктор" << endl;
    }

    double getX()
    {
        return this->x;
    }

    double getY()
    {
        return this->y;
    }
    double getZ()
    {
        return this->z;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    Vector vector1;
    Vector vector2;

    cout << "Введите координаты первого вектора:\n";
    vector1.inputVector();

    cout << "Введите координаты второго вектора:\n";
    vector2.inputVector();

    double length1 = vector1.calculateLength();
    double length2 = vector2.calculateLength();

    cout << "Длина первого вектора: " << length1 << endl;
    cout << "Длина второго вектора: " << length2 << endl;

    double dotProduct = vector1.calculateDotProduct(vector2);
    cout << "Скалярное произведение двух векторов: " << dotProduct << endl;

    Vector crossProduct = vector1.calculateCrossProduct(vector2);
    cout << "Векторное произведение двух векторов: (" << crossProduct.getX() << ", " << crossProduct.getY() << ", " << crossProduct.getZ() << ")" << endl;

    return 0;
}