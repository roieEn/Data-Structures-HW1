#pragma once
#include "Student.h"
#include "AvlTree.h"
#include "wet1util.h"
#include "Pair.h"


class Course {
    int courseId;
    int coursePoints;
    AvlTree<Pair<int,Student>> studentsTree; //when Block will be its own file will be Block<Pair<int,Student>>
public:
    Course(const int id, const int points) : courseId(id), coursePoints(points) {}
    StatusType removeStudent(int id);
    StatusType addStudent(int id);
    ~Course() = default; //should use the correct destructor of AvlTree
};