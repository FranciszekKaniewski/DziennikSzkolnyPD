#ifndef PD_GROUP_H
#define PD_GROUP_H
#include <string>
#include "student.h"

class Group{
public:
    Group();
    Group(int groupNumber);

    ~Group();

    Student* studentsArr[30];
    int numberOfStudents;
    int number;

    void addStudentToGroup(std::string grades);
private:
    static int freeId;

    static int newId();
};

#endif