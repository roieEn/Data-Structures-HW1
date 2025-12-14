#include "TechSystem.h"


StatusType TechSystem::addStudent(const int studentId) {
    if(studentId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        this->studentsTree.Add(studentId);
    }
    catch (const std::invalid_argument& e) {
        return StatusType::FAILURE; //id is already in courseId
    }
    catch (const std::bad_alloc& e) {
        return StatusType::ALLOCATION_ERROR;
    }
    catch (...) {
        return StatusType::FAILURE;
    }
    return StatusType::SUCCESS;
}

StatusType TechSystem::removeStudent(int studentId) {
    if(studentId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        this->studentsTree.Remove(studentId);
    }
    catch (const std::invalid_argument& e) {
        return StatusType::FAILURE; //id is already in courseId
    }
    catch (const std::bad_alloc& e) {
        return StatusType::ALLOCATION_ERROR;
    }
    catch (...) {
        return StatusType::FAILURE;
    }
    return StatusType::SUCCESS;
}

StatusType TechSystem::addCourse(const int courseId, const int points) {
    if(courseId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        this->coursesTree.Add(Course(courseId, points));
    }
    catch (const std::invalid_argument& e) {
        return StatusType::FAILURE; //id is already in courseId
    }
    catch (const std::bad_alloc& e) {
        return StatusType::ALLOCATION_ERROR;
    }
    catch (...) {
        return StatusType::FAILURE;
    }
    return StatusType::SUCCESS;
}

StatusType TechSystem::removeCourse(const int courseId) {
    if(courseId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        this->coursesTree.Remove(courseId);
    }
    catch (const std::invalid_argument& e) {
        return StatusType::FAILURE; //id is already in courseId
    }
    catch (const std::bad_alloc& e) {
        return StatusType::ALLOCATION_ERROR;
    }
    catch (...) {
        return StatusType::FAILURE;
    }
    return StatusType::SUCCESS;
}


StatusType TechSystem::enrollStudent(int studentId, int courseId) {

}

StatusType TechSystem::completeCourse(int studentId, int courseId) {

}

StatusType TechSystem::awardAcademicPoints(int points) {

}

output_t<int> TechSystem::getStudentPoints(int studentId) {

}




