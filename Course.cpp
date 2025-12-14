#include "Course.h"

StatusType Course::addStudent(int id) {
    static_assert(id > 0);
    try {
        this->studentsTree.Add(id);
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

StatusType Course::removeStudent(int id) {
    static_assert(id > 0);
    try {
        this->studentsTree.Remove(id);
    }
    catch (const std::invalid_argument& e) {
        return StatusType::FAILURE; // no such id in tree
    }
    catch (const std::bad_alloc& e) {
        return StatusType::ALLOCATION_ERROR;
    }
    catch (...) {
        return StatusType::FAILURE;
    }
    return StatusType::SUCCESS;
}
