#include "../Puppy.h"
#include <iostream>

Puppy::Puppy(const std::string& name) : Dog(name) {}

void Puppy::makeSound() {
    std::cout << "Yip yip" << std::endl;
}

void Puppy::jump() {
    // Puppies might jump differently than adult dogs
    std::cout << "Jumping like a puppy" << std::endl;
}

void Puppy::run() {
    // Puppies might run playfully
    std::cout << "Running playfully like a puppy" << std::endl;
}

void Puppy::bite() {
    // Puppies might bite gently during play
    std::cout << "Biting gently like a puppy" << std::endl;
}