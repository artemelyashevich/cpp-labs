#pragma once

#include <string>

/**
 * @brief Enum representing different faculties a student can belong to.
 */
enum class Faculty
{
    Science,     /**< Faculty of Science */
    Arts,        /**< Faculty of Arts */
    Engineering, /**< Faculty of Engineering */
    Business,    /**< Faculty of Business */
    Law          /**< Faculty of Law */
};

/**
 * @brief Class representing a student.
 */
class Student
{
private:
    int id;                 /**< Student ID */
    std::string lastName;   /**< Last name of the student */
    std::string firstName;  /**< First name of the student */
    std::string middleName; /**< Middle name of the student */
    std::string birthDate;  /**< Birth date of the student */
    std::string address;    /**< Address of the student */
    std::string phone;      /**< Phone number of the student */
    Faculty faculty;        /**< Faculty of the student */
    int year;               /**< Year of study */
    std::string group;      /**< Student group */

public:
    /**
     * @brief Constructor to initialize a student.
     * @param id Student ID
     * @param lastName Last name of the student
     * @param firstName First name of the student
     * @param middleName Middle name of the student
     * @param birthDate Birth date of the student
     * @param address Address of the student
     * @param phone Phone number of the student
     * @param faculty Faculty of the student
     * @param year Year of study
     * @param group Student group
     */
    Student(int id, const std::string &lastName, const std::string &firstName,
            const std::string &middleName, const std::string &birthDate,
            const std::string &address, const std::string &phone,
            Faculty faculty, int year, const std::string &group);

    /**
     * @brief Default constructor.
     */
    Student();

    // Getter methods
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

    // Setter methods
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