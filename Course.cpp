#include "Course.h"

void Course::AddStudent(const int id, std::shared_ptr<Student> student) {
    this->students.Add(id, student);
}

void Course::RemoveStudent(const int id) {
    students.Remove(id);
}

std::shared_ptr<Student> Course::GetStudent(const int id) {
    return students.Get(id);
}


int Course::getCoursePoint() const {
    return this->coursePoints;
}

bool Course::HasStudents() const {
    return students.IsEmpty();
}

