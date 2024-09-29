#pragma once

#include "Dog.h"

class Puppy : public Dog {
public:
    Puppy(const std::string& name);

    void makeSound() override;
    void jump() override;
    void run() override;
    void bite() override;
    bool equals(const Animal& other) override;
    int hashCode() override;
    std::string toString() override;
};