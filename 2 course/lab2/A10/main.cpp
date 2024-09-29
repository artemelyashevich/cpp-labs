#include "pch.h"

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