#include "TechSystem.h"


StatusType TechSystem::addStudent(const int studentId) {
    if(studentId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        const std::shared_ptr<Student> student = std::make_unique<Student>(studentId, -1 * this->currentBonus);
        this->studentsTree.Add(student);
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
        return StatusType::FAILURE; //id is not in students tree
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
        this->coursesTree.Remove(courseId); //need to check if course has students
    }
    catch (const std::invalid_argument& e) {
        return StatusType::FAILURE; //id is not in courseId
    }
    catch (const std::bad_alloc& e) {
        return StatusType::ALLOCATION_ERROR;
    }
    catch (...) {
        return StatusType::FAILURE;
    }
    return StatusType::SUCCESS;
}


StatusType TechSystem::enrollStudent(const int studentId, const int courseId) {
    if(courseId <= 0 || studentId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        this->coursesTree.Find(courseId).Add(studentId);
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

StatusType TechSystem::completeCourse(const int studentId, const int courseId) {
    if(courseId <= 0 || studentId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        Pair<int,std::shared_ptr<Course>> course = coursesTree.Find(courseId);
        Student* studentToRemove = course.Remove(studentId);
        studentToRemove->m_points += course->getCoursePoint();
    }
    catch (const std::invalid_argument& e) {
        return StatusType::FAILURE; //id is not in courseId
    }
    catch (const std::bad_alloc& e) {
        return StatusType::ALLOCATION_ERROR;
    }
    catch (...) {
        return StatusType::FAILURE;
    }
    return StatusType::SUCCESS;
}

StatusType TechSystem::awardAcademicPoints(int points) {
    if(points <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        this->currentBonus += points;
    }
    catch (std::bad_alloc& e) {
        return StatusType::ALLOCATION_ERROR;
    }
    return StatusType::SUCCESS;
}

output_t<int> TechSystem::getStudentPoints(int studentId) {
    if(studentId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        return this->studentsTree.Find(studentId)->m_points;
    }
    catch (const std::invalid_argument& e) {
        return StatusType::FAILURE; //id is not is tree
    }
    catch (const std::bad_alloc& e) {
        return StatusType::ALLOCATION_ERROR;
    }
    catch (...) {
        return StatusType::FAILURE;
    }
    return StatusType::SUCCESS;
}




