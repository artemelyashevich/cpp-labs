#include "pch.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <vector>
#include <string>

auto logger = spdlog::stdout_color_mt("logger");

class Car
{
private:
    int position;
    int speed;

public:
    Car(int pos, int spd) : position(pos), speed(spd) {}

    int getPosition() const
    {
        return position;
    }

    void setPosition(int pos)
    {
        position = pos;
    }

    int getSpeed() const
    {
        return speed;
    }

    void setSpeed(int spd)
    {
        speed = spd;
    }
};

class PositionValidator
{
public:
    static void validate(int position)
    {
        logger->info("Attempting to check valid value of car position.");
        if (position < 0)
        {
            logger->warn("Position must be non-negative");
            throw std::invalid_argument("Position must be non-negative");
        }
        logger->info("Validation has been passed.");
    }
};

class ParkingService
{
public:
    int countOvertakes(const std::vector<Car> &cars)
    {
        logger->info("Attempting to find count of overtakes.");
        int overtakes = 0;
        int n = cars.size();

        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (
                    (cars[i].getPosition() < cars[j].getPosition() && cars[i].getSpeed() > cars[j].getSpeed()) || (cars[i].getPosition() > cars[j].getPosition() && cars[i].getSpeed() < cars[j].getSpeed()))
                {
                    overtakes++;
                }
            }
        }
        logger->info("Count of attempting of overtakes has been found.");
        return overtakes;
    }
};

class ParkingController
{
private:
    ParkingService parkingService;
    PositionValidator validator;

public:
    int manageAndCountOvertakes(std::vector<Car> &cars)
    {
        for (const Car &car : cars)
        {
            this->validator.validate(car.getPosition());
        }
        return this->parkingService.countOvertakes(cars);
    }
};

TEST(CarTest, GetPosition)
{
    Car car(10, 100);
    EXPECT_EQ(car.getPosition(), 10);
}

TEST(CarTest, SetPosition)
{
    Car car(10, 100);
    car.setPosition(20);
    EXPECT_EQ(car.getPosition(), 20);
}

TEST(CarTest, GetSpeed)
{
    Car car(10, 100);
    EXPECT_EQ(car.getSpeed(), 100);
}

TEST(CarTest, SetSpeed)
{
    Car car(10, 100);
    car.setSpeed(200);
    EXPECT_EQ(car.getSpeed(), 200);
}

TEST(PositionValidatorTest, ValidatePositive)
{
    EXPECT_NO_THROW(PositionValidator::validate(10));
}

TEST(PositionValidatorTest, ValidateNegative)
{
    EXPECT_THROW(PositionValidator::validate(-1), std::invalid_argument);
}

TEST(ParkingServiceTest, CountOvertakes)
{
    std::vector<Car> cars = {
        Car(0, 2),
        Car(1, 1),
        Car(2, 3),
        Car(4, 2)};

    ParkingService parkingService;
    int result = parkingService.countOvertakes(cars);
    EXPECT_EQ(result, 2);
}

TEST(ParkingControllerTest, ManageAndCountOvertakes)
{
    std::vector<Car> cars = {
        Car(0, 2),
        Car(1, 1),
        Car(2, 3),
        Car(4, 2)};

    ParkingController parkingController;
    int result = parkingController.manageAndCountOvertakes(cars);
    EXPECT_EQ(result, 2);
}

TEST(ParkingControllerTest, ManageAndCountOvertakesWithInvalidPosition)
{
    std::vector<Car> cars = {
        Car(-1, 2),
        Car(1, 1),
        Car(2, 3),
        Car(4, 2)};

    ParkingController parkingController;
    EXPECT_THROW(parkingController.manageAndCountOvertakes(cars), std::invalid_argument);
}