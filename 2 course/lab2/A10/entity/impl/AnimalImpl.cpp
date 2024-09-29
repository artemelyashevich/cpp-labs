#include "../Animal.h"
#include "iostream"

Animal::Animal(const std::string& name) : name(name) {}

std::string Animal::getName() const {
    return name;
}

void Animal::setName(const std::string& newName) {
    name = newName;
}

void Animal::makeSound() {
    std::cout << "Animal sound" << std::endl;
}

void Animal::jump() {
    std::cout << "Animal is jumping" << std::endl;
}

void Animal::run() {
    std::cout << "Animal is running" << std::endl;
}

void Animal::bite() {
    std::cout << "Animal is biting" << std::endl;
}

bool Animal::equals(const Animal& other) {
    return name == other.name;
}

int Animal::hashCode() {
    return std::hash<std::string>{}(name);
}
std::string Animal::toString() {
    return "Animal: " + name;
}