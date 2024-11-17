#include <string>
#ifndef PD_STUDENT_H
#define PD_STUDENT_H

class Student {
public:
    Student();
    Student(int id, std::string grades);
    Student(const Student &student);

    ~Student();


    int id;
    int behavior;
    int numberOfAwards;
    int *gradesArrPtr;
    int numberOfGrades;

    float avgGrades();

    int fivePlusCounter();

private:
    void setGrades(std::string s);


};

#endif
