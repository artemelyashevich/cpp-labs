#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

enum class Faculty
{
    Science,
    Arts,
    Engineering,
    Business,
    Law
};

/**
 * @class Student
 * @brief Represents a student with personal and academic information.
 *
 * The Student class encapsulates details about a student, including their
 * personal information (name, birth date, address, and phone) and academic
 * information (faculty, year, and group).
 */
class Student
{
public:
    int id;                 /**< Unique identifier for the student. */
    std::string lastName;   /**< Last name of the student. */
    std::string firstName;  /**< First name of the student. */
    std::string middleName; /**< Middle name of the student. */
    std::string birthDate;  /**< Birth date of the student in YYYY-MM-DD format. */
    std::string address;    /**< Home address of the student. */
    std::string phone;      /**< Contact phone number of the student. */
    Faculty faculty;        /**< Faculty to which the student belongs. */
    int year;               /**< Year of study (1 to 4). */
    std::string group;      /**< Group the student is associated with. */

    /**
     * @brief Constructs a Student object with the specified details.
     *
     * @param id Unique identifier for the student.
     * @param lastName Last name of the student.
     * @param firstName First name of the student.
     * @param middleName Middle name of the student.
     * @param birthDate Birth date of the student in YYYY-MM-DD format.
     * @param address Home address of the student.
     * @param phone Contact phone number of the student.
     * @param faculty Faculty to which the student belongs.
     * @param year Year of study (1 to 4).
     * @param group Group the student is associated with.
     */
    Student(int id, const std::string& lastName, const std::string& firstName,
        const std::string& middleName, const std::string& birthDate,
        const std::string& address, const std::string& phone,
        Faculty faculty, int year, const std::string& group)
        : id(id), lastName(lastName), firstName(firstName),
        middleName(middleName), birthDate(birthDate), address(address),
        phone(phone), faculty(faculty), year(year), group(group) {}
};

/**
 * @class StudentDatabase
 * @brief Manages a collection of students and provides methods to query them.
 *
 * The StudentDatabase class stores a list of Student objects and offers
 * various methods to add students and retrieve them based on different criteria,
 * such as faculty, birth year, and group.
 */
class StudentDatabase
{
private:
    std::vector<Student> students; /**< Vector to store all student records. */

public:
    /**
     * @brief Adds a student to the database.
     *
     * This method appends the provided Student object to the internal
     * collection of students.
     *
     * @param student The Student object to add to the database.
     */
    void addStudent(const Student& student)
    {
        students.push_back(student);
    }

    /**
     * @brief Retrieves students belonging to a specific faculty.
     *
     * This method searches the database for students that are part of the
     * specified faculty and returns a vector containing those students.
     *
     * @param faculty The Faculty to filter students by.
     * @return A vector of Student objects belonging to the specified faculty.
     */
    std::vector<Student> getStudentsByFaculty(Faculty faculty)
    {
        std::vector<Student> result;
        for (const auto& student : students)
        {
            if (student.faculty == faculty)
            {
                result.push_back(student);
            }
        }
        return result;
    }

    /**
     * @brief Retrieves students born after a specified year.
     *
     * This method filters the students in the database based on their birth
     * year and returns those who were born after the specified year.
     *
     * @param year The year to filter students by (inclusive).
     * @return A vector of Student objects born after the specified year.
     */
    std::vector<Student> getStudentsBornAfter(int year)
    {
        std::vector<Student> result;
        for (const auto& student : students)
        {
            int birthYear = std::stoi(student.birthDate.substr(0, 4));
            if (birthYear > year)
            {
                result.push_back(student);
            }
        }
        return result;
    }

    /**
     * @brief Retrieves students belonging to a specific group.
     *
     * This method searches the database for students that are part of the
     * specified group and returns a vector containing those students.
     *
     * @param group The name of the group to filter students by.
     * @return A vector of Student objects belonging to the specified group.
     */
    std::vector<Student> getStudentsByGroup(const std::string& group)
    {
        std::vector<Student> result;
        for (const auto& student : students)
        {
            if (student.group == group)
            {
                result.push_back(student);
            }
        }
        return result;
    }

    int getId() const {
        return id;
    }

    void setId(int newId) {
        id = newId;
    }

    std::string getLastName() const {
        return lastName;
    }

    void setLastName(const std::string& newLastName) {
        lastName = newLastName;
    }

    std::string getFirstName() const {
        return firstName;
    }

    void setFirstName(const std::string& newFirstName) {
        firstName = newFirstName;
    }

