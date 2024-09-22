#pragma once

#include <vector>
#include <map>
#include <string>

// Class representing a service for managing students
class StudentService
{
private:
    // Vector to store student objects
    std::vector<Student> students;

public:
    // Method to add a new student to the service
    void addStudent(const Student &student);

    // Method to get students belonging to a specific faculty
    std::vector<Student> getStudentsByFaculty(Faculty faculty);

    // Method to get students belonging to a specific group
    std::vector<Student> getStudentsByGroup(const std::string &group);

    // Method to get students born after a specified year
    std::vector<Student> getStudentsBornAfter(int year);

    // Method to group students by faculty into a map
    std::map<Faculty, std::vector<Student>> getStudentsByFacultyMap();

    // Method to group students by group into a map
    std::map<std::string, std::vector<Student>> getStudentsByGroupMap();
};