#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>

class Aircraft
{
private:
    std::string model;
    int capacity;
    int payload;
    int range;
    double fuelConsumption;

public:
    Aircraft(std::string model, int capacity, int payload, int range, double fuelConsumption)
        : model(model), capacity(capacity), payload(payload), range(range), fuelConsumption(fuelConsumption) {}

    virtual ~Aircraft() {}

    std::string getModel() const { return model; }
    int getCapacity() const { return capacity; }
    int getPayload() const { return payload; }
    int getRange() const { return range; }
    double getFuelConsumption() const { return fuelConsumption; }

    void setModel(const std::string &newModel) { model = newModel; }
    void setCapacity(int newCapacity) { capacity = newCapacity; }
    void setPayload(int newPayload) { payload = newPayload; }
    void setRange(int newRange) { range = newRange; }
    void setFuelConsumption(double newFuelConsumption) { fuelConsumption = newFuelConsumption; }

    virtual std::string toString() const
    {
        return "Model: " + model + ", Capacity: " + std::to_string(capacity) +
               ", Payload: " + std::to_string(payload) + ", Range: " + std::to_string(range) +
               ", Fuel Consumption: " + std::to_string(fuelConsumption);
    }
};

class PassengerAircraft : public Aircraft
{
public:
    PassengerAircraft(std::string model, int capacity, int payload, int range, double fuelConsumption)
        : Aircraft(model, capacity, payload, range, fuelConsumption) {}

    std::string toString() const override
    {
        return "Passenger Aircraft - " + Aircraft::toString();
    }
};

class PlaneService
{
public:
    static bool compareRange(const Aircraft &a, const Aircraft &b)
    {
        return a.getRange() < b.getRange();
    }

    static bool checkFuelConsumptionRange(const Aircraft &aircraft, double minFuel, double maxFuel)
    {
        double fuelConsumption = aircraft.getFuelConsumption();
        return fuelConsumption >= minFuel && fuelConsumption <= maxFuel;
    }

    static std::vector<Aircraft> sortByRange(std::vector<Aircraft> &aircrafts)
    {
        std::sort(aircrafts.begin(), aircrafts.end(), compareRange);
        return aircrafts;
    }

    static Aircraft inFuelConsumptionRange(const std::vector<Aircraft> &aircrafts, double minFuel, double maxFuel)
    {
        for (const Aircraft &aircraft : aircrafts)
        {
            if (checkFuelConsumptionRange(aircraft, minFuel, maxFuel))
            {
                return aircraft;
            }
        }
        return Aircraft("", 0, 0, 0, 0.0);
    }
};

TEST(AircraftTest, MaximumValuesTest)
{
    Aircraft aircraft("Boeing 747", 1000, 50000, 10000, 10.5);

    EXPECT_EQ("Boeing 747", aircraft.getModel());
    EXPECT_EQ(1000, aircraft.getCapacity());
    EXPECT_EQ(50000, aircraft.getPayload());
    EXPECT_EQ(10000, aircraft.getRange());
    EXPECT_DOUBLE_EQ(10.5, aircraft.getFuelConsumption());
}

TEST(AircraftTest, SetValuesTest)
{
    Aircraft aircraft("Airbus A380", 800, 60000, 12000, 12.5);

    aircraft.setModel("Airbus A350");
    aircraft.setCapacity(900);
    aircraft.setPayload(70000);
    aircraft.setRange(13000);
    aircraft.setFuelConsumption(13.5);

    EXPECT_EQ("Airbus A350", aircraft.getModel());
    EXPECT_EQ(900, aircraft.getCapacity());
    EXPECT_EQ(70000, aircraft.getPayload());
    EXPECT_EQ(13000, aircraft.getRange());
    EXPECT_DOUBLE_EQ(13.5, aircraft.getFuelConsumption());
}

TEST(AircraftTest, ToStringTest)
{
    Aircraft aircraft("Boeing 777", 500, 30000, 8000, 8.0);

    std::string expectedString = "Model: Boeing 777, Capacity: 500, Payload: 30000, Range: 8000, Fuel Consumption: 8.000000";

    EXPECT_EQ(expectedString, aircraft.toString());
}

TEST(PassengerAircraftTest, MaximumValuesTest)
{
    PassengerAircraft aircraft("Boeing 747", 1000, 50000, 10000, 10.5);

    EXPECT_EQ("Boeing 747", aircraft.getModel());
    EXPECT_EQ(1000, aircraft.getCapacity());
    EXPECT_EQ(50000, aircraft.getPayload());
    EXPECT_EQ(10000, aircraft.getRange());
    EXPECT_DOUBLE_EQ(10.5, aircraft.getFuelConsumption());
}

