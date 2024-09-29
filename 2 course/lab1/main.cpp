#include "pch.h"
#include <iostream>
#include <string>
#include <functional>
#include <chrono>

class Animal
{
private:
    std::string name;

public:
    Animal(const std::string &name) : name(name) {}

    virtual void makeSound()
    {
        std::cout << "Animal sound\n";
    }

    virtual void jump()
    {
        std::cout << "Animal is jumping\n";
    }

    virtual void run()
    {
        std::cout << "Animal is running\n";
    }

    virtual void bite()
    {
        std::cout << "Animal is biting\n";
    }

    virtual bool equals(const Animal &other) const
    {
        return name == other.getName();
    }

    virtual size_t hashCode() const
    {
        return std::hash<std::string>{}(name);
    }

    virtual std::string toString() const
    {
        return "Animal: " + name;
    }

    std::string getName() const
    {
        return name;
    }
};

class Dog : public Animal
{
public:
    Dog(const std::string &name) : Animal(name) {}

    void makeSound() override
    {
        std::cout << "Woof woof\n";
    }

    void bite() override
    {
        std::cout << "Biting like a dog\n";
    }

    bool equals(const Animal &other) const override
    {
        if (const Dog *otherDog = dynamic_cast<const Dog *>(&other))
        {
            return getName() == otherDog->getName();
        }
        return false;
    }

    size_t hashCode() const override
    {
        return std::hash<std::string>{}("Dog:" + getName());
    }

    std::string toString() const override
    {
        return "Dog: " + getName();
    }
};

class Puppy : public Dog
{
public:
    Puppy(const std::string &name) : Dog(name) {}

    void makeSound() override
    {
        std::cout << "Yip yip\n";
    }

    void jump() override
    {
        std::cout << "Jumping playfully like a puppy\n";
    }

    void bite() override
    {
        std::cout << "Biting gently like a puppy\n";
    }

    bool equals(const Animal &other) const override
    {
        if (const Puppy *otherPuppy = dynamic_cast<const Puppy *>(&other))
        {
            return getName() == otherPuppy->getName();
        }
        return false;
    }

    size_t hashCode() const override
    {
        return std::hash<std::string>{}("Puppy:" + getName());
    }

    std::string toString() const override
    {
        return "Puppy: " + getName();
    }
};

TEST(AnimalTest, NameCheck)
{
    Animal animal("Lion");
    EXPECT_EQ("Lion", animal.getName());
}

TEST(AnimalTest, MakeSoundTest)
{
    Animal animal("Dog");
    testing::internal::CaptureStdout();
    animal.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Animal sound\n", output);
}

TEST(AnimalTest, JumpTest)
{
    Animal animal("Cat");
    testing::internal::CaptureStdout();
    animal.jump();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Animal is jumping\n", output);
}

TEST(DogTest, NameCheck)
{
    Dog dog("Buddy");
    EXPECT_EQ("Buddy", dog.getName());
}

TEST(DogTest, MakeSoundTest)
{
    Dog dog("Rex");
    testing::internal::CaptureStdout();
    dog.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Woof woof\n", output);
}

TEST(DogTest, BiteTest)
{
    Dog dog("Max");
    testing::internal::CaptureStdout();
    dog.bite();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Biting like a dog\n", output);
}

TEST(PuppyTest, NameCheck)
{
    Puppy puppy("Rusty");
    EXPECT_EQ("Rusty", puppy.getName());
}

TEST(PuppyTest, MakeSoundTest)
{
    Puppy puppy("Bella");
    testing::internal::CaptureStdout();
    puppy.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Yip yip\n", output);
}

TEST(PuppyTest, JumpTest)
{
    Puppy puppy("Cooper");
    testing::internal::CaptureStdout();
    puppy.jump();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Jumping playfully like a puppy\n", output);
}

TEST(LongRunningTest, PerformanceTest)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000000; ++i)
    {
        int result = i * i;
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    int threshold = 100;

    EXPECT_LT(duration.count(), threshold);
}