    std::string getMiddleName() const {
        return middleName;
    }

    void setMiddleName(const std::string& newMiddleName) {
        middleName = newMiddleName;
    }

    std::string getBirthDate() const {
        return birthDate;
    }

    void setBirthDate(const std::string& newBirthDate) {
        birthDate = newBirthDate;
    }

    std::string getAddress() const {
        return address;
    }

    void setAddress(const std::string& newAddress) {
        address = newAddress;
    }

    std::string getPhone() const {
        return phone;
    }

    void setPhone(const std::string& newPhone) {
        phone = newPhone;
    }

    Faculty getFaculty() const {
        return faculty;
    }

    void setFaculty(Faculty newFaculty) {
        faculty = newFaculty;
    }

    int getYear() const {
        return year;
    }

    void setYear(int newYear) {
        year = newYear;
    }

    std::string getGroup() const {
        return group;
    }

    void setGroup(const std::string& newGroup) {
        group = newGroup;
    }
};

/**
 * @brief Custom assertion function.
 *
 * This function checks a condition and outputs an error message if the condition is false.
 * It terminates the program if the assertion fails.
 *
 * @param condition The condition to evaluate.
 * @param message The message to display if the assertion fails.
 */
void assertCondition(bool condition, const std::string& message)
{
    if (!condition)
    {
        std::cerr << "Assertion failed: " << message << std::endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Tests adding students to the database.
 *
 * This function adds several students to the database and checks that the correct
 * number of students are returned for various queries.
 */
void testAddingStudents()
{
    StudentDatabase db;
    db.addStudent(Student(1, "Иванов", "Иван", "Иванович", "2000-01-01", "Москва", "1234567890", Faculty::Engineering, 1, "Группа 1"));
    db.addStudent(Student(2, "Петров", "Петр", "Петрович", "1999-05-10", "Санкт-Петербург", "0987654321", Faculty::Science, 2, "Группа 1"));
    db.addStudent(Student(3, "Сидоров", "Сидор", "Сидорович", "2001-03-15", "Казань", "1112223334", Faculty::Arts, 1, "Группа 2"));

    assertCondition(db.getStudentsByFaculty(Faculty::Engineering).size() == 1, "Should return 1 student in Engineering");
    assertCondition(db.getStudentsBornAfter(2000).size() == 1, "Should return 1 student born after 2000");
    assertCondition(db.getStudentsByGroup("Группа 1").size() == 2, "Should return 2 students in Группа 1");
}

/**
 * @brief Tests the behavior of an empty database.
 *
 * This function checks that all queries on an empty database return empty results.
 */
void testEmptyDatabase()
{
    StudentDatabase emptyDb;
    assertCondition(emptyDb.getStudentsByFaculty(Faculty::Science).empty(), "Should return empty for Science in empty DB");
    assertCondition(emptyDb.getStudentsBornAfter(2000).empty(), "Should return empty for born after 2000 in empty DB");
    assertCondition(emptyDb.getStudentsByGroup("Группа 1").empty(), "Should return empty for Группа 1 in empty DB");
}

/**
 * @brief Tests querying a non-existent group.
 *
 * This function ensures that querying for a group that does not exist returns an empty result.
 */
void testNonExistentGroup()
{
    StudentDatabase db;
    db.addStudent(Student(1, "Иванов", "Иван", "Иванович", "2000-01-01", "Москва", "1234567890", Faculty::Engineering, 1, "Группа 1"));
    assertCondition(db.getStudentsByGroup("Non-Existent Group").empty(), "Should return empty for non-existent group");
}

/**
 * @brief Tests querying a faculty with no matches.
 *
 * This function checks that querying for a faculty not present in the database returns an empty result.
 */
void testFacultyWithNoMatches()
{
    StudentDatabase db;
    db.addStudent(Student(1, "Иванов", "Иван", "Иванович", "2000-01-01", "Москва", "1234567890", Faculty::Engineering, 1, "Группа 1"));
    assertCondition(db.getStudentsByFaculty(Faculty::Business).empty(), "Should return empty for Business faculty");
}

/**
 * @brief Tests birth year boundaries for student queries.
 *
 * This function checks that students are correctly filtered based on their birth year.
 */
void testBirthYearBoundary()
{
    StudentDatabase db;
    db.addStudent(Student(1, "Иванов", "Иван", "Иванович", "2000-01-01", "Москва", "1234567890", Faculty::Engineering, 1, "Группа 1"));
    db.addStudent(Student(2, "Петров", "Петр", "Петрович", "1999-05-10", "Санкт-Петербург", "0987654321", Faculty::Science, 2, "Группа 1"));
    db.addStudent(Student(3, "Сидоров", "Сидор", "Сидорович", "2001-03-15", "Казань", "1112223334", Faculty::Arts, 1, "Группа 2"));

    assertCondition(db.getStudentsBornAfter(1990).size() == 3, "Should return all 3 students born after 1990");
    assertCondition(db.getStudentsBornAfter(2001).empty(), "Should return empty for born after 2001");
}

/**
 * @brief Tests multiple entries in the same group.
 *
 * This function checks that the database correctly returns multiple students in the same group.
 */
void testMultipleEntriesSameGroup()
{
    StudentDatabase db;
    db.addStudent(Student(1, "Иванов", "Иван", "Иванович", "2000-01-01", "Москва", "1234567890", Faculty::Engineering, 1, "Группа 1"));
    db.addStudent(Student(2, "Петров", "Петр", "Петрович", "1999-05-10", "Санкт-Петербург", "0987654321", Faculty::Science, 2, "Группа 1"));
    db.addStudent(Student(3, "Сидоров", "Сидор", "Сидорович", "2001-03-15", "Казань", "1112223334", Faculty::Arts, 1, "Группа 1")); // Same group

    assertCondition(db.getStudentsByGroup("Группа 1").size() == 3, "Should return 3 students in Группа 1");
}

/**
 * @brief Tests querying students by specific years.
 *
 * This function checks that the database correctly returns students based on their faculty.
 */
void testYearSpecificStudents()
{
    StudentDatabase db;
    db.addStudent(Student(1, "Иванов", "Иван", "Иванович", "2000-01-01", "Москва", "1234567890", Faculty::Engineering, 1, "Группа 1"));
    db.addStudent(Student(2, "Петров", "Петр", "Петрович", "1999-05-10", "Санкт-Петербург", "0987654321", Faculty::Science, 2, "Группа 2"));

    assertCondition(db.getStudentsByFaculty(Faculty::Science).size() == 1, "Should return 1 student in Science");
    assertCondition(db.getStudentsByFaculty(Faculty::Engineering).size() == 1, "Should return 1 student in Engineering");
}

/**
 * @brief Tests handling of duplicate student entries.
 *
 * This function checks that the database counts duplicate entries correctly.
 */
void testDuplicateStudents()
{
    StudentDatabase db;
    db.addStudent(Student(1, "Иванов", "Иван", "Иванович", "2000-01-01", "Москва", "1234567890", Faculty::Engineering, 1, "Группа 1"));
    db.addStudent(Student(1, "Иванов", "Иван", "Иванович", "2000-01-01", "Москва", "1234567890", Faculty::Engineering, 1, "Группа 1")); // Duplicate

    assertCondition(db.getStudentsByGroup("Группа 1").size() == 2, "Should return 2 students including duplicates in Группа 1");
}

/**
 * @brief Tests handling of special character names.
 *
 * This function checks that the database correctly handles names with special characters.
 */
void testSpecialCharacterNames()
{
    StudentDatabase db;
    db.addStudent(Student(1, "O'Connor", "Sean", "Michael", "2000-01-01", "Dublin", "1234567890", Faculty::Arts, 2, "Группа 1"));
    db.addStudent(Student(2, "Nørgaard", "Lars", "Peter", "1998-05-10", "Copenhagen", "0987654321", Faculty::Science, 1, "Группа 2"));

    assertCondition(db.getStudentsByGroup("Группа 1").size() == 1, "Should return 1 student in Группа 1 with special characters");
    assertCondition(db.getStudentsByGroup("Группа 2").size() == 1, "Should return 1 student in Группа 2 with special characters");
}

/**
 * @brief Runs all test cases for the StudentDatabase.
 *
 * This function executes a series of tests to validate the functionality
 * of the StudentDatabase class. It checks various scenarios such as adding
 * students, querying an empty database, and handling special cases.
 */
void runTests()
{
    testAddingStudents();
    testEmptyDatabase();
    testNonExistentGroup();
    testFacultyWithNoMatches();
    testBirthYearBoundary();
    testMultipleEntriesSameGroup();
    testYearSpecificStudents();
    testDuplicateStudents();
    testSpecialCharacterNames();

    std::cout << "All tests passed!" << std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    runTests();
    return 0;
}