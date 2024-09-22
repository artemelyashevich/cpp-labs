#pragma once

#include <string>

enum class Faculty
{
    Science,
    Arts,
    Engineering,
    Business,
    Law
};

// Class representing a student
class Student
{
private:
    // Private member variables
    int id;
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string birthDate;
    std::string address;
    std::string phone;
    Faculty faculty;
    int year;
    std::string group;

public:
    // Constructor with parameters to initialize a student
    Student(int id, const std::string &lastName, const std::string &firstName,
            const std::string &middleName, const std::string &birthDate,
            const std::string &address, const std::string &phone,
            Faculty faculty, int year, const std::string &group) {}

    // Default constructor
    Student() {}

    // Getter and setter methods for various member variables
    int getId();

    std::string getLastName();

    std::string getFirstName();

    std::string getMiddleName();

    std::string getBirthDate();

    std::string getAddress();

    std::string getPhone();

    Faculty getFaculty();

    int getYear();

    std::string getGroup();

    void setId(int newId);

    void setLastName(const std::string &newLastName);

    void setFirstName(const std::string &newFirstName);

    void setMiddleName(const std::string &newMiddleName);

    void setBirthDate(const std::string &newBirthDate);

    void setAddress(const std::string &newAddress);

    void setPhone(const std::string &newPhone);

    void setFaculty(const Faculty &newFaculty);

    void setYear(int newYear);

    void setGroup(const std::string &newGroup);
};