// 4,3 - 20

#include <iostream>
#include <cmath>

using namespace std;

class City
{
private:
    string name;
    double latitude;  // Географическая широта
    double longitude; // Географическая долгота

public:
    City(const string &cityName, double cityLatitude, double cityLongitude)
        : name(cityName), latitude(cityLatitude), longitude(cityLongitude) {}

    string getName() const
    {
        return name;
    }

    void setName(const string &cityName)
    {
        name = cityName;
    }

    double getLatitude() const
    {
        return latitude;
    }

    void setLatitude(double cityLatitude)
    {
        latitude = cityLatitude;
    }

    double getLongitude() const
    {
        return longitude;
    }

    void setLongitude(double cityLongitude)
    {
        longitude = cityLongitude;
    }

    double calculateDistance(const City &otherCity) const
    {
        double lat1Rad = latitude * 3.14 / 180.0;
        double lon1Rad = longitude * 3.14 / 180.0;
        double lat2Rad = otherCity.latitude * 3.14 / 180.0;
        double lon2Rad = otherCity.longitude * 3.14 / 180.0;

        // Формула Гаверсинуса для вычисления расстояния на сфере
        double deltaLat = lat2Rad - lat1Rad;
        double deltaLon = lon2Rad - lon1Rad;
        double a = sin(deltaLat / 2) * sin(deltaLat / 2) +
                   cos(lat1Rad) * cos(lat2Rad) *
                       sin(deltaLon / 2) * sin(deltaLon / 2);
        double c = 2 * atan2(sqrt(a), sqrt(1 - a));
        const double earthRadius = 6371.0; // Радиус Земли в километрах
        double distance = earthRadius * c;

        return distance;
    }

    ~City()
    {
        cout << "Город " << name << " удален" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    City city1("Москва", 55.751244, 37.618423);
    City city2("Сан-Франциско", 37.774929, -122.419416);

    cout << "Город 1: " << city1.getName() << " (" << city1.getLatitude() << ", " << city1.getLongitude() << ")" << endl;
    cout << "Город 2: " << city2.getName() << " (" << city2.getLatitude() << ", " << city2.getLongitude() << ")" << endl;

    double distance = city1.calculateDistance(city2);
    cout << "Расстояние между городами: " << distance << " км" << endl;

    City city3("Зельва", 53.1000, 25.1500);
    City city4("Минск", 53.9000, 27.5667);

    cout << "Город 3: " << city3.getName() << " (" << city3.getLatitude() << ", " << city3.getLongitude() << ")" << endl;
    cout << "Город 4: " << city4.getName() << " (" << city4.getLatitude() << ", " << city4.getLongitude() << ")" << endl;

    double distance1 = city3.calculateDistance(city4);
    cout << "Расстояние между городами: " << distance1 << " км" << endl;
    return 0;
}