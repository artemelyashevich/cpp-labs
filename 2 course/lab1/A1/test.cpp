#include "pch.h"

// Test cases for a getStudentsByFaculty method
TEST(StudentServiceTest, GetStudentsByFaculty_EmptyStudentList)
{
    StudentService studentService;

    Student student;

    Faculty testFaculty = Faculty::Engineering;

    student.setLastName("Doe");
    student.setFaculty(testFaculty);

    studentService.addStudent(student);

    std::vector<Student> result = studentService.getStudentsByFaculty(Faculty::Arts);

    EXPECT_TRUE(result.empty());
}

TEST(StudentServiceTest, GetStudentsByFaculty_SingleStudentMatch)
{
    StudentService studentService;

    Faculty testFaculty = Faculty::Arts;
    Student student;

    student.setLastName("Doe");
    student.setFaculty(testFaculty);

    studentService.addStudent(student);

    std::vector<Student> result = studentService.getStudentsByFaculty(testFaculty);

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0].getLastName(), "Doe");
}

TEST(StudentServiceTest, GetStudentsByFaculty_NoStudentMatch)
{
    StudentService studentService;

    Faculty testFaculty = Faculty::Arts;
    Student student1;
    ("Alice Smith", Faculty::Engineering);
    student1.setLastName("Smith");
    student1.setFaculty(Faculty::Engineering);
    Student student2;
    student1.setLastName("Johnson");
    student1.setFaculty(Faculty::Business);

    studentService.addStudent(student1);
    studentService.addStudent(student2);

    std::vector<Student> result = studentService.getStudentsByFaculty(testFaculty);

    EXPECT_TRUE(result.empty());
}

TEST(StudentServiceTest, GetStudentsByFaculty_Test)
{
    StudentService studentService;

    Student student1;
    student1.setId(1);
    student1.setFirstName("Alice");
    student1.setLastName("Smith");
    student1.setFaculty(Faculty::Engineering);
    studentService.addStudent(student1);

    std::vector<Student> engineeringStudents = studentService.getStudentsByFaculty(Faculty::Engineering);

    ASSERT_EQ(engineeringStudents.size(), 1);
}

// Test cases for a getStudentsByGroup method
TEST(StudentServiceTest, GetStudentsByGroup_EmptyStudentList)
{
    std::string testGroup = "GroupA";

    StudentService studentService;

    Student student;
    student.setId(1);
    student.setFirstName("Alice");
    student.setGroup("a");
    student.setFaculty(Faculty::Engineering);

    studentService.addStudent(student);

    std::vector<Student> result = studentService.getStudentsByGroup(testGroup);

    EXPECT_TRUE(result.empty());
}

TEST(StudentServiceTest, GetStudentsByGroup_SingleStudentMatch)
{
    std::string testGroup = "GroupA";

    StudentService studentService;

    Student student;
    student.setId(1);
    student.setFirstName("Alice");
    student.setGroup(testGroup);
    student.setFaculty(Faculty::Engineering);

    studentService.addStudent(student);

    std::vector<Student> result = studentService.getStudentsByGroup(testGroup);

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0].getFirstName(), "Alice");
}

TEST(StudentServiceTest, GetStudentsByGroup_NoStudentMatch)
{
    StudentService studentService;

    std::string testGroup = "GroupC";

    Student student1;
    student1.setId(1);
    student1.setFirstName("Alice");
    student1.setGroup("GroupA");
    student1.setFaculty(Faculty::Engineering);

    Student student2;
    student2.setId(1);
    student2.setFirstName("Alice");
    student2.setGroup("GroupA");
    student2.setFaculty(Faculty::Engineering);

    studentService.addStudent(student1);
    studentService.addStudent(student2);

    std::vector<Student> result = studentService.getStudentsByGroup(testGroup);

    EXPECT_TRUE(result.empty());
}

TEST(StudentServiceTest, GetStudentsByGroup_Test)
{
    StudentService studentService;

    Student student1;
    student1.setId(1);
    student1.setFirstName("Bob");
    student1.setLastName("Johnson");
    student1.setGroup("A1");
    studentService.addStudent(student1);

    std::vector<Student> groupA1Students = studentService.getStudentsByGroup("A1");

    ASSERT_EQ(groupA1Students.size(), 1);
}

// Test cases for a getStudentsBornAfter method
TEST(StudentServiceTest, GetStudentsBornAfter_NoStudentsBornAfterYear)
{
    StudentService studentService;
    int testYear = 2000;

    Student student1;
    student1.setFirstName("John");
    student1.setBirthDate("1998-05-15");
    Student student2;
    student2.setFirstName("Alice");
    student2.setBirthDate("1999-07-20");

    studentService.addStudent(student1);
    studentService.addStudent(student2);

    std::vector<Student> result = studentService.getStudentsBornAfter(testYear);

    EXPECT_TRUE(result.empty());
}

