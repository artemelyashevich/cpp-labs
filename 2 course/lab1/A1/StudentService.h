#pragma once

#include <vector>
#include <map>
#include <string>

/**
 * @brief Class representing a service for managing students.
 */
class StudentService
{
private:
    std::vector<Student> students; /**< Vector to store student objects. */

public:
    /**
     * @brief Method to add a new student to the service.
     * @param student The student object to add.
     */
    void addStudent(const Student &student);

    /**
     * @brief Method to get students belonging to a specific faculty.
     * @param faculty The faculty to filter students by.
     * @return A vector of students belonging to the specified faculty.
     */
    std::vector<Student> getStudentsByFaculty(Faculty faculty);

    /**
     * @brief Method to get students belonging to a specific group.
     * @param group The group to filter students by.
     * @return A vector of students belonging to the specified group.
     */
    std::vector<Student> getStudentsByGroup(const std::string &group);

    /**
     * @brief Method to get students born after a specified year.
     * @param year The year to filter students by.
     * @return A vector of students born after the specified year.
     */
    std::vector<Student> getStudentsBornAfter(int year);

    /**
     * @brief Method to group students by faculty into a map.
     * @return A map where the key is the faculty and the value is a vector of students belonging to that faculty.
     */
    std::map<Faculty, std::vector<Student>> getStudentsByFacultyMap();

    /**
     * @brief Method to group students by group into a map.
     * @return A map where the key is the student group and the value is a vector of students belonging to that group.
     */
    std::map<std::string, std::vector<Student>> getStudentsByGroupMap();
};