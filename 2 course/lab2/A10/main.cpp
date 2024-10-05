#include "pch.h"

#include <iostream>
#include <string>

class Animal
{
private:
    std::string name;

public:
    Animal(const std::string &name) : name(name) {}

    std::string getName() const
    {
        return name;
    }

    void setName(const std::string &newName)
    {
        name = newName;
    }

    virtual void makeSound()
    {
        std::cout << "Animal makes a sound." << std::endl;
    }

    virtual void jump()
    {
        std::cout << "Animal jumps." << std::endl;
    }

    virtual void run()
    {
        std::cout << "Animal runs." << std::endl;
    }

    virtual void bite()
    {
        std::cout << "Animal bites." << std::endl;
    }

    virtual bool equals(const Animal &other)
    {
        return this->name == other.name;
    }

    virtual int hashCode()
    {
        int hash = 0;
        for (char c : name)
        {
            hash += c;
        }
        return hash;
    }

    virtual std::string toString()
    {
        return "Animal[name=" + name + "]";
    }
};

class Dog : public Animal
{
private:
    std::string breed;

public:
    Dog(const std::string &name, const std::string &breed) : Animal(name), breed(breed) {}

    std::string getBreed() const
    {
        return breed;
    }

    void setBreed(const std::string &newBreed)
    {
        breed = newBreed;
    }

    void makeSound() override
    {
        std::cout << "Dog " << getName() << " (" << breed << ") barks: Woof! Woof!" << std::endl;
    }

    void jump() override
    {
        std::cout << "Dog " << getName() << " (" << breed << ") jumps high." << std::endl;
    }

    void run() override
    {
        std::cout << "Dog " << getName() << " (" << breed << ") runs fast." << std::endl;
    }

    void bite() override
    {
        std::cout << "Dog " << getName() << " (" << breed << ") bites." << std::endl;
    }

    bool equals(const Animal &other) override
    {
        const Dog *otherDog = dynamic_cast<const Dog *>(&other);
        return otherDog && this->getName() == otherDog->getName() && this->breed == otherDog->breed;
    }

    int hashCode() override
    {
        int hash = 0;
        for (char c : getName())
        {
            hash += c;
        }
        return hash;
    }

    std::string toString() override
    {
        return "Dog[name=" + getName() + ", breed=" + breed + "]";
    }
};

class Puppy : public Dog
{
private:
    std::string uniqueFeature;

public:
    Puppy(const std::string &name, const std::string &breed, const std::string &uniqueFeature) : Dog(name, breed), uniqueFeature(uniqueFeature) {}

    std::string getUniqueFeature() const
    {
        return uniqueFeature;
    }

    void setUniqueFeature(const std::string &newFeature)
    {
        uniqueFeature = newFeature;
    }

    void makeSound() override
    {
        std::cout << "Puppy " << getName() << " (" << getBreed() << ") makes a cute sound: Woof! Woof!" << std::endl;
    }

    void jump() override
    {
        std::cout << "Puppy " << getName() << " (" << getBreed() << ") jumps around excitedly." << std::endl;
    }

    void run() override
    {
        std::cout << "Puppy " << getName() << " (" << getBreed() << ") runs playfully." << std::endl;
    }

    void bite() override
    {
        std::cout << "Puppy " << getName() << " (" << getBreed() << ") playfully bites." << std::endl;
    }

    bool equals(const Animal &other) override
    {
        const Puppy *otherPuppy = dynamic_cast<const Puppy *>(&other);
        return otherPuppy && this->getName() == otherPuppy->getName() && this->getBreed() == otherPuppy->getBreed() && this->uniqueFeature == otherPuppy->uniqueFeature;
    }

    int hashCode() override
    {
        int hash = 0;
        for (char c : getName())
        {
            hash += c;
        }
        return hash;
    }

    std::string toString() override
    {
        return "Puppy[name=" + getName() + ", breed=" + getBreed() + ", uniqueFeature=" + uniqueFeature + "]";
    }
};

TEST(AnimalTest, GetNameTest)
{
    Animal animal("Fluffy");
    EXPECT_EQ(animal.getName(), "Fluffy");
}

TEST(AnimalTest, SetNameTest)
{
    Animal animal("Buddy");
    animal.setName("Max");
    EXPECT_EQ(animal.getName(), "Max");
}

TEST(AnimalTest, ToStringTest)
{
    Animal animal("Rex");
    EXPECT_EQ(animal.toString(), "Animal[name=Rex]");
}

TEST(DogTest, MakeSoundTest)
{
    Dog dog("Buddy", "Golden Retriever");
    testing::internal::CaptureStdout();
    dog.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Buddy (Golden Retriever) barks: Woof! Woof!") != std::string::npos);
}

TEST(PuppyTest, UniqueFeatureTest)
{
    Puppy puppy("Charlie", "Dachshund", "Spots on tail");
    testing::internal::CaptureStdout();
    puppy.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Charlie (Dachshund) makes a cute sound: Woof! Woof!") != std::string::npos);
}
