#include "headers/group.h"
#include <iostream>
#include <bits/stdc++.h>

int Group::freeId = 10;

Group::Group() {
    for(int i=0;i<30;i++) this->studentsArr[i] = nullptr;

    this->numberOfStudents = 0;
    this->number = -1;
}

Group::Group(int groupNumber) {
    for(int i=0;i<30;i++) this->studentsArr[i] = nullptr;
    this->numberOfStudents = 0;

    this->number = groupNumber;
}

Group::~Group() {
    for(int i=0;i<30;i++) delete this->studentsArr[i];
}

int Group::newId() {
    return Group::freeId + 5;
}

void Group::addStudentToGroup(std::string grades) {
    Student* newStudent = new Student(Group::freeId,grades);
    Group::freeId = this->newId();

    if(this->numberOfStudents == 30){
        Student* lowestAvgGradesStudentPtr = newStudent;
        float newAvg = newStudent->avgGrades();

//        std::cout<<"==================== Grupa "<<this->number+1<<" ===================="<<std::endl; //TEST
//        std::cout<<"Student id:"<<newStudent->id<<" chce zapisac sie do grupy "<<this->number+1<<" ma srednia:"<<newAvg<<std::endl; //TEST

        for(int i=0;i<this->numberOfStudents;i++){
            if(this->studentsArr[i]->avgGrades() < lowestAvgGradesStudentPtr->avgGrades())
                lowestAvgGradesStudentPtr = studentsArr[i];
        }
        // TEST
//        std::cout<<"Student id:"<<lowestAvgGradesStudentPtr->id<<" ma najnizsza srednia: "<<lowestAvgGradesStudentPtr->avgGrades()<<" w grupie "<<
//        this->number+1<<std::endl;

        const float EPSILON = 0.0001f;
        if(newAvg > lowestAvgGradesStudentPtr->avgGrades() + EPSILON){
//            std::cout<<"Student id:"<<lowestAvgGradesStudentPtr->id<<" opuszcza grupe, Student id:"<<newStudent->id<<" dolancza do grupy "<<this->number+1<<std::endl; //TEST
            int idx;
            for (idx = 0; idx < sizeof(this->studentsArr) / sizeof(this->studentsArr[0]); idx++) {
                if (this->studentsArr[idx]->id == lowestAvgGradesStudentPtr->id) {
                    break;
                }
            }
            studentsArr[idx] = newStudent;
        }

//        std::cout<<std::endl; //TEST

        return;
    }

    this->studentsArr[this->numberOfStudents] = newStudent;
    this->numberOfStudents ++;
}

