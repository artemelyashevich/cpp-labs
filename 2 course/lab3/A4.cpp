#include "pch.h"

#include <iostream>
#include <vector>
#include <string>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

auto logger = spdlog::stdout_color_mt("test_logger");

enum class SubjectType
{
    MATH,
    HISTORY,
    ENGLISH
};
class Utils
{
public:
    static std::string getSubjectName(SubjectType subject)
    {
        switch (subject)
        {
        case SubjectType::MATH:
            return "Math";
        case SubjectType::HISTORY:
            return "History";
        case SubjectType::ENGLISH:
            return "English";
        default:
            return "Unknown";
        }
    }
};

class AcademicRecord
{
public:
    class Session
    {
    public:
        SubjectType subject;
        int grade;

        Session(SubjectType subject, int grade) : subject(subject), grade(grade) {}
    };

private:
    std::vector<Session> sessions;
    int studentID;
    std::string firstName;
    std::string lastName;
    std::string faculty;

public:
    AcademicRecord(int id, std::string first, std::string last, std::string fac) : studentID(id), firstName(first), lastName(last), faculty(fac) {}

    void addSession(SubjectType subject, int grade)
    {
        sessions.push_back(Session(subject, grade));
    }

    std::string toString()
    {
        std::string result = "Academic Record for Student ID: " + std::to_string(studentID) + "\n";
        result += "Name: " + firstName + " " + lastName + "\n";
        result += "Faculty: " + faculty + "\n";
        result += "Sessions:\n";
        for (const auto &session : sessions)
        {
            result += "Subject: " + Utils::getSubjectName(session.subject) + ", Grade: " + std::to_string(session.grade) + "\n";
        }
        return result;
    }

    int getStudentID() const
    {
        return studentID;
    }

    void setStudentID(int id)
    {
        studentID = id;
    }

    std::string getFirstName() const
    {
        return firstName;
    }

    void setFirstName(const std::string &first)
    {
        firstName = first;
    }

    std::string getLastName() const
    {
        return lastName;
    }

    void setLastName(const std::string &last)
    {
        lastName = last;
    }

    std::string getFaculty() const
    {
        return faculty;
    }

    void setFaculty(const std::string &fac)
    {
        faculty = fac;
    }
};

TEST(AcademicRecordTest, GetSetStudentIDTest)
{
    logger->info("Trying get student by id.");
    AcademicRecord ar(99999, "Jane", "Brown", "Biology");
    EXPECT_EQ(ar.getStudentID(), 99999);

    ar.setStudentID(88888);
    EXPECT_EQ(ar.getStudentID(), 88888);
}

TEST(AcademicRecordTest, GetSetFirstNameTest)
{
    logger->info("Trying get first name.");

    AcademicRecord ar(77777, "Alex", "Johnson", "Chemistry");
    EXPECT_EQ(ar.getFirstName(), "Alex");

    ar.setFirstName("Emma");
    EXPECT_EQ(ar.getFirstName(), "Emma");
}

TEST(AcademicRecordTest, GetSetFacultyTest)
{
    logger->info("Trying get faculty.");

    AcademicRecord ar(66666, "Chris", "Williams", "Engineering");
    EXPECT_EQ(ar.getFaculty(), "Engineering");

    ar.setFaculty("Mathematics");
    EXPECT_EQ(ar.getFaculty(), "Mathematics");
}

TEST(AcademicRecordTest, GetSubjectNameTest)
{
    logger->info("Trying get subjects.");

    ASSERT_EQ(Utils::getSubjectName(SubjectType::MATH), "Math");
    ASSERT_EQ(Utils::getSubjectName(SubjectType::HISTORY), "History");
    ASSERT_EQ(Utils::getSubjectName(SubjectType::ENGLISH), "English");
}