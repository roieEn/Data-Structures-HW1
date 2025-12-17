#pragma once
#include "Course.h"
#include "Student.h"
#include "AvlTree.h"
#include "Pair.h"
#include "wet1util.h"

class TechSystem {
    AvlTree<Pair<int, std::shared_ptr<Student>>> studentsTree;
    AvlTree<Pair<int, std::unique_ptr<Course>>> coursesTree;
    int currentBonus = 0;

public:
    TechSystem() = default;
    virtual ~TechSystem() = default;
    StatusType addStudent(int studentId);
    StatusType removeStudent(int studentId);
    StatusType addCourse(int courseId, int points);
    StatusType removeCourse(int courseId);
    StatusType enrollStudent(int studentId, int courseId);
    StatusType completeCourse(int studentId, int courseId);
    StatusType awardAcademicPoints(int points);
    output_t<int> getStudentPoints(int studentId);
};