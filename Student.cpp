#include "Student.h"

Student::Student()
{
}

Student::Student() {}

int Student::getId()
{
    return this->id;
}

std::string Student::getLastName()
{
    return this->lastName;
}

std::string Student::getFirstName()
{
    return this->firstName;
}

std::string Student::getMiddleName()
{
    return this->middleName;
}

std::string Student::getBirthDate()
{
    return this->birthDate;
}

std::string Student::getAddress()
{
    return this->address;
}

std::string Student::getPhone()
{
    return this->phone;
}

Faculty Student::getFaculty()
{
    return this->faculty;
}

int Student::getYear()
{
    return this->year;
}

std::string Student::getGroup()
{
    return this->group;
}

void Student::setId(int newId)
{
    this->id = newId;
}

void Student::setLastName(const std::string &newLastName)
{
    this->lastName = newLastName;
}

void Student::setFirstName(const std::string &newFirstName)
{
    this->firstName = newFirstName;
}

void Student::setMiddleName(const std::string &newMiddleName)
{
    this->middleName = newMiddleName;
}

void Student::setBirthDate(const std::string &newBirthDate)
{
    this->birthDate = newBirthDate;
}

void Student::setAddress(const std::string &newAddress)
{
    this->address = newAddress;
}

void Student::setPhone(const std::string &newPhone)
{
    this->phone = newPhone;
}

void Student::setFaculty(const Faculty &newFaculty)
{
    this->faculty = newFaculty;
}

void Student::setYear(int newYear)
{
    this->year = newYear;
}

void Student::setGroup(const std::string &newGroup)
{
    this->group = newGroup;
}