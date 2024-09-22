#include "Student.h"
#include "StudentService.h"

void StudentService::addStudent(const Student &student)
{
    students.push_back(student);
}

std::vector<Student> StudentService::getStudentsByFaculty(Faculty faculty)
{
    std::vector<Student> result;
    for (Student &student : students)
    {
        if (student.getFaculty() == faculty)
        {
            result.push_back(student);
        }
    }
    return result;
}

std::vector<Student> StudentService::getStudentsByGroup(const std::string &group)
{
    std::vector<Student> result;
    for (Student &student : students)
    {
        if (student.getGroup() == group)
        {
            result.push_back(student);
        }
    }
    return result;
}

std::vector<Student> StudentService::getStudentsBornAfter(int year)
{
    std::vector<Student> result;
    for (Student &student : students)
    {
        int birthYear = std::stoi(student.getBirthDate().substr(0, 4));
        if (birthYear > year)
        {
            result.push_back(student);
        }
    }
    return result;
}

std::map<Faculty, std::vector<Student>> StudentService::getStudentsByFacultyMap()
{
    std::map<Faculty, std::vector<Student>> studentsByFaculty;

    for (Student &student : students)
    {
        studentsByFaculty[student.getFaculty()].push_back(student);
    }

    return studentsByFaculty;
}

std::map<std::string, std::vector<Student>> StudentService::getStudentsByGroupMap()
{
    std::map<std::string, std::vector<Student>> studentsByGroup;

    for (Student &student : students)
    {
        studentsByGroup[student.getGroup()].push_back(student);
    }

    return studentsByGroup;
}