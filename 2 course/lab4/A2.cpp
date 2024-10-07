#include "pch.h"

#include <string>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

using namespace std;

auto logger = spdlog::stdout_color_mt("logger");

class Stack
{
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        logger->info("Trying push value: " + value);
        if (top >= MAX_SIZE - 1)
        {
            logger->warn("Stack overflow");
        }
        else
        {
            arr[++top] = value;
            logger->info("Value has been pushed: " + value);
        }
    }

    void pop()
    {
        logger->info("Trying pop last value");
        if (top < 0)
        {
            logger->warn("Stack is empty");
        }
        else
        {
            top--;
            logger->info("Value has been popped");
        }
    }

    int topValue()
    {
        if (top < 0)
        {
            logger->warn("Stack is empty");
            return -1;
        }
        else
        {
            logger->info("Trying to return top value");
            return arr[top];
        }
    }

    bool isEmpty()
    {
        logger->info("Trying to check if stack empty");
        return (top == -1);
    }
};

class NumberService
{
public:
    static string reverseNumber(int number)
    {
        logger->info("Trying to reverse number " + number);
        Stack digitsStack;
        string reversedNumber = "";

        while (number > 0)
        {
            int digit = number % 10;
            digitsStack.push(digit);
            number /= 10;
        }

        while (!digitsStack.isEmpty())
        {
            reversedNumber += to_string(digitsStack.topValue());
            digitsStack.pop();
        }
        logger->info("Number has been reversed and pushe into stack: " + number);
        return reversedNumber;
    }
};

TEST(NumberServiceTest, ReverseNumberTest)
{
    int number = 12345;
    std::string reversedNumber = NumberService::reverseNumber(number);

    ASSERT_EQ(reversedNumber, "54321");
}

TEST(StackTest, PushTest)
{
    Stack stack;

    stack.push(5);
    ASSERT_EQ(stack.topValue(), 5);
}

TEST(StackTest, PopTest)
{
    Stack stack;

    stack.push(5);
    stack.pop();
    ASSERT_TRUE(stack.isEmpty());
}

TEST(StackTest, PushMaxElementsTest)
{
    Stack stack;
    const int MAX_SIZE = 100;

    for (int i = 0; i < MAX_SIZE; ++i)
    {
        stack.push(i);
    }

    ASSERT_EQ(stack.topValue(), MAX_SIZE - 1);
}

TEST(StackTest, PopAllElementsTest)
{
    Stack stack;
    const int MAX_SIZE = 100;

    for (int i = 0; i < MAX_SIZE; ++i)
    {
        stack.push(i);
    }

    for (int i = MAX_SIZE - 1; i >= 0; --i)
    {
        ASSERT_EQ(stack.topValue(), i);
        stack.pop();
    }

    ASSERT_TRUE(stack.isEmpty());
}

TEST(StackTest, PopEmptyStackTest)
{
    Stack stack;

    ASSERT_TRUE(stack.isEmpty());
    stack.pop();
    ASSERT_TRUE(stack.isEmpty());
}