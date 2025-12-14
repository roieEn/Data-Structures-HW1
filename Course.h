#pragma once
#include "Student.h"
#include "AvlTree.h"
#include "wet1util.h"
#include "Pair.h"
#include <memory>

class Course {
    int courseId;
    int coursePoints;
    AvlTree<std::shared_ptr<Student>> studentsTree;
public:
    Course(const int id, const int points) : courseId(id), coursePoints(points) {}
    StatusType removeStudent(int id);
    StatusType addStudent(int id);
    int getCoursePoint() const;
    ~Course() = default; //should use the correct destructor of AvlTree
};