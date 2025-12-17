#pragma once
#include "Student.h"
#include "dict.h"
#include "wet1util.h"
#include <memory>

class Course {
    int courseId;
    int coursePoints;
    Dict<std::shared_ptr<Student>> students;
public:
    Course(const int id, const int points) : courseId(id), coursePoints(points) {}
    void RemoveStudent(int id);
    void AddStudent(int id, std::shared_ptr<Student> student);
    std::shared_ptr<Student> GetStudent(int id);
    int getCoursePoint() const;
    bool HasStudents() const;
    ~Course() = default; //should use the correct destructor of Dict
};