#pragma once

#include <string>

class Animal {
private:
    std::string name;

public:
    Animal(const std::string& name);

    std::string getName() const;
    void setName(const std::string& newName);

    virtual void makeSound();
    virtual void jump();
    virtual void run();
    virtual void bite();
    virtual bool equals(const Animal& other);
    virtual int hashCode();
    virtual std::string toString();
};