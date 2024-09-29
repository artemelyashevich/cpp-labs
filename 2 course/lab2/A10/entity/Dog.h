#pragma once
#include "Animal.h"

class Dog : public Animal {
public:
    Dog(const std::string& name);

    void makeSound() override;
    void jump() override;
    void run() override;
    void bite() override;
    bool equals(const Animal& other) override;
    int hashCode() override;
    std::string toString() override;
};