TEST(StudentServiceTest, GetStudentsBornAfter_SingleStudentBornAfterYear)
{
    StudentService studentService;

    int testYear = 1997;
    Student student1;
    student1.setFirstName("John");
    student1.setBirthDate("1996-05-15");
    Student student2;
    student2.setFirstName("Alice");
    student2.setBirthDate("1999-07-20");

    studentService.addStudent(student1);
    studentService.addStudent(student2);

    std::vector<Student> result = studentService.getStudentsBornAfter(testYear);

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0].getFirstName(), "Alice");
}

TEST(StudentServiceTest, GetStudentsBornAfter_MultipleStudentsBornAfterYear)
{
    StudentService studentService;

    int testYear = 1990;

    Student student1;
    student1.setFirstName("John");
    student1.setBirthDate("1998-05-15");
    Student student2;
    student2.setFirstName("Alice");
    student2.setBirthDate("1999-07-20");

    studentService.addStudent(student1);
    studentService.addStudent(student2);

    std::vector<Student> result = studentService.getStudentsBornAfter(testYear);

    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].getFirstName(), "John");
    EXPECT_EQ(result[1].getFirstName(), "Alice");
}

TEST(StudentServiceTest, GetStudentsBornAfter_Test)
{
    StudentService studentService;

    Student student1;
    student1.setId(1);
    student1.setFirstName("Alice");
    student1.setLastName("Smith");
    student1.setBirthDate("1998-03-15");
    studentService.addStudent(student1);

    Student student2;
    student2.setId(2);
    student2.setFirstName("Bob");
    student2.setLastName("Jones");
    student2.setBirthDate("2002-07-20");
    studentService.addStudent(student2);

    Student student3;
    student3.setId(3);
    student3.setFirstName("Charlie");
    student3.setLastName("Brown");
    student3.setBirthDate("1999-11-30");
    studentService.addStudent(student3);

    auto studentsBornAfterYear = studentService.getStudentsBornAfter(2000);

    ASSERT_EQ(studentsBornAfterYear.size(), 1);
    ASSERT_EQ(studentsBornAfterYear[0].getId(), 2);
}

// Test cases for getStudentsByFacultyMap method
TEST(StudentServiceTest, GetStudentsByFacultyMap_NoStudentsInMap)
{
    StudentService service;

    std::map<Faculty, std::vector<Student>> result = service.getStudentsByFacultyMap();

    EXPECT_TRUE(result.empty());
}

TEST(StudentServiceTest, GetStudentsByFacultyMap_SingleStudentInMap)
{
    StudentService service;

    Student student;
    student.setFirstName("Alice");
    student.setFaculty(Faculty::Engineering);
    student.setGroup("GroupA");

    service.addStudent(student);

    std::map<Faculty, std::vector<Student>> result = service.getStudentsByFacultyMap();

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[Faculty::Engineering].size(), 1);
    EXPECT_EQ(result[Faculty::Engineering][0].getFirstName(), "Alice");
}

TEST(StudentServiceTest, GetStudentsByFacultyMap_MultipleStudentsInMap)
{
    StudentService service;

    Student student1;
    student1.setFirstName("John");
    student1.setFaculty(Faculty::Science);
    student1.setGroup("GroupA");

    Student student2;
    student2.setFirstName("Bob");
    student2.setFaculty(Faculty::Business);
    student2.setGroup("GroupB");

    service.addStudent(student1);
    service.addStudent(student2);

    std::map<Faculty, std::vector<Student>> result = service.getStudentsByFacultyMap();

    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[Faculty::Science].size(), 1);
    EXPECT_EQ(result[Faculty::Business].size(), 1);
}

// Test cases for getStudentsByGroupMap method
TEST(StudentServiceTest, getStudentsByGroupMap_NoStudentsInMap)
{
    StudentService service;

    std::map<std::string, std::vector<Student>> result = service.getStudentsByGroupMap();

    EXPECT_TRUE(result.empty());
}

TEST(StudentServiceTest, getStudentsByGroupMap_SingleStudentInMap)
{
    StudentService service;

    Student student;
    student.setFirstName("Alice");
    student.setGroup("GroupA");

    service.addStudent(student);

    std::map<std::string, std::vector<Student>> result = service.getStudentsByGroupMap();

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result["GroupA"].size(), 1);
    EXPECT_EQ(result["GroupA"][0].getFirstName(), "Alice");
}

TEST(StudentServiceTest, getStudentsByGroupMap_MultipleStudentsInMap)
{
    StudentService service;

    Student student1;
    student1.setFirstName("John");
    student1.setGroup("GroupA");

    Student student2;
    student2.setFirstName("Bob");
    student2.setGroup("GroupB");

    service.addStudent(student1);
    service.addStudent(student2);

    std::map<std::string, std::vector<Student>> result = service.getStudentsByGroupMap();

    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result["GroupA"].size(), 1);
    EXPECT_EQ(result["GroupB"].size(), 1);
}