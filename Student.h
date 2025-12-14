#pragma once
struct Student {
    int m_id;
    int m_points;
    Student(const int id, const int points) : m_id(id), m_points(points) {}
    Student() = delete;
};