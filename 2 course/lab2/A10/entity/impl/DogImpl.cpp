#include "../Dog.h"
#include <iostream>

Dog::Dog(const std::string& name) : Animal(name) {}

void Dog::makeSound() {
    std::cout << "Woof woof" << std::endl;
}

void Dog::jump() {
    std::cout << "Jumping like a dog" << std::endl;
}

void Dog::run() {
    std::cout << "Running like a dog" << std::endl;
}

void Dog::bite() {
    std::cout << "Biting like a dog" << std::endl;
}

bool Dog::equals(const Animal& other) {
    const Dog* otherDog = dynamic_cast<const Dog*>(&other);
    if (otherDog) {
        return this->getName() == otherDog->getName();
    }
    return false;
}

int Dog::hashCode() {
    // A simple hash function using the hash of the dog's name
    return std::hash<std::string>{}(this->getName());
}

std::string Dog::toString() {
    return "Dog: " + this->getName();
}