TEST(PassengerAircraftTest, SetValuesTest)
{
    PassengerAircraft aircraft("Airbus A380", 800, 60000, 12000, 12.5);

    aircraft.setModel("Airbus A350");
    aircraft.setCapacity(900);
    aircraft.setPayload(70000);
    aircraft.setRange(13000);
    aircraft.setFuelConsumption(13.5);

    EXPECT_EQ("Airbus A350", aircraft.getModel());
    EXPECT_EQ(900, aircraft.getCapacity());
    EXPECT_EQ(70000, aircraft.getPayload());
    EXPECT_EQ(13000, aircraft.getRange());
    EXPECT_DOUBLE_EQ(13.5, aircraft.getFuelConsumption());
}

TEST(PassengerAircraftTest, ToStringTest)
{
    PassengerAircraft aircraft("Boeing 777", 500, 30000, 8000, 8.0);

    std::string expectedString = "Passenger Aircraft - Model: Boeing 777, Capacity: 500, Payload: 30000, Range: 8000, Fuel Consumption: 8.000000";

    EXPECT_EQ(expectedString, aircraft.toString());
}

TEST(CompareRangeTest, FirstAircraftLongerRange)
{
    Aircraft aircraft1("Boeing 747", 1000, 50000, 10000, 10.5);
    Aircraft aircraft2("Airbus A380", 800, 60000, 8000, 12.5);

    EXPECT_FALSE(PlaneService::compareRange(aircraft1, aircraft2));
}

TEST(CompareRangeTest, SecondAircraftLongerRange)
{
    Aircraft aircraft1("Boeing 747", 1000, 50000, 8000, 10.5);
    Aircraft aircraft2("Airbus A380", 800, 60000, 10000, 12.5);

    EXPECT_TRUE(PlaneService::compareRange(aircraft1, aircraft2));
}

TEST(CompareRangeTest, EqualRangeAircraft)
{
    Aircraft aircraft1("Boeing 747", 1000, 50000, 10000, 10.5);
    Aircraft aircraft2("Airbus A380", 800, 60000, 10000, 12.5);

    EXPECT_FALSE(PlaneService::compareRange(aircraft1, aircraft2));
}

TEST(CheckFuelConsumptionRangeTest, WithinRange)
{
    Aircraft aircraft("Boeing 747", 1000, 50000, 10000, 10.5);

    double minFuel = 5.0;
    double maxFuel = 15.0;

    EXPECT_TRUE(PlaneService::checkFuelConsumptionRange(aircraft, minFuel, maxFuel));
}

TEST(CheckFuelConsumptionRangeTest, LowerBound)
{
    Aircraft aircraft("Airbus A380", 800, 60000, 12000, 3.5);

    double minFuel = 5.0;
    double maxFuel = 15.0;

    EXPECT_FALSE(PlaneService::checkFuelConsumptionRange(aircraft, minFuel, maxFuel));
}

TEST(CheckFuelConsumptionRangeTest, UpperBound)
{
    Aircraft aircraft("Boeing 777", 500, 30000, 8000, 20.0);

    double minFuel = 5.0;
    double maxFuel = 15.0;

    EXPECT_FALSE(PlaneService::checkFuelConsumptionRange(aircraft, minFuel, maxFuel));
}

TEST(SortByRangeTest, EmptyList)
{
    std::vector<Aircraft> aircraftList;

    PlaneService::sortByRange(aircraftList);

    EXPECT_TRUE(aircraftList.empty());
}

TEST(SortByRangeTest, SingleAircraft)
{
    Aircraft aircraft("Boeing 747", 1000, 50000, 10000, 10.5);
    std::vector<Aircraft> aircraftList = {aircraft};

    PlaneService::sortByRange(aircraftList);

    EXPECT_EQ(1, aircraftList.size());
    EXPECT_EQ("Boeing 747", aircraftList[0].getModel());
}

TEST(SortByRangeTest, MultipleAircraft)
{
    Aircraft aircraft1("Boeing 747", 1000, 50000, 10000, 10.5);
    Aircraft aircraft2("Airbus A380", 800, 60000, 12000, 12.5);
    Aircraft aircraft3("Boeing 777", 500, 30000, 8000, 8.0);

    std::vector<Aircraft> aircraftList = {aircraft1, aircraft2, aircraft3};

    PlaneService::sortByRange(aircraftList);

    EXPECT_EQ(3, aircraftList.size());
    EXPECT_EQ("Boeing 777", aircraftList[0].getModel());
    EXPECT_EQ("Boeing 747", aircraftList[1].getModel());
    EXPECT_EQ("Airbus A380", aircraftList[2].getModel());
}
