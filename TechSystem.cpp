#include "TechSystem.h"


StatusType TechSystem::addStudent(const int studentId) {
    if(studentId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        std::shared_ptr<Student> student = std::make_shared<Student>(studentId, -1 * this->currentBonus);
        this->students.Add(studentId, student);
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

StatusType TechSystem::removeStudent(const int studentId) {
    if(studentId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        this->students.Remove(studentId);
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
        std::shared_ptr<Course> course = std::make_shared<Course>(courseId,points);
        this->courses.Add(courseId, course);
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
        this->courses.Remove(courseId); //need to check if course has students
    }
    catch (const std::invalid_argument& e) {
        return StatusType::FAILURE; //id is not in coursesTree
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
        const std::shared_ptr<Student>& student = students.Get(studentId); //checks if student exists
        courses.Get(courseId)->AddStudent(studentId, student); //tries to add student, fails if already exists in course
    }
    catch (const std::invalid_argument& e) {
        return StatusType::FAILURE; //id is already in courseId or student doesn't exist
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
        const std::shared_ptr<Course>& course = courses.Get(courseId);
        const std::shared_ptr<Student> student = course->GetStudent(studentId);
        course->RemoveStudent(studentId);
        student->m_points += course->getCoursePoint();
    }
    catch (const std::invalid_argument& e) {
        return StatusType::FAILURE; //course doesn't exist or student isn't in course
    }
    catch (const std::bad_alloc& e) {
        return StatusType::ALLOCATION_ERROR;
    }
    catch (...) {
        return StatusType::FAILURE;
    }
    return StatusType::SUCCESS;
}

StatusType TechSystem::awardAcademicPoints(const int points) {
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

output_t<int> TechSystem::getStudentPoints(const int studentId) {
    if(studentId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        return this->students.Get(studentId)->m_points + this->currentBonus;
        /*each student starts with the hole of the bonus he didn't get.
         *so that if the bonus didn't change meaning that this student should get zero bonus points
         *he will start with -bonus and will end with -bonus + points + bonus = points
         */
    }
    catch (const std::invalid_argument& e) {
        return StatusType::FAILURE; //student doesn't exist
    }
    catch (const std::bad_alloc& e) {
        return StatusType::ALLOCATION_ERROR;
    }
    catch (...) {
        return StatusType::FAILURE;
    }
